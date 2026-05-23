
/*@
  assigns \nothing;
  ensures \result ==
    (\sum integer k; 1 <= k <= number ? ((number % k) == 0 ? 1 : 0) : 0);
*/
int foo374(int number) {

    int div = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant number == \at(number,Pre);
      loop invariant 1 <= c <= number + 1 || number < 1;
      loop invariant div ==
        (\sum integer k; 1 <= k < c ? ((\at(number,Pre) % k) == 0 ? 1 : 0) : 0);
      loop assigns c, div;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }

    return div;
}
