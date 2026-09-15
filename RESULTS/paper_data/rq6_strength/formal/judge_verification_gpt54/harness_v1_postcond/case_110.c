#include <limits.h>


/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */

/*@ensures (\old(num1) == 0 && \old(num2) == 0) ==> \result == -1;
  ensures (\old(num1) != 0 || \old(num2) != 0) && (abs_int(\old(num1)) == 0 || abs_int(\old(num2)) == 0) ==> 
            \result == (abs_int(\old(num1)) > abs_int(\old(num2)) ? abs_int(\old(num1)) : abs_int(\old(num2)));
  ensures (\old(num1) != 0 || \old(num2) != 0) && abs_int(\old(num1)) != 0 && abs_int(\old(num2)) != 0 ==> 
            (1 <= \result && \result <= abs_int(\old(num1)) && 1 <= \result && \result <= abs_int(\old(num2)));
  assigns \nothing;*/
int stub_A(int num1, int num2);

/*@loop invariant result == 1 || result <= i + 1;
		loop invariant result == 1 || result >= 1;
		loop invariant result == 1 || result <= num2;
		loop invariant result == 1 || result <= num1;
		loop invariant result == 1 || result <= num1 && result <= num2;
		loop invariant result == 1 || result <= i;
		loop invariant result == 1 || result <= i && result >= 1;
		loop invariant result == 1 || result < i;
		loop invariant result == 1 || num2 % result == 0;
		loop invariant result == 1 || num2 % result == 0 || result == 1;
		loop invariant result == 1 || num1 % result == 0;
		loop invariant result == 1 || num1 % result == 0 || result == 1;
		loop invariant result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d);
		loop invariant result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result);
		loop invariant result == 1 || \forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result;
		loop invariant result == 1 || \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d;
		loop invariant result == 1 || \exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d;
		loop invariant result == 1 || (result <= i && result >= 1);
		loop invariant result == 1 || (result <= i && num1 % result == 0 && num2 % result == 0);
		loop invariant result == 1 || (num1 % result == 0 && num2 % result == 0);
		loop invariant result == 1 || (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k));
		loop invariant result == 1 || (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result);
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d));
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result));
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result));
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result);
		loop invariant result == 1 || (\exists integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 && result == k);
		loop invariant result == 1 || (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d);
		loop invariant result == 1 || (\exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d);
		loop invariant result == 1 || (1 <= result <= i);
		loop invariant result == 1 || (1 <= result && result <= i);
		loop invariant result == 1 || (1 <= result && result <= i && num1 % result == 0 && num2 % result == 0);
		loop invariant result <= num2;
		loop invariant result <= num1;
		loop invariant result <= num1 + 1 && result <= num2 + 1;
		loop invariant result <= num1 && result <= num2;
		loop invariant result <= i;
		loop invariant result <= i + 1;
		loop invariant result <= i && result >= 1;
		loop invariant num2 % result == 0 || result == 1;
		loop invariant num1 >= 0 && num2 >= 0;
		loop invariant num1 >= 0 && num2 >= 0 && result >= 1;
		loop invariant num1 > 0 || num2 > 0;
		loop invariant num1 % result == 0 || result == 1;
		loop invariant num1 % result == 0 && num2 % result == 0;
		loop invariant num1 % result == 0 && num2 % result == 0 || result == 1;
		loop invariant i <= num2 + 1;
		loop invariant i <= num1 + 1;
		loop invariant i <= num1 + 1 && i <= num2 + 1;
		loop invariant \forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k);
		loop invariant \forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> (num1 % k != 0 || num2 % k != 0 || k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> result >= k);
		loop invariant \forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> (!(num1 % k == 0 && num2 % k == 0) || k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || result >= k;
		loop invariant \forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result;
		loop invariant \forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> result >= k;
		loop invariant \forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> k <= result;
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % result == 0 && num2 % result == 0);
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d);
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> num1 % result == 0 && num2 % result == 0);
		loop invariant \forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> (!(num1 % d == 0 && num2 % d == 0) || d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result;
		loop invariant \forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> num1 % result == 0 && num2 % result == 0;
		loop invariant \forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> d <= result;
		loop invariant \exists integer k; 1 <= k <= result && num1 % k == 0 && num2 % k == 0;
		loop invariant \exists integer k; 1 <= k <= i && result == k && num1 % k == 0 && num2 % k == 0;
		loop invariant \exists integer d; 1 <= d <= result && num1 % d == 0 && num2 % d == 0;
		loop invariant \exists integer d; 1 <= d <= i && result == d;
		loop invariant \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0;
		loop invariant \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result >= d;
		loop invariant \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d;
		loop invariant 1 <= result;
		loop invariant 1 <= result && result <= i + 1;
		loop invariant 1 <= i;
		loop invariant 1 <= i <= num1 + 1 && 1 <= i <= num2 + 1;
		loop invariant 0 <= num2;
		loop invariant 0 <= num1;
		loop invariant 0 <= num1 && 0 <= num2;
		loop invariant 0 < result;
		loop assigns result;
		loop assigns i;*/
int stub_B(int num1, int num2);

/*@loop invariant result == 1 || result <= i + 1;
		loop invariant result == 1 || result >= 1;
		loop invariant result == 1 || result <= num2;
		loop invariant result == 1 || result <= num1;
		loop invariant result == 1 || result <= num1 && result <= num2;
		loop invariant result == 1 || result <= i;
		loop invariant result == 1 || result <= i && result >= 1;
		loop invariant result == 1 || result < i;
		loop invariant result == 1 || num2 % result == 0;
		loop invariant result == 1 || num2 % result == 0 || result == 1;
		loop invariant result == 1 || num1 % result == 0;
		loop invariant result == 1 || num1 % result == 0 || result == 1;
		loop invariant result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d);
		loop invariant result == 1 || \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result);
		loop invariant result == 1 || \forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result;
		loop invariant result == 1 || \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d;
		loop invariant result == 1 || \exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d;
		loop invariant result == 1 || (result <= i && result >= 1);
		loop invariant result == 1 || (result <= i && num1 % result == 0 && num2 % result == 0);
		loop invariant result == 1 || (num1 % result == 0 && num2 % result == 0);
		loop invariant result == 1 || (\forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k));
		loop invariant result == 1 || (\forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result);
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d));
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result));
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result));
		loop invariant result == 1 || (\forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result);
		loop invariant result == 1 || (\exists integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 && result == k);
		loop invariant result == 1 || (\exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d);
		loop invariant result == 1 || (\exists integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 && result == d);
		loop invariant result == 1 || (1 <= result <= i);
		loop invariant result == 1 || (1 <= result && result <= i);
		loop invariant result == 1 || (1 <= result && result <= i && num1 % result == 0 && num2 % result == 0);
		loop invariant result <= num2;
		loop invariant result <= num1;
		loop invariant result <= num1 + 1 && result <= num2 + 1;
		loop invariant result <= num1 && result <= num2;
		loop invariant result <= i;
		loop invariant result <= i + 1;
		loop invariant result <= i && result >= 1;
		loop invariant num2 % result == 0 || result == 1;
		loop invariant num1 >= 0 && num2 >= 0;
		loop invariant num1 >= 0 && num2 >= 0 && result >= 1;
		loop invariant num1 > 0 || num2 > 0;
		loop invariant num1 % result == 0 || result == 1;
		loop invariant num1 % result == 0 && num2 % result == 0;
		loop invariant num1 % result == 0 && num2 % result == 0 || result == 1;
		loop invariant i <= num2 + 1;
		loop invariant i <= num1 + 1;
		loop invariant i <= num1 + 1 && i <= num2 + 1;
		loop invariant \forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> result >= k);
		loop invariant \forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> (num1 % k != 0 || num2 % k != 0 || k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> result >= k);
		loop invariant \forall integer k; 1 <= k < i ==> ((num1 % k == 0 && num2 % k == 0) ==> k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> (!(num1 % k == 0 && num2 % k == 0) || k <= result);
		loop invariant \forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || result >= k;
		loop invariant \forall integer k; 1 <= k < i ==> !(num1 % k == 0 && num2 % k == 0) || k <= result;
		loop invariant \forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> result >= k;
		loop invariant \forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> k <= result;
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % result == 0 && num2 % result == 0);
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> result >= d);
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % d == 0 && num2 % d == 0 ==> d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> (num1 % d != 0 || num2 % d != 0 || d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> num1 % result == 0 && num2 % result == 0);
		loop invariant \forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> (!(num1 % d == 0 && num2 % d == 0) || d <= result);
		loop invariant \forall integer d; 1 <= d < i ==> !(num1 % d == 0 && num2 % d == 0) || d <= result;
		loop invariant \forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> num1 % result == 0 && num2 % result == 0;
		loop invariant \forall integer d; 1 <= d < i && num1 % d == 0 && num2 % d == 0 ==> d <= result;
		loop invariant \exists integer k; 1 <= k <= result && num1 % k == 0 && num2 % k == 0;
		loop invariant \exists integer k; 1 <= k <= i && result == k && num1 % k == 0 && num2 % k == 0;
		loop invariant \exists integer d; 1 <= d <= result && num1 % d == 0 && num2 % d == 0;
		loop invariant \exists integer d; 1 <= d <= i && result == d;
		loop invariant \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0;
		loop invariant \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result >= d;
		loop invariant \exists integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 && result == d;
		loop invariant 1 <= result;
		loop invariant 1 <= result && result <= i + 1;
		loop invariant 1 <= i;
		loop invariant 1 <= i <= num1 + 1 && 1 <= i <= num2 + 1;
		loop invariant 0 <= num2;
		loop invariant 0 <= num1;
		loop invariant 0 <= num1 && 0 <= num2;
		loop invariant 0 < result;
		loop assigns result;
		loop assigns i;*/
int check_A_implies_B(int num1, int num2) {
    return stub_A(num1, num2);
}

/*@ensures (\old(num1) == 0 && \old(num2) == 0) ==> \result == -1;
  ensures (\old(num1) != 0 || \old(num2) != 0) && (abs_int(\old(num1)) == 0 || abs_int(\old(num2)) == 0) ==> 
            \result == (abs_int(\old(num1)) > abs_int(\old(num2)) ? abs_int(\old(num1)) : abs_int(\old(num2)));
  ensures (\old(num1) != 0 || \old(num2) != 0) && abs_int(\old(num1)) != 0 && abs_int(\old(num2)) != 0 ==> 
            (1 <= \result && \result <= abs_int(\old(num1)) && 1 <= \result && \result <= abs_int(\old(num2)));
  assigns \nothing;*/
int check_B_implies_A(int num1, int num2) {
    return stub_B(num1, num2);
}
