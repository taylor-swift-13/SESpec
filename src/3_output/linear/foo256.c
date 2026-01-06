
void foo256() {
    int v;

    v = 1;

    /*@
      loop invariant \exists integer k; 0 <= k && v == 1 + 2*k && v <= 51;
      loop assigns v;
    */
    while (v <= 50) {
        v = v + 2;
    }

    /*@ assert v >= 51; */
}
