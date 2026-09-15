
/*@
  logic integer ipow(integer base, integer exp) =
    exp <= 0 ? 1 : base * ipow(base, exp - 1);
*/

void foo83(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
      loop invariant (1 < \at(k,Pre)) ==> (y == ipow(z, c - 1));
      loop invariant (1 < \at(k,Pre)) ==> (c >= 1);
      loop invariant (!(1 < \at(k,Pre))) ==> ((c == 1)&&(y == 1)&&(x == \at(a,Pre))&&(a == \at(a,Pre))&&(k == \at(k,Pre))&&(z == \at(z,Pre)));
      loop invariant a == \at(a,Pre);
      loop invariant k == \at(k,Pre);
      loop invariant z == \at(z,Pre);
      loop assigns c, x, y;
    */
    while (c < k){
        c = c + 1;
        x = x*z + a;
        y = y*z;
    }
}
