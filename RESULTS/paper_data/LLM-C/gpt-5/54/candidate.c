/*@ 
  assigns \nothing;
*/
void foo228() {

    int x;
    int y;

    x = 0;

    /*@ 
      loop invariant 0 <= x <= 100;
      loop invariant (y % 2 == 0) ==> (x % 2 == 0);
      loop assigns x;
      loop variant 100 - x;
    */
    while (x < 99) {
       if(y % 2 == 0){
       x = x + 2;
      }
       else{
       x = x + 1;
      }
      }

    /*@ assert (x == 100 && y % 2 == 0) || (x == 99 && y % 2 != 0); */
    /*@ assert 99 <= x <= 100; */
  }
