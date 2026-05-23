
/*@
  requires num >= 0;
  ensures \result == (num | (\at(num, Pre) & ~(\at(num, Pre) >> 1)));
*/

int foo354(int num) {

    int even = 0;
    int result = 0;
    int sum = num;

    /*@
      loop invariant sum >= 0;
      loop invariant even >= 0;
      loop invariant sum == \at(num, Pre) >> even;
      
      loop invariant (!(\at(num, Pre) > 0)) ==> ((sum == \at(num, Pre)) && (result == 0) && (even == 0) && (num == \at(num, Pre)));
      loop invariant sum == \at(num, Pre) >> even;
      loop invariant num == \at(num, Pre);
      loop assigns result, sum, even;
    */
    while (sum > 0) {
        if (even % 2 == 1) {
            result |= (1 << even);
        }
        even++;
        sum >>= 1;
    }

    return (num | result);
}
