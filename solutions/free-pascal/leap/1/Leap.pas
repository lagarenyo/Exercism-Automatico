unit Leap;

{$mode ObjFPC}{$H+}

interface

function LeapYear(const year : integer) : boolean;

implementation

uses SysUtils;

function LeapYear(const year : integer) : boolean;
begin
  if (year mod 4 = 0) then
    begin
      if ((year mod 100)=0) then
        if ((year mod 400)<>0) then
          exit(false);
      exit(true);
    end;
  LeapYear:= false;
end;
end.
