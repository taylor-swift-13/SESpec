
/*@
  assigns \nothing;
*/
int foo393(int num) {

		int ret = 1;
		
        /*@
          loop invariant 1 <= loop;
          loop invariant num == \at(num,Pre);
          loop assigns loop, ret;
        */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int remainder = (int) (ret % 100);
		return remainder;
}
