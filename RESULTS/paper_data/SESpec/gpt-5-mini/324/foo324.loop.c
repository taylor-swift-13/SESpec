
/*@
  logic integer fact(integer n) =
    n <= 1 ? 1 : n * fact(n - 1);
*/

/*@
  requires number == \at(number,Pre);
  requires number >= 1;
*/

int foo324(int number) {

    int first = 1;

    /*@
      loop invariant 2 <= c;
      loop invariant c <= \at(number,Pre) + 1;
      loop invariant first >= 1;
      loop invariant number == \at(number,Pre);
      loop invariant (c <= \at(number,Pre)) ==> (first == fact(c-1));
      loop invariant (c <= \at(number,Pre)) ==> (first >= 1);
      loop invariant (!(c <= \at(number,Pre))) ==> (first == fact(\at(number,Pre)));
      loop assigns c, first;
    */
    for (int c = 2; c <= number; c++) {
        first *= c;
    }

    int result = 0;
    
    /*@
      loop invariant 0 <= result <= 9;
      loop invariant first >= 0;
      loop invariant (!(first > 0)) ==> (first == 0 && 0 <= result && result <= 9);
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }
            
    return result;
}
