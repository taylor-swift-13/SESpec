
/*@
  assigns \nothing;
  ensures \result == 0 || \result >= 0;
*/
int foo326(int num) {

		int first = 1;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns c, first;
        */
        for (int c = 2; c <= num; c++) {
			first *= c;
		}
            
		int result = 0;
		
        /*@
          loop invariant result == 0 || result >= 0;
          loop assigns result, first;
        */
        while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
