/*@
    requires k >= 0;
    assigns \nothing;
    ensures \true;
*/
int main18(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
        loop invariant 0 <= c <= k;
        loop invariant y == c;
        loop invariant x == \sum integer j; 1 <= j <= c; j*j*j*j;
        loop assigns c, y, x;
        loop variant k - c;
    */
    while(c < k){
     c = c +1 ;
     y = y +1;
     x = y*y*y*y+x;
    }

}
