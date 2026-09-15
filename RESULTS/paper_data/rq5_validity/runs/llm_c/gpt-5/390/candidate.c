/*@ 
  logic integer falling_factorial(integer n, integer k) =
    k <= 0 ? 1 : falling_factorial(n, k - 1) * (n - k + 1);
*/

int permutationCoefficient(int n, int k);

/*@ 
  requires 0 <= k && k <= n;
  assigns \nothing;
  ensures \result == falling_factorial(n, k);
*/
int permutationCoefficient(int n, int k) {

        int res = 1;
        int i = 1;
        /*@
          loop invariant 1 <= i <= k + 1;
          loop invariant res == falling_factorial(n, i - 1);
          loop assigns i, res;
          loop variant k - i + 1;
        */
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
