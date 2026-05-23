
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer initial_num(integer num, integer c, integer r) =
    num * power(10, r) + c * (power(10, r) - 1) / 9;
*/

/*@
  logic integer initial_r(integer r) = r;
*/

/*@
  logic integer initial_c(integer c) = c;
*/

/*@
  logic integer initial_result(integer result) = result;
*/

/*@
  logic integer compute_result(integer num, integer c, integer r) =
    (num * power(10, r)) / c;
*/

/*@
  requires c != 0; // Division by zero is undefined
  requires r >= 0; // r must be non-negative to ensure loop termination
  assigns \nothing; // The function does not modify any global state
*/
int foo304(int num, int c, int r) {

    int result = 0;

    /*@
      loop invariant (\at(r,Pre) > 0) ==> (r == \at(r,Pre) - (\at(r,Pre) - r));
      loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
      loop invariant c == \at(c,Pre);
      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / c;
        num %= c;
    }

    return result;
}
