int f(int i);

int f(int i) {

    if (i < 1 || i > 100) {
      return -1;
    }

    return ((1 << i) != 1) ? 1 : 0;
}
