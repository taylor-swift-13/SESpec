#include <limits.h>

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_A_implies_B(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (i == 0 || a[i-1] == b[i-1]); */
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]); */
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0); */
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])); */
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])); */
    /*@ assert (a_len == b_len && (i == 0 || a[i-1] == b[i-1])); */
    /*@ assert ((i == 0) || a[i-1] == b[i-1]); */
    /*@ assert ((i == 0 || a[i-1] == b[i-1])); */
    /*@ assert (a_len == b_len); */
    /*@ assert (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len); */
    /*@ assert (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]); */
    /*@ assert (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])); */
    /*@ assert (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false); */
    /*@ assert (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])); */
    /*@ assert (a_len == b_len && 0 <= i); */
    /*@ assert (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])); */
    /*@ assert (\forall integer k; i <= k < a_len ==> a_len == b_len); */
    /*@ assert (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]); */
    /*@ assert (\forall integer k; i <= k < a_len ==> (k < a_len)); */
    /*@ assert (\forall integer k; i <= k < a_len ==> (a_len == b_len)); */
    /*@ assert (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == b[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])); */
    /*@ assert (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])); */
    /*@ assert (\exists integer k; 0 <= k < i ==> a[k] != b[k]); */
    /*@ assert (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false); */
    /*@ assert (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len); */
    /*@ assert (0 <= i); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (0 <= i <= a_len); */
    /*@ assert (b_len == a_len); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == b[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)); */
    /*@ assert ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k])); */
}
