#include <assert.h>

double bar(long long l);
double foo(double x);

/*@
    requires l < 100L && l > -100L;
    assigns \nothing;
    ensures \result == (double) l;
*/
double bar(long long l) {
    assert(l < 100L && l > -100L);
    return (double)l;
}

/*@
    requires (x < 0.0) ? (10.0*x > -100.0 && 10.0*x < 100.0)
                       : (x/10.0 > -100.0 && x/10.0 < 100.0);
    assigns \nothing;
    ensures \result == (double)((long long)((x < 0.0) ? 10.0*x : x/10.0));
*/
double foo(double x) {
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return bar(l);
}
