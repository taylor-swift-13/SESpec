int foo32(double i);


int foo32(double i) {
    if (i == 0.0) return 0;
    double j = 10.0 / i;
    (void)j;
    return 1;
}