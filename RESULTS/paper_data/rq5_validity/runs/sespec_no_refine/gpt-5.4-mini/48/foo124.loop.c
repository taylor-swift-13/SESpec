
/*@
  predicate undef_data_at{L}(int *p) = \true;
*/

void foo124() {

    int x;
    int y;
    int xa;
    int ya;

    xa = 0;
    ya = 0;

    /*@
      loop invariant ya == 0;
      loop assigns x, y, xa, ya;
    */
    while(unknown()){
       x = xa + ya * 2 + 1;
       if(unknown()){
       y = ya - xa * 2 + x;
      }
       else{
       y = ya - xa * 2 - x;
      }
       xa = x - y * 2;
       ya = x * 2 + y;
    }

  }
