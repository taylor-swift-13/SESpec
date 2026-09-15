
/*@ logic integer ipow(integer a, integer n) =
      n <= 0 ? 1 : a * ipow(a, n - 1);
*/

int foo388(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
      loop invariant (1 < \at(k,Pre)) ==> (c >= 1);
      loop invariant (1 < \at(k,Pre)) ==> (k == \at(k,Pre));
      loop invariant (1 < \at(k,Pre)) ==> (z == \at(z,Pre));
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
