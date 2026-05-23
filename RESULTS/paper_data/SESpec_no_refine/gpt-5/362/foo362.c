
/*@
  assigns \nothing;
  ensures evens_count(size) > 0 ==> \result == evens_sum(size) / evens_count(size);
*/
int foo362(int size) {

    int result = 0;
    int total = 0;

    /*@
      loop invariant 0 <= total <= c - 1;
      loop invariant result >= 0;
      loop invariant total == evens_count(c - 1);
      loop invariant (c <= \at(size,Pre)) ==> (total == evens_count(c - 1)) ;
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
