
/*@
  logic integer count_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? 1 : 0) + count_odds(n - 1);

  logic integer sum_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_odds(n - 1);
*/

int foo251(int size) {

    int ret = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size,Pre);
      loop assigns c, ret, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }

    return ret / total;
}
