
void foo255() {
    int v;

    v = 1;
            
    /*@
      loop invariant 1 <= v <= 51;
      loop invariant v % 2 == 1;
      loop assigns v;
    */
    while (v <= 50) {
        v = v + 2;
    }

    /*@ assert v <= 52; */
}
