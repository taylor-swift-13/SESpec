
/*@ logic integer bs_rec(int *args, integer first, integer last, integer value); */

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures args_len == \old(args_len);
  ensures array == \old(array);
  ensures (args_len <= 0) ==> \result == 0;
  ensures (args_len > 0) ==> (0 <= \result <= args_len);
  ensures \result >= 0;
*/
int foo255(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < \at(args_len,Pre) ==> args[k] == \at(args[k], Pre);

          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (0 <= result <= \at(args_len,Pre) && -1 <= top <= \at(args_len,Pre) - 1 && result <= top + 1);
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= result <= \at(args_len,Pre)));
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= top <= \at(args_len,Pre) - 1));
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < \at(args_len,Pre) ==> args[k] == \at(args[k], Pre) ;
          loop assigns result, top;
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
