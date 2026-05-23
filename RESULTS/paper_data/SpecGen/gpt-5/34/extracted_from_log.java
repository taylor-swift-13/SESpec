class Sespec0034 {
    //@ ensures denominator == 0 ==> (\result == (numerator >= 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE));
    //@ ensures denominator != 0 ==> (\result == numerator / denominator);
    static /*@ spec_public @*/ int foo34(int numerator, int denominator) {
        int quotient;
        int quotientNeedsNegation = 0;
        if (denominator == 0) {
            quotient = numerator >= 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        } else {
            if ((numerator < 0) && (denominator > 0)) quotientNeedsNegation = 1;
            else if ((numerator > 0) && (denominator < 0)) quotientNeedsNegation = 1;
            int calcDenominator = denominator >= 0 ? denominator : -denominator;
            int tempAbsQuotient = (numerator >= 0 ? numerator : -numerator) / calcDenominator;
            quotient = (quotientNeedsNegation != 0) ? -tempAbsQuotient : tempAbsQuotient;
        }
        return quotient;
    }
}