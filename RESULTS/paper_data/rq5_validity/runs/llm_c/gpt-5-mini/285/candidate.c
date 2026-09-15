/*@
    requires n >= 1;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures \result == "Even" <==>
        ((\sum integer j; 1 <= j <= n; (n % j == 0 ? 1 : 0)) % 2 == 0);
*/
const char * countDivisors(int n) {

        int count = 0;
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant 0 <= count <= n;
            loop invariant count == (\sum integer j; 1 <= j < i; (n % j == 0 ? 1 : 0));
            loop assigns i, count;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}
