
/*@ predicate undef_data_at(int *p) = \true; */

/*@
  predicate REL_XA(int xa, int x, int y) = xa == x - 2*y;
  predicate REL_YA(int ya, int x, int y) = ya == 2*x + y;
*/

void foo124() {

    int x;
    int y;
    int xa;
    int ya;

    xa = 0;
    ya = 0;

    /*@
      loop invariant  ((ya == 0)&&(xa == 0)) || (REL_XA(xa, x, y)) ;
      loop invariant  ((ya == 0)&&(xa == 0)) || (REL_YA(ya, x, y)) ;
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
