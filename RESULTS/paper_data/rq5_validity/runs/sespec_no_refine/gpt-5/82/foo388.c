
/*@
  logic integer ipow(integer base, integer exp) =
    (exp <= 0) ? 1 : base * ipow(base, exp - 1);
*/

/*@
  requires \true;
*/
void foo388(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
      loop invariant (1 < \at(k,Pre)) ==> (y == ipow(\at(z,Pre), c - 1));
      loop invariant (1 < \at(k,Pre)) ==> (c >= 1);
      loop invariant (!(1 < \at(k,Pre))) ==> ((c == 1)&&(y == 1)&&(x == 1)&&(k == \at(k,Pre))&&(z == \at(z,Pre)));
      loop invariant k == \at(k,Pre);
      loop invariant z == \at(z,Pre);
      loop assigns c, x, y;
    */
    while (c < k){
        c = c + 1;
        x = x*z + 1;
        y = y*z;
    }
}
