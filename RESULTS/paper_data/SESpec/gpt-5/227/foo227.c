
/*@
  
  ensures b == 0 ==> \result == 1;
  ensures b != 0 ==> \true;
*/
int foo227(int b) {
    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * (b + 1));
    int arr_len = b + 1;
    arr[0] = 1;

    /*@
      loop invariant arr_len == b + 1;
      loop assigns d, arr[1..b];
    */
    for (int d = 1; d <= b; d++) {

        /*@
          loop assigns c, arr[d];
        */
        for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }

    }

    return arr[b];
}
