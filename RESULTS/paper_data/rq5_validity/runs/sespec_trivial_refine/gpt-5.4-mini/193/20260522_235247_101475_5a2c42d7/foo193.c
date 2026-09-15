
#include <stdlib.h>

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  requires 1 <= count;
  assigns \nothing;
  ensures \result == 0 <==> (count % 2 == 1);
  ensures count % 2 == 1 ==> \result == 0;
  ensures count % 2 == 0 ==> \result > 0;
  ensures count == 1 ==> \result == 0;
  ensures count == 2 ==> \result == 3;
*/
int foo193(int count) {

        int *arr = (int *)malloc(sizeof(int) * (count + 1));
        int arr_len = count + 1;
        int *C = (int *)malloc(sizeof(int) * (count + 1));
        int C_len = count + 1;
        arr[0] = 1;
        arr[1] = 0;
        C[0] = 0;
        C[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count < 1 || (2 <= w <= count + 1);
          loop assigns w, arr[2 .. count], C[2 .. count];
            */
            for (int w = 2; w <= count; w++) {
            arr[w] = arr[w - 2]
                    + 2 * C[w - 1];
            C[w] = arr[w - 1] + C[w - 2];
        }
            
        return arr[count];
}
