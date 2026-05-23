
/*@
  logic integer sum_of_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? n : 0) + sum_of_evens(n - 1);

  logic integer count_of_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? 1 : 0) + count_of_evens(n - 1);
*/

int foo254(int size) {

    int result = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size,Pre);
      loop assigns c, result, total;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            result += c;
            total++;
        }
    }

    return result / total;
}
