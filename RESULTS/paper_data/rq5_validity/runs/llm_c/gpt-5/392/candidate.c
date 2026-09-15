#include <limits.h>

/*@ logic integer fact(integer n) = (n <= 0) ? 1 : n * fact(n-1); */

int lastTwoDigits(int num);

/*@ 
  requires num <= 12;
  assigns \nothing;
  ensures 0 <= \result && \result < 100;
  ensures \result == (fact(num) % 100);
  terminates \true;
*/
int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		  loop invariant (num < 1) ==> (number == 1 && ret == 1);
		  loop invariant (num >= 1) ==> (1 <= number && number <= num + 1 && ret == fact(number - 1));
		  loop assigns ret, number;
		  loop variant (num >= 1) ? (num - number + 1) : 0;
		*/
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		/*@ assert ret == fact(num); */
		int result = (int) (ret % 100);
		return result;
}
