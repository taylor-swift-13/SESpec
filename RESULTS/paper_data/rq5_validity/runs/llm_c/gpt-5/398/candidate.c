#include <limits.h>

/*@ 
  logic integer ipow10(integer k) = k <= 0 ? 1 : 10 * ipow10(k-1);
*/

/*@ 
  requires \true;
  assigns \nothing;

  behavior nonpositive:
    assumes number <= 0;
    ensures \result == 0;

  behavior positive:
    assumes number > 0;
    ensures \result >= 1;
    ensures \old(number) / ipow10(\result) == 0;
    ensures \old(number) / ipow10(\result - 1) > 0;

  disjoint behaviors nonpositive, positive;
  complete behaviors nonpositive, positive;

  ensures \result >= 0;
*/
int countDigit(int number);

int countDigit(int number) {

		int ret = 0;
		/*@
		  loop invariant ret >= 0;
		  loop invariant number == \at(number,Pre) / ipow10(ret);
		  loop assigns number, ret;
		  loop variant number;
		*/
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}
