
/*@
  logic integer bitwise_or_shifted(int number, integer ret) = 
    (\sum integer i; 0 <= i < ret && i % 2 == 0; (1 << i));
*/

/*@
  logic integer compute_result(int number, integer ret) = 
    bitwise_or_shifted(number, ret);
*/

/*@
  ensures \result == (\at(number,Pre) ^ compute_result(\at(number,Pre), compute_ret(\at(number,Pre), \at(number,Pre))));
  assigns \nothing;
*/
int foo215(int number) {

    int result = 0;
    int ret = 0;
    int total = number;

    /*@
      loop invariant (\at(number,Pre) > 0) ==> (result == compute_result(\at(number,Pre), ret));
      loop invariant (\at(number,Pre) > 0) ==> (ret == compute_ret(\at(number,Pre), total));
      loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(result == 0)&&(number == \at(number,Pre)));
      loop invariant total == \at(number,Pre);
      loop invariant number == \at(number,Pre);
      loop assigns result, total, ret;
    */
    while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }

    return number ^ result;
}
