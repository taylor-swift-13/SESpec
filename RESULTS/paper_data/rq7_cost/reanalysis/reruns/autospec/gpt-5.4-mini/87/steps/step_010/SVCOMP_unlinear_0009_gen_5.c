int main17(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant 0 <= c <= k;
    loop invariant c == y;
    loop invariant y == c;
    loop invariant x >= 0;
    loop invariant x >= c * c * c;
    loop invariant x >= y * y * y;
    loop invariant x == 0 || x >= c * c * c;
    loop invariant x == 0 || x >= y * y * y;
    loop invariant y*y*y <= x;
    loop invariant y == c;
    loop invariant y == c && 0 <= c;
    loop invariant y <= x;
    loop invariant y <= k;
    loop invariant y <= k || y * y * y <= x;
    loop invariant y <= k || c <= x;
    loop invariant y < k;
    loop invariant y - c == 0;
    loop invariant y * y * y <= x;
    loop invariant y * y * y <= x || c <= x;
    loop invariant y * y * y < x;
    loop invariant x >= 0 || c <= k;
    loop invariant x == y*y*y;
    loop invariant x == y*y*y - y;
    loop invariant x == y*y*y + x;
    loop invariant x == y*y*y * (c > 0);
    loop invariant x == y * y * y;
    loop invariant x == y * y * y || x > y * y * y;
    loop invariant x == y * y * y + x;
    loop invariant x == y * y * y + x - y * y * y;
    loop invariant x == y * y * y + x - (y * y * y);
    loop invariant x == y * y * y * c;
    loop invariant x == y * y * y * (c > 0);
    loop invariant x == c * c * c;
    loop invariant x == 0 || x >= y * y * y;
    loop invariant x == 0 || x >= c * c * c;
    loop invariant x == (y * y * y) + x - (y * y * y);
    loop invariant x == (y * y * y) * c;
    loop invariant c*c*c <= x;
    loop invariant c == y;
    loop invariant c <= y;
    loop invariant c <= x;
    loop invariant c <= k;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c < x;
    loop invariant c - y == 0;
    loop invariant c * c * c <= x;
    loop invariant c * c * c <= x || y <= k;
    loop invariant c * c * c <= x || y * y * y <= x;
    loop invariant c * c * c <= x || c <= x;
    loop invariant c * c * c < x;
    loop invariant 0 <= y;
    loop invariant 0 <= y == c;
    loop invariant 0 <= x;
    loop invariant 0 <= x - c*c*c;
    loop invariant 0 <= x - c * c * c;
    loop invariant 0 <= k - c;
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
