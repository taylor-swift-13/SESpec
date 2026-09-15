
int foo110(int num1, int num2) {

    int result = 1;
    num1 = (0 <= num1) ? num1 : -num1;
    num2 = (0 <= num2) ? num2 : -num2;

    if (num1 == 0 && num2 == 0) {
        return -1;
    }

    if (num1 == 0 || num2 == 0) {
        return (num1 > num2) ? num1 : num2;
    }

    /*@
      loop invariant 1 <= i <= num1 + 1;
      loop invariant 1 <= i <= num2 + 1;
      loop invariant result > 0;
      loop invariant result <= i;
      loop invariant result <= num1 && result <= num2;
      loop invariant num1 % result == 0 && num2 % result == 0;
      loop invariant \forall integer k; 1 <= k < i ==> (num1 % k == 0 && num2 % k == 0 ==> k <= result);
      loop assigns i, result;
    */
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            result = i;
        }
    }

    return result;
}
