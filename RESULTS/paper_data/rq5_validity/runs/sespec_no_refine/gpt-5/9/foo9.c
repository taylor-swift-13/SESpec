#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);

/*@
  requires \true;
*/

/*@
  requires \true;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo9(int m, int n);

#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);
int foo9(int m, int n);


int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}


/*@
  requires \true;
  assigns \nothing;
  ensures (m < 0 || m >= 10000 || n < 0 || n >= 10000) ==> \result == -1;
  ensures (0 <= m && m < 10000 && 0 <= n && n < 10000) ==> (\result == ((foo36_helper1_c9(m, n, 0) == m + n) ? 1 : 0));
  ensures \result == (
            (m < 0 || m >= 10000 || n < 0 || n >= 10000)
              ? -1
              : ((foo36_helper1_c9(m, n, 0) == m + n) ? 1 : 0)
          );
  ensures \result == PLACE_HOLDER_RESULT;
*/
int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}