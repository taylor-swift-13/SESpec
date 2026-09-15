int foo31(int i);


int foo31(int i) {
    if (i == 0) return 0;
    int j = 10 / i;
    (void)j;
    return 1;
}