int foo10(int numerator, int denominator);

int foo10(int numerator, int denominator) {

    int quotient;
    int tempAbsQuotient;
    int quotientNeedsNegation = 0;
    if (denominator == 0) {
      quotient = numerator >= 0 ? MAX_INT : MIN_INT;

    } else {

      if ((numerator < 0) && (denominator > 0)) quotientNeedsNegation = 1;
      else if ((numerator > 0) && (denominator < 0)) quotientNeedsNegation = 1;
      else quotientNeedsNegation = 0;

      int calcDenominator;

      if (denominator >= 0) calcDenominator = denominator;
      else calcDenominator = -denominator;

      tempAbsQuotient = (int) (numerator >= 0 ? numerator : -numerator) / calcDenominator;
      quotient = quotientNeedsNegation ? -(int) tempAbsQuotient : (int) tempAbsQuotient;
    }

    return quotient;
}
