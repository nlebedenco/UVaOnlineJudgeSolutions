{
Problema:

receberemos entradas com nomes de árvores. Devemos ordenar estes nomes em ordem alfabética crescente sem repetição,
enquanto computamos o número de ocorrências de cada tipo de árvore e o total de entradas. 
Terminadas as entradas, imprimimos a lista em ordem alfabética onde cada nome é seguido pelo percentual de presença 
na lista com precisão de 4 casas decimais. O máximo de espécies é 10.000. O máximo de entradas é 1.000.000
Cada nome de árvore tem no máximo 30 caracteres.

Solução:

Usaremos um vetor de 10.000 posições para as possíveis 10.000 espécies distintas. Usaremos pesquisa binária para
verificar se um elemento já foi inserido. Caso já tenha si inserido (retornando o índice do elemento)
incrementamos sua contagem de ocorrâncias, caso contrário inserimos usando inserção num vetor ordenado
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
	Arvore: pEspecie;			// Variável para conter o nome da Árvore que está dando entrada entrada
	NovoNome: string[30];			// para conter o nome da nova espécie entrada.
	Especies: array [1..10000] of pEspecie; // vetor de espécies distintas
	TotalEntradas: longword = 0;		// Total de entradas para calculo do percentual de incidência de espécies
	TotalEspecies: word = 0;		// Total de Espécies distintas
	TestCases: word = 0;		// Número de Test Cases - deveria se word ou longword, mas se passarem um número negativo temos que desviar o erro
	Caso: word = 1;			// Caso Sendo recebido - o primeiro caso deve ser 1
	Indice: word;				// para receber o valor da pesquisa binária
	x: word;
	
{Busca binária. Se encontrar retorna o índice do elemento, se não encontrar retorna 0}
function BinarySearch(Prim, Ult: word; const Chave: string[30]): word; 
var
	m: word;
begin
	Result := 0;
	if Prim > Ult then Exit; // caso em que não há nenhum item no vetor
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
		{ReInicializa Variáveis}
		TotalEntradas := 0;
		TotalEspecies := 0;
	end;
end;
end.