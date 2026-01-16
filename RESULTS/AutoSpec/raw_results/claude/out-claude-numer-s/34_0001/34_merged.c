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
 loop invariant r*r <= a;
 loop invariant r <= x;
 loop invariant 2*x + r*(r-1) == a;
 loop invariant 0 <= r;
 loop assigns x;
 loop assigns r;
 */
 while (x > r){
     x = x - r;
     r = r + 1;
 }
  // post-condition
  /*@ assert (r-1) * (r-1) <= a; */
}
