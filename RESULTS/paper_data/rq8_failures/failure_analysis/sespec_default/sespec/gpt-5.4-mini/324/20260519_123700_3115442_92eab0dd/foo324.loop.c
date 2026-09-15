
/*@ logic integer prod_upto(integer n) =
      n <= 1 ? 1 : prod_upto(n - 1) * n;
*/

int foo324(int number) {

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
          loop invariant \true;
          loop invariant 0 <= result < 10;
          loop assigns result, first;
        */
        while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
