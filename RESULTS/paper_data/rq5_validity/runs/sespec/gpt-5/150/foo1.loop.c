
/*@ logic integer init_val(integer k) = k + 1; */
/*@
  predicate unchanged_result(int* a, integer n) =
    \forall integer k; 0 <= k < n ==> a[k] == k + 1;
*/

/*@
  predicate copied_prefix(int* src, int* dst, integer n, integer c) =
    0 <= c <= n && (\forall integer k; 0 <= k < c ==> dst[k] == src[k]);
*/

/*@
  predicate result_initialized_prefix(int* a, integer n, integer c) =
    0 <= c <= n &&
    (\forall integer k; 0 <= k < c ==> a[k] == init_val(k));
*/


int foo1(int value, int p) {

    int *result = (int *)malloc(sizeof(int) * (value));
    int result_len = value;
    int *b = (int *)malloc(sizeof(int) * (value));
    int b_len = value;
    int c, j = 0;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 0 <= c;
      loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
      loop assigns c, result[0 .. value - 1];
    */
    for (c = 0; c < value; c++) {
        result[c] = c + 1;
    }
        
    
            
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 0 <= c;
      loop assigns c, b[0 .. value - 1], j;
    */
    for (c = 0; c < value; c++) {
        b[c] = result[c];
        if (result[c] % 2 != 0) {
            j++;
            if (j == p) {
                return result[c];
            }
        }
    }
            
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c;
          loop assigns c, b[0 .. value - 1], j;
            */
            for (c = 0; c < value; c++) {
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
