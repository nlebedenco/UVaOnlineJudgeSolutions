program p10487;
const
     INPUT_FILE = 'input2.pas';
     SIZE = 1000;
var
   fator: array[0..SIZE] of longint;  // 0 eh sentinela
   Objetivo, MaisProximo, Candidato: longint;
   num_fatores, x, y, query: word;
   num_queries: longword;
   Caso: word;

procedure Sort;
var
   i, j: word;
begin
    for i := 2 to num_fatores do
    begin
        fator[0] := fator[i];
        j := i;
        while (fator[j-1] > fator[0]) do
        begin
            fator[j] := fator[j-1];
            Dec(j);
        end;
        fator[j] := fator[0];
    end;
end;

begin
     {$IFNDEF ONLINE_JUDGE}
             assign(input, INPUT_FILE); reset(input);
     {$ENDIF}
     Caso := 0;
     while not eof(input) do
     begin
          readln(num_fatores); if num_fatores = 0 then Exit;

          Inc(Caso);

          for x := 1 to num_fatores do readln(fator[x]);

          readln(num_queries);
          Sort;

          writeln ('Case ', Caso,':');
          for query := 1 to num_queries do
          begin
             readln(objetivo);
             MaisProximo := 0;
             if objetivo <= fator[2] then MaisProximo := fator[1] + fator[2]
             else
             begin
                  for x := num_fatores downto 2 do
                  begin
                     for y := x-1 downto 1 do
                     begin
                        Candidato := fator[x] + fator[y];
                        if abs(objetivo - candidato) < abs(objetivo - MaisProximo) then
                            MaisProximo := Candidato;
                     end;
                     if MaisProximo = objetivo then break;
                  end;
             end;

             writeln('Closest sum to ', objetivo, ' is ', MaisProximo, '.');
          end;


     end;
end.