public class NotCommonFactor {
    /*@ public normal_behavior
      @   requires factor != 0;
      @   ensures \result == (a % factor != 0 || b % factor != 0);
      @ also
      @   exceptional_behavior
      @   requires factor == 0;
      @   signals_only ArithmeticException;
      @*/
    public boolean notCommonFactor (int a, int b, int factor) {
        return a % factor != 0 || b % factor != 0;
    }
}