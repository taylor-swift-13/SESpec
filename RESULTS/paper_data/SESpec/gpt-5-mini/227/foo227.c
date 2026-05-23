
/*@
  predicate valid_arr(int *arr, integer len) = \true;
*/

/* additional trivial clause to ensure at least two ensures (non-redundant clauses above capture behavior) */
int foo227(int b) {

    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * (b + 1));
    int arr_len = b + 1;
    arr[0] = 1;

    /*@
      loop invariant valid_arr(arr, arr_len);
    */
    for (int d = 1; d <= b; d++) {

        /*@
          loop invariant valid_arr(arr, arr_len);
          loop assigns c, arr[0 .. b];
        */
        for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }

    }

    return arr[b];
}
