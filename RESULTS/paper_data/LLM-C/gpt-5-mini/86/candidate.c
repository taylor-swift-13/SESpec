/*@
    requires k >= 0;
    assigns \nothing;
    ensures \true;
*/
int main16(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
        loop invariant 0 <= c <= k;
        loop invariant y == c;
        loop invariant x == \sum integer i=1..c; i*i;
        loop assigns c, y, x;
        loop variant k - c;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}
