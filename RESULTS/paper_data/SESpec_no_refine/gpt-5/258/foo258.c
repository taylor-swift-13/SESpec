
/*@
  // no additional predicates or logic functions are needed
*/

/*@
  requires \valid(&i[0] + (0..i_len-1));
  requires \forall integer k; 0 <= k < i_len ==> 0 <= i[k] <= 100;
  requires i_len > 0;
  requires i_len < 100;
  assigns \nothing;
  ensures (\result == -1 ==>
             (\forall integer k;
                0 <= k < (array < i_len ? array : i_len) ==> i[k] != k));
  ensures (\result != -1 ==>
             (0 <= \result < (array < i_len ? array : i_len) && i[\result] == \result));
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
