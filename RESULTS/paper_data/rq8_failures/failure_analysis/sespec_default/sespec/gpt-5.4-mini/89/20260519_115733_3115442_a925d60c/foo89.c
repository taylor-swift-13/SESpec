
void foo89(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant k == \at(k,Pre);
      loop invariant c == y;
      loop assigns c, y, x;
    */
    while(c < k){
        c = c + 1 ;
        y = y + 1;
        x = y*y*y*y*y+x;
    }
}
