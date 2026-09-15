
/*@
  requires n >= 0;
  decreases n;
  assigns \nothing;
*/
int foo5(int n);


int foo5(int n) {
    if (n > 100) return n - 10;
    else return foo5(foo5(n + 11));
}
