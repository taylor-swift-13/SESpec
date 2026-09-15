/*@
    requires denom != 0;
    ensures \result == 1;
    assigns \nothing;
*/
int arithmeticException6(int denom);

int arithmeticException6(int denom) {
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}
