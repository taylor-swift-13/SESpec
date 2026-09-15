#include <limits.h>

/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */

/*@ requires (1 <= result) && (result <= num1) && (result <= num2) && (num1 % result == 0) && (num2 % result == 0) && (num1 >= 0 && num2 >= 0) && (1 <= i <= num1 + 1) && (result <= i);
    assigns \nothing;
*/
void check_A_implies_B(int d, int i, int k, int num1, int num2) {
    /*@ assert (result == 1 || result <= i + 1); */
    /*@ assert (result == 1 || result >= 1); */
    /*@ assert (result == 1 || result <= num2); */
    /*@ assert (result == 1 || result <= num1); */
    /*@ assert (result == 1 || result <= num1 && result <= num2); */
    /*@ assert (result == 1 || result <= i); */
    /*@ assert (result == 1 || result <= i && result >= 1); */
    /*@ assert (result == 1 || result < i); */
    /*@ assert (result == 1 || num2 % result == 0); */
    /*@ assert (result == 1 || num2 % result == 0 || result == 1); */
    /*@ assert (result == 1 || num1 % result == 0); */
    /*@ assert (result == 1 || num1 % result == 0 || result == 1); */
    /*@ assert (result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d)); */
    /*@ assert (result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result)); */
    /*@ assert (result == 1 || \forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result); */
    /*@ assert (result == 1 || \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d); */
    /*@ assert (result == 1 || \exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d); */
    /*@ assert (result == 1 || (result <= i && result >= 1)); */
    /*@ assert (result == 1 || (result <= i && num1 % result == 0 && num2 % result == 0)); */
    /*@ assert (result == 1 || (num1 % result == 0 && num2 % result == 0)); */
    /*@ assert (result == 1 || (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k))); */
    /*@ assert (result == 1 || (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result)); */
    /*@ assert (result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d))); */
    /*@ assert (result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result))); */
    /*@ assert (result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result))); */
    /*@ assert (result == 1 || (\forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result)); */
    /*@ assert (result == 1 || (\exists integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 && result == k)); */
    /*@ assert (result == 1 || (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d)); */
    /*@ assert (result == 1 || (\exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d)); */
    /*@ assert (result == 1 || (1 <= result <= i)); */
    /*@ assert (result == 1 || (1 <= result && result <= i)); */
    /*@ assert (result == 1 || (1 <= result && result <= i && num1 % result == 0 && num2 % result == 0)); */
    /*@ assert (result <= num2); */
    /*@ assert (result <= num1); */
    /*@ assert (result <= num1 + 1 && result <= num2 + 1); */
    /*@ assert (result <= num1 && result <= num2); */
    /*@ assert (result <= i); */
    /*@ assert (result <= i + 1); */
    /*@ assert (result <= i && result >= 1); */
    /*@ assert (num2 % result == 0 || result == 1); */
    /*@ assert (num1 >= 0 && num2 >= 0); */
    /*@ assert (num1 >= 0 && num2 >= 0 && result >= 1); */
    /*@ assert (num1 > 0 || num2 > 0); */
    /*@ assert (num1 % result == 0 || result == 1); */
    /*@ assert (num1 % result == 0 && num2 % result == 0); */
    /*@ assert (num1 % result == 0 && num2 % result == 0 || result == 1); */
    /*@ assert (i <= num2 + 1); */
    /*@ assert (i <= num1 + 1); */
    /*@ assert (i <= num1 + 1 && i <= num2 + 1); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (num1 % k != 0 || num2 % k != 0 || k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> result >= k)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (!(num1 % k == 0 && num2 % k == 0) || k <= result)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || result >= k); */
    /*@ assert (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result); */
    /*@ assert (\forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> result >= k); */
    /*@ assert (\forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> k <= result); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (num1 % result == 0 && num2 % result == 0)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> num1 % result == 0 && num2 % result == 0)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> d <= result)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> (!(num1 % d == 0 && num2 % d == 0) || d <= result)); */
    /*@ assert (\forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result); */
    /*@ assert (\forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> num1 % result == 0 && num2 % result == 0); */
    /*@ assert (\forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> d <= result); */
    /*@ assert (\exists integer k; 1 <= k <= result && num1 % k == 0 && num2 % k == 0); */
    /*@ assert (\exists integer k; 1 <= k <= i && result == k && num1 % k == 0 && num2 % k == 0); */
    /*@ assert (\exists integer d; 1 <= d <= result && num1 % d == 0 && num2 % d == 0); */
    /*@ assert (\exists integer d; 1 <= d <= i && result == d); */
    /*@ assert (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0); */
    /*@ assert (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result >= d); */
    /*@ assert (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d); */
    /*@ assert (1 <= result); */
    /*@ assert (1 <= result && result <= i + 1); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= i <= num1 + 1 && 1 <= i <= num2 + 1); */
    /*@ assert (0 <= num2); */
    /*@ assert (0 <= num1); */
    /*@ assert (0 <= num1 && 0 <= num2); */
    /*@ assert (0 < result); */
}

/*@ requires (result == 1 || result <= i + 1) && (result == 1 || result >= 1) && (result == 1 || result <= num2) && (result == 1 || result <= num1) && (result == 1 || result <= num1 && result <= num2) && (result == 1 || result <= i) && (result == 1 || result <= i && result >= 1) && (result == 1 || result < i) && (result == 1 || num2 % result == 0) && (result == 1 || num2 % result == 0 || result == 1) && (result == 1 || num1 % result == 0) && (result == 1 || num1 % result == 0 || result == 1) && (result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d)) && (result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result)) && (result == 1 || \forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result) && (result == 1 || \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d) && (result == 1 || \exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d) && (result == 1 || (result <= i && result >= 1)) && (result == 1 || (result <= i && num1 % result == 0 && num2 % result == 0)) && (result == 1 || (num1 % result == 0 && num2 % result == 0)) && (result == 1 || (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k))) && (result == 1 || (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result)) && (result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d))) && (result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result))) && (result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result))) && (result == 1 || (\forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result)) && (result == 1 || (\exists integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 && result == k)) && (result == 1 || (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d)) && (result == 1 || (\exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d)) && (result == 1 || (1 <= result <= i)) && (result == 1 || (1 <= result && result <= i)) && (result == 1 || (1 <= result && result <= i && num1 % result == 0 && num2 % result == 0)) && (result <= num2) && (result <= num1) && (result <= num1 + 1 && result <= num2 + 1) && (result <= num1 && result <= num2) && (result <= i) && (result <= i + 1) && (result <= i && result >= 1) && (num2 % result == 0 || result == 1) && (num1 >= 0 && num2 >= 0) && (num1 >= 0 && num2 >= 0 && result >= 1) && (num1 > 0 || num2 > 0) && (num1 % result == 0 || result == 1) && (num1 % result == 0 && num2 % result == 0) && (num1 % result == 0 && num2 % result == 0 || result == 1) && (i <= num2 + 1) && (i <= num1 + 1) && (i <= num1 + 1 && i <= num2 + 1) && (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k)) && (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> k <= result)) && (\forall integer k; 1 <= k < i ==> (num1 % k != 0 || num2 % k != 0 || k <= result)) && (\forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> result >= k)) && (\forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> k <= result)) && (\forall integer k; 1 <= k < i ==> (!(num1 % k == 0 && num2 % k == 0) || k <= result)) && (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || result >= k) && (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result) && (\forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> result >= k) && (\forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> k <= result) && (\forall integer d; 1 <= d < i ==> (num1 % result == 0 && num2 % result == 0)) && (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d)) && (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result)) && (\forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result)) && (\forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> num1 % result == 0 && num2 % result == 0)) && (\forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> d <= result)) && (\forall integer d; 1 <= d < i ==> (!(num1 % d == 0 && num2 % d == 0) || d <= result)) && (\forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result) && (\forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> num1 % result == 0 && num2 % result == 0) && (\forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> d <= result) && (\exists integer k; 1 <= k <= result && num1 % k == 0 && num2 % k == 0) && (\exists integer k; 1 <= k <= i && result == k && num1 % k == 0 && num2 % k == 0) && (\exists integer d; 1 <= d <= result && num1 % d == 0 && num2 % d == 0) && (\exists integer d; 1 <= d <= i && result == d) && (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0) && (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result >= d) && (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d) && (1 <= result) && (1 <= result && result <= i + 1) && (1 <= i) && (1 <= i <= num1 + 1 && 1 <= i <= num2 + 1) && (0 <= num2) && (0 <= num1) && (0 <= num1 && 0 <= num2) && (0 < result);
    assigns \nothing;
*/
void check_B_implies_A(int d, int i, int k, int num1, int num2) {
    /*@ assert (1 <= result); */
    /*@ assert (result <= num1); */
    /*@ assert (result <= num2); */
    /*@ assert (num1 % result == 0); */
    /*@ assert (num2 % result == 0); */
    /*@ assert (num1 >= 0 && num2 >= 0); */
    /*@ assert (1 <= i <= num1 + 1); */
    /*@ assert (result <= i); */
}
