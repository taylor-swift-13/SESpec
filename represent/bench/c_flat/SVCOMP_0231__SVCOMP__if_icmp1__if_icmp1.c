int f(int i, int j);
int fun(int i);

int f(int i, int j) {

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

int fun(int i) {

    if (i + 1 < 0) return 1;
    return f(i, i + 1);
}
