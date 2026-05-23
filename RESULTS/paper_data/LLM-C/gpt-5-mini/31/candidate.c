int arithmeticException1(int i);

/*@
    assigns \nothing;
    behavior zero:
        assumes i == 0;
        ensures \result == 0;
    behavior nonzero:
        assumes i != 0;
        ensures \result == 1;
    complete behaviors zero, nonzero;
    disjoint behaviors zero, nonzero;
*/
int arithmeticException1(int i) {
    if (i == 0) return 0;
    int j = 10 / i;
    (void)j;
    return 1;
}
