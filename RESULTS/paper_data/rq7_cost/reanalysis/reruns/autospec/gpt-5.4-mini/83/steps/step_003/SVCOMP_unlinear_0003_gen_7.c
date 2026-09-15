/*@
  requires k >= 1;
  assigns \nothing;
*/
int main11(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
      loop invariant 1 <= c <= k;
      loop invariant x == a * y + a * (c - 1);
      loop invariant y == (c == 1 ? 1 : y);
      loop assigns c, x, y;
    */
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }