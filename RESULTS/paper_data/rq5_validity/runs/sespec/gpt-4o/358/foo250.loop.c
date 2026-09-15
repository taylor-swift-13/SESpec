
/*@
  logic integer sum_of_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_of_odds(n - 1);
*/

/*@
  logic integer count_odds(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? 1 : 0) + count_odds(n - 1);
*/

int foo250(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size,Pre);
      loop assigns index, average, total;
    */
    for (int index = 1; index <= size; index++) {
        if (index % 2 != 0) {
            average += index;
            total++;
        }
    }

    return average / total;
}
