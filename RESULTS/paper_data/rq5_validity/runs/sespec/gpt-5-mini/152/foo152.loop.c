
/*@ 
  logic integer seq_val(integer i) = i + 1;
*/

/*@
  logic integer count_even(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_even(a, lo, hi - 1) + ((a[hi - 1] % 2 == 0) ? 1 : 0);
*/

/*@
  requires number >= 0;
  requires p >= 0;
*/
int foo152(int number, int p) {

    int *result = (int *)malloc(sizeof(int) * (number));
    int result_len = number;
    int *b = (int *)malloc(sizeof(int) * (number));
    int b_len = number;
    int c, j = 0;
        
    /*@
      loop invariant 0 <= c <= number;
      loop assigns c, result[0..number-1];
    */
    for (c = 0; c < number; c++) {
        result[c] = c + 1;
    }
            
    /*@
      loop invariant 0 <= c <= number;
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
      loop invariant 0 <= c <= number;
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
