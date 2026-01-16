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
 Looking at this problem, I need to generate loop invariants for the `while (x > r)` loop that will help prove the postcondition `(r-1) * (r-1) <= a`.
 
 Let me analyze what happens in the loop:
 - Initially: `r = 0`, `x = a / 2`
 - Each iteration: `x = x - r`, `r = r + 1`
 - Loop continues while `x > r`
 - After loop: need to prove `(r-1) * (r-1) <= a`
 
 The key relationships to maintain:
 
 ```c
 loop invariant r >= 0;
 loop invariant x >= 0;
 loop invariant 2 * x + r * r == a;
 loop invariant x >= r ==> 2 * x + r * r == a;
 loop assigns x;
 loop assigns r;
 ```
 */
 while (x > r){
     x = x - r;
     r = r + 1;
 }
  // post-condition
  /*@ assert (r-1) * (r-1) <= a; */
}
