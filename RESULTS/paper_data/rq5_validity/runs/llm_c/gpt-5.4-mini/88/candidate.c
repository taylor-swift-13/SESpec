/*@
    requires k >= 0;
    ensures y == 0;
    ensures x == 0;
    ensures c == 0;
*/
int main18(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
        loop invariant 0 <= c <= k;
        loop invariant y == c;
        loop invariant x == (\sum integer i; 0 <= i < c; (i+1)*(i+1)*(i+1)*(i+1));
        loop assigns c, y, x;
        loop variant k - c;
    */
    while(c < k){
     c = c +1 ;
     y = y +1;
     x = y*y*y*y+x;
    }

}
