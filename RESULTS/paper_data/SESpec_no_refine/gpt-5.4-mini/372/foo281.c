
/*@
  assigns \nothing;
  ensures \result == count_divisors(num, num);
*/
int foo281(int num) {

		int div = 0;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns c, div;
        */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
            
		return div;
}
