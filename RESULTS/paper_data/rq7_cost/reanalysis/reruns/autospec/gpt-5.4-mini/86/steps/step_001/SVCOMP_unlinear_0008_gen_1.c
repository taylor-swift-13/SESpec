int main16(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant 0 <= c <= k;
    loop invariant x >= 0;
    loop invariant y == c;
    loop invariant x == y * y + x - (c - y);
    loop assigns c;
    loop assigns y;
    loop assigns x;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}
