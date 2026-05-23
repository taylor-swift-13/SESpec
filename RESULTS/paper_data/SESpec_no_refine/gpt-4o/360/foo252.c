
/*@
  logic integer sum_odd(int n) =
    n <= 0 ? 0 : (n % 2 != 0 ? n : 0) + sum_odd(n - 1);
*/

/*@
  requires size > 0;
  assigns \nothing;
  ensures \result == sum_odd(size) / count_odd(size);
*/
int foo252(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant average == sum_odd(c - 1);
      loop invariant total == count_odd(c - 1);
      loop invariant size == \at(size,Pre);
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
