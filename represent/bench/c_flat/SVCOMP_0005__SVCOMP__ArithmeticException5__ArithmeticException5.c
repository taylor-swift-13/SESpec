int arithmeticException5(double i);

int arithmeticException5(double i) {

    try {
      double j = 10 / i;
    } catch (ArithmeticException exc) {
      return 0;
    }
    return 1;
}
