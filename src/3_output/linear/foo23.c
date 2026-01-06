
void foo23() {
    int i=1;
    int j=20;
   
    /*@
      loop invariant i % 2 == 1;
      loop invariant j == 20 - ((i - 1)/2);
      loop invariant 20 - j == (i - 1)/2;
      loop invariant j >= 13;
      loop assigns i, j;
    */
    while (j >= i) {
      i = i + 2;
      j = j - 1;
    }
  
    /*@ assert j == 13;*/
}
