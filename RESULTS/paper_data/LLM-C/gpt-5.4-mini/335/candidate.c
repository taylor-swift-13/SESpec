/*@
    requires a <= b;
    assigns \nothing;
    ensures \result == 1 || \result == 0 || (\result >= 0 && \result <= 9);
*/
int computeLastDigit(int a, int b);

int computeLastDigit(int a, int b) {
        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            /*@
                loop invariant a + 1 <= i <= b + 1;
                loop invariant 0 <= variable <= 9;
                loop assigns i, variable;
                loop variant b + 1 - i;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}
