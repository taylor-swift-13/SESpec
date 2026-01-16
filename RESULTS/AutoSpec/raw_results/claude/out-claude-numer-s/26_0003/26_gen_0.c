/*@
  requires a % 2 == 0;
  requires a > 0;
*/
int hoo26(int a) {
    // variable declarations
    int x = a / 2;
    int r = 0;

    // loop body
   /*@
   loop invariant x >= 0;
   loop invariant r >= 0;
   loop invariant (x + r*r) == a / 2;
   loop invariant (r * r) <= a;
   loop invariant x + r * r == a / 2;
   loop invariant r * r <= a;
   loop assigns x, r;
   */
   while (x > r){
       x = x - r;
       r = r + 1;
   }
    // post-condition
    /*@ assert (r+1) * (r+1) >= a; */
}
