#include<iostream> 
 #include<string> 
 #include<vector> 
 using namespace std; 
 
 int max(int x, int y) {if (x>y) return x; else return y;} 
 int min(int x, int y) {if (x<y) return x; else return y;} 
 
 int main() 
 { 
   vector<int> vecF; // vector holding each amount paid 
 
   while (1) 
   { 
      int num;  // number of students 
      int x; 
      int total=0; // total amount spent in pennies 
      int more=0; // amount over the average spent in pennies 
      int less=0; // amount under the average spent in pennies 
      bool round=false; // average came out evenly or not 
 
     vecF.clear(); 
 
      cin>>num; 
      if (!num) 
         break; 
 
      for (x=0; x<num; x++) 
      { 
          double d; 
          cin>>d; 
        d *=100; 
	d += 0.01;
          vecF.push_back(int(d)); 
          total+=(vecF[x]); 
      } 
 
      if (total%num!=0) 
          round=true; 
 
      total/=num; 
 
      for (x=0; x<vecF.size(); x++) 
      { 
          if (round && vecF[x]>=total+1) 
             more+=(vecF[x]-(total+1)); 
          else if (!round && vecF[x]>total) 
             more+=(vecF[x]-total); 
          else 
             less+=(total-vecF[x]); 
      } 
 
      less=max(less,more); 
 
      cout<<"$"<<less/100<<"."; 
 
      if (less%100<10) 
          cout<<"0"; 
       
      cout<<less%100<<endl; 
 
    } 
     
    return 0; 
 }  
