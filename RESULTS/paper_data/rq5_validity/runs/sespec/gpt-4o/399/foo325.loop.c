
/*@
  logic integer num_digits(integer v) = 
    (v <= 0) ? 0 : 1 + num_digits(v / 10);
*/

/*@
  requires value == \at(value, Pre);
*/
int foo325(int value) {

    int result = 0;

    /*@
      loop invariant (\at(value,Pre) > 0) ==> (value >= 0);
      loop invariant (\at(value,Pre) > 0) ==> (result + num_digits(value) == num_digits(\at(value,Pre)));
      loop invariant (!(\at(value,Pre) > 0)) ==> ((result == 0)&&(value == \at(value,Pre)));
      loop assigns value, result;
    */
    while (value > 0) {
        value /= 10;
        result++;
    }

    return result;
}
