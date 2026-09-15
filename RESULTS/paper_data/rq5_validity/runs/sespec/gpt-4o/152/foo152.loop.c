
#include <stdlib.h>

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer count_odd(int* array, integer begin, integer end) =
    end <= begin ? 0 : count_odd(array, begin, end - 1) + (array[end - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer count_even(int* array, integer begin, integer end) =
    end <= begin ? 0 : count_even(array, begin, end - 1) + (array[end - 1] % 2 == 0 ? 1 : 0);
*/

int foo152(int number, int p) {
    int *result = (int *)malloc(sizeof(int) * (number));
    int result_len = number;
    int *b = (int *)malloc(sizeof(int) * (number));
    int b_len = number;
    int c, j = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
      loop assigns c, result[0..number-1];
    */
    for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }

    /*@
      loop assigns c, b[0..number-1], j;
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 != 0) {
            j++;
            if (j == p) {
                return result[c];
            }
        }
    }

    /*@
      loop assigns c, b[0..number-1], j;
    */
    for (c = 0; c < number; c++) {
        b[c] = result[c];
        if (result[c] % 2 == 0) {
            j++;
            if (j == p) {
                return result[c];
            }
        }
    }

    return 0;
}
