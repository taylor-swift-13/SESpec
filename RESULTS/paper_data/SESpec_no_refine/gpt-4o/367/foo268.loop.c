
/*@
  logic integer initial_n = \at(n, Pre);
*/

/*@
  loop invariant (2 <= initial_n / 2) ==> (i >= 2 && i <= initial_n / i + 1);
  loop invariant (!(2 <= initial_n / 2)) ==> ((i == 2) && (n == initial_n));
  loop invariant n == initial_n;
  loop assigns i;
*/
int foo268(int n) {

    int i = 2;

    while (i <= n / i) {
        if (n % i == 0) {
            return i;
        }
        i++;
    }

    return n;
}
