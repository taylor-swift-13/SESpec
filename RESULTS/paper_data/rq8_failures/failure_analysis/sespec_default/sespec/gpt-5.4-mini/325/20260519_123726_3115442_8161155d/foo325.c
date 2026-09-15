
/*@ 
  assigns \nothing;
  
*/
int foo325(int num) {

		int first = 1;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns j, first;
        */
        for (int j = 2; j <= num; j++) {
			first *= j;
		}
            
		int result = 0;
		
        /*@
          loop invariant 0 <= result <= 9;
          loop assigns result, first;
        */
        while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
