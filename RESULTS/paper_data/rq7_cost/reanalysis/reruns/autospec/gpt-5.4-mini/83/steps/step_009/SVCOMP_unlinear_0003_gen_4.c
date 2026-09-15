int main11(int z,int k,int a){
/*@
    requires k >= 1;
    assigns \nothing;
*/
    int x=a;
    int y=1;
    int c=1;

/*@
    loop invariant 1 <= c <= k;
    loop invariant \true;
    loop assigns c, x, y;
    loop variant k - c;
*/
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }
