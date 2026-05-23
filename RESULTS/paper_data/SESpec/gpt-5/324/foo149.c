
/*@ logic integer pow10(integer k) =
      k <= 0 ? 1 : 10 * pow10(k - 1); */

/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@
  requires number >= 0;
  assigns \nothing;
*/
int foo149(int number) {

    int first = 1;

    /*@
      loop invariant number == \at(number,Pre);
      loop invariant 2 <= c <= number + 1 || (number < 2 && c == 2);
      loop invariant first == fact(c - 1);
      loop invariant c >= 2 ==> first >= 1;
      loop assigns c, first;
    */
    for (int c = 2; c <= number; c++) {
        first *= c;
    }

    int result = 0;
    
    /*@
      loop invariant first >= 0;
      loop invariant result >= 0;
      loop invariant result < 10 || first == 0;
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }
            
    return result;
}
