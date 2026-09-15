
/*@
  logic integer count_matches(int *a, integer lo, integer hi, integer j, integer p) =
    lo >= hi ? 0 :
    count_matches(a, lo, hi - 1, j, p) + (a[hi - 1] + a[j] == p ? 1 : 0);

  logic integer pair_count(int *a, integer lo, integer hi, integer p) =
    lo >= hi ? 0 :
    pair_count(a, lo, hi - 1, p) + count_matches(a, lo, hi - 1, hi - 1, p);
*/

/*@
  requires num >= 0;
  requires array_len >= num;
  requires \valid_read(array + (0 .. array_len - 1));
*/
int foo244(int * array, int array_len, int num, int p) {

        int ret = 0;

        /*@
          loop invariant 0 <= index <= num;
          loop invariant 0 <= ret;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop assigns index, ret;
        */
        for (int index = 0; index < num; index++) {

            /*@
              loop invariant index + 1 <= j <= num;
              loop invariant 0 <= ret;
              loop invariant p == \at(p,Pre);
              loop invariant num == \at(num,Pre);
              loop invariant array_len == \at(array_len,Pre);
              loop invariant array == \at(array,Pre);
              loop assigns j, ret;
            */
            for (int j = index + 1; j < num; j++) {
                if (array[index] + array[j] == p) {
                    ret++;
                }
            }

        }

        return ret;
}
