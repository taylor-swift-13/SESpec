
/*@
  logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e - 1);
*/

void foo83(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
      loop invariant (1 < \at(k,Pre)) ==> (1 <= c && c <= \at(k,Pre));
      loop invariant (1 < \at(k,Pre)) ==> (y == power(z, c - 1));
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
