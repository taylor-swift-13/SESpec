#include <stddef.h>

int findEvenPair(int * a, int a_len, int n);

/*@ 
  logic integer count_even_pairs{L}(int *a, integer n) =
    \sum(integer i = 0; i < n; i++,
         \sum(integer j = i+1; j < n; j++,
              (((a[i] ^ a[j]) & 1) == 0) ? 1 : 0));
*/

/*@
  behavior null_ptr:
    assumes a == \null;
    assigns \nothing;
    ensures \result == -1;

  behavior small_len:
    assumes a != \null && a_len <= 1;
    assigns \nothing;
    ensures \result == 0;

  behavior normal:
    assumes a != \null && a_len > 1;
    requires 0 <= a_len <= 65536;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \result == count_even_pairs(a, a_len);
    ensures 0 <= \result <= (a_len * (a_len - 1)) / 2;

  complete behaviors null_ptr, small_len, normal;
  disjoint behaviors null_ptr, small_len, normal;
*/
int findEvenPair(int * a, int a_len, int n) {

        if (a == NULL) {
            return -1;
        }
        if (a_len == 1) {
            return 0;
        }

        int evenPairCount = 0;
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant a_len <= 1 || \valid_read(a + (0 .. a_len-1));
          loop invariant evenPairCount ==
            \sum(integer ii = 0; ii < i; ii++,
                 \sum(integer jj = ii+1; jj < a_len; jj++,
                      (((a[ii] ^ a[jj]) & 1) == 0) ? 1 : 0));
          loop assigns i, evenPairCount;
          loop variant a_len - i;
        */
        for (int i = 0; i < a_len; i++) {
            /*@
              loop invariant i + 1 <= j <= a_len;
              loop invariant evenPairCount ==
                \sum(integer ii = 0; ii < i; ii++,
                     \sum(integer jj = ii+1; jj < a_len; jj++,
                          (((a[ii] ^ a[jj]) & 1) == 0) ? 1 : 0))
                + \sum(integer jj = i+1; jj < j; jj++,
                       (((a[i] ^ a[jj]) & 1) == 0) ? 1 : 0);
              loop assigns j, evenPairCount, x, y, v;
              loop variant a_len - j;
            */
            for (int j = i + 1; j < a_len; j++) {
                int x = a[i];
                int y = a[j];
                int v = x ^ y;
                /*@ assert ((v & 1) == 0) <==> (((a[i] ^ a[j]) & 1) == 0); */
                if ((v & 1) == 0) {
                    evenPairCount++;
                }
            }
        }
        return evenPairCount;
}
