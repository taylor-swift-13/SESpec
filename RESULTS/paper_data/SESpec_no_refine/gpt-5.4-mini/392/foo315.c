
/*@
  assigns \nothing;
*/
int foo315(int num) {

		int ret = 1;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns number, ret;
        */
            for (int number = 1; number <= num; number++) {
			ret *= number;
		}
            
		int result = (int) (ret % 100);
		return result;
}
