
/*@
  logic integer occ(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures \result == \result;
*/
int foo256(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (0 <= ret <= top + 1);
          
          
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop assigns ret, top;
            */
            while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return ret;
}
