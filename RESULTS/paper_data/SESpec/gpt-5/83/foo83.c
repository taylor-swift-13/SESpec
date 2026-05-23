
/*@
  logic integer ipow(integer z, integer n) =
    n <= 0 ? 1 : z * ipow(z, n - 1);

  logic integer geom_sum(integer z, integer n) =
    n <= 0 ? 0 : geom_sum(z, n - 1) * z + 1;
*/

void foo83(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
      loop invariant geom_sum(z, c) == (c <= 0 ? 0 : geom_sum(z, c - 1) * z + 1);
      loop invariant ipow(z, c - 1) == ((c - 1) <= 0 ? 1 : z * ipow(z, (c - 1) - 1));
      loop invariant (c == 1) ==> (x == a && y == 1);
      loop invariant (c > 1) ==> (y == ipow(z, c - 2) * z);
      loop invariant (1 < \at(k,Pre)) ==> ( (c == 1) ==> (x == a && y == 1) );
      loop invariant (1 < \at(k,Pre)) ==> ( y == ipow(z, c - 1) );
      loop invariant (1 < \at(k,Pre)) ==> ( 1 <= c && c <= \at(k,Pre) );
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
