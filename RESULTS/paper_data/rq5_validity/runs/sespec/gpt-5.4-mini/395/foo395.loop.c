


int foo395(int p) {
    int odd = 0;

    /*@
      loop invariant p == \at(p,Pre);
      loop invariant 0 <= odd;
      loop invariant odd >= 0;
      loop assigns odd;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }

    return odd;
}
