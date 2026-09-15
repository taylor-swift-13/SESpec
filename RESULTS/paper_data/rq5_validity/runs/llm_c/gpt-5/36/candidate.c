#include <assert.h>

/*@ 
  requires \true;
  assigns \nothing;
*/
double bar(long long l);

/*@ 
  requires \true;
  assigns \nothing;
*/
double foo(double x);

/*@ 
  requires l < 100LL && l > -100LL;
  assigns \nothing;
  ensures \result == (double)l;
*/
double bar(long long l) {
    assert(l < 100L && l > -100L);
    return (double)l;
}

/*@ 
  requires \true;
  assigns \nothing;
  ensures -100.0 < \result < 100.0;
*/
double foo(double x) {
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return bar(l);
}
