int foo3(int i);

int foo3(int i) {

    try {
      int j = 10 / i;
    } catch (ArithmeticException exc) {
      return 0;
    }
    return 1;
}
