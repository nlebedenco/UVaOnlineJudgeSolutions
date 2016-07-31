#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

const int BASE = 10000;	// 10^4 para que a multiplicação possa caber num long 
struct Bigint
{
	deque<long> number;
	bool negativo;

	Bigint(const deque<long>& v = deque<long>(), const bool sinal = false): number(v),negativo(sinal){}
	Bigint(const Bigint& a):number(a.number), negativo(a.negativo){} // const de copia
	
	Bigint(int n)  { *this = Bigint((unsigned long)n); negativo = (n < 0); }
	Bigint(long n) { *this = Bigint((unsigned long)n); negativo = (n < 0); }
	Bigint(unsigned int n):negativo(false) { *this = Bigint((unsigned long)n); }
	Bigint(unsigned long);
	Bigint(const string&);
		
	bool isZero() const;
	void removeZeros() { while (not number.empty() && number.back() == 0) number.pop_back(); }
	int compare(const Bigint&) const;
	int unsignedcompare(const Bigint&) const;
	string str() const;
	long tolong() const;
	
	Bigint& operator=(const Bigint&); // assignment operator
};

Bigint::Bigint(unsigned long n):negativo(false)
{
	while (n > 0)
	{
		number.push_back(n % BASE);
		n /= BASE;
	}
}

Bigint::Bigint(const string& S):negativo(false)
{
	if (S.empty()) *this = Bigint();
	else if (not isdigit(S[0]) && S[0] != '-') *this = Bigint();
	else
	{	
		int k = (int)log10(double(BASE));
		int i = S.size();
		while (i >= k)
		{
			i -= k;
			number.push_back(labs(strtol(S.substr(i, k).c_str(), NULL, 10)));
		}
		number.push_back(labs(strtol(S.substr(0, i).c_str(), NULL, 10)));
		removeZeros();
		negativo = (S[0] == '-');
	}
}

Bigint& Bigint::operator=(const Bigint& B)
{
	if (this != &B)
	{
		number = B.number;
		negativo = B.negativo;
	}
	return *this;
}

bool Bigint::isZero() const
{
	for (int i = 0; i < number.size(); i++)
		if (number[i] != 0) return false;
	return true;
}

string Bigint::str() const
{
	if (isZero()) return "0";
	
	stringstream S;
	if (negativo) S << '-';
	S << number.back();
	for (int i = number.size()-2; i > -1; i--)
		S << setw((int)log10(double(BASE))) << setfill('0') << number[i];
	return S.str();
}

long Bigint::tolong() const
{
	long a = 0; 
	for (int i = 0; i < number.size() && a >= 0; i++) 
		a += number[i]; // a >= pra parar se o a estourar!	
	a *= (negativo?-1:1); // acerta o sinal
}

int Bigint::unsignedcompare(const Bigint& B) const
{
	bool y = isZero(); bool z = B.isZero();
	if (y && z) return 0;
	if (not y && z) return 1;
	if (y && not z) return -1;
	
	if (number.size() != B.number.size()) return (number.size() < B.number.size()? -1: 1);
	for (int i = number.size()-1; i > -1; i--)
		if (number[i] != B.number[i]) return (number[i] < B.number[i]? -1: 1);
	return 0;
}

int Bigint::compare(const Bigint& B) const
{
	if (negativo != B.negativo) return negativo?-1:1;
	if (not negativo) return unsignedcompare(B);
	else return unsignedcompare(B) * -1;
}

Bigint abs(const Bigint& A) { return Bigint(A.number, false); }

Bigint operator -(const Bigint&, const Bigint&); // foreward declaration needed by operator+
Bigint operator +(const Bigint& A, const Bigint& B)
{
	if (A.negativo != B.negativo) 
	{
		if (A.negativo) return (B - abs(A));
		else return A - abs(B);
	}
	int i; 
	Bigint C; 
	long vaiUm = 0;
	for (i = 0; i < A.number.size() && i < B.number.size(); i++)
	{
		C.number.push_back( (A.number[i] + B.number[i] + vaiUm) % BASE);
		vaiUm = (A.number[i] + B.number[i] + vaiUm) / BASE;
	}
	for (; i < A.number.size(); i++)
	{
		C.number.push_back( (A.number[i] + vaiUm) % BASE);
		vaiUm = (A.number[i] + vaiUm) / BASE;
	}
	for (; i < B.number.size(); i++)
	{
		C.number.push_back( (B.number[i] + vaiUm) % BASE);
		vaiUm = (B.number[i] + vaiUm) / BASE;
	}
	if (vaiUm) C.number.push_back(vaiUm);
	C.negativo = A.negativo;
	return C;
}

Bigint operator -(const Bigint& A, const Bigint& B)
{
	Bigint C;
	if (A.negativo != B.negativo) return A + Bigint(B.number, not B.negativo);
	if (A.compare(B) == -1) return Bigint((B - A).number, true); // se B > A, B - A * (-1)
	
	long borrow = 0;
	int i;
	for (i = 0; i < B.number.size(); i++)		// se A > B, A.size() >= B.size()
	{
		long v = A.number[i] - borrow - B.number[i];
		if (A.number[i] > 0) borrow = 0;
		if (v < 0)
		{
			v += BASE;
			borrow = 1;
		}
		C.number.push_back(v % BASE);
	}
	for (;i < A.number.size(); i++)
	{
		long v = A.number[i] - borrow;
		if (A.number[i] > 0) borrow = 0;
		C.number.push_back(v % BASE);
	}
	C.removeZeros();
	return C;
}

bool operator==(const Bigint& A, const Bigint& B) { return (A.compare(B) == 0);  }
bool operator <(const Bigint& A, const Bigint& B) { return (A.compare(B) == -1); }
bool operator >(const Bigint& A, const Bigint& B) { return (B < A);  }
bool operator<=(const Bigint& A, const Bigint& B) { return not (B < A);  }
bool operator>=(const Bigint& A, const Bigint& B) { return not (A < B);  }
bool operator!=(const Bigint& A, const Bigint& B) { return not (A == B); }

ostream& operator <<(ostream& stream, const Bigint& A) { return stream << A.str(); }
istream& operator >>(istream& stream, Bigint& A) 
{ 
	string ws;
	stream >> ws;
	if (not ws.empty() && ws != "-")
		if ( (isdigit(ws[0]) || ws[0] == '-') 
			&& ws.find_first_not_of("0123456789", 1) == string::npos )
				A = Bigint(ws);
	return stream;
}

//using namespace std;

vector <Bigint> V (5000);

Bigint Fib(int n)
{
	if (n == 1) return Bigint("1");
	else if (n == 2) return Bigint("1");
	else 
	{
		if (V[n] != Bigint("0")) return V[n];
		else 
		{
			V[n] = Fib(n-1) + Fib(n-2);
			return V[n];
		}
	}
}
int a;
int main()
{
	while (cin >> a) cout << Fib(a) << "\n";

	return 0;
}
