int f(int x);
int test(int x);

int f(int x) {

    if (x > 0) return 1;
    return test(x);
}

int test(int x) {

    x = x + 1;
    switch (x) {
      case 2:

        return 0;
      case 3000:

        break;
      default:

        break;
    }
    return 1;
}
