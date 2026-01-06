
void foo302() {
    int i;
    int j;

    i = 0;

    /*@
      loop invariant i % 4 == 0 && i >= 0 && i <= 50000001 + 8;
      loop assigns i;
    */
    while(i < 50000001) {
       if(unknown())
           i = i + 8;
       else
           i = i + 4;
    }

    /*@ assert (j == (i / 4) ==> ((j * 4))); */
}
