int main2(int x,int y){

  int q=0;
  int r=0;

  /*@
  loop invariant y * q + r <= x;
  loop invariant 0 <= r < y;
  loop invariant 0 <= q;
  loop invariant y * q + r >= 0;
  loop invariant r <= x;
  loop invariant q * y + r < x || y * q + r == x;
  loop invariant y * q + r <= x;
  loop invariant y * q + r < x;
  loop invariant x > y * q + r ==> (r < y - 1 || q >= 0);
  loop invariant r <= y - 1;
  loop invariant r < y;
  loop invariant q + r <= x;
  loop invariant 0 <= r;
  loop invariant 0 <= q;
  loop invariant 0 <= q * y + r;
  loop assigns r;
  loop assigns q;
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
