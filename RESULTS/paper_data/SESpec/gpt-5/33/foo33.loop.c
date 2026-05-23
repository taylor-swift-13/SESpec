int foo33(int denom);


int foo33(int denom) {
    if (denom == 0) return 0;
    int j = 10 / denom;
    (void)j;
    return 1;
}