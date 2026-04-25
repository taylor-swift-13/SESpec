void foo296(int * a, int a_len);

void foo296(int * a, int a_len) {

      int sum = 0;
      int max = a[0];

      for (int i=0; i<a_len; i++) {
        sum += a[i];
        if (max < a[i]) max = a[i];
      }
}
