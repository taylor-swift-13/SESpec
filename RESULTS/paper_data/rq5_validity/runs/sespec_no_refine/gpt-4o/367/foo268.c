
/*@
  logic integer initial_n = \at(n, Pre);
*/

/*@
  ensures n <= 1 ==> \result == n;
  ensures n > 1 && (\exists integer d; 2 <= d <= initial_n / d && initial_n % d == 0) ==> \result == (\min integer d; 2 <= d <= initial_n / d && initial_n % d == 0);
  ensures n > 1 && !(\exists integer d; 2 <= d <= initial_n / d && initial_n % d == 0) ==> \result == n;
  assigns \nothing;
*/
int foo268(int n) {

    int i = 2;

    /*@
      loop invariant (2 <= initial_n / 2) ==> (i >= 2 && i <= initial_n / i + 1);
      loop invariant (!(2 <= initial_n / 2)) ==> ((i == 2) && (n == initial_n));
      loop invariant n == initial_n;
      loop assigns i;
      loop variant initial_n / i - i;
    */
    while (i <= n / i) {
        if (n % i == 0) {
            return i;
        }
        i++;
    }

    return n;
}
