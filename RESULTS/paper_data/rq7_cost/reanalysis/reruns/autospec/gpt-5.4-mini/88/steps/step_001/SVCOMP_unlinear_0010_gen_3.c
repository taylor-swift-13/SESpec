int main18(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant 0 <= c <= k;
    loop invariant x >= 0;
    loop invariant y == c;
    loop invariant x == \sum(integer t = 1, c, t*t*t*t);
    loop assigns c;
    loop assigns x;
    loop assigns y;
    */
    while(c < k){
     c = c +1 ;
     y = y +1;
     x = y*y*y*y+x;
    }

}
