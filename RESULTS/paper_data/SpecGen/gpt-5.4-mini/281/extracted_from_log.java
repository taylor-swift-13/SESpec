class CountDivisors {

    /*@ requires num >= 1;
      @ requires (\forall int i; 1 <= i && i <= num; i != 0);
      @ requires (\forall int i; 1 <= i && i <= num; i != 0 && num % i == 0);
      @ requires (\forall int i; 1 <= i && i <= num; i != 0);
      @ requires (\forall int i; 1 <= i && i <= num; i != 0);
      @*/
    public static String countDivisors(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                count++;
            }
        }
        return (count % 2 == 0) ? "Even" : "Odd";
    }
}