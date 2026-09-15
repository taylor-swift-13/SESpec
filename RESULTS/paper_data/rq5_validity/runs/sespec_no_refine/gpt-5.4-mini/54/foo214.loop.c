
/*@ 
  logic integer undef_data_at(integer *p) = \true ? 0 : 0;
*/

void foo214() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant 0 <= x <= 99;
      loop invariant x % 1 == 0;
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
