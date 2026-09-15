int arithmeticException5(double i);

 /*@
     behavior zero:
         assumes i == 0.0;
         assigns \nothing;
         ensures \result == 0;
     behavior nonzero:
         assumes i != 0.0;
         assigns \nothing;
         ensures \result == 1;
     complete behaviors zero, nonzero;
     disjoint behaviors zero, nonzero;
 */
int arithmeticException5(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}
