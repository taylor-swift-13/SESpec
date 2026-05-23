public class InsertionSort {

  //@ requires a != null;
  //@ ensures a != null;
  public static void sort(int[] a) {
    final int N = a.length;
    /*@ maintaining 1 <= i && i - 1 <= N;  
      @ maintaining a != null && a.length == N;
      @ decreases N - i;
      @*/
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];
      /*@ maintaining -1 <= j && j < i;
        @ maintaining a != null && a.length == N;
        @ decreases j + 1;
        @*/
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
  }

}