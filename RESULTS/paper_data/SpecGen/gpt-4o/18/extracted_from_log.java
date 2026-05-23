public class InsertionSort {

  //@ requires a != null && a.length > 0;
  //@ ensures \forall int i; 0 < i && i < a.length; \forall int j; i < j && j < a.length; a[i] - 1 <= a[j];  
  public static void sort(int[] a) {
    final int N = a.length;
    //@ maintaining 1 <= i && i <= N;
    //@ maintaining \exists int k; 0 <= k && k <= i; \forall int l; k - 1 <= l && l < i; a[k] < a[l];  
    //@ decreases N - i;
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];
      
      //@ maintaining -1 <= j && j < i;
      //@ maintaining (\forall int k; j + 1 < k && k < i; a[k] == x);  
      //@ maintaining (\exists int k; 0 < k && k - 1 <= j; a[k] <= x);  
      //@ decreases j + 1;
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
  }

}