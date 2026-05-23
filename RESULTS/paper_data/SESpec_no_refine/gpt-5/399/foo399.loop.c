
/*@
  logic integer digits10(integer x) =
    x <= 0 ? 0 :
    x < 10 ? 1 :
    1 + digits10(x / 10);
*/

int foo399(int value) {

    int result = 0;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant (\at(value,Pre) > 0) ==> (result + digits10(value) == digits10(\at(value,Pre)));
      loop invariant (\at(value,Pre) > 0) ==> (value >= 0);
      loop invariant (\at(value,Pre) > 0) ==> (result >= 0);
      loop invariant (!(\at(value,Pre) > 0)) ==> ((result == 0)&&(value == \at(value,Pre)));
      loop assigns value, result;
    */
    while (value > 0) {
        value /= 10;
        result++;
    }
        
    return result;
}
