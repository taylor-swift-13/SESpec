/*@
    requires k >= 0;
    ensures \true;
*/
int main19(int k){

    int y = 0;
    int x = 0;
    int c = 0;

    /*@
        loop invariant 0 <= c <= k;
        loop invariant y == c;
        loop invariant x == \sum(0, c-1, \lambda integer i; (i+1)*(i+1)*(i+1)*(i+1)*(i+1));
        loop assigns c, y, x;
        loop variant k - c;
    */
    while(c < k){
        c = c + 1;
        y = y + 1;
        x = y * y * y * y * y + x;
    }
}
