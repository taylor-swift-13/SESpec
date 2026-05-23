
/*@
logic integer count_current{L}(int *a, integer p, integer i, integer j) =
  (j <= i + 1) ? 0 :
  count_current{L}(a, p, i, j - 1) + ((a[i] + a[j - 1] == p) ? 1 : 0);

logic integer count_prefix{L}(int *a, integer num, integer p, integer idx) =
  (idx <= 0) ? 0 :
  count_prefix{L}(a, num, p, idx - 1) + count_current{L}(a, p, idx - 1, num);
*/

/*@ 
  requires 0 <= num <= array_len;
  requires num == 0 || \valid_read(array + (0 .. num-1));
  assigns \nothing;
  ensures \result == count_prefix(array, num, p, num);
  ensures \result >= 0;
*/
int foo244(int * array, int array_len, int num, int p) {
    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret == count_prefix(array, num, p, index);
      loop invariant 0 <= ret;
      loop assigns index, ret;
      loop variant num - index;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant ret == count_prefix(array, num, p, index)
                           + count_current(array, p, index, j);
          loop invariant 0 <= ret;
          loop assigns j, ret;
          loop variant num - j;
        */
        for (int j = index + 1; j < num; j++) {
            if (array[index] + array[j] == p) {
                ret++;
            }
        }

        /*@ assert ret == count_prefix(array, num, p, index)
                        + count_current(array, p, index, num); */
        /*@ assert ret == count_prefix(array, num, p, index + 1); */
    }

    return ret;
}
