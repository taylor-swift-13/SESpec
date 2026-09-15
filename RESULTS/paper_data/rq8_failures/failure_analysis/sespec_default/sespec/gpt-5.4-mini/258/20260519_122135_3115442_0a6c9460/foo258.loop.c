
int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant stop < array;
          loop invariant (0 <= array - 1) ==> (ret <= stop + 1);
          loop invariant (!(0 <= array - 1)) ==> (ret == 0 && stop == array - 1);
          loop invariant array == \at(array,Pre);
          loop invariant i_len == \at(i_len,Pre);
          loop invariant i == \at(i,Pre);
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
