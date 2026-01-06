
void foo95(int x) {
    int i =0;
    int j =0;
    int y =1;
    
    /*@
      loop invariant (0 <= \at(x,Pre)) ==> (i <= x + 1 && j == i * y);
      loop invariant (0 <= \at(x,Pre)) ==> (j == i * y);
      loop invariant (!(0 <= \at(x,Pre))) ==> ((y == 1)&&(j == 0)&&(i == 0)&&(x == \at(x,Pre)));
      loop invariant y == 1;
      loop invariant x == \at(x,Pre);
      loop assigns i, j;
    */
    while (i <= x) {
      i = i + 1;
      j = j + y;
    }
  
  /*@ assert (y == 1) ==> (i == j) ;*/
}
