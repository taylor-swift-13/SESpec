
/*@
  logic integer count_div(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_div(n, lo, hi - 1) + ((n % (hi - 1)) == 0 ? 1 : 0);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 == 0) ==> \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 != 0) ==> \result != \null;
*/
const char * foo280(int number) {
		int result = 0;
		
        /*@
          loop invariant 1 <= c;
          loop invariant c <= number + 1;
          loop invariant number == \at(number, Pre);
          loop invariant 0 <= result <= c - 1;
          loop invariant result == count_div(number, 1, c);
          loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 || result >= 1);
          loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> count_div(number, 1, c) >= count_div(number, 1, k) + 1);
          loop invariant (c > number) ==> (result == count_div(number, 1, number + 1));
          loop invariant (c > number) ==> (number == \at(number, Pre));
          loop assigns c, result;
        */
        for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
