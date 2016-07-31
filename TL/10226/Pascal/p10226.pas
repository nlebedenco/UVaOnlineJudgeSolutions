{
Problema:

receberemos entradas com nomes de �rvores. Devemos ordenar estes nomes em ordem alfab�tica crescente sem repeti��o,
enquanto computamos o n�mero de ocorr�ncias de cada tipo de �rvore e o total de entradas. 
Terminadas as entradas, imprimimos a lista em ordem alfab�tica onde cada nome � seguido pelo percentual de presen�a 
na lista com precis�o de 4 casas decimais. O m�ximo de esp�cies � 10.000. O m�ximo de entradas � 1.000.000
Cada nome de �rvore tem no m�ximo 30 caracteres.

Solu��o:

Usaremos um vetor de 10.000 posi��es para as poss�veis 10.000 esp�cies distintas. Usaremos pesquisa bin�ria para
verificar se um elemento j� foi inserido. Caso j� tenha si inserido (retornando o �ndice do elemento)
incrementamos sua contagem de ocorr�ncias, caso contr�rio inserimos usando inser��o num vetor ordenado
}

program p10226(input, output);

type 
	pEspecie 	= ^TEspecie;
	TEspecie 	= record 
				Chave: string[30];
				Nome: string[30];
				Entradas: longint;
			  end;
		   
var
	Arvore: pEspecie;			// Vari�vel para conter o nome da �rvore que est� dando entrada entrada
	NovoNome: string[30];			// para conter o nome da nova esp�cie entrada.
	Especies: array [1..10000] of pEspecie; // vetor de esp�cies distintas
	TotalEntradas: longword = 0;		// Total de entradas para calculo do percentual de incid�ncia de esp�cies
	TotalEspecies: word = 0;		// Total de Esp�cies distintas
	TestCases: word = 0;		// N�mero de Test Cases - deveria se word ou longword, mas se passarem um n�mero negativo temos que desviar o erro
	Caso: word = 1;			// Caso Sendo recebido - o primeiro caso deve ser 1
	Indice: word;				// para receber o valor da pesquisa bin�ria
	x: word;
	
{Busca bin�ria. Se encontrar retorna o �ndice do elemento, se n�o encontrar retorna 0}
function BinarySearch(Prim, Ult: word; const Chave: string[30]): word; 
var
	m: word;
begin
	Result := 0;
	if Prim > Ult then Exit; // caso em que n�o h� nenhum item no vetor
	while (Prim <= Ult) do
	begin
		m := (Prim + Ult) div 2;
		if (Chave < Especies[m]^.Chave) then Ult := m - 1
		else if (Chave > Especies[m]^.Chave) then Prim := m + 1
		else Prim := Ult + 1;
	end;
	if (Especies[m]^.Chave = Chave) then Result := m;
end;

	
{Functions}
procedure Insere(NovaEntrada: pEspecie);
var
	i: word;
begin
	i := TotalEspecies;
	while (i >= 1) and (Especies[i]^.Chave > NovaEntrada^.Chave) do
	begin
		Especies[i+1] := Especies[i];
		Dec(i);
	end;
	Especies[i+1] := NovaEntrada;
	Inc(TotalEspecies);
end;

begin
while not eof do
begin
	Readln(TestCases);
	Readln;
	Caso := 1;
	while Caso <= TestCases do
	begin
		{Recebe o Input}
		Readln(NovoNome);
		while NovoNome <> '' do
		begin
			{Primeiro Pesquisa}
			Indice := BinarySearch(1, TotalEspecies, NovoNome);
			if Indice > 0 then Inc(Especies[Indice]^.Entradas)
			else 
			begin
				new(Arvore);
				with (Arvore^) do
				begin
					Nome := NovoNome;
					Chave := Nome;
					Entradas := 1;
				end;
				Insere(Arvore);
			end;
			Inc(TotalEntradas);
			Readln(NovoNome);
		end;
		{Exibe o Output} 
		for x := 1 to TotalEspecies do
		begin
			writeln(Especies[x]^.Nome, ' ', (Especies[x]^.Entradas / TotalEntradas * 100):0:4);
			dispose(Especies[x]); // Cada Elemento deve ser desalocado conforme for exibido
			Especies[x] := nil;
			//if x < TotalEspecies then writeln;
		end;
		if Caso < TestCases then begin writeln; end;   // devemos imprimir uma linha em branco entre os outputs de diferentes testcases
		
		Inc(Caso); // Incrementa o contador de casos
		{ReInicializa Vari�veis}
		TotalEntradas := 0;
		TotalEspecies := 0;
	end;
end;
end.