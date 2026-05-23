
/*@

*/

int foo398(int number) {

		int ret = 0;
		
            
        /*@
          loop invariant \true;
          loop invariant number >= 0;
          loop invariant ret >= 0;
          loop assigns number, ret;
        */
            while (number > 0) {
			number /= 10;
			ret++;
		}
            
		return ret;
}
