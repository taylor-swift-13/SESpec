/*@
    requires \true;
    assigns \nothing;
*/
int main11(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
        loop invariant 1 <= c <= k || k < 1;
        loop invariant x == a * (1 + z + (c - 2) * z) || c == 1;
        loop invariant y == 1 || c == 1;
        loop assigns c, x, y;
        loop variant k - c;
    */
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }