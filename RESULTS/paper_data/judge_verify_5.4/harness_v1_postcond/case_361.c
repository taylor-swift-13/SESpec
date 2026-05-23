#include <limits.h>


/*@
  logic integer even_count(integer n) =
    n <= 0 ? 0 : even_count(n - 1) + ((n % 2 == 0) ? 1 : 0);
*/

  logic integer even_sum(integer n) =
    n <= 0 ? 0 : even_sum(n - 1) + ((n % 2 == 0) ? n : 0);

/*@requires size >= 2;
  requires even_count(size) > 0;
  assigns \nothing;
  
  ensures even_count(size) > 0;
  ensures \result >= 0;
  ensures \result <= even_sum(size);*/
int stub_A(int size);

/*@loop invariant total >= 0 && average >= 0;
		loop invariant total > 0 ==> average >= total;
		loop invariant total > 0 ==> average >= 2 * total;
		loop invariant total == j / 2 || total == (j - 1) / 2;
		loop invariant total == 0 || total <= j;
		loop invariant total == 0 || total <= j / 2;
		loop invariant total == 0 || total * 2 <= j;
		loop invariant total == 0 || j > 0;
		loop invariant total == 0 || average >= total;
		loop invariant total == 0 || average >= 2 * total;
		loop invariant total == 0 || average >= 0;
		loop invariant total == 0 || average > 0;
		loop invariant total == 0 || average == 0 || average >= total;
		loop invariant total == 0 || 2 * total <= j;
		loop invariant total == 0 || 1 <= total;
		loop invariant total == 0 ==> average == 0;
		loop invariant total == (j - 1) / 2;
		loop invariant total == (j - 1) / 2 || total == j / 2;
		loop invariant total <= j;
		loop invariant total <= j / 2;
		loop invariant total <= j / 2 + 1;
		loop invariant total <= j - 1;
		loop invariant total <= average;
		loop invariant total <= (j + 1) / 2;
		loop invariant total < j;
		loop invariant total * 2 <= j;
		loop invariant total * 2 <= j + 1;
		loop invariant total * 2 - 2 <= average;
		loop invariant total % 2 == 0 || total % 2 == 1;
		loop invariant j == 1 || j > 0;
		loop invariant j == 1 + (j - 1);
		loop invariant j <= size + 1 || 0 <= j;
		loop invariant j % 2 == 1 || j % 2 == 0;
		loop invariant j % 2 == 1 ==> total == (j - 1) / 2;
		loop invariant j % 2 == 1 ==> average >= total;
		loop invariant j % 2 == 0 || j % 2 == 1;
		loop invariant j % 2 == 0 ==> average >= total;
		loop invariant average >= 0 && total >= 0;
		loop invariant average == total * total + total;
		loop invariant average == total * (total + 1);
		loop invariant average == total * (total + 1) || total == 0;
		loop invariant average == total * (total + 1) || average >= total;
		loop invariant average == total * (total + 1) || average == total * (total + 1) - total;
		loop invariant average == 0 || total > 0;
		loop invariant average == 0 || average >= total;
		loop invariant average == 0 ==> total == 0;
		loop invariant average % 2 == 0;
		loop invariant average % 2 == 0 || average % 2 == 1;
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 || k % 2 == 0);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> total == total);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average >= 0);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average == average);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 || k % 2 == 1);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 1);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 0);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> average >= k);
		loop invariant \forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 1;
		loop invariant \forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 0;
		loop invariant \forall integer k; 1 <= k < j && k % 2 == 0 ==> average >= k;
		loop invariant 2 * total <= j;
		loop invariant 2 * total <= j + 1;
		loop invariant 2 * total <= average;
		loop invariant 1 <= j;
		loop invariant 0 <= total;
		loop invariant 0 <= j;
		loop invariant 0 <= j - total;
		loop invariant 0 <= average;
		loop invariant 0 < j;
		loop assigns total;
		loop assigns j;
		loop assigns average;*/
int stub_B(int size);

/*@loop invariant total >= 0 && average >= 0;
		loop invariant total > 0 ==> average >= total;
		loop invariant total > 0 ==> average >= 2 * total;
		loop invariant total == j / 2 || total == (j - 1) / 2;
		loop invariant total == 0 || total <= j;
		loop invariant total == 0 || total <= j / 2;
		loop invariant total == 0 || total * 2 <= j;
		loop invariant total == 0 || j > 0;
		loop invariant total == 0 || average >= total;
		loop invariant total == 0 || average >= 2 * total;
		loop invariant total == 0 || average >= 0;
		loop invariant total == 0 || average > 0;
		loop invariant total == 0 || average == 0 || average >= total;
		loop invariant total == 0 || 2 * total <= j;
		loop invariant total == 0 || 1 <= total;
		loop invariant total == 0 ==> average == 0;
		loop invariant total == (j - 1) / 2;
		loop invariant total == (j - 1) / 2 || total == j / 2;
		loop invariant total <= j;
		loop invariant total <= j / 2;
		loop invariant total <= j / 2 + 1;
		loop invariant total <= j - 1;
		loop invariant total <= average;
		loop invariant total <= (j + 1) / 2;
		loop invariant total < j;
		loop invariant total * 2 <= j;
		loop invariant total * 2 <= j + 1;
		loop invariant total * 2 - 2 <= average;
		loop invariant total % 2 == 0 || total % 2 == 1;
		loop invariant j == 1 || j > 0;
		loop invariant j == 1 + (j - 1);
		loop invariant j <= size + 1 || 0 <= j;
		loop invariant j % 2 == 1 || j % 2 == 0;
		loop invariant j % 2 == 1 ==> total == (j - 1) / 2;
		loop invariant j % 2 == 1 ==> average >= total;
		loop invariant j % 2 == 0 || j % 2 == 1;
		loop invariant j % 2 == 0 ==> average >= total;
		loop invariant average >= 0 && total >= 0;
		loop invariant average == total * total + total;
		loop invariant average == total * (total + 1);
		loop invariant average == total * (total + 1) || total == 0;
		loop invariant average == total * (total + 1) || average >= total;
		loop invariant average == total * (total + 1) || average == total * (total + 1) - total;
		loop invariant average == 0 || total > 0;
		loop invariant average == 0 || average >= total;
		loop invariant average == 0 ==> total == 0;
		loop invariant average % 2 == 0;
		loop invariant average % 2 == 0 || average % 2 == 1;
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 || k % 2 == 0);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> total == total);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average >= 0);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 1 ==> average == average);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 || k % 2 == 1);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 1);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> total >= 0);
		loop invariant \forall integer k; 1 <= k < j ==> (k % 2 == 0 ==> average >= k);
		loop invariant \forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 1;
		loop invariant \forall integer k; 1 <= k < j && k % 2 == 0 ==> total >= 0;
		loop invariant \forall integer k; 1 <= k < j && k % 2 == 0 ==> average >= k;
		loop invariant 2 * total <= j;
		loop invariant 2 * total <= j + 1;
		loop invariant 2 * total <= average;
		loop invariant 1 <= j;
		loop invariant 0 <= total;
		loop invariant 0 <= j;
		loop invariant 0 <= j - total;
		loop invariant 0 <= average;
		loop invariant 0 < j;
		loop assigns total;
		loop assigns j;
		loop assigns average;*/
int check_A_implies_B(int size) {
    return stub_A(size);
}

/*@requires size >= 2;
  requires even_count(size) > 0;
  assigns \nothing;
  
  ensures even_count(size) > 0;
  ensures \result >= 0;
  ensures \result <= even_sum(size);*/
int check_B_implies_A(int size) {
    return stub_B(size);
}
