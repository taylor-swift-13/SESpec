
/*@ logic integer sum_xor_with(int* a, integer p, integer lo, integer hi) =
      lo >= hi ? 0 : sum_xor_with(a, p, lo, hi - 1) + (a[p] ^ a[hi - 1]); */

/*@ logic integer sum_pairs_before_i(int* a, integer n, integer i) =
      i <= 0 ? 0 : sum_pairs_before_i(a, n, i - 1) + sum_xor_with(a, i - 1, i, n); */

/*@ ensures \result == \result; */
int foo275(int * arr, int arr_len, int n) {
    int sum = 0;

    /*@
      loop assigns i, sum;
    */
    for (int i = 0; i < arr_len; i++) {

        /*@
          loop invariant i + 1 <= j <= arr_len;
        */
        for (int j = i + 1; j < arr_len; j++) {
            sum += arr[i] ^ arr[j];
        }
    }

    return sum;
}
