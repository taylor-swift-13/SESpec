int numberOfCuts(int n);

/*@
    requires n >= 1;
    assigns \nothing;
    behavior one:
        assumes n == 1;
        ensures \result == 0;
    behavior even:
        assumes n % 2 == 0 && n > 1;
        ensures \result == n/2;
    behavior odd:
        assumes n % 2 != 0 && n > 1;
        ensures \result == n;
    complete behaviors one, even, odd;
    disjoint behaviors one, even, odd;
*/
int numberOfCuts(int n) {

        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
}
