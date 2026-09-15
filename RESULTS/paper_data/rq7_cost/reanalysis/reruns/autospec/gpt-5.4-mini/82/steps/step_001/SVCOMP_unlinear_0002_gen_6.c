/*@
    requires k >= 0;
    assigns \nothing;
*/
int main10(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
        loop invariant 1 <= c <= k + 1;
        loop invariant x == (c == 1 ? 1 : x);
        loop invariant y == (c == 1 ? 1 : y);
        loop assigns c, x, y;
        loop variant k - c;
    */
    while (c < k){
   c = c + 1;
   x = x*z + 1;
   y = y*z;
    }

  }