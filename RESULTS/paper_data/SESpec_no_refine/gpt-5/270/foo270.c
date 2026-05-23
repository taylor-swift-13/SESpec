
#include <stdlib.h>

/*@ logic integer foo270_seq(integer m, integer n) =
      n <= 0 ? 1 :
      (n == 1 ? m :
      (n == 2 ? m * m :
       ((m - 1) * (foo270_seq(m, n - 1) + foo270_seq(m, n - 2))) % 1000000007));
*/
/*@
  assigns \nothing;
  ensures count >= 0 ==> \result == foo270_seq(m, count);
*/
int foo270(int count, int m) {

        int w = 1000000007;
        int *div = (int *)malloc(sizeof(int) * (count + 1));
        int div_len = count + 1;
        div[0] = 1;
        div[1] = m;
        div[2] = m * m;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 3 <= d <= count + 1;
              loop invariant div_len == count + 1;
              loop invariant \valid(div + (0 .. div_len - 1));
              loop invariant w == 1000000007;
              loop invariant \forall integer k; 0 <= k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
              loop invariant \forall integer k; 3 <= k < d ==> div[k] == ((m - 1) * (div[k - 1] + div[k - 2])) % w;
              loop assigns d, div[..];
            */
            for (int d = 3; d <= count; d++) {
            div[d] = ((m - 1)
                    * (div[d - 1] + div[d - 2])) % w;
        }
            
        return div[count];
}
