int foo52_helper1(int i, int j);
int foo52(int i);

int foo52_helper1(int i, int j) {

    if (i == j) {
      return 0;
    }
    if (i >= j) {
      return 0;
    }
    if (2 > 1) {
      if (j > i) {
        return 1;
      } else {
        return 0;
      }
    }
    if (j <= i) {
      return 0;
    }
    if (j < i) {
      return 0;
    } else {
      return 1;
    }
}

int foo52(int i) {

    if (i + 1 < 0) return 1;
    return foo52_helper1(i, i + 1);
}
