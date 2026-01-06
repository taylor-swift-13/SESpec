
/*@
    requires i >= 0;
*/
void foo194(int i) {
    int x;
    int y;
    int z;

    x = i;
    y = i;
    z = 0;

    /*@
      loop invariant (\at(i,Pre) != 0) ==> (x == \at(i,Pre) - z);
      loop invariant (\at(i,Pre) != 0) ==> (y == \at(i,Pre) - 2*z);
      loop invariant (\at(i,Pre) != 0) ==> (z >= 0 && z <= \at(i,Pre));
      loop invariant (!(\at(i,Pre) != 0)) ==> ((z == 0)&&(y == \at(i,Pre))&&(x == \at(i,Pre))&&(i == \at(i,Pre)));
      loop invariant i == \at(i,Pre);
      loop assigns x, y, z;
    */
    while(x != 0) {
       x = x - 1;
       y = y - 2;
       z = z + 1;
    }

    /*@ assert y == 0 - z; */
}
