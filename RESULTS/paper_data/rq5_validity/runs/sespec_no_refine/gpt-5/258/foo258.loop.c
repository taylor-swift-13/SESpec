
/*@
  // no additional predicates or logic functions are needed
*/

int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant array == \at(array,Pre);
              loop invariant i_len == \at(i_len,Pre);
              loop invariant i == \at(i,Pre);
              loop invariant stop == array - 1 ==> ret == 0;
              loop invariant 0 <= ret || stop < 0;
              loop invariant ret <= stop ==> 0 <= ret;
              loop invariant ret <= stop ==> stop < i_len;
              loop invariant \valid_read(i + (0 .. i_len-1));
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
