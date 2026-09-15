
int foo394(int k){

    int y=0;
    int x=0;
    int c=0;

    /*@
      loop invariant k == \at(k,Pre);
      loop invariant y == c;
      loop assigns c, y, x;
    */
    while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}
