
/*@
  requires count >= 1;
  ensures (count == 0) ==> (\result == 1);
  ensures (count == 1) ==> \true;
*/
int foo51_c193(int count) {

    int *arr = (int *)malloc(sizeof(int) * (count + 1));
    int arr_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    arr[0] = 1;
    arr[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
      loop invariant 2 <= w;
      loop invariant arr_len == count + 1;
      loop invariant C_len == count + 1;
      loop assigns w, arr[0..arr_len-1], C[0..C_len-1];
    */
    for (int w = 2; w <= count; w++) {
        arr[w] = arr[w - 2]
                 + 2 * C[w - 1];
        C[w] = arr[w - 1] + C[w - 2];
    }

    return arr[count];
}
