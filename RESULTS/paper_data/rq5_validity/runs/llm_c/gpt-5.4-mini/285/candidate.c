/*@
    requires n >= 1;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures (\result == "Even") <==> (\exists integer c; c == \numof{integer i; 1 <= i <= n && n % i == 0}; c % 2 == 0);
    ensures (\result == "Odd") <==> (\exists integer c; c == \numof{integer i; 1 <= i <= n && n % i == 0}; c % 2 != 0);
*/
const char * countDivisors(int n);

const char * countDivisors(int n) {

        int count = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant 0 <= count <= i - 1;
            loop invariant count == \numof{integer j; 1 <= j < i && n % j == 0};
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
