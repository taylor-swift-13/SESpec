#include <limits.h>

int evenBitToggleNumber(int number);

/*@ 
  assigns \nothing;

  ensures number <= 0 ==> \result == number;

  ensures number > 0 ==>
    (\exists integer len;
        0 <= len < 8 * sizeof(int) &&
        ((number >> len) == 0) &&
        (len == 0 || ((number >> (len - 1)) != 0)) &&
        (\forall integer i; 0 <= i < 8 * sizeof(int) ==>
            (
              ((i < len) && (i % 2 == 0)) ==> (((\result >> i) & 1) == 1 - (((number >> i) & 1)))
            ) &&
            (
              (!((i < len) && (i % 2 == 0))) ==> (((\result >> i) & 1) == (((number >> i) & 1)))
            )
        )
    );
*/
int evenBitToggleNumber(int number) {

		int result = 0;
		int ret = 0;
		int total = number;

		/*@
		  loop invariant number > 0;
		  loop invariant 0 <= ret <= (int)(8 * sizeof(int)) - 2;
		  loop invariant total >= 0;
		  loop invariant total == (number >> ret);
		  loop invariant \forall integer i; 0 <= i < ret ==> (((result >> i) & 1) == (i % 2 == 0 ? 1 : 0));
		  loop invariant \forall integer i; ret <= i < 8 * sizeof(int) ==> (((result >> i) & 1) == 0);
		  loop assigns result, ret, total;
		  loop variant total;
		*/
		while (total > 0) {
			//@ assert 0 <= ret <= (int)(8 * sizeof(int)) - 2;
			if (ret % 2 == 0) {
				//@ assert 0 <= ret <= (int)(8 * sizeof(int)) - 2;
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ result;
}
