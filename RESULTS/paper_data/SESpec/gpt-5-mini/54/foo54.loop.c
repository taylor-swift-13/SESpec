
/*@ 
  // No top-level logic/predicate definitions are required.
*/
        
void foo54() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant 0 <= x && x <= 101;
      loop invariant x >= 0;
      loop invariant \exists integer a, b; 0 <= a && 0 <= b && x == a + 2*b;
      loop invariant \forall integer k; 0 <= k < x ==> k >= 0;
      loop invariant x < 99 || x >= 99;
      loop invariant x == 0 || x > 0;
      loop assigns x;
    */
    while (x < 99) {
       if(y % 2 == 0){
         x = x + 2;
       }
       else{
         x = x + 1;
       }
    }
}
