
/*@
  logic integer idx(int result, int top) = result;
  logic integer topv(int result, int top) = top;
*/

/*@ 
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (0 <= \old(args_len) - 1) ==> (((\old(args_len) - 1 < 0) ==> \result == \old(args_len)) && ((\old(args_len) - 1 >= 0) ==> (\result == idx(result, top))));
  ensures (0 <= \old(args_len) - 1) ==> (((\old(args_len) - 1 < 0) ==> \result == \old(args_len)) && ((\old(args_len) - 1 >= 0) ==> (\result >= 0 && \result <= \old(args_len))));
  ensures (0 <= \old(args_len) - 1) ==> (((\old(args_len) - 1 < 0) ==> \result == \old(args_len)) && ((\old(args_len) - 1 >= 0) ==> (\result == \old(args_len) || (0 <= \result <= \old(args_len)))));
  ensures \old(args_len) > 0 ==> (\result >= 0 && \result <= \old(args_len));
  ensures (\exists integer i; 0 <= i < \old(args_len) && args[i] == array) ==> (0 <= \result < \old(args_len) && args[\result] == array);
  ensures (\forall integer i; 0 <= i < \old(args_len) && args[i] < array) ==> \result == \old(args_len);
  ensures (\forall integer i; 0 <= i < \old(args_len) && args[i] > array) ==> \result == 0;
*/
int foo118(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		
            
            /*@
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= result <= top + 1));
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (result <= top + 1));
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant 0 <= result <= \at(args_len,Pre);
            loop assigns i, result, top;
            */
            while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return result;
}
