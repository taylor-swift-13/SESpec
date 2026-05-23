
/*@ 
  predicate sorted(int* a, integer lo, integer hi) =
    \forall integer x,y; lo <= x <= y < hi ==> a[x] <= a[y];
*/

/*@
  requires \valid(args + (0..\at(args_len,Pre)-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires sorted(args, 0, \at(args_len,Pre));
*/
int foo256(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= \at(args_len,Pre);
          loop invariant -1 <= top <= \at(args_len,Pre) - 1;
          loop invariant ret <= top + 1;
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant sorted(args, 0, \at(args_len,Pre));
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
