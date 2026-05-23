
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer max_divisible_by_3(integer n) =
    n == 0 ? 0 : (n % 3 == 0 ? 1 + max_divisible_by_3(n / 3) : 0);
*/

/*@
  requires n == \at(n,Pre);
  assigns \nothing;
*/
int foo74(int n) {

    int temp = n;

    /*@
      loop assigns temp;
      loop variant temp;
    */
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }

    return temp == 1;
}
