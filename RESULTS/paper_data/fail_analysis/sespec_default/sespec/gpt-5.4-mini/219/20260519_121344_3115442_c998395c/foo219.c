
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures \true;
*/
int foo219(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		
            /*@
              loop invariant result == -1 || args[result] == array;
              loop assigns ret, hi, result;
            */
            while (ret <= hi) {
			int tmp = (ret + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				ret = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
