
/*@
  requires size >= 0;
  assigns \nothing;
  ensures size == 0 || count_of_evens(size) == 0 ==> \result == 0;
  ensures size > 0 && count_of_evens(size) > 0 ==> \result == sum_of_evens(size) / count_of_evens(size);
*/
int foo254(int size) {

    int result = 0;
    int total = 0;

    /*@
      loop invariant 1 <= c <= size + 1;
      loop invariant result == sum_of_evens(c - 1);
      loop invariant total == count_of_evens(c - 1);
      loop invariant size == \at(size,Pre);
      loop assigns c, result, total;
      loop variant size - c;
    */
    for (int c = 1; c <= size; c++) {
        if (c % 2 == 0) {
            result += c;
            total++;
        }
    }

    return total == 0 ? 0 : result / total;
}
