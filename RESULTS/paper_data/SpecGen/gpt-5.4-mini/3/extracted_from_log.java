class GCD {
    //@ requires true;
    //@ ensures (y1 <= 0 || y2 <= 0) ==> \result == 0;
    //@ ensures (y1 > 0 && y2 > 0 && y1 == y2) ==> \result == y1;
    //@ ensures (y1 > 0 && y2 > 0) ==> \result > 0;
 
    static int gcd(int y1, int y2) {
        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return gcd(y1 - y2, y2);
        }
        return gcd(y1, y2 - y1);
    }
}