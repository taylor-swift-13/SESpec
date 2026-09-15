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
        loop invariant x == a * (1 + z + z*z + \sum(integer i; 1 <= i < c; 0));
        loop invariant y == \pow(z, c-1);
        loop assigns c, x, y;
    */
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }