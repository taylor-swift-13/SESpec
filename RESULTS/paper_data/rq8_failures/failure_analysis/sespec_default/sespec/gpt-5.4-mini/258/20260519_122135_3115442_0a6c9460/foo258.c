

/*@
  requires \valid(i + (0 .. i_len - 1));
  requires \forall integer j; 0 <= j < i_len ==> 0 <= i[j] <= 100;
  requires i_len > 0;
  requires i_len < 100;
  requires 0 <= array <= i_len;
  assigns \nothing;
  ensures (\result >= 0) || \result == -1;
  ensures (\result >= 0) ==> i[\result] == \result;
*/
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
