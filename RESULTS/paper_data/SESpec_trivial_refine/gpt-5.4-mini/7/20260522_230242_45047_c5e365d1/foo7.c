
/*@
  requires 0 <= m;
  requires m <= 2147483647;
  requires n == 0 || m == 0;
  assigns \nothing;
*/
int foo7(int n, int m);

/*@
  requires 0 <= m;
  requires m <= 2147483647;
  requires n == 0 || m == 0;
  decreases m;
  assigns \nothing;
  ensures \result == 0;
*/
int foo7(int n, int m) {

    if (m < 0) {
      return foo7(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    return n + foo7(n, m - 1);
}
