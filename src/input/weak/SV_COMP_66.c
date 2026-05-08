int foo66(int i);

int foo66(int i) {

    if (i < 1 || i > 100) {
      return -1;
    }

    return ((1L << i) != 1L) ? 1 : 0;
}
