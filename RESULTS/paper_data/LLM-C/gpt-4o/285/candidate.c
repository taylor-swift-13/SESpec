/*@ 
    requires n > 0;
    ensures \result == "Even" || \result == "Odd";
    ensures \result == "Even" <==> (\exists integer count; count == (\sum integer i; 1 <= i <= n && n % i == 0 ? 1 : 0) && count % 2 == 0);
    ensures \result == "Odd" <==> (\exists integer count; count == (\sum integer i; 1 <= i <= n && n % i == 0 ? 1 : 0) && count % 2 != 0);
    assigns \nothing;
*/
const char * countDivisors(int n) {

        int count = 0;
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant count == (\sum integer j; 1 <= j < i && n % j == 0 ? 1 : 0);
        loop assigns i, count;
        loop variant n - i;
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
