#include <assert.h>

double foo46_helper1_c36(long long l);
double foo36(double x);

#include <assert.h>

double foo46_helper1_c36(long long l);
double foo36(double x);


/*@
  assigns \nothing;
  ensures \result == (double)l;
*/
double foo46_helper1_c36(long long l) {
    assert(l < 100L && l > -100L);
    return (double)l;
}


/*@
             ( (x < 0.0 && l == (long long)(x * 10.0)) ||
               (x >= 0.0 && l == (long long)(x / 10.0)) )
             && -100L < l && l < 100L
           ) ==> \result == (double)(
                (x < 0.0) ? (long long)(x * 10.0) : (long long)(x / 10.0)
           );
  assigns \nothing;
*/
double foo36(double x) {
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return foo46_helper1_c36(l);
}