
/*@
  logic integer num_digits(integer x) =
    (x <= 0) ? 0 : 1 + num_digits(x / 10);
*/

/*@
  requires value >= 0;
  assigns value, result;
  ensures \result == num_digits(\at(value, Pre));
*/
int foo325(int value) {

    int result = 0;

    /*@
      loop invariant (\at(value,Pre) > 0) ==> (value >= 0);
      loop invariant (\at(value,Pre) > 0) ==> (result == num_digits(\at(value,Pre)) - num_digits(value));
      loop invariant (!(\at(value,Pre) > 0)) ==> ((result == 0)&&(value == \at(value,Pre)));
      loop assigns value, result;
      loop variant value;
    */
    while (value > 0) {
        value /= 10;
        result++;
    }

    return result;
}
