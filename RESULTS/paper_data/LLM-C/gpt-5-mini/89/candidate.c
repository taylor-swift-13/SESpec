/*@
    requires k >= 0;
    assigns \nothing;
    ensures \true;
*/
int main19(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
        loop invariant 0 <= c && c <= k;
        loop invariant y == c;
        loop invariant x == (\sum integer i; 1 <= i <= c; i*i*i*i*i);
        loop assigns c, y, x;
        loop variant k - c;
    */
    while(c < k){
     c = c + 1 ;
     y = y + 1;
     x=y*y*y*y*y+x;
    }

}
