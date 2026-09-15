int foo42_c12(int i);


int foo42_c12(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo42_c12(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}