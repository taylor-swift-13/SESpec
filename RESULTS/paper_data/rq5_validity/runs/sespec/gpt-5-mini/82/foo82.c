
/*@ 
  logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e - 1);
*/

/*@
  requires k >= 1;
  requires z >= 0;
*/
void foo82(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
      loop invariant 1 <= c <= k;
      loop invariant 0 <= x;
      loop invariant 0 <= y;

      loop invariant y == power((integer)z, (integer)(c - 1));

      loop invariant \forall integer i; 1 <= i && i < c ==> power((integer)z, (integer)(i - 1)) >= 0;
      loop invariant x >= 1;

      loop invariant (1 < \at(k,Pre)) ==> (c <= \at(k,Pre));
      loop invariant (1 < \at(k,Pre)) ==> (y == power((integer)\at(z,Pre), (integer)(c - 1)));
      loop invariant (1 < \at(k,Pre)) ==> (c >= 1);

      loop invariant (!(1 < \at(k,Pre))) ==> ((c == 1) && (y == 1) && (x == 1) && (k == \at(k,Pre)) && (z == \at(z,Pre)));
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
