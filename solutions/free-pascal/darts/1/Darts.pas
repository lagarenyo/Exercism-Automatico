unit Darts;

{$mode ObjFPC}{$H+}

interface

function score(const x : single; const y : single) : uint8;

implementation

uses SysUtils;

function score(const x : single; const y : single) : uint8;
var 
	rad: single;
begin
	rad:= sqrt( sqr( x ) + sqr( y ));
		if rad > 10 then
		result := 0
	else
		if rad > 5 then
			result := 1
		else
			if rad > 1 then
				result := 5
			else
		result := 10;	
end;
end.