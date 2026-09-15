
/*@
  requires m >= 0;
  assigns \nothing;
*/
int foo7(int n, int m);


/*@
  logic integer foo7_sum(int n, integer m) =
    m < 0 ? foo7_sum(n, -m) :
    m == 0 ? 0 :
    n + foo7_sum(n, m - 1);
*/
/*@
  requires m >= 0;
  decreases m;
  assigns \nothing;
  ensures \result == foo7_sum(n, m);
  ensures m == 0 ==> \result == 0;
  ensures m > 0 ==> \result == n + foo7_sum(n, m - 1);
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
