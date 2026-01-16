/*@
requires k >= 0 && k <= 30;
*/
int main15(int k){
   
    int y=0;
    int x=0;
    int c=0;
  

    // loop body
    /*@
    loop invariant 0 <= c <= k;
    loop invariant y == c;
    loop invariant x == c * (c + 1) / 2;
    loop assigns c, y, x;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y + x;
    }

    // @ assert 2 * x - k * k - k == 0;
}


