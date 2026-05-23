int main2(int x,int y){

  int q=0;
  int r=0;

  /*@
      loop invariant y > 0;
      loop invariant q >= 0;
      loop invariant 0 <= r && r < y;
      loop invariant y*q + r <= x;
      loop assigns q, r;
      loop variant x - (y*q + r);
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
