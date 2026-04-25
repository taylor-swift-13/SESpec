int foo21_helper1(int x);
int foo21(int x);

int foo21_helper1(int x) {

    if (x < 0) return 1;
    return foo21(x);
}

int foo21(int x) {

    x = 3;
    if (x > 0)
    else {
      return 0;
    }
    return 1;
}
