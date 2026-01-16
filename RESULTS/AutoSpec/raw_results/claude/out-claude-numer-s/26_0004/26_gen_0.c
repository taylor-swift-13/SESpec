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
   loop invariant 0 <= r <= a/2;
   loop invariant x >= 0;
   loop invariant x == a/2 - (r*(r-1))/2;
   loop invariant x > r;
   loop assigns x, r;
   */
   while (x > r){
       x = x - r;
       r = r + 1;
   }
    // post-condition
    /*@ assert (r+1) * (r+1) >= a; */
}
