int arithmeticException6(int denom);

int arithmeticException6(int denom) {

    try {
      int j = 10 / denom;
    } catch (ArithmeticException exc) {
      return 0;
    }
    return 1;
}
