#include <limits.h>
#include <stdlib.h>


/*@
  logic integer count_odd_upto(integer n) =
    n <= 0 ? 0 : count_odd_upto(n - 1) + (((n - 1) % 2 != 0) ? 1 : 0);
*/

  logic integer count_even_upto(integer n) =
    n <= 0 ? 0 : count_even_upto(n - 1) + (((n - 1) % 2 == 0) ? 1 : 0);

/*@loop assigns c, b[0..value-1], j;*/
int stub_A(int value, int p);

/*@loop invariant result_len == value;
		loop invariant j == 0 || j > 0;
		loop invariant c == 0 || c > 0;
		loop invariant b_len == value;
		loop invariant 0 <= j;
		loop invariant 0 <= c;
		loop assigns j;
		loop assigns c;
		loop assigns b[0..value-1];*/
int stub_B(int value, int p);

/*@loop invariant result_len == value;
		loop invariant j == 0 || j > 0;
		loop invariant c == 0 || c > 0;
		loop invariant b_len == value;
		loop invariant 0 <= j;
		loop invariant 0 <= c;
		loop assigns j;
		loop assigns c;
		loop assigns b[0..value-1];*/
int check_A_implies_B(int value, int p) {
    return stub_A(value, p);
}

/*@loop assigns c, b[0..value-1], j;*/
int check_B_implies_A(int value, int p) {
    return stub_B(value, p);
}
