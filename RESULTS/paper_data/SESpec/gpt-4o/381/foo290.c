
/*@ 
  logic integer gcd(integer a, integer b) = 
    (b == 0) ? a : gcd(b, a % b);
*/

/*@
  logic integer gcd_count_upto(integer x, integer y, integer n) = 
    (n == 0) ? 0 : gcd_count_upto(x, y, n - 1) + ((x % n == 0 && y % n == 0) ? 1 : 0);
*/

/*@
  requires x > 0 && y > 0;
  assigns \nothing;
  ensures \result == gcd_count_upto(x, y, (x < y ? x : y));
*/
int foo290(int x, int y) {

    int count = 0;

    /*@
      loop invariant y == \at(y, Pre);
      loop invariant x == \at(x, Pre);
      loop invariant count == gcd_count_upto(x, y, i - 1);
      loop invariant 1 <= i <= (x < y ? x : y) + 1;
      loop assigns i, count;
      loop variant (x < y ? x : y) - i;
    */
    for (int i = 1; i <= x && i <= y; i++) {
        if (x % i == 0 && y % i == 0) {
            count++;
        }
    }

    return count;
}
