
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures n <= 0 ==> \result == 0;
  ensures n > 0 ==> (\result == 1 <==> is_power_of_4(\old(n)));
*/
int foo73(int n) {

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop assigns n;
      loop variant n;
    */
    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}
