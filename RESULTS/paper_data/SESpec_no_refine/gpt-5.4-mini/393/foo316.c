
/*@ 
  assigns \nothing;
  ensures \result == ((\old(num) <= 0 ? 1 : fact(\old(num))) % 100);
*/
int foo316(int num) {

		int ret = 1;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns loop, ret;
        */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int remainder = (int) (ret % 100);
		return remainder;
}
