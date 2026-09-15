public class InsertionSort {

  public static void sort(int[] a) {
    final int N = a.length;
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
  }

}
