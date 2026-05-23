
/*@
  logic integer sum_odd(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_odd(n - 1);
*/

/*@
  logic integer count_odd(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? 1 : 0) + count_odd(n - 1);
*/

/*@
  requires size >= 0;
  requires count_odd(size) > 0; // Prevent division by zero
  assigns \nothing;
  ensures \result == (sum_odd(size) / count_odd(size));
  ensures sum_odd(size) / count_odd(size) == \result; // Explicitly state the result of integer division
*/
int foo360(int size) {
    int average = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant average == sum_odd(c - 1);
      loop invariant total == count_odd(c - 1);
      loop invariant size == \at(size, Pre);
      loop assigns c, average, total;
      loop variant size - c;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            average += c;
            total++;
        }
    }

    return average / total;
}
