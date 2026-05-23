
/*@
  assigns \nothing;
  ensures \result == count_divisors_upto(num, num + 1);
  ensures 0 <= \result;
*/
int foo372(int num) {

    int div = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 0 <= div;
      loop invariant num == \at(num,Pre);
      loop assigns c, div;
    */
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            div++;
        }
    }

    return div;
}
