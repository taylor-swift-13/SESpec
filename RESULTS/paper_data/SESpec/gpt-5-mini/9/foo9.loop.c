#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);
int foo9(int m, int n);

#include <assert.h>

/*@
  requires \true;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo36_helper1_c9(int m, int n, int c);
int foo9(int m, int n);


/*@ logic integer foo36_helper1_result(integer m, integer n) = m + n; */
/*@
  requires \true;
  decreases 150 - c;
  assigns \nothing;
  ensures \result == foo36_helper1_result(m, n);
*/
int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}


int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}