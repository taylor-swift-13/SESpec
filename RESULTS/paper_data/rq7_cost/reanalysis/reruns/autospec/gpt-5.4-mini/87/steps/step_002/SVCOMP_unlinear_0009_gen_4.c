int main17(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant 0 <= c <= k;
    loop invariant y == c;
    loop invariant x >= 0;
    loop invariant x == y * y * y + x - y * y * y;
    loop invariant c == y;
    loop invariant k - c >= 0;
    loop invariant y == c;
    loop invariant x == y*y*y - y;
    loop invariant x == y*y*y + x;
    loop invariant x == y*y*y * (c > 0);
    loop invariant x == y * y * y + x;
    loop invariant x == y * y * y * c;
    loop invariant x == c * c * c;
    loop invariant x == (y * y * y) + x - (y * y * y);
    loop invariant c <= k;
    loop invariant 0 <= x;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;
    */
    while(c < k){
     c = c +1 ;
     y = y +1;
     x=y*y*y+x;
    }

}
