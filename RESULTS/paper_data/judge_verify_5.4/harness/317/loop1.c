#include <limits.h>

/*@ logic integer count_divs(integer num, integer size) =
      size < 2 ? 0 :
      count_divs(num, size - 1) + (num % size == 0 ? 1 : 0); */

/*@ requires (2 <= size) && (result >= 0) && (result == count_divs(num, size - 1)) && (result <= size - 2) && (\forall integer d; 2 <= d < size && d <= num / d && num % d == 0 ==> result >= 1) && ((size > 2) ==> result <= size - 2) && ((size <= num / size) ==> (result == count_divs(num, size - 1))) && ((!(size <= num / size)) ==> (result == count_divs(num, size - 1)));
    assigns \nothing;
*/
void check_A_implies_B(int d, int k, int num, int size) {
    /*@ assert (size >= 2 ==> result < size); */
    /*@ assert (size >= 2 ==> result >= 0); */
    /*@ assert (size >= 2 ==> result <= size); */
    /*@ assert (size >= 2 ==> result <= size - 1); */
    /*@ assert (size > 2 ==> result >= 0); */
    /*@ assert (size > 2 ==> result <= num); */
    /*@ assert (size <= num / size || size > num / size); */
    /*@ assert (result >= 0 ==> size >= 2); */
    /*@ assert (result == 0 || size >= 2); */
    /*@ assert (result == 0 || size > 2); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 || result <= size - 1); */
    /*@ assert (result == 0 || num >= 2); */
    /*@ assert (result <= size); */
    /*@ assert (result <= size - 2); */
    /*@ assert (result <= size - 1); */
    /*@ assert (num == num); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k == 0 || num % k != 0)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= size)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= num)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < size ==> (num % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < size && num % k == 0 ==> result >= 1); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 1); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 0); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d == 0 ==> result <= size); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d != 0 || result >= 1); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d != 0 || result >= 0); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d != 0 || result > 0); */
    /*@ assert (\forall integer d; 2 <= d < size ==> num % d != 0 ==> result >= 0); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d == 0 || num % d != 0)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 1)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 0)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= size)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= num)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 1)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 0)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d != 0 ==> result >= 0)); */
    /*@ assert (\forall integer d; 2 <= d < size ==> (num % d != 0 ==> result <= size)); */
    /*@ assert (\forall integer d; 2 <= d < size && num % d == 0 ==> result >= 1); */
    /*@ assert (\forall integer d; 2 <= d < size && num % d == 0 ==> result > 0); */
    /*@ assert (\forall integer d; 2 <= d < size && num % d == 0 ==> result <= size); */
    /*@ assert (\forall integer d; 2 <= d < size && num % d != 0 ==> result >= 0); */
    /*@ assert (\forall integer d; 2 <= d < size && d <= num / d ==> (num % d == 0 ==> result >= 1)); */
    /*@ assert (\exists integer d; 2 <= d < size && num % d == 0 ==> result >= 1); */
    /*@ assert (2 <= size); */
    /*@ assert (2 <= size ==> result >= 0); */
    /*@ assert (1 <= size); */
    /*@ assert (1 <= size - result); */
    /*@ assert (1 < size); */
    /*@ assert (0 <= size - result); */
    /*@ assert (0 <= result); */
    /*@ assert (0 < size); */
}

/*@ requires (size >= 2 ==> result < size) && (size >= 2 ==> result >= 0) && (size >= 2 ==> result <= size) && (size >= 2 ==> result <= size - 1) && (size > 2 ==> result >= 0) && (size > 2 ==> result <= num) && (size <= num / size || size > num / size) && (result >= 0 ==> size >= 2) && (result == 0 || size >= 2) && (result == 0 || size > 2) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 || result <= size - 1) && (result == 0 || num >= 2) && (result <= size) && (result <= size - 2) && (result <= size - 1) && (num == num) && (\forall integer k; 2 <= k < size ==> (num % k == 0 || num % k != 0)) && (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 1)) && (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 0)) && (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= size)) && (\forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= num)) && (\forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 1)) && (\forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 0)) && (\forall integer k; 2 <= k < size ==> (num % k != 0 ==> result >= 0)) && (\forall integer k; 2 <= k < size && num % k == 0 ==> result >= 1) && (\forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 1) && (\forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 0) && (\forall integer d; 2 <= d < size ==> num % d == 0 ==> result <= size) && (\forall integer d; 2 <= d < size ==> num % d != 0 || result >= 1) && (\forall integer d; 2 <= d < size ==> num % d != 0 || result >= 0) && (\forall integer d; 2 <= d < size ==> num % d != 0 || result > 0) && (\forall integer d; 2 <= d < size ==> num % d != 0 ==> result >= 0) && (\forall integer d; 2 <= d < size ==> (num % d == 0 || num % d != 0)) && (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 1)) && (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 0)) && (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= size)) && (\forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= num)) && (\forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 1)) && (\forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 0)) && (\forall integer d; 2 <= d < size ==> (num % d != 0 ==> result >= 0)) && (\forall integer d; 2 <= d < size ==> (num % d != 0 ==> result <= size)) && (\forall integer d; 2 <= d < size && num % d == 0 ==> result >= 1) && (\forall integer d; 2 <= d < size && num % d == 0 ==> result > 0) && (\forall integer d; 2 <= d < size && num % d == 0 ==> result <= size) && (\forall integer d; 2 <= d < size && num % d != 0 ==> result >= 0) && (\forall integer d; 2 <= d < size && d <= num / d ==> (num % d == 0 ==> result >= 1)) && (\exists integer d; 2 <= d < size && num % d == 0 ==> result >= 1) && (2 <= size) && (2 <= size ==> result >= 0) && (1 <= size) && (1 <= size - result) && (1 < size) && (0 <= size - result) && (0 <= result) && (0 < size);
    assigns \nothing;
*/
void check_B_implies_A(int d, int k, int num, int size) {
    /*@ assert (2 <= size); */
    /*@ assert (result >= 0); */
    /*@ assert (result == count_divs(num, size - 1)); */
    /*@ assert (result <= size - 2); */
    /*@ assert (\forall integer d; 2 <= d < size && d <= num / d && num % d == 0 ==> result >= 1); */
    /*@ assert ((size > 2) ==> result <= size - 2); */
    /*@ assert ((size <= num / size) ==> (result == count_divs(num, size - 1))); */
    /*@ assert ((!(size <= num / size)) ==> (result == count_divs(num, size - 1))); */
}
