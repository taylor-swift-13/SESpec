/*@ 
  requires y > 0;
  assigns \nothing;
*/
int main2(int x,int y){

  int q=0;
  int r=0;

  /*@
    loop invariant q >= 0;
    loop invariant 0 <= r <= y-1;
    loop invariant x > y*q + r;
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
