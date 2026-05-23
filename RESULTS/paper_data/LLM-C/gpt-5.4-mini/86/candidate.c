/*@
    requires k >= 0;
    assigns \nothing;
    ensures y == 0;
*/
int main16(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
        loop invariant 0 <= c <= k;
        loop invariant y == c;
        loop invariant x == c * (c + 1) * (2 * c + 1) / 6;
        loop assigns c, y, x;
        loop variant k - c;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}
