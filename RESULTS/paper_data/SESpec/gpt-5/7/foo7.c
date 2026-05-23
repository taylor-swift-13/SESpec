int foo7(int n, int m);


/*@ logic integer foo7_model(integer n, integer m) =
      m < 0 ? foo7_model(n, -m) : (m == 0 ? 0 : n + foo7_model(n, m - 1)); */
/*@
  decreases (m >= 0 ? m : -m);
  assigns \nothing;
  ensures \result == foo7_model(n, m);
  ensures m == 0 ==> \result == 0;
  ensures m > 0 ==> \result == n * m;
  ensures m < 0 ==> \result == n * (-m);
  ensures n == 0 ==> \result == 0;
  ensures \result == (m >= 0 ? n * m : n * (-m));
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