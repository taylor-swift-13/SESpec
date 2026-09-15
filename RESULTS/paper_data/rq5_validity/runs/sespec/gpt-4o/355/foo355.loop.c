
/*@
  logic integer count_bits(integer x) = 
    x == 0 ? 0 : (x % 2) + count_bits(x / 2);
*/

int foo355(int num) {

    int result = 0;
    int end = 0;
    int sum = num;

    /*@
      loop invariant result >= 0;
      loop invariant num == \at(num,Pre);
      loop invariant sum == \at(num,Pre) >> result;
      loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre)) && (end == 0) && (result == 0) && (num == \at(num,Pre)));
      loop assigns end, sum, result;
    */
    while (sum > 0) {
        if (result % 2 == 1) {
            end |= (1 << result);
        }
        result++;
        sum >>= 1;
    }

    return (num | end);
}
