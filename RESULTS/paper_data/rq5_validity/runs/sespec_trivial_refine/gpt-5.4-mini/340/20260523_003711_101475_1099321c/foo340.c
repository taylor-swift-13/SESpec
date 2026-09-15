
/*@ axiomatic Foo340Count {
    logic integer foo340_count(integer n, integer z);

    axiom foo340_count_base:
      \forall integer n, z; z <= 0 ==> foo340_count(n, z) == 0;

    axiom foo340_count_step:
      \forall integer n, z; z > 0 ==>
        foo340_count(n, z) == foo340_count(n, z - 1) + ((n % z) == 0 ? 1 : 0);
  }
*/

/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
  ensures \old(z) < 0 ==> \result == foo340_count(n, -\old(z));
  ensures \old(z) >= 0 ==> \result == foo340_count(n, \old(z));
*/
int foo340(int n, int z) {
    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant 0 <= result;
      loop invariant result <= loop - 1;
      loop assigns result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
