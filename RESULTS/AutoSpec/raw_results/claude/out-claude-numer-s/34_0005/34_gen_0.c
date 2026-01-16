//freire1.c
/*@
  requires a % 2 == 0;
  requires a > 0;
*/
int hoo34(int a){
  // variable declarations
 int x, r;
  //precondition
 r = 0;
 x = a / 2;

  // loop body
 /*@
 loop invariant x >= 0;
 loop invariant r >= 0;
 loop invariant (r-1)*(r-1) <= a;
 loop invariant x + (r*(r-1))/2 == a/2;
 loop assigns x, r;
 */
 while (x > r){
     x = x - r;
     r = r + 1;
 }
  // post-condition
  /*@ assert (r-1) * (r-1) <= a; */
}
