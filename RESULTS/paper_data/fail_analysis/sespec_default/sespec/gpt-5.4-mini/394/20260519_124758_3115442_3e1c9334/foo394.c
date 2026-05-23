
/*@
  assigns \nothing;
*/
int foo394(int num) {

		int ret = 1;
		
        /*@
          loop invariant 1 <= loop;
          loop invariant ret >= 1;
          loop invariant num == \at(num, Pre);
          loop assigns loop, ret;
        */
        for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int result = (int) (ret % 100);
		return result;
}
