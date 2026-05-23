#include <limits.h>



/*@requires size >= 1;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
  ensures \result >= 1;
  ensures \result <= size;*/
int stub_A(int size);

/*@loop invariant total > 0 ==> average >= total;
		loop invariant total == c / 2 || total == (c + 1) / 2;
		loop invariant total == 0 || total > 0;
		loop invariant total == 0 || total <= c;
		loop invariant total == 0 || total <= average;
		loop invariant total == 0 || total <= (c + 1) / 2;
		loop invariant total == 0 || c >= 1;
		loop invariant total == 0 || average >= total;
		loop invariant total == 0 || average >= 1;
		loop invariant total == 0 || average >= 0;
		loop invariant total == 0 || average > 0;
		loop invariant total == 0 || average / total >= 1;
		loop invariant total == (c / 2) || total == ((c + 1) / 2);
		loop invariant total == (c - 1) / 2 || total == c / 2;
		loop invariant total == (c - 1) / 2 || total == (c + 1) / 2;
		loop invariant total == (c - 1) / 2 + ((c - 1) % 2);
		loop invariant total == (c - 1) / 2 + ((c - 1) % 2 != 0 ? 1 : 0);
		loop invariant total == (c + 1) / 2 || total == c / 2;
		loop invariant total <= c;
		loop invariant total <= c / 2 + 1;
		loop invariant total <= c + 1;
		loop invariant total <= average;
		loop invariant total <= (c + 1) / 2;
		loop invariant total * total <= average;
		loop invariant total * 2 <= c;
		loop invariant total * 2 <= c + 1;
		loop invariant c == 1 || c > 1;
		loop invariant c == 0 || c >= 1;
		loop invariant c - total <= c;
		loop invariant c - 1 <= total * 2;
		loop invariant c - 1 <= average || c <= size + 1;
		loop invariant c % 2 == 0 || c % 2 == 1;
		loop invariant average >= 0 && total >= 0;
		loop invariant average >= 0 && average >= total;
		loop invariant average == total * total;
		loop invariant average == total * total || average >= total;
		loop invariant average == 0 || total > 0;
		loop invariant average == 0 || average >= total;
		loop invariant average == 0 || average >= 0;
		loop invariant average == 0 || average > 0;
		loop invariant average % 2 == 0 || average % 2 == 1;
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 || total >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 || total > 0);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 || average >= k);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> total >= 1);
		loop invariant \forall integer k; 1 <= k < c && k % 2 != 0 ==> average >= k;
		loop invariant 2 * total <= c + 1;
		loop invariant 1 <= c;
		loop invariant 0 <= total;
		loop invariant 0 <= c;
		loop invariant 0 <= c - total;
		loop invariant 0 <= average;
		loop invariant 0 <= average && 0 <= total;
		loop assigns total;
		loop assigns c;
		loop assigns average;*/
int stub_B(int size);

/*@loop invariant total > 0 ==> average >= total;
		loop invariant total == c / 2 || total == (c + 1) / 2;
		loop invariant total == 0 || total > 0;
		loop invariant total == 0 || total <= c;
		loop invariant total == 0 || total <= average;
		loop invariant total == 0 || total <= (c + 1) / 2;
		loop invariant total == 0 || c >= 1;
		loop invariant total == 0 || average >= total;
		loop invariant total == 0 || average >= 1;
		loop invariant total == 0 || average >= 0;
		loop invariant total == 0 || average > 0;
		loop invariant total == 0 || average / total >= 1;
		loop invariant total == (c / 2) || total == ((c + 1) / 2);
		loop invariant total == (c - 1) / 2 || total == c / 2;
		loop invariant total == (c - 1) / 2 || total == (c + 1) / 2;
		loop invariant total == (c - 1) / 2 + ((c - 1) % 2);
		loop invariant total == (c - 1) / 2 + ((c - 1) % 2 != 0 ? 1 : 0);
		loop invariant total == (c + 1) / 2 || total == c / 2;
		loop invariant total <= c;
		loop invariant total <= c / 2 + 1;
		loop invariant total <= c + 1;
		loop invariant total <= average;
		loop invariant total <= (c + 1) / 2;
		loop invariant total * total <= average;
		loop invariant total * 2 <= c;
		loop invariant total * 2 <= c + 1;
		loop invariant c == 1 || c > 1;
		loop invariant c == 0 || c >= 1;
		loop invariant c - total <= c;
		loop invariant c - 1 <= total * 2;
		loop invariant c - 1 <= average || c <= size + 1;
		loop invariant c % 2 == 0 || c % 2 == 1;
		loop invariant average >= 0 && total >= 0;
		loop invariant average >= 0 && average >= total;
		loop invariant average == total * total;
		loop invariant average == total * total || average >= total;
		loop invariant average == 0 || total > 0;
		loop invariant average == 0 || average >= total;
		loop invariant average == 0 || average >= 0;
		loop invariant average == 0 || average > 0;
		loop invariant average % 2 == 0 || average % 2 == 1;
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 || total >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 || total > 0);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 || average >= k);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 != 0 ==> total >= 1);
		loop invariant \forall integer k; 1 <= k < c && k % 2 != 0 ==> average >= k;
		loop invariant 2 * total <= c + 1;
		loop invariant 1 <= c;
		loop invariant 0 <= total;
		loop invariant 0 <= c;
		loop invariant 0 <= c - total;
		loop invariant 0 <= average;
		loop invariant 0 <= average && 0 <= total;
		loop assigns total;
		loop assigns c;
		loop assigns average;*/
int check_A_implies_B(int size) {
    return stub_A(size);
}

/*@requires size >= 1;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
  ensures \result >= 1;
  ensures \result <= size;*/
int check_B_implies_A(int size) {
    return stub_B(size);
}
