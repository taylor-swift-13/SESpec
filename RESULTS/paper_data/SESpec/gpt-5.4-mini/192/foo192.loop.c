
#include <stdlib.h>

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

int foo192(int count) {

    int *w = (int *)malloc(sizeof(int) * (count + 1));
    int w_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    w[0] = 1;
    w[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
      loop invariant 2 <= index;
      loop assigns index, w[0..count], C[0..count];
    */
    for (int index = 2; index <= count; index++) {
        w[index] = w[index - 2] + 2 * C[index - 1];
        C[index] = w[index - 1] + C[index - 2];
    }

    return w[count];
}
