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
 ```c;
 ```;
 The key insight is that `x + r*(r-1)/2` remains related to `a/2`, and we need invariants to prove the final assertion.;
 Looking at this problem, I need to generate loop invariants for the while loop that will help prove the postcondition `(r-1) * (r-1) <= a`.;
 Let me analyze what the loop does:;
 - The loop maintains a relationship between `x`, `r`, and `a`;
 - Loop: decreases `x` by `r`, increases `r` by 1;
 - Initial: `r = 0`, `x = a / 2`;
 */
 while (x > r){
     x = x - r;
     r = r + 1;
 }
  // post-condition
  /*@ assert (r-1) * (r-1) <= a; */
}
