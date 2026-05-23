
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
  logic integer initial_result() = 0;
*/

/*@
  logic integer compute_result(integer num, integer b, integer r) =
    (initial_num(num, b, r) / b);
*/

/*@
  logic integer compute_remainder(integer num, integer b, integer r) =
    (initial_num(num, b, r) % b);
*/

/*@
  logic integer compute_r(integer r) = r - 1;
*/

/*@
  logic integer compute_num(integer num, integer b, integer r) =
    compute_remainder(num, b, r);
*/

/*@
  logic integer compute_result(integer num, integer b, integer r) =
    compute_result(num,b,r);
