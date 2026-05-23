
/*@ 
  logic integer powi(integer z, integer n) =
    (n <= 0) ? 1 : z * powi(z, n - 1);

  logic integer sum_geo(integer z, integer n) =
    (n <= 0) ? 0 : sum_geo(z, n - 1) + powi(z, n - 1);
*/

/*@
  requires \true;
*/
void foo389(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
      loop invariant (1 < \at(k,Pre)) ==> (y == powi(\at(z,Pre), c - 1)) ;
      loop invariant (1 < \at(k,Pre)) ==> (1 <= c && c <= \at(k,Pre)) ;
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
