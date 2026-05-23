#include <limits.h>

/*@ requires ((0 <= \at(x,Pre)) ==> (0 <= l <= \at(x,Pre) + 1)) && ((0 <= \at(x,Pre)) ==> (-1 <= ans < l)) && ((0 <= \at(x,Pre)) ==> (r <= \at(x,Pre))) && ((0 <= \at(x,Pre)) ==> (ans == -1 || (ans * ans) <= x)) && ((0 <= \at(x,Pre)) ==> (ans == -1 || (ans * ans) <= x)) && ((0 <= \at(x,Pre)) ==> (l >= 0)) && ((0 <= \at(x,Pre)) ==> (r <= \at(x,Pre))) && ((0 <= \at(x,Pre)) ==> (ans >= -1)) && ((!(0 <= \at(x,Pre))) ==> ((ans == -1)&&(r == \at(x,Pre))&&(l == 0)&&(x == \at(x,Pre)))) && (x == \at(x,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *ans, int l, int r, int x) {
    /*@ assert (r <= x); */
    /*@ assert (r < x + 1); */
    /*@ assert (r + 1 <= x + 1); */
    /*@ assert (l == ans + 1 || ans == -1); */
    /*@ assert (l <= r + 2 || ans == -1); */
    /*@ assert (ans == -1 || l == ans + 1); */
    /*@ assert (ans == -1 || l == ans + 1 || l <= r + 1); */
    /*@ assert (ans == -1 || l <= x + 1); */
    /*@ assert (ans == -1 || l <= r + 1); */
    /*@ assert (ans == -1 || l <= ans + 1); */
    /*@ assert (ans == -1 || l - 1 <= ans); */
    /*@ assert (ans == -1 || l - 1 <= ans + 1); */
    /*@ assert (ans == -1 || ans <= x); */
    /*@ assert (ans == -1 || ans <= x + 1); */
    /*@ assert (ans == -1 || ans <= x && (long)ans * ans <= (long)x); */
    /*@ assert (ans == -1 || ans <= r); */
    /*@ assert (ans == -1 || ans <= r + 1); */
    /*@ assert (ans == -1 || ans <= r + 1 && (long)ans * ans <= (long)x); */
    /*@ assert (ans == -1 || ans <= l); */
    /*@ assert (ans == -1 || ans <= l + r + 1); */
    /*@ assert (ans == -1 || ans <= l + 1); */
    /*@ assert (ans == -1 || ans < x + 1); */
    /*@ assert (ans == -1 || ans < r + 2); */
    /*@ assert (ans == -1 || ans < r + 1); */
    /*@ assert (ans == -1 || ans < l); */
    /*@ assert (ans == -1 || ans < l <= x + 1); */
    /*@ assert (ans == -1 || ans < l + 2); */
    /*@ assert (ans == -1 || ans < l + 1); */
    /*@ assert (ans == -1 || ans < l && r <= x); */
    /*@ assert (ans == -1 || ans < l && l <= x + 1); */
    /*@ assert (ans == -1 || ans < l && ans <= r + 1); */
    /*@ assert (ans == -1 || ans < l && (long)ans * ans <= (long)x); */
    /*@ assert (ans == -1 || ans * ans <= x); */
    /*@ assert (ans == -1 || (long)ans * ans <= x); */
    /*@ assert (ans == -1 || (long)ans * ans <= x && ans < l); */
    /*@ assert (ans == -1 || (long)ans * ans <= x && ans < l && ans <= r + 1); */
    /*@ assert (ans == -1 || (long)ans * ans <= (long)x); */
    /*@ assert (ans == -1 || (long)ans * ans <= (long)x && ans <= r + 1); */
    /*@ assert (ans == -1 || (long)ans * ans <= (long)x && ans <= l); */
    /*@ assert (ans == -1 || (long)ans * ans <= (long)x && ans < l); */
    /*@ assert (ans == -1 || (long)ans * ans <= (long)x && ans < l + 1); */
    /*@ assert (ans == -1 || (long)ans * ans <= (long)x && ans < l && ans <= r + 1); */
    /*@ assert (ans == -1 || ((long)ans * ans <= x && ans < l)); */
    /*@ assert (ans == -1 || ((long)ans * ans <= (long)x)); */
    /*@ assert (ans == -1 || ((long)ans * ans <= (long)x && ans < l)); */
    /*@ assert (ans == -1 || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1)); */
    /*@ assert (ans < l); */
    /*@ assert (ans < l + 1); */
    /*@ assert (ans + 1 <= l); */
    /*@ assert (0 <= l); */
    /*@ assert (-1 <= ans); */
    /*@ assert ((ans == -1) || ans <= r + 1); */
    /*@ assert ((ans == -1) || ans < l); */
    /*@ assert ((ans == -1) || (long)ans * ans <= (long)x); */
    /*@ assert ((ans == -1) || (l == ans + 1)); */
    /*@ assert ((ans == -1) || ((long)ans * ans <= x)); */
    /*@ assert ((ans == -1) || ((long)ans * ans <= (long)x)); */
    /*@ assert ((ans == -1) || ((long)ans * ans <= (long)x && ans < l)); */
    /*@ assert ((ans == -1) || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1)); */
}

/*@ requires (r <= x) && (r < x + 1) && (r + 1 <= x + 1) && (l == ans + 1 || ans == -1) && (l <= r + 2 || ans == -1) && (ans == -1 || l == ans + 1) && (ans == -1 || l == ans + 1 || l <= r + 1) && (ans == -1 || l <= x + 1) && (ans == -1 || l <= r + 1) && (ans == -1 || l <= ans + 1) && (ans == -1 || l - 1 <= ans) && (ans == -1 || l - 1 <= ans + 1) && (ans == -1 || ans <= x) && (ans == -1 || ans <= x + 1) && (ans == -1 || ans <= x && (long)ans * ans <= (long)x) && (ans == -1 || ans <= r) && (ans == -1 || ans <= r + 1) && (ans == -1 || ans <= r + 1 && (long)ans * ans <= (long)x) && (ans == -1 || ans <= l) && (ans == -1 || ans <= l + r + 1) && (ans == -1 || ans <= l + 1) && (ans == -1 || ans < x + 1) && (ans == -1 || ans < r + 2) && (ans == -1 || ans < r + 1) && (ans == -1 || ans < l) && (ans == -1 || ans < l <= x + 1) && (ans == -1 || ans < l + 2) && (ans == -1 || ans < l + 1) && (ans == -1 || ans < l && r <= x) && (ans == -1 || ans < l && l <= x + 1) && (ans == -1 || ans < l && ans <= r + 1) && (ans == -1 || ans < l && (long)ans * ans <= (long)x) && (ans == -1 || ans * ans <= x) && (ans == -1 || (long)ans * ans <= x) && (ans == -1 || (long)ans * ans <= x && ans < l) && (ans == -1 || (long)ans * ans <= x && ans < l && ans <= r + 1) && (ans == -1 || (long)ans * ans <= (long)x) && (ans == -1 || (long)ans * ans <= (long)x && ans <= r + 1) && (ans == -1 || (long)ans * ans <= (long)x && ans <= l) && (ans == -1 || (long)ans * ans <= (long)x && ans < l) && (ans == -1 || (long)ans * ans <= (long)x && ans < l + 1) && (ans == -1 || (long)ans * ans <= (long)x && ans < l && ans <= r + 1) && (ans == -1 || ((long)ans * ans <= x && ans < l)) && (ans == -1 || ((long)ans * ans <= (long)x)) && (ans == -1 || ((long)ans * ans <= (long)x && ans < l)) && (ans == -1 || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1)) && (ans < l) && (ans < l + 1) && (ans + 1 <= l) && (0 <= l) && (-1 <= ans) && ((ans == -1) || ans <= r + 1) && ((ans == -1) || ans < l) && ((ans == -1) || (long)ans * ans <= (long)x) && ((ans == -1) || (l == ans + 1)) && ((ans == -1) || ((long)ans * ans <= x)) && ((ans == -1) || ((long)ans * ans <= (long)x)) && ((ans == -1) || ((long)ans * ans <= (long)x && ans < l)) && ((ans == -1) || ((long)ans * ans <= (long)x && ans < l && ans <= r + 1));
    assigns \nothing;
*/
void check_B_implies_A(int *ans, int l, int r, int x) {
    /*@ assert ((0 <= \at(x,Pre)) ==> (0 <= l <= \at(x,Pre) + 1)); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (-1 <= ans < l)); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (r <= \at(x,Pre))); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (ans == -1 || (ans * ans) <= x)); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (ans == -1 || (ans * ans) <= x)); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (l >= 0)); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (r <= \at(x,Pre))); */
    /*@ assert ((0 <= \at(x,Pre)) ==> (ans >= -1)); */
    /*@ assert ((!(0 <= \at(x,Pre))) ==> ((ans == -1)&&(r == \at(x,Pre))&&(l == 0)&&(x == \at(x,Pre)))); */
    /*@ assert (x == \at(x,Pre)); */
}
