
/*@
logic integer pow(integer b, integer e) = (e == 0 ? 1 : b * pow(b, e - 1));
logic integer geom(integer b, integer e) = (e == 0 ? 1 : geom(b, e - 1) * b + 1);
*/

void foo82(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant c >= 1;
      loop invariant x == geom(z, c - 1);
      loop invariant y == pow(z, c - 1);
      loop assigns c, x, y;
    */
    while (c < k){
        c = c + 1;
        x = x*z + 1;
        y = y*z;
    }
}
