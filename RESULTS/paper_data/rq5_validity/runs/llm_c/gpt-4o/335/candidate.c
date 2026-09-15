/*@
    requires a >= 0 && b >= 0;
    ensures \result >= 0 && \result < 10;
    behavior equal_a_b:
        assumes a == b;
        ensures \result == 1;
    behavior large_difference:
        assumes b - a >= 5;
        ensures \result == 0;
    behavior general_case:
        assumes a != b && b - a < 5;
        ensures \result == (\prod integer i; a+1 <= i <= b; (i % 10)) % 10;
    complete behaviors equal_a_b, large_difference, general_case;
    disjoint behaviors equal_a_b, large_difference, general_case;
*/
int computeLastDigit(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            /*@
                loop invariant a + 1 <= i <= b + 1;
                loop invariant variable == (\prod integer j; a+1 <= j < i; (j % 10)) % 10;
                loop assigns i, variable;
                loop variant b + 1 - i;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}
