#include <assert.h>

/*@
    requires l < 100L && l > -100L;
    ensures \result == (double)l;
    assigns \nothing;
*/
double bar(long long l) {
    assert(l < 100L && l > -100L);
    return (double)l;
}

/*@
    ensures \result == (x < 0.0 ? bar((long long)(x * 10.0)) : bar((long long)(x / 10.0)));
    assigns \nothing;
*/
double foo(double x) {
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return bar(l);
}
