
/*@
  logic integer power_of_two(integer base, integer exp) =
    exp <= 0 ? base : 2 * power_of_two(base, exp - 1);
*/

/*@
  logic integer sum_of_powers(integer base, integer exp) =
    exp <= 0 ? 0 : power_of_two(base, exp - 1) + sum_of_powers(base, exp - 1);
*/

/*@
  requires \true;
  assigns z, y, x;
  ensures \result == a * b;
  ensures z == a * b;
*/
int foo392(int a, int b) {
    int x = a;
    int y = b;
    int z = 0;

    /*@
      loop invariant z + y * x == a * b;
      loop invariant b == \at(b, Pre);
      loop invariant a == \at(a, Pre);
      loop assigns z, y, x;
      loop variant y;
    */
    while (y != 0) {
        if (y % 2 == 1) {
            z = z + x;
            y = y - 1;
        }
        x = 2 * x;
        y = y / 2;
    }
    return z;
}
