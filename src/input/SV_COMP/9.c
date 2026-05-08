int foo9(int index);

int foo9(int index) {

    int a[4];
    int a_len = 4;
    if (index < 0 || index >= a_len) {
      return 0;
    }
    a[index] = 0;
    return 1;
}
