#include <limits.h>


/*@ logic integer count_divs(integer num, integer size) =
      size < 2 ? 0 :
      count_divs(num, size - 1) + (num % size == 0 ? 1 : 0);
*/

/*@requires num >= 1;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures \result >= 0;*/
int stub_A(int num);

/*@loop invariant size >= 2 ==> result < size;
		loop invariant size >= 2 ==> result >= 0;
		loop invariant size >= 2 ==> result <= size;
		loop invariant size >= 2 ==> result <= size - 1;
		loop invariant size > 2 ==> result >= 0;
		loop invariant size > 2 ==> result <= num;
		loop invariant size <= num / size || size > num / size;
		loop invariant result >= 0 ==> size >= 2;
		loop invariant result == 0 || size >= 2;
		loop invariant result == 0 || size > 2;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result <= size - 1;
		loop invariant result == 0 || num >= 2;
		loop invariant result <= size;
		loop invariant result <= size - 2;
		loop invariant result <= size - 1;
		loop invariant num == num;
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= size);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= num);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < size && num % k == 0 ==> result >= 1;
		loop invariant \forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 1;
		loop invariant \forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 0;
		loop invariant \forall integer d; 2 <= d < size ==> num % d == 0 ==> result <= size;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 || result >= 1;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 || result >= 0;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 || result > 0;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 ==> result >= 0;
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 || num % d != 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 1);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= size);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= num);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 1);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 ==> result >= 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 ==> result <= size);
		loop invariant \forall integer d; 2 <= d < size && num % d == 0 ==> result >= 1;
		loop invariant \forall integer d; 2 <= d < size && num % d == 0 ==> result > 0;
		loop invariant \forall integer d; 2 <= d < size && num % d == 0 ==> result <= size;
		loop invariant \forall integer d; 2 <= d < size && num % d != 0 ==> result >= 0;
		loop invariant \forall integer d; 2 <= d < size && d <= num / d ==> (num % d == 0 ==> result >= 1);
		loop invariant \exists integer d; 2 <= d < size && num % d == 0 ==> result >= 1;
		loop invariant 2 <= size;
		loop invariant 2 <= size ==> result >= 0;
		loop invariant 1 <= size;
		loop invariant 1 <= size - result;
		loop invariant 1 < size;
		loop invariant 0 <= size - result;
		loop invariant 0 <= result;
		loop invariant 0 < size;
		loop assigns size;
		loop assigns result;*/
int stub_B(int num);

/*@loop invariant size >= 2 ==> result < size;
		loop invariant size >= 2 ==> result >= 0;
		loop invariant size >= 2 ==> result <= size;
		loop invariant size >= 2 ==> result <= size - 1;
		loop invariant size > 2 ==> result >= 0;
		loop invariant size > 2 ==> result <= num;
		loop invariant size <= num / size || size > num / size;
		loop invariant result >= 0 ==> size >= 2;
		loop invariant result == 0 || size >= 2;
		loop invariant result == 0 || size > 2;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result <= size - 1;
		loop invariant result == 0 || num >= 2;
		loop invariant result <= size;
		loop invariant result <= size - 2;
		loop invariant result <= size - 1;
		loop invariant num == num;
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= size);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> result <= num);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 2 <= k < size ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < size && num % k == 0 ==> result >= 1;
		loop invariant \forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 1;
		loop invariant \forall integer d; 2 <= d < size ==> num % d == 0 ==> result >= 0;
		loop invariant \forall integer d; 2 <= d < size ==> num % d == 0 ==> result <= size;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 || result >= 1;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 || result >= 0;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 || result > 0;
		loop invariant \forall integer d; 2 <= d < size ==> num % d != 0 ==> result >= 0;
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 || num % d != 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 1);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result >= 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= size);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d == 0 ==> result <= num);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 1);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 || result >= 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 ==> result >= 0);
		loop invariant \forall integer d; 2 <= d < size ==> (num % d != 0 ==> result <= size);
		loop invariant \forall integer d; 2 <= d < size && num % d == 0 ==> result >= 1;
		loop invariant \forall integer d; 2 <= d < size && num % d == 0 ==> result > 0;
		loop invariant \forall integer d; 2 <= d < size && num % d == 0 ==> result <= size;
		loop invariant \forall integer d; 2 <= d < size && num % d != 0 ==> result >= 0;
		loop invariant \forall integer d; 2 <= d < size && d <= num / d ==> (num % d == 0 ==> result >= 1);
		loop invariant \exists integer d; 2 <= d < size && num % d == 0 ==> result >= 1;
		loop invariant 2 <= size;
		loop invariant 2 <= size ==> result >= 0;
		loop invariant 1 <= size;
		loop invariant 1 <= size - result;
		loop invariant 1 < size;
		loop invariant 0 <= size - result;
		loop invariant 0 <= result;
		loop invariant 0 < size;
		loop assigns size;
		loop assigns result;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num >= 1;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures \result >= 0;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
