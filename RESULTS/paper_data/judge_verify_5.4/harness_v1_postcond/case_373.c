#include <limits.h>


/*@
  logic integer count_divisors(integer n, integer i) =
    i <= 0 ? 0 : count_divisors(n, i - 1) + ((n % i == 0) ? 1 : 0);
*/

/*@loop invariant 1 <= index;
          loop invariant index >= 1;
          loop invariant 0 <= div;
          loop invariant div <= index - 1;
          loop invariant div == count_divisors(number, index - 1);
          loop invariant number == \at(number,Pre);
          loop assigns index, div;*/
int stub_A(int number);

/*@loop invariant number >= 0 ==> index >= 1;
		loop invariant number >= 0 ==> index <= number + 1;
		loop invariant number >= 0 ==> div <= number;
		loop invariant number >= 0 ==> div <= index;
		loop invariant number >= 0 ==> div <= index - 1;
		loop invariant number >= 0 ==> div <= index - 1 + 1;
		loop invariant number >= 0 ==> div <= index + 1;
		loop invariant number >= 0 ==> 0 <= div <= index;
		loop invariant number < 0 || div >= 0;
		loop invariant number < 0 || div <= number;
		loop invariant index > 1 ==> div >= 1;
		loop invariant index > 1 ==> div >= 0;
		loop invariant index == 1 ==> div == 0;
		loop invariant div >= 0 && index >= 1;
		loop invariant div > 0 ==> index >= 1;
		loop invariant div > 0 ==> index > 1;
		loop invariant div == 0 || div >= 1;
		loop invariant div == 0 || div > 0;
		loop invariant div == 0 ==> index == 1;
		loop invariant div == 0 ==> index <= 1;
		loop invariant div <= number || 0 <= index;
		loop invariant div <= index;
		loop invariant div <= index - 1;
		loop invariant div <= index - 1 + 1;
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 || number % k != 0);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 ==> div <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k != 0 || div >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k != 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < index && number % k == 0 ==> div >= 1;
		loop invariant \forall integer k; 1 <= k < index && number % k == 0 ==> div >= 0;
		loop invariant \forall integer k; 1 <= k < index && number % k != 0 ==> div >= 0;
		loop invariant \exists integer k; 1 <= k <= index && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k < index && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k < index && number % k == 0 ==> div >= 0;
		loop invariant 1 <= index;
		loop invariant 1 <= index || div == 0;
		loop invariant 1 <= index - div;
		loop invariant 0 <= index;
		loop invariant 0 <= index || index <= number + 1;
		loop invariant 0 <= index - div;
		loop invariant 0 <= div;
		loop invariant 0 < index;
		loop assigns index;
		loop assigns div;*/
int stub_B(int number);

/*@loop invariant number >= 0 ==> index >= 1;
		loop invariant number >= 0 ==> index <= number + 1;
		loop invariant number >= 0 ==> div <= number;
		loop invariant number >= 0 ==> div <= index;
		loop invariant number >= 0 ==> div <= index - 1;
		loop invariant number >= 0 ==> div <= index - 1 + 1;
		loop invariant number >= 0 ==> div <= index + 1;
		loop invariant number >= 0 ==> 0 <= div <= index;
		loop invariant number < 0 || div >= 0;
		loop invariant number < 0 || div <= number;
		loop invariant index > 1 ==> div >= 1;
		loop invariant index > 1 ==> div >= 0;
		loop invariant index == 1 ==> div == 0;
		loop invariant div >= 0 && index >= 1;
		loop invariant div > 0 ==> index >= 1;
		loop invariant div > 0 ==> index > 1;
		loop invariant div == 0 || div >= 1;
		loop invariant div == 0 || div > 0;
		loop invariant div == 0 ==> index == 1;
		loop invariant div == 0 ==> index <= 1;
		loop invariant div <= number || 0 <= index;
		loop invariant div <= index;
		loop invariant div <= index - 1;
		loop invariant div <= index - 1 + 1;
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 || number % k != 0);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k == 0 ==> div <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k != 0 || div >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (number % k != 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < index && number % k == 0 ==> div >= 1;
		loop invariant \forall integer k; 1 <= k < index && number % k == 0 ==> div >= 0;
		loop invariant \forall integer k; 1 <= k < index && number % k != 0 ==> div >= 0;
		loop invariant \exists integer k; 1 <= k <= index && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k < index && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k < index && number % k == 0 ==> div >= 0;
		loop invariant 1 <= index;
		loop invariant 1 <= index || div == 0;
		loop invariant 1 <= index - div;
		loop invariant 0 <= index;
		loop invariant 0 <= index || index <= number + 1;
		loop invariant 0 <= index - div;
		loop invariant 0 <= div;
		loop invariant 0 < index;
		loop assigns index;
		loop assigns div;*/
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@loop invariant 1 <= index;
          loop invariant index >= 1;
          loop invariant 0 <= div;
          loop invariant div <= index - 1;
          loop invariant div == count_divisors(number, index - 1);
          loop invariant number == \at(number,Pre);
          loop assigns index, div;*/
int check_B_implies_A(int number) {
    return stub_B(number);
}
