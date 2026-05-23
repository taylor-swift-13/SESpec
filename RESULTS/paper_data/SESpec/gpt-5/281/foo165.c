
/*@
  logic integer count_div_up_to(integer n, integer k) =
    k <= 0 ? 0
           : count_div_up_to(n, k - 1) + ((k != 0 && n % k == 0) ? 1 : 0);
*/

/*@
  requires num >= 1;
  assigns \nothing;
  // The function returns "Even" iff the divisor count up to num is even.
*/
const char * foo165(int num) {

    int result = 0;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 1 <= index;
      loop invariant 0 <= result <= index - 1;
      loop invariant result == count_div_up_to(num, index - 1);
      loop invariant num == \at(num,Pre);
      loop assigns index, result;
    */
    for (int index = 1; index <= num; index++) {
        if (num % index == 0) {
            result++;
        }
    }
        
    if (result % 2 == 0) {
      return "Even";
    } else {
      return "Odd";
    }
}
