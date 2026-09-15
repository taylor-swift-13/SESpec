int main2(int x,int y){

  int q=0;
  int r=0;

  /*@
  loop invariant y * q + r <= x;
  loop invariant 0 <= r;
  loop invariant 0 <= q;
  loop invariant r < y;
  loop assigns q;
  loop assigns r;
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
