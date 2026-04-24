double bar(long long l);
double foo(double x);

double bar(long long l) {

    assert l < 100L && l > -100L;
    return (double) l;
}

double foo(double x) {

    if (x < 0.0) {
      x *= 10.0;
    } else {
      x /= 10.0;
    }
    long l = (long) x;
    return bar(l);
}
