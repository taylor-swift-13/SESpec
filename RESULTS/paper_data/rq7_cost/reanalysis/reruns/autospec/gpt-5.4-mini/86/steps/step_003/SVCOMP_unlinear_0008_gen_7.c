int main16(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant y == c;
    loop invariant 0 <= c <= k;
    loop invariant 0 <= y <= k;
    loop invariant x >= 0;
    loop invariant x >= y;
    loop invariant c - y == 0;
    loop invariant x - y * y >= 0;
    loop invariant y == c;
    loop invariant y <= x;
    loop invariant y <= k;
    loop invariant y <= c;
    loop invariant y * y <= x;
    loop invariant x == y * y;
    loop invariant x == y * y + x - (c - y);
    loop invariant x == c * c;
    loop invariant x == c * c || x == y * y;
    loop invariant x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1));
    loop invariant x == 0 || x > 0;
    loop invariant x - y == c;
    loop invariant c == y;
    loop invariant c <= x;
    loop invariant c <= k;
    loop invariant c <= k || y <= k;
    loop invariant c - y == 0;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop invariant 0 <= x - y * y;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}
