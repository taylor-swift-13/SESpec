
/*@
  // Helper logic to count evens up to n and sum them; both are standard closed forms.
  logic integer evens_count(integer n) = n <= 0 ? 0 : n / 2;
  logic integer evens_sum(integer n) = n <= 0 ? 0 : (n / 2) * (n / 2 + 1);
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
