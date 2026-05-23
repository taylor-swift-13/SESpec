public class InsertionSort {

  /*@
    @ requires a != null;
    @ assignable a[*];
    @ ensures (\forall int k; 0 <= k && k < a.length-1; a[k] <= a[k+1]);
    @ ensures a.length == \old(a.length);
    @*/
  public static void sort(int[] a) {
    final int N = a.length;

    /*@ 
      @ // loop variable i ranges over 1..N
      @ maintaining 0 <= i && i <= N;
      @ // the prefix [0..i-1] is sorted
      @ maintaining (\forall int p; 0 <= p && p < i-1; a[p] <= a[p+1]);
      @*/
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      /*@
        @ // j stays within -1 .. i-1 so j+1 is within 0..i
        @ maintaining -1 <= j && j < i;
        @ // elements from j+1 to i-1 are >= x (these are the shifted ones)
        @ maintaining (\forall int p; j+1 <= p && p <= i-1; a[p] >= x);
        @*/
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
  }

}