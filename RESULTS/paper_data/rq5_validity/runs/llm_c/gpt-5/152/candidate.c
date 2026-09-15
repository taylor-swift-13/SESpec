#include <stdlib.h>

/*@ 
  logic integer odd_count(integer n) = (n + 1) / 2;
  logic integer even_count(integer n) = n / 2;
*/

/*@
  requires number >= 0;

  behavior out_of_range:
    assumes number == 0 || p <= 0 || p > number;
    ensures \result == 0;

  behavior first_segment:
    assumes number > 0 && 1 <= p && p <= odd_count(number);
    ensures \result == 2*p - 1;

  behavior second_segment:
    assumes number > 0 && odd_count(number) < p && p <= number;
    ensures \result == 2*(p - odd_count(number));

  ensures \result == 0 || (1 <= \result && \result <= number);

  complete behaviors;
  disjoint behaviors;
*/
int getNumber(int number, int p);

int getNumber(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, j = 0;
		/*@
		  loop invariant 0 <= c <= number;
		  loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
		  loop assigns c, result[0..number-1];
		  loop variant number - c;
		*/
		for (c = 0; c < number; c++) {
			result[c] = c + 1;
		}
		/*@
		  loop invariant 0 <= c <= number;
		  loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
		  loop invariant j == (c + 1) / 2;
		  loop assigns c, j, b[0..number-1];
		  loop variant number - c;
		*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				/*@ 
				  assert 0 <= c && c < number;
				  assert result[c] == c + 1;
				  assert 1 <= result[c] && result[c] <= number;
				*/
				if (j == p) {
					return result[c];
				}
			}
		}
		/*@
		  loop invariant 0 <= c <= number;
		  loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
		  loop invariant j == odd_count(number) + (c / 2);
		  loop assigns c, j, b[0..number-1];
		  loop variant number - c;
		*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				/*@ 
				  assert 0 <= c && c < number;
				  assert result[c] == c + 1;
				  assert 1 <= result[c] && result[c] <= number;
				*/
				if (j == p) {
					return result[c];
				}
			}
		}
		return 0;
}
