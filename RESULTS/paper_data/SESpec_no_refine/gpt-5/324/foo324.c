
/*@ logic integer pow10(integer k) =
      k <= 0 ? 1 : 10 * pow10(k - 1); */
/*@
  assigns \nothing;
  ensures \result >= 0 && \result <= 9;
  ensures \exists integer k; \exists integer q;
            k >= 0 &&
            q >= 0 &&
            pow10(k) <= prod_range(1, number) &&
            prod_range(1, number) < 10 * pow10(k) &&
            q == prod_range(1, number) / pow10(k) &&
            q >= 0 && q <= 9 &&
            \result == q;
*/
int foo324(int number) {

    int first = 1;

    /*@
      loop invariant number == \at(number,Pre);
      loop assigns c, first;
    */
    for (int c = 2; c <= number; c++) {
        first *= c;
    }

    int result = 0;

    /*@
      loop invariant number == \at(number,Pre);
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
