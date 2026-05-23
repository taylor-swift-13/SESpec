/*@
    requires i != 0.0;
    ensures \result == 1;
    assigns \nothing;
*/
int arithmeticException5(double i);

int arithmeticException5(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}
