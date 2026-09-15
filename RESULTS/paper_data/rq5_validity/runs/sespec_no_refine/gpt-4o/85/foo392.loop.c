
/*@
  logic integer power_of_two(integer base, integer exp) =
    exp <= 0 ? base : 2 * power_of_two(base, exp - 1);
*/

/*@
  logic integer sum_of_powers(integer base, integer exp) =
    exp <= 0 ? 0 : power_of_two(base, exp - 1) + sum_of_powers(base, exp - 1);
*/

/*@
  logic integer binary_representation_sum(integer base, integer exp, integer z) =
    z == sum_of_powers(base, exp);
*/

int foo392(int a, int b) {
    int x = a;
    int y = b;
    int z = 0;

    /*@
      loop invariant (\at(b,Pre) != 0) ==> (z + y * x == \at(a,Pre) * \at(b,Pre));
      loop invariant (\at(b,Pre) != 0) ==> (binary_representation_sum);
      loop invariant (\at(b,Pre) != 0) ==> (binary_representation_sum);
      loop invariant (!(\at(b,Pre) != 0)) ==> ((z == 0) && (y == \at(b,Pre)) && (x == \at(a,Pre)) && (b == \at(b,Pre)) && (a == \at(a,Pre)));
      loop invariant b == \at(b,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns z, y, x;
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
