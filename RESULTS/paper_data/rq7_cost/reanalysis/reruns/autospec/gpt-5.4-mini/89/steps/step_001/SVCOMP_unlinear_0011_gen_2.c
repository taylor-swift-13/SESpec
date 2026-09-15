int main19(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
    loop invariant 0 <= c <= k;
    loop invariant x >= 0;
    loop invariant y == c;
    loop invariant x == \sum(0, c-1, \lambda integer t; (t+1)*(t+1)*(t+1)*(t+1)*(t+1));
    loop assigns c;
    loop assigns x;
    loop assigns y;
    */
    while(c < k){
     c = c + 1 ;
     y = y + 1;
     x=y*y*y*y*y+x;
    }

}
