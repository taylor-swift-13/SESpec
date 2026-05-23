
/*@
  logic integer count_divisors(integer n, integer limit) =
    limit <= 0 ? 0 : count_divisors(n, limit - 1) + (n % limit == 0 ? 1 : 0);
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
