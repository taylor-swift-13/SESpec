/*@
    requires k >= 1;
    assigns \nothing;
*/
int main10(int z,int k){

    int x=1;
    int y=1;
    int c=1;

    /*@
        loop invariant 1 <= c <= k;
        loop invariant y >= 1;
        loop assigns c, x, y;
        loop variant k - c;
    */
    while (c < k){
   c = c + 1;
   x = x*z + 1;
   y = y*z;
    }

  }
