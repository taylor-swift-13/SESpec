/*@
    requires \true;
    assigns \nothing;
*/
int main11(int z,int k,int a){

    int x=a;
    int y=1;
    int c=1;

    /*@
        loop invariant 1 <= c <= k + 1;
        loop invariant x == a * (1 + \sum(integer i; 0 <= i < c-1; \pow(z, i)));
        loop invariant y == \pow(z, c-1);
        loop assigns c, x, y;
    */
    while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }