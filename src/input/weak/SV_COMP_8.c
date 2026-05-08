int foo8(int size);

int foo8(int size) {

    if (size < 0) return -1;
    int a[4];
    int a_len = 4;
    if (size >= a_len) {
      return 0;
    }
    int i = a[size];
    return 1;
}
