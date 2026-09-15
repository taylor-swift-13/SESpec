
/*@
  logic integer invpairs_prefix{L}(int* a, integer n) =
    n <= 0 ? 0
           : invpairs_prefix(a, n - 1)
             + (\sum integer j; 0 <= j < n - 1; (a[j] > a[n-1] ? 1 : 0));
*/
        
/*@
  requires \valid(args + (0 .. args_len-1));
  requires 0 <= num <= args_len;
  assigns \nothing;
  ensures \result == invpairs_prefix(args, num);
  ensures 0 <= \result <= num * (num - 1) / 2;
*/
int foo246(int * args, int args_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= \at(num,Pre);
          loop invariant 0 <= ret <= index * (index - 1) / 2;
          loop invariant ret == invpairs_prefix(args, index);
          loop invariant \forall integer t; 0 <= t < \at(args_len,Pre) ==> args[t] == \at(args[t],Pre);
          loop assigns index, k, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant 0 <= ret <= index * (index - 1) / 2;
          loop assigns ret, index;
            */
            for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
