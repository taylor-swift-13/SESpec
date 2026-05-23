/*@ 
    ensures \result == 0 ==> i == 0.0;
    ensures \result == 1 ==> i != 0.0;
    requires i != 0.0 ==> \true;
    assigns \nothing;
*/
int arithmeticException5(double i);

int arithmeticException5(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}
