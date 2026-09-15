public class Mccarthy91 {
  //@ ensures (\result == 91) <==> (n - 1 <= 100);  
  //@ ensures (n > 100) ==> (\result == n - 10);
  public static int f(int n) {
    if (n > 100) return n - 10;
    else return f(f(n + 11));
  }
}