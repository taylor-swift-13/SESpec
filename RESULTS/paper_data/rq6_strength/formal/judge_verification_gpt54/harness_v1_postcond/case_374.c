#include <limits.h>


/*@
  logic integer count_div(integer n, integer k) =
    k <= 0 ? 0 : count_div(n, k - 1) + ((n % k) == 0 ? 1 : 0);
*/

/*@requires number >= 0;
   assigns \nothing;
   ensures \result == count_div(number, number);
   ensures number == 0 ==> \result == 0;
   ensures number > 0 ==> \result >= 0;*/
int stub_A(int number);

/*@loop invariant div > 0 ==> c > 1;
		loop invariant div == 0 || div >= 1;
		loop invariant div == 0 || div >= 0;
		loop invariant div == 0 || div > 0;
		loop invariant div == 0 ==> c == 1;
		loop invariant div <= c;
		loop invariant div <= c - 1;
		loop invariant div <= c - 1 || div == c;
		loop invariant div <= c - 1 || c == 1;
		loop invariant div <= c + 1;
		loop invariant c == div + 1 || c > div;
		loop invariant c == 1 + div || c > div;
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 || number % k != 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> div <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c - 1);
		loop invariant \forall integer k; 1 <= k < c ==> ((number % k == 0) ==> div >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> ((number % k != 0) ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < c && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k <= c ==> (number % k == 0);
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0;
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 0;
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0 ==> div > 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> div >= 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> div > 0;
		loop invariant 1 <= c;
		loop invariant 1 <= c - div;
		loop invariant 0 <= div;
		loop invariant 0 <= c;
		loop invariant 0 <= c - div;
		loop assigns div;
		loop assigns c;*/
int stub_B(int number);

/*@loop invariant div > 0 ==> c > 1;
		loop invariant div == 0 || div >= 1;
		loop invariant div == 0 || div >= 0;
		loop invariant div == 0 || div > 0;
		loop invariant div == 0 ==> c == 1;
		loop invariant div <= c;
		loop invariant div <= c - 1;
		loop invariant div <= c - 1 || div == c;
		loop invariant div <= c - 1 || c == 1;
		loop invariant div <= c + 1;
		loop invariant c == div + 1 || c > div;
		loop invariant c == 1 + div || c > div;
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 || number % k != 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> div <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> div <= c - 1);
		loop invariant \forall integer k; 1 <= k < c ==> ((number % k == 0) ==> div >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> ((number % k != 0) ==> div >= 0);
		loop invariant \forall integer k; 1 <= k < c && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k <= c ==> (number % k == 0);
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0;
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0 ==> div >= 0;
		loop invariant \exists integer k; 1 <= k <= c && number % k == 0 ==> div > 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> div >= 1;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> div >= 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> div > 0;
		loop invariant 1 <= c;
		loop invariant 1 <= c - div;
		loop invariant 0 <= div;
		loop invariant 0 <= c;
		loop invariant 0 <= c - div;
		loop assigns div;
		loop assigns c;*/
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@requires number >= 0;
   assigns \nothing;
   ensures \result == count_div(number, number);
   ensures number == 0 ==> \result == 0;
   ensures number > 0 ==> \result >= 0;*/
int check_B_implies_A(int number) {
    return stub_B(number);
}
