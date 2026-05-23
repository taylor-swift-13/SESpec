
int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant i_len == \at(i_len,Pre);
          loop invariant i == \at(i,Pre);
          loop invariant (ret <= stop) ==> (ret <= (ret + (stop - ret) / 2) && (ret + (stop - ret) / 2) <= stop);
          loop invariant \forall integer k; 0 <= k < i_len ==> i[k] == \at(i[k], Pre);

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
