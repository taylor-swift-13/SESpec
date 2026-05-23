public class IsCommonMultiple {
    /*@ spec_public
      @ public normal_behavior
      @   requires a != 0 && b != 0;
      @   ensures \result <==> (m % a == 0 && m % b == 0);
      @ also
      @ public exceptional_behavior
      @   requires a == 0 || b == 0;
      @   signals_only ArithmeticException;
      @*/
    public boolean isCommonMultiple (int a, int b, int m) {
        return m % a == 0 && m % b == 0;
    }
}