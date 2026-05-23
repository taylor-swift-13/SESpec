
/*@
*/
        
int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant -1 <= stop;
          loop invariant ret <= stop + 1;
          loop invariant \forall integer k; 0 <= k < ret ==> i[k] < k;
          loop invariant \forall integer k; stop < k < array ==> i[k] > k;
          loop assigns ret, stop;
            */
            while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			if (i[cur] == cur) {
				return cur;
			} else if (i[cur] < cur) {
				ret = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
            
		return -1;
}
