#include <assert.h>

/*@
    requires l < 100L && l > -100L;
    assigns \nothing;
    ensures \result == (double)l;
*/
double bar(long long l);

/*@
    requires x < 1000.0 && x > -1000.0;
    assigns \nothing;
*/
double foo(double x);

double bar(long long l) {
    assert(l < 100L && l > -100L);
    return (double)l;
}

double foo(double x) {
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return bar(l);
}
