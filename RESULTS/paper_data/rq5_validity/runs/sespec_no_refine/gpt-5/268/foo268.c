
#include <stdlib.h>

/*@ logic integer foo268_seq_term(integer count, integer w, integer idx) =
      idx == 0 ? 1 :
      idx == 1 ? w :
      idx == 2 ? w * w :
      (((w - 1) * (foo268_seq_term(count, w, idx - 1) + foo268_seq_term(count, w, idx - 2))) % 1000000007); */
/*@
  assigns \nothing;
*/
int foo268(int count, int w) {

    int result = 1000000007;
    int *div = (int *)malloc(sizeof(int) * (count + 1));
    int div_len = count + 1;
    div[0] = 1;
    div[1] = w;
    div[2] = w * w;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant div_len == count + 1;
                        div[k] == (((w - 1) * (div[k - 1] + div[k - 2])) % result);
      loop assigns d, div[0 .. count];
    */
    for (int d = 3; d <= count; d++) {
        div[d] = ((w - 1)
                * (div[d - 1] + div[d - 2])) % result;
    }
            
    return div[count];
}
