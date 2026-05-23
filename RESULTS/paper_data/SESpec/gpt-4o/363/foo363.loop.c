
/*@
  logic integer sum_even(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? n : 0) + sum_even(n - 1);

  logic integer count_even(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? 1 : 0) + count_even(n - 1);
*/

int foo363(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size,Pre);
      loop assigns c, average, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            average += c;
            total++;
        }
    }

    return average / total;
}
