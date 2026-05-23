int computeLastDigit(int a, int b);

/*@
    requires \true;
    assigns \nothing;
    ensures 0 <= \result && \result <= 9;

    behavior nonincreasing:
        assumes a >= b;
        ensures \result == 1;

    behavior large_gap:
        assumes b - a >= 5;
        ensures \result == 0;

    behavior small_increasing:
        assumes a < b && b - a < 5;
        ensures \result == (\product integer i; a+1 <= i <= b; (i % 10)) % 10;

    complete behaviors nonincreasing, large_gap, small_increasing;
    disjoint behaviors nonincreasing, large_gap, small_increasing;
*/
int computeLastDigit(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            /*@
              loop invariant a+1 <= i <= b+1;
              loop invariant 0 <= variable && variable <= 9;
              loop invariant variable == (\product integer j; a+1 <= j < i; (j % 10)) % 10;
              loop assigns i, variable;
              loop variant b + 1 - i;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}
