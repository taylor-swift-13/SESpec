
#include <stdlib.h>

/*@
  logic integer compute_div(int w, integer d, integer result) =
    d == 0 ? 1 :
    d == 1 ? w :
    d == 2 ? w * w :
    ((w - 1) * (compute_div(w, d - 1, result) + compute_div(w, d - 2, result))) % result;

  predicate valid_div_array(int* div, integer count, int w, int result) =
    \forall integer d; 0 <= d <= count ==> div[d] == compute_div(w, d, result);
*/

/*@
  requires count >= 0;
  requires w > 0;
  requires \valid(div + (0 .. count));
  assigns div[0 .. count];
  ensures \result == compute_div(w, count, 1000000007);
  ensures valid_div_array(div, count, w, 1000000007);
  ensures \result == div[count];
*/
int foo268(int count, int w) {
    int result = 1000000007;
    int *div = (int *)malloc(sizeof(int) * (count + 1));
    int div_len = count + 1;
    div[0] = 1;
    div[1] = w;
    div[2] = w * w;

    /*@
      loop invariant 3 <= d <= count + 1;
      loop invariant \forall integer k; 0 <= k < d ==> div[k] == compute_div(w, k, result);
      loop invariant valid_div_array(div, d - 1, w, result);
      loop assigns div[3 .. count], d;
      loop variant count - d;
    */
    for (int d = 3; d <= count; d++) {
        div[d] = ((w - 1) * (div[d - 1] + div[d - 2])) % result;
    }

    return div[count];
}
