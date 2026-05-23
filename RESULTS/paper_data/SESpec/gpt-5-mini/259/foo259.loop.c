
/*@ 
  predicate valid_read_slice{L}(int* a, integer n) =
    n >= 0 ==> \valid_read(a + (0 .. n-1));
*/
        
int foo259(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		
            
        /*@
          loop invariant (0 <= \at(array,Pre) - 1) ==> (\forall integer k; 0 <= k < \at(array,Pre) ==> args[k] == \at(args[k],Pre));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= i && i <= \at(array,Pre) && -1 <= stop && stop < \at(array,Pre) && i <= stop + 1));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || ( -1 <= stop && stop < \at(array,Pre) ));
          loop invariant (!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop assigns i, stop;
        */
            while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
            
		return -1;
}
