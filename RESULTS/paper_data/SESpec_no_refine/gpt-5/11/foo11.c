int foo11(int i);


int foo11(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo11(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}