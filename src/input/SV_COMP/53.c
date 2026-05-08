int foo53();

int foo53() {

    int i = 0;
    if (i != 0) {
      return 0;
    }
    i = 1;
    if (i == 0) {
      return 0;
    }
    if (i < 0) {
      return 0;
    }
    i = 0;
    if (i > 0) {
      return 0;
    }
    i = 1;
    if (i <= 0) {
      return 0;
    }
    i = -1;
    if (i >= 0) {
      return 0;
    }
    return 1;
}
