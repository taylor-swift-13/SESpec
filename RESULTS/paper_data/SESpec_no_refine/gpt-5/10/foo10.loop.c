int foo10(int i);


int foo10(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo10(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}