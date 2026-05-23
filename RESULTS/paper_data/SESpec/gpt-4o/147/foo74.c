
/*@
  // Define the missing logic function max_divisible_by_3
  logic integer max_divisible_by_3(integer n) =
    n == 0 ? 0 : (n % 3 == 0 ? n : max_divisible_by_3(n - 1));
*/

/*@
  requires n >= 0;
  requires n % 3 == 0;
  assigns \nothing;
*/
int foo74(int n) {

    int temp = n;

    /*@
      loop invariant temp >= 0;
      loop invariant max_divisible_by_3(\at(n, Pre)) % 3 == 0;
      loop invariant temp <= max_divisible_by_3(\at(n, Pre));
      loop assigns temp;
      loop variant temp;
    */
    while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }

    return temp == 1;
}
