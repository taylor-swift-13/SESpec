
/*@
  requires \valid(p + (0 .. p_len - 1));
  requires p_len >= 0;
  ensures \result >= 0;
*/

int foo231(int * p, int p_len, int array) {

    int count = 0;
    int total = p_len;

    /*@
      loop invariant 0 <= index <= total;
      loop invariant count >= 0;
      loop invariant total == \at(p_len, Pre);
      loop invariant array == \at(array, Pre);
      loop invariant p_len == \at(p_len, Pre);
      loop invariant p == \at(p, Pre);
      loop assigns index, count;
    */
    for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant index + 1 <= c <= total;
          loop invariant count >= 0;
          loop invariant \forall int j; index + 1 <= j < c ==> (p[index] != p[j] ==> count >= 0);
          loop assigns c, count;
        */
        for (int c = index + 1; c < total; c++) {
            if (p[index] != p[c]) {
                count++;
            }
        }
    }

    return count;
}
