int foo20_helper1(int x);
int foo20(int x);

int foo20_helper1(int x) {

    if (x > 0) return 1;
    return foo20(x);
}

int foo20(int x) {

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
