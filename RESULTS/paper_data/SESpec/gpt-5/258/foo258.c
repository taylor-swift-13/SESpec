

/*@
  requires \valid(&i[0] + (0..i_len-1));
  requires \forall integer k; 0 <= k < i_len ==> 0 <= i[k] <= 100;
  assigns \nothing;
  ensures (\result == -1) ==> (\at(array,Pre) == array && \at(i_len,Pre) == i_len && i == \at(i,Pre));
  ensures (\result >= 0) ==> (i == \at(i,Pre));
  ensures (\result >= 0) ==> (i[\result] == \at(i[\result],Pre));
  ensures (\result >= 0) ==> (i[\result] == \result);
  ensures (\result >= 0) ==> (0 <= \result);
  ensures \result == -1 || (i[\result] == \result);
*/
int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
        
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
