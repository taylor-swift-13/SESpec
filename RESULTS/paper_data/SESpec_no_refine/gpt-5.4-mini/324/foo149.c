
/*@
  assigns \nothing;
  ensures \result == (fact(number) % 10);
*/
int foo149(int number) {
		int first = 1;
		
        /*@
          loop invariant number == \at(number,Pre);
          loop assigns c, first;
        */
            for (int c = 2; c <= number; c++) {
			first *= c;
		}
            
		int result = 0;
		
            
        /*@
          loop assigns result, first;
        */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
