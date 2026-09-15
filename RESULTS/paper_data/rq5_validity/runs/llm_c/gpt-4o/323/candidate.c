/*@
    requires n > 0;
    ensures \result >= 0;
    ensures \result == 0 ==> \forall integer i; 2 <= i <= n / i ==> n % i != 0;
    ensures \result > 0 ==> \exists integer i; 2 <= i <= n / i && n % i == 0;
    assigns \nothing;
*/
int countFac(int n) {

        int count = 0;
        if (n == 1) return 1;
        /*@
            loop invariant 2 <= i <= n / i + 1;
            loop invariant count >= 0;
            loop invariant \forall integer j; 2 <= j < i ==> (n % j != 0 || (n / j == j && count > 0));
            loop assigns i, count;
            loop variant n / i - i;
        */
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
}
