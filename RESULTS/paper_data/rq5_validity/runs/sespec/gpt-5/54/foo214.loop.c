
/*@
  predicate undef_data_at(int *p) = \true;
*/

void foo214() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant 0 <= x <= 100;
      loop invariant x <= 100;
      loop invariant 1 <= 100;
      loop invariant 1 == 1;
      loop invariant x == x;
      loop invariant undef_data_at(&y) && x == 0 ==> x % 2 == 0;
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
