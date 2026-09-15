
/*@
  requires \valid_read(i + (0 .. array-1));
  requires array >= 0;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && i[\result] == \result);
  ensures \result == -1 ==> \result == -1;
  ensures \result == -1 ==> \result == -1;
*/
int foo258(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant -1 <= stop < array;
          loop invariant ret <= stop + 1;

          loop invariant (0 <= \at(array,Pre) - 1) ==> (ret <= stop + 1);
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(i_len == \at(i_len,Pre))&&(i == \at(i,Pre))) || (ret <= stop + 1));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(i_len == \at(i_len,Pre))&&(i == \at(i,Pre))) || (ret <= stop + 1));
          loop invariant (!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(i_len == \at(i_len,Pre))&&(i == \at(i,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant i_len == \at(i_len,Pre);
          loop invariant i == \at(i,Pre);
          loop invariant \valid_read(i + (0 .. array-1));
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
