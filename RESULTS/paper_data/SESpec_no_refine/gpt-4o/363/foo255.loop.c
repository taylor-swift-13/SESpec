
/*@
  logic integer sum_of_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? n : 0) + sum_of_evens(n - 1);
*/

/*@
  logic integer count_of_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? 1 : 0) + count_of_evens(n - 1);
*/

/*@
  requires size >= 0;
  ensures \result == (size == 0 ? 0 : sum_of_evens(size) / count_of_evens(size));
*/
int foo255(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant average == sum_of_evens(c - 1);
      loop invariant total == count_of_evens(c - 1);
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
