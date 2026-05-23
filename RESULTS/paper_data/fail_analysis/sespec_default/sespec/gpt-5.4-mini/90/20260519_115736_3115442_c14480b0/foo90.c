
/*@ logic integer q_value(integer x, integer y, integer q, integer r) = q; */
/*@ logic integer r_value(integer x, integer y, integer q, integer r) = r; */

void foo90(int x,int y){

  int q=0;
  int r=0;

  /*@
    loop invariant y == \at(y,Pre);
    loop invariant x == \at(x,Pre);
    loop invariant q >= 0;
    loop invariant r >= 0;
    loop invariant r < y || y <= 0;
    loop invariant (r == 0 && q == 0) || q > 0 || r > 0;
    loop assigns r, q;
  */
  while(x > y * q + r) {
      if (r == y - 1){
          r = 0;
          q += 1;
      }
      else{
          r += 1;
      }

  }
}
