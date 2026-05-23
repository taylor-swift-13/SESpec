
/*@
  logic integer count_divisors(integer n, integer k) =
    (k == 0) ? 0 : (n % k == 0 ? 1 : 0) + count_divisors(n, k - 1);
*/

/*@
  requires num >= 0;
  requires num <= 2147483647; // Ensure num is within the range of int
  assigns \nothing;
*/
const char * foo165(int num) {

    int result = 0;
    
    /*@
      loop invariant 1 <= index <= (num > 0 ? num + 1 : 1);
      loop invariant result == count_divisors(\at(num,Pre), index - 1);
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
