int f(int x);
int test(int x);

int f(int x) {

    if (x < 0) return 1;
    return test(x);
}

int test(int x) {

    x = 3;
    if (x > 0)
    else {
      return 0;
    }
    return 1;
}
