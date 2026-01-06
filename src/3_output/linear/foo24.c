
void foo24() {
    int i=1;
    int j=10;
   
    /*@
      loop invariant i % 2 == 1;
      loop invariant j == 10 - (i - 1)/2;
      loop invariant j + (i - 1)/2 == 10;
      loop invariant (i - 1)/2 <= 4;
      loop assigns i, j;
    */
    while (j >= i) {
        i = i + 2;
        j = j - 1;
    }
  
    /*@ assert j == 6;*/
}
