
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer initial_num(integer num, integer b, integer r) =
    num * power(10, r);
*/

/*@
  logic integer initial_r(integer r) = r;
*/

/*@
  logic integer initial_b(integer b) = b;
*/

/*@
  logic integer result_at_iteration(integer num, integer b, integer r, integer initial_num) =
    (initial_num / power(10, r)) / b;
*/

/*@
  logic integer num_at_iteration(integer num, integer b, integer r, integer initial_num) =
    (initial_num / power(10, r)) % b;
*/

int foo302(int num, int b, int r) {

    int result = 0;

    /*@
      loop invariant (\at(r,Pre) > 0) ==> (r == initial_r(\at(r,Pre)) - (\at(r,Pre) - r));
      loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(b == \at(b,Pre))&&(num == \at(num,Pre)));
      loop invariant b == \at(b,Pre);
      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / b;
        num %= b;
    }

    return result;
}
