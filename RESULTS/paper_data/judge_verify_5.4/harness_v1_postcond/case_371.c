#include <limits.h>



/*@requires p != 0;
  assigns \nothing;
  ensures value < 1 || \result == 0 || (1 <= \result && \result <= value);
  ensures \result == 0 ==> \forall integer i; 1 <= i <= value ==> (i % p) != z;
  ensures \result != 0 ==> (\result % p) == z;
  ensures \result != 0 ==> \forall integer i; \result < i <= value ==> (i % p) != z;
  ensures \result != 0 ==> \forall integer i; 1 <= i <= value && (i % p) == z ==> i <= \result;*/
int stub_A(int value, int p, int z);

/*@loop invariant result == 0 || 0 <= result;
		loop invariant result == 0 || (\exists integer k; 1 <= k <= c && k % p == z && result == k);
		loop invariant result == 0 || (1 <= result <= value);
		loop invariant \forall integer k; 1 <= k < c && k % p == z ==> k <= result;
		loop invariant result == 0 || result == value || (result % p) == z;
		loop invariant result == 0 || result == value || ((result % p) == z);
		loop invariant result == 0 || result == c - 1 || result % p == z;
		loop invariant result == 0 || result <= value;
		loop invariant result == 0 || result <= c;
		loop invariant result == 0 || result <= c - 1;
		loop invariant result == 0 || result < c;
		loop invariant result == 0 || result % p == z;
		loop invariant result == 0 || \exists integer k; 1 <= k < c && (k % p) == z && result == k;
		loop invariant result == 0 || 1 <= result <= value;
		loop invariant result == 0 || (result <= c - 1);
		loop invariant result == 0 || (result % p) == z;
		loop invariant result == 0 || (\exists integer k; 1 <= k <= c && (k % p) == z && result == k);
		loop invariant result == 0 || (\exists integer k; 1 <= k < c && (k % p) == z && result == k);
		loop invariant result == 0 || (1 <= result <= c - 1);
		loop invariant result == 0 || ((result % p) == z);
		loop invariant result <= c;
		loop invariant result <= c || result <= value;
		loop invariant result <= c - 1;
		loop invariant result < c;
		loop invariant result % p == z || result == 0;
		loop invariant c == 1 || result == 0 || result % p == z;
		loop invariant c <= value + 1 || result <= c;
		loop invariant \forall integer k; 1 <= k < c ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (k % p) == z ==> k <= result;
		loop invariant \forall integer k; 1 <= k < c ==> (k % p) != z || k <= result;
		loop invariant \forall integer k; 1 <= k < c ==> (k % p == z ==> k <= result);
		loop invariant \forall integer k; 1 <= k < c ==> (k % p != z || k <= result);
		loop invariant \forall integer k; 1 <= k < c ==> ((k % p) == z ==> k <= result);
		loop invariant \forall integer k; 1 <= k < c ==> ((k % p) != z || k <= result);
		loop invariant \forall integer k; 1 <= k < c && (k % p) == z ==> k <= result;
		loop invariant \forall integer k; 1 <= k < c && (k % p == z) ==> k <= result;
		loop invariant \forall integer k; 1 <= k < c && ((k % p) == z) ==> k <= result;
		loop invariant \exists integer k; 1 <= k < c && (k % p) == z ==> result == k;
		loop invariant 1 <= c;
		loop invariant 0 <= result;
		loop invariant 0 <= c;
		loop invariant 0 <= c || result <= value;
		loop invariant 0 <= c || c <= value + 1;
		loop invariant 0 <= c || c - 1 <= value;
		loop invariant 0 < c;
		loop assigns result;
		loop assigns c;*/
int stub_B(int value, int p, int z);

/*@loop invariant result == 0 || 0 <= result;
		loop invariant result == 0 || (\exists integer k; 1 <= k <= c && k % p == z && result == k);
		loop invariant result == 0 || (1 <= result <= value);
		loop invariant \forall integer k; 1 <= k < c && k % p == z ==> k <= result;
		loop invariant result == 0 || result == value || (result % p) == z;
		loop invariant result == 0 || result == value || ((result % p) == z);
		loop invariant result == 0 || result == c - 1 || result % p == z;
		loop invariant result == 0 || result <= value;
		loop invariant result == 0 || result <= c;
		loop invariant result == 0 || result <= c - 1;
		loop invariant result == 0 || result < c;
		loop invariant result == 0 || result % p == z;
		loop invariant result == 0 || \exists integer k; 1 <= k < c && (k % p) == z && result == k;
		loop invariant result == 0 || 1 <= result <= value;
		loop invariant result == 0 || (result <= c - 1);
		loop invariant result == 0 || (result % p) == z;
		loop invariant result == 0 || (\exists integer k; 1 <= k <= c && (k % p) == z && result == k);
		loop invariant result == 0 || (\exists integer k; 1 <= k < c && (k % p) == z && result == k);
		loop invariant result == 0 || (1 <= result <= c - 1);
		loop invariant result == 0 || ((result % p) == z);
		loop invariant result <= c;
		loop invariant result <= c || result <= value;
		loop invariant result <= c - 1;
		loop invariant result < c;
		loop invariant result % p == z || result == 0;
		loop invariant c == 1 || result == 0 || result % p == z;
		loop invariant c <= value + 1 || result <= c;
		loop invariant \forall integer k; 1 <= k < c ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (k % p) == z ==> k <= result;
		loop invariant \forall integer k; 1 <= k < c ==> (k % p) != z || k <= result;
		loop invariant \forall integer k; 1 <= k < c ==> (k % p == z ==> k <= result);
		loop invariant \forall integer k; 1 <= k < c ==> (k % p != z || k <= result);
		loop invariant \forall integer k; 1 <= k < c ==> ((k % p) == z ==> k <= result);
		loop invariant \forall integer k; 1 <= k < c ==> ((k % p) != z || k <= result);
		loop invariant \forall integer k; 1 <= k < c && (k % p) == z ==> k <= result;
		loop invariant \forall integer k; 1 <= k < c && (k % p == z) ==> k <= result;
		loop invariant \forall integer k; 1 <= k < c && ((k % p) == z) ==> k <= result;
		loop invariant \exists integer k; 1 <= k < c && (k % p) == z ==> result == k;
		loop invariant 1 <= c;
		loop invariant 0 <= result;
		loop invariant 0 <= c;
		loop invariant 0 <= c || result <= value;
		loop invariant 0 <= c || c <= value + 1;
		loop invariant 0 <= c || c - 1 <= value;
		loop invariant 0 < c;
		loop assigns result;
		loop assigns c;*/
int check_A_implies_B(int value, int p, int z) {
    return stub_A(value, p, z);
}

/*@requires p != 0;
  assigns \nothing;
  ensures value < 1 || \result == 0 || (1 <= \result && \result <= value);
  ensures \result == 0 ==> \forall integer i; 1 <= i <= value ==> (i % p) != z;
  ensures \result != 0 ==> (\result % p) == z;
  ensures \result != 0 ==> \forall integer i; \result < i <= value ==> (i % p) != z;
  ensures \result != 0 ==> \forall integer i; 1 <= i <= value && (i % p) == z ==> i <= \result;*/
int check_B_implies_A(int value, int p, int z) {
    return stub_B(value, p, z);
}
