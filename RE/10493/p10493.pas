program p10493;
uses math;
const
     INPUT_FILE = 'input3';
var
   N, M, nivel, x: longword;
   Folhas, Elementos: extended;
begin
     {$IFNDEF ONLINE_JUDGE}
             assign(input, INPUT_FILE); reset(input);
     {$ENDIF}
     while not eof(input) do
     begin
         read(N);
         readln(M);
         if (N = 0) and (M = 0) then Exit;
         write(N, ' ', M, ' ');
         if M = 1 then
         begin
              if (N > 1) then writeln('1')
              else if (N = 1) then writeln('Multiple');

         end
         else if (N = 1) then writeln('Impossible')
         else
         begin
                  nivel := 0;
                  Folhas := 1;
                  while round(Folhas) < M do
                  begin
                       Inc(nivel);
                       Folhas := power(N, nivel-1);
                  end;
                  Elementos := 0;
                  for x := 1 to nivel do Elementos := Elementos + power(N, x-1);

                  while round(Folhas) > M do
                  begin
                       Folhas := Folhas - N;
                       Folhas := Folhas + 1;
                       Elementos := Elementos - N;
                  end;
                  if round(Folhas) < M then writeln('Impossible')
                  else writeln(round(Elementos));
         end;
     end;
end.