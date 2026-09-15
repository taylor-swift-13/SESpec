int main18(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant 0 <= c <= k;
    loop invariant y == c;
    loop invariant x >= 0;
    loop invariant x >= y;
    loop invariant x - y*y*y*y >= - (y*y*y*y);
    loop invariant x == \sum(integer i, 1, c, i*i*i*i);
    loop invariant y == c;
    loop invariant y <= x;
    loop invariant y <= k;
    loop invariant x == y*y*y*y - y + 1;
    loop invariant x == y*y*y*y + x;
    loop invariant x == y*y*y*y + (x - y*y*y*y);
    loop invariant x == y*y*y*y + (c*(c-1)*(2*c-1)*(3*c-2))/?;
    loop invariant x == y * y * y * y + x - y * y * y * y;
    loop invariant x == y * y * y * y * c;
    loop invariant x == y * y * y * y * c / 4;
    loop invariant x == \sum(integer t = 1, c, t*t*t*t);
    loop invariant x == \sum(integer i, 1, c, i*i*i*i);
    loop invariant x == \sum(integer i, 0, c-1, (i+1)*(i+1)*(i+1)*(i+1));
    loop invariant x == (y * y * y * y) + x - (c * c);
    loop invariant c <= x;
    loop invariant c <= k;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop invariant 0 <= x - y*y*y*y;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;
    */
    while(c < k){
     c = c +1 ;
     y = y +1;
     x = y*y*y*y+x;
    }

}
