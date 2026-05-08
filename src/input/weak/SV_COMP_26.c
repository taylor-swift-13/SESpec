void foo26(int * a, int a_len);

void foo26(int * a, int a_len) {

    int N = a_len;
    for (int i = 1; i < N; i++) {
      int j = i - 1;
      int x = a[i];

      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
}
