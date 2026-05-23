public class InsertionSort {

  //@ requires a != null;
  //@ ensures a.length == \old(a.length);
  public static void sort(int[] a) {
    final int N = a.length;
    //@ maintaining a.length == N && 1 <= i && i <= N;
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      //@ maintaining a.length == N && -1 <= j && j < i;
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
  }

}