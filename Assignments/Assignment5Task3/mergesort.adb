with Ada.Text_IO, Ada.Integer_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO;

procedure main is

type MY_ARRAY is array(1..5) of integer;
R:MY_ARRAY;

    procedure merge (a:           in out MY_ARRAY;
					 low,mid,high:in     integer) is
       temp: MY_ARRAY;
       choose1: boolean;
       loop_low,loop_high:integer;

    begin
       loop_low:=low;
       loop_high:=high;

       for i in low..high loop

          if (loop_low>mid) then choose1:=false;
          elsif (loop_high>high) then choose1:=true;
          else  choose1:= a(loop_low)<a(loop_high);
          end if;			-- choose which side

          if choose1 then		-- choose from low side
              temp(i):=a(loop_low);
              loop_low:=loop_low+1;
          else
              temp(i):=a(loop_high);	-- choose from high side
              loop_high:=loop_high+1;
          end if;
       end loop;
       a:=temp;
    end merge;

    procedure mergesort(a: 		 in out MY_ARRAY;
						low,high:       integer) is
       mid:integer;
    begin
       if low<high then
         mid:= (high+low)/2;
         mergesort(a,low,mid);
         mergesort(a,mid+1,high);
         merge(a,low,mid,high);
       end if;
    end mergesort;

begin
	-- something happens here to get the initial values of tosort
	R:= (12, 27, 13, 122, 44);
	
	-- then use mergesort to sort the array
	--mergesort(R,1,5);
	for Index in 1..5 loop
      Put("The array named First has the values ");
      Put(R(Index));
      New_Line;
   end loop;

end main;
