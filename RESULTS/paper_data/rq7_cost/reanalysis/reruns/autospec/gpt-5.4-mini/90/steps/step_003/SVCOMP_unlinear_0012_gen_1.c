int main2(int x,int y){

  int q=0;
  int r=0;

  /*@
  loop invariant y > 0 ==> r < y;
  loop invariant y * q <= x;
  loop invariant y * q + r <= x;
  loop invariant x > y * q + r || x == y * q + r;
  loop invariant x > y * q + r ==> (r < y - 1 || q >= 0);
  loop invariant r <= y - 1;
  loop invariant r <= x;
  loop invariant q + r <= x;
  loop invariant 0 <= x - (y * q + r);
  loop invariant 0 <= q * y + r;
  loop invariant (r == y - 1) ==> q >= 0;
  loop invariant \exists integer t; 0 <= t <= q ==> y * t <= x;
  loop invariant y > 0 ==> r < y;
  loop invariant y * q <= x;
  loop invariant y * q + r <= x;
  loop invariant y * q + r < x;
  loop invariant x > y * q + r || x == y * q + r;
  loop invariant x > y * q + r ==> r < y;
  loop invariant x > y * q + r ==> (r < y - 1 || q >= 0);
  loop invariant r == y - 1 ==> y * q + r < x;
  loop invariant r <= y - 1;
  loop invariant r <= x;
  loop invariant r < y;
  loop invariant q + r <= x;
  loop invariant q * y + r <= x;
  loop invariant q * y + r < x || y * q + r == x;
  loop invariant 0 <= y * q + r;
  loop invariant 0 <= x - (y * q + r);
  loop invariant 0 <= r;
  loop invariant 0 <= q;
  loop invariant 0 <= q * y + r;
  loop invariant (r == y - 1) ==> q >= 0;
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
