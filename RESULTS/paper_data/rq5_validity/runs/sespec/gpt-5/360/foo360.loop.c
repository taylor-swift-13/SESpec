
#include <limits.h>

/*@
  logic integer count_odds(integer n) =
    n <= 0 ? 0 : count_odds(n - 1) + ((n % 2 != 0) ? 1 : 0);
*/

/*@
  logic integer sum_odds(integer n) =
    n <= 0 ? 0 : sum_odds(n - 1) + ((n % 2 != 0) ? n : 0);
*/

/*@
  requires size >= 1;
*/
int foo360(int size) {

		int average = 0;
		int total = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */

            /*@
          loop invariant 1 <= c <= \at(size,Pre) + 1;
          loop invariant size == \at(size,Pre);

          loop invariant 0 <= total <= c - 1;
          loop invariant 0 <= average;

          loop invariant total == count_odds(c - 1);
          loop invariant average == sum_odds(c - 1);

          loop invariant (c <= \at(size,Pre)) ==> (total == count_odds(c - 1));
          loop invariant (c <= \at(size,Pre)) ==> (average == sum_odds(c - 1));
          loop invariant (c <= \at(size,Pre)) ==> (average == sum_odds(c - 1)) ;
          loop invariant (c <= \at(size,Pre)) ==> (total == count_odds(c - 1)) ;
          loop invariant size == \at(size,Pre);
          loop assigns c, average, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}

		return average / total;
}
