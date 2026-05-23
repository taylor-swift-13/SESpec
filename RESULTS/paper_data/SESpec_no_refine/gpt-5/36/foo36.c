#include <assert.h>

double foo46_helper1_c36(long long l);
double foo36(double x);

#include <assert.h>

double foo46_helper1_c36(long long l);
double foo36(double x);


double foo46_helper1_c36(long long l) {
    assert(l < 100L && l > -100L);
    return (double)l;
}


/*@
  assigns \nothing;
  ensures \result == foo46_helper1_c36((long long)((x < 0.0) ? (x * 10.0) : (x / 10.0)));
*/
double foo36(double x) {
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return foo46_helper1_c36(l);
}