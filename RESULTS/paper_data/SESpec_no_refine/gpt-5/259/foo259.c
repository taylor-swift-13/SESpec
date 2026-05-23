
/*@
  // No additional predicates or logic functions are required.
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (\result == -1) || (0 <= \result < args_len && \result < array && args[\result] == \result);
  ensures \result != -1 ==> (0 <= \result < args_len && \result < array && args[\result] == \result);
  ensures \result == -1 ==> (
            array <= 0 ? \true :
            \forall integer k; 0 <= k < (args_len < array ? args_len : array) ==> args[k] != k
          );
  ensures \result == (\exists integer k; 0 <= k < args_len && k < array && args[k] == k) ? 
            (\exists integer k; 0 <= k < args_len && k < array && args[k] == k && \result == k) : -1;
*/
int foo259(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. args_len - 1));
          loop invariant stop < array;
          loop invariant 0 <= i <= stop + 1;
          loop assigns i, stop;
            */
            while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
            
		return -1;
}
