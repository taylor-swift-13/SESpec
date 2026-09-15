int arithmeticException6(int denom);

/*@
    behavior zero:
      assumes denom == 0;
      ensures \result == 0;
      assigns \nothing;

    behavior non_zero:
      assumes denom != 0;
      ensures \result == 1;
      assigns \nothing;

    complete behaviors zero, non_zero;
    disjoint behaviors zero, non_zero;
*/
int arithmeticException6(int denom) {
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}
