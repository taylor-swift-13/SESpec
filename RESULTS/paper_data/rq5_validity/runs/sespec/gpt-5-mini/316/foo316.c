
/*@
  requires \true;
  assigns \nothing;
  ensures number == 1 ==> \result == 1;
  ensures number != 1 ==> \result >= 0;
*/
int foo316(int number) {

    int result = 0;
    if (number == 1)
        return 1;
    
    /*@
      loop invariant 2 <= c;
      loop invariant 0 <= result;
      loop invariant result <= c - 2;
      loop invariant (\forall integer d; 2 <= d < c ==> (number % d == 0) ==> (number / d >= d));
      loop invariant (c <= number / c) ==> result >= 0;
      loop invariant (!(c <= number / c)) ==> (c > number / c);
      loop assigns c, result;
    */
    for (int c = 2; c <= number / c; c++) {
        if (number % c == 0) {
            result++;
            if (number / c == c) {
                break;
            }
        }
    }
    
    return result;
}
