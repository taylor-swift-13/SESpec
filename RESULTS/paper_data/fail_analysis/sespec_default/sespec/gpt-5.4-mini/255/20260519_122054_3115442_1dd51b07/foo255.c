

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
*/
int foo255(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		
            
        /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant array == \at(array,Pre);
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
