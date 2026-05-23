/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
void foo228() {

    int x;
    int y;

    x = 0;

    /*@ 
        loop invariant 0 <= x <= 100;
        loop assigns x;
        loop variant 99 - x;
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
