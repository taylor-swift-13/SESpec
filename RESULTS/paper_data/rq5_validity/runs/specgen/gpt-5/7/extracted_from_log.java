public class MultCommutative {

  //@ ensures m >= 0 ==> \result == n * m;
  //@ ensures m < 0 ==> \result == n * (-m);
  /*@ spec_public @*/ static int mult(int n, int m) {
    if (m < 0) {
      return mult(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    return n + mult(n, m - 1);
  }

}