
/*@
  // no extra predicates or logic functions are needed
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;   
  ensures (\result == -1) || (0 <= \result < n && args[\result] == array); 
  ensures \result == \result;  
*/
int foo220(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant n == \at(n,Pre);
              loop invariant array == \at(array,Pre);
              loop invariant args_len == \at(args_len,Pre);
              loop invariant args == \at(args,Pre);
              loop invariant \valid_read(args + (0 .. n-1));
              loop invariant 0 <= n ==> 0 <= i <= n;
              loop invariant -1 <= hi < n;
              loop invariant i <= hi + 1;
              loop invariant (result == -1) || (0 <= result < n && args[result] == array);
              loop assigns i, hi, result;
            */
            while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
