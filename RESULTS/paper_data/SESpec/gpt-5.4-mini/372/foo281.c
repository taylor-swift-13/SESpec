
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == 0 || \result > 0;
*/
int foo281(int num) {

		int div = 0;
		
            /*@
          loop invariant div >= 0;
          loop invariant num == \at(num,Pre);
          loop invariant (c <= \at(num,Pre)) ==> (div <= c - 1);
          loop assigns c, div;
            */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
            
		return div;
}
