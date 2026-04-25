double foo46_helper1(long long l);
double foo46(double x);

double foo46_helper1(long long l) {

    assert l < 100L && l > -100L;
    return (double) l;
}

double foo46(double x) {

    if (x < 0.0) {
      x *= 10.0;
    } else {
      x /= 10.0;
    }
    long l = (long) x;
    return foo46_helper1(l);
}
