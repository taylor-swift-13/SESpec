
/*@
  logic integer arr_value{L}(integer w, integer count) =
    w == 0 ? 1 :
    w == 1 ? 0 :
    arr_value(w - 2, count) + 2 * C_value(w - 1, count);

  logic integer C_value{L}(integer w, integer count) =
    w == 0 ? 0 :
    w == 1 ? 1 :
    arr_value(w - 1, count) + C_value(w - 2, count);
*/

/*@
  requires count >= 0;
  ensures \result == arr_value(count, count);
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

    /*@
      loop invariant 2 <= w <= count + 1;
      loop invariant \forall integer i; 0 <= i < w ==> arr[i] == arr_value(i, count);
      loop invariant \forall integer i; 0 <= i < w ==> C[i] == C_value(i, count);
      loop invariant \forall integer i; 0 <= i < w ==> arr[i] >= 0;
      loop invariant \forall integer i; 0 <= i < w ==> C[i] >= 0;
      loop assigns w, arr[0..count], C[0..count];
    */
    for (int w = 2; w <= count; w++) {
        arr[w] = arr[w - 2] + 2 * C[w - 1];
        C[w] = arr[w - 1] + C[w - 2];
    }

    return arr[count];
}
