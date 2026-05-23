
/*@
  logic integer sum_odd(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_odd(n - 1);
*/

/*@
  logic integer count_odd(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? 1 : 0) + count_odd(n - 1);
*/

/*@
  predicate valid_average_total(int average, int total, int c) =
    average == sum_odd(c - 1) && total == count_odd(c - 1);
*/

int foo360(int size) {
    int average = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size, Pre);
      loop assigns c, average, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            average += c;
            total++;
        }
    }

    return average / total;
}
