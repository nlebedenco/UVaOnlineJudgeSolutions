program p10611(input, output);

const
     MAX_MACACAS = 50000;
     SEM_MACACA = 'X';

var
   NumeroMacacas, i: word;
   Macacas: array[1..MAX_MACACAS] of longword;
   Perguntas, j: word;
   Altura: longword;
   Indice, anterior, posterior: word;

function Pesquisa(k: longword): word;
var
   c, f, m: word;
begin
    c := 1;
    f := NumeroMacacas;
    while (c <= f) do
    begin
       m := (c + f) div 2;
       if (k < Macacas[m]) then f := m - 1
       else
       begin
          if (k > Macacas[m]) then c := m + 1
          else c := f +1;
       end;
    end;
    Pesquisa := m
end;

begin
    {$IFNDEF ONLINE_JUDGE} assign(input, 'input2.txt'); reset(input); {$ENDIF}

    while not eof(input) do
    begin
        Readln(NumeroMacacas);
        for i := 1 to NumeroMacacas do
        begin
            Read(Macacas[i]);
        end;
        readln;
        Readln(Perguntas);
        for j := 1 to Perguntas do
        begin
            Read(Altura);
            Indice := Pesquisa(Altura);
            anterior := indice;
            while (Macacas[anterior] >= Altura) and  (anterior >= 1) do            Dec(anterior);
            if anterior = 0 then write(SEM_MACACA, ' ')
            else write(Macacas[anterior], ' ');

            posterior := indice;
            while (Macacas[posterior] <= Altura) and (posterior <= NumeroMacacas) do  Inc(posterior);
            if (posterior = NumeroMacacas + 1) then write(SEM_MACACA)
            else write(Macacas[posterior]);

            writeln;
        end;
        Readln;
    end;
end.