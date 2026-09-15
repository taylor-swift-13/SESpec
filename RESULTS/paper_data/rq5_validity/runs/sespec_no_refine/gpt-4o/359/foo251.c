
/*@
  requires size >= 0;
  assigns \nothing;
  ensures \result == (size == 0 ? 0 : sum_odds(size) / count_odds(size));
*/
int foo251(int size) {

    int ret = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant ret == sum_odds(c - 1);
      loop invariant total == count_odds(c - 1);
      loop invariant size == \at(size, Pre);
      loop assigns c, ret, total;
      loop variant size - c;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }

    return ret / total;
}
