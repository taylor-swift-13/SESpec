
/*@
*/

int foo393(int num) {

		int ret = 1;
		
            
        /*@ 
          loop invariant ret >= 1;
          loop invariant loop >= 1;
          loop assigns ret, loop;
        */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int remainder = (int) (ret % 100);
		return remainder;
}
