
/*@ logic integer decimal_length(integer n) =
      n <= 0 ? 0 : 1 + decimal_length(n / 10); */
/*@ 
  assigns \nothing;
  ensures \result == decimal_length(\old(value));
  ensures \result >= 0;
*/
int foo399(int value) {
    int result = 0;

    /*@
      loop invariant result + decimal_length(value) == decimal_length(\at(value,Pre));
      loop invariant result >= 0;
      loop assigns value, result;
      loop variant value;
    */
    while (value > 0) {
        value /= 10;
        result++;
    }

    return result;
}
