
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer max_divisible_by_3(integer n) =
    n == 0 ? 0 : (n % 3 == 0 ? max_divisible_by_3(n / 3) : n);
*/

int foo74(int n) {

    int temp = n;

    /*@
      loop invariant (!(\at(n,Pre) != 0 && \at(n,Pre) % 3 == 0)) ==> ((temp == \at(n,Pre)) && (n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns temp;
    */
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }

    return temp == 1;
}
