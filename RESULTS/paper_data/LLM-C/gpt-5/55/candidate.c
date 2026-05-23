/*@ 
  requires \true;
  assigns \nothing;
  ensures x >= 2;
  ensures x >= y;
*/
void foo232(unsigned int y) {

    unsigned int x;

    x = 2;

    /*@
      loop invariant x >= 2;
      loop assigns x;
      loop variant y - x;
    */
    while (x < y) {
       /*@ assert x < y / x ==> x * x < y; */
       if (x < y / x) {
       x *= x;
      }
       else {
       x++;
      }
      }

  }
