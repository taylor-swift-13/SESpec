int foo140(int n);


/*@
  requires n >= 0;
  assigns \nothing;
  ensures n == 1 ==> \result == 0;
  ensures n != 1 && n % 2 == 0 ==> \result == n / 2;
  ensures n != 1 && n % 2 != 0 ==> \result == n;
  ensures \result >= 0;
*/
int foo140(int n) {

    if (n == 1) {
        return 0;
    }
    if (n % 2 == 0) {
        return n / 2;
    }
    return n;
}