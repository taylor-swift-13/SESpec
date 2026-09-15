
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures n <= 0 ==> \result == 0;
  ensures n > 0 ==> (\result == 1 <==> is_power_of_two(\old(n)));
  ensures n > 0 ==> (\result == 0 <==> !is_power_of_two(\old(n)));
*/
int foo77(int n) {

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop assigns n;
      loop variant n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
