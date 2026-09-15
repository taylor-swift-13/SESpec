/*@
    requires i != 0;
    assigns \nothing;
    ensures \result == 1;
*/
int arithmeticException1(int i);

int arithmeticException1(int i) {
    if (i == 0) return 0;
    int j = 10 / i;
    (void)j;
    return 1;
}
