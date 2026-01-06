
void foo219() {
    int s;

    s = 0;

    /*@
      loop invariant s == 0;
      loop assigns s;
    */
    while(unknown()) {
       if (s != 0) {
           s = s + 1;
       }
    }

    /*@ assert s == 0; */
}
