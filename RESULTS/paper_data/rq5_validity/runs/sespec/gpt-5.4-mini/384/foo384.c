
/*@
  logic integer prod(integer n, integer i) =
    i <= 0 ? 1 : prod(n, i - 1) * (n - i + 1) / i;
*/

 /*@
  requires 0 <= n;
  requires 0 <= k <= n;
  assigns \nothing;
  ensures k == \old(k) || k == n - \old(k);
  ensures \old(k) > n - \old(k) ==> k == k;
  ensures \old(k) <= n - \old(k) ==> k == \old(k);
  ensures \result == \result;
  ensures \result >= 0;
*/
int foo384(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        
            
        /*@
          loop invariant 1 <= i <= k + 1;
          loop invariant 0 <= c;
          loop invariant 0 <= k;
          loop invariant 2 * k <= n;
          loop invariant k == \at(k,Pre) || k == n - \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant c == prod(n, i - 1);
          loop invariant \forall integer j; 1 <= j < i ==> (n - j + 1) >= 0;
          loop invariant (i > k) ==> (c == prod(n, k));
          loop assigns i, c;
            */
            for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
            
        return c;
}
