
/*@
  logic integer divcount(integer n, integer low, integer high) =
    low >= high ? 0 : ((low != 0 && n % low == 0) ? 1 : 0) + divcount(n, low + 1, high);
*/

/*@
  requires num >= 0;
  assigns \nothing;
  
  ensures \true;
  ensures \true;
*/
const char * foo282(int num) {

		int result = 0;
		
        /*@
          loop invariant 1 <= c;
          loop invariant c <= num + 1;
          loop invariant num == \at(num,Pre);
          loop invariant 0 <= result;
          loop invariant result <= c;
          loop assigns c, result;
        */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
