int foo42(int i);

int foo42(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo42(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}
