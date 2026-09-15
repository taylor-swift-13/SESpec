
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer bitwise_or_shift(integer num, integer result) =
    (\exists integer k; 0 <= k < result && (num >> k) % 2 == 1 && (1 << k) == (1 << result));
*/

/*@
  requires \valid(&num);
  assigns end, sum, result;
  ensures \result == (num | compute_end(num, result));
*/
int foo218(int num) {

    int result = 0;
    int end = 0;
    int sum = num;

    /*@
      loop invariant (\at(num,Pre) > 0) ==> 
        (end == compute_end(\at(num,Pre), result));
      loop invariant (!(\at(num,Pre) > 0)) ==> 
        ((sum == \at(num,Pre))&&(end == 0)&&(result == 0)&&(num == \at(num,Pre)));
      loop invariant sum == \at(num,Pre);
      loop invariant end == 0;
      loop invariant num == \at(num,Pre);
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
