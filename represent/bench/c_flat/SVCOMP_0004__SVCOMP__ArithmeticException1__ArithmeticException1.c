int arithmeticException1(int i);

int arithmeticException1(int i) {

    try {
      int j = 10 / i;
    } catch (ArithmeticException exc) {
      return 0;
    }
    return 1;
}
