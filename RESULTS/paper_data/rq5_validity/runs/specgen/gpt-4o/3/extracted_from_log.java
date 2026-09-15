class GCD {
    //@ requires y1 > 0 && y2 > 0;
    //@ ensures \result > 0;
    //@ ensures y1 % \result == 0 && y2 % \result == 0;
    //@ ensures (\forall int d; d > 0 && y1 % d == 0 && y2 % d == 0; d <= \result);
    static int gcd(int y1, int y2) {
        if (y1 <= 0 || y2 <= 0) {
          //@ ensures \result == 0;
          return 0;
        }
        if (y1 == y2) {
          //@ ensures \result == y1;
          return y1;
        }
        if (y1 > y2) {
          //@ ensures \result == gcd(y1 - y2, y2);
          return gcd(y1 - y2, y2);
        }
        //@ ensures \result == gcd(y1, y2 - y1);
        return gcd(y1, y2 - y1);
    }
}