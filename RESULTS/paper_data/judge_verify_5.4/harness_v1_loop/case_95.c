#include <limits.h>

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_0(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (i == 0 || a[i-1] == b[i-1]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_1(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_2(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_3(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_4(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_5(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && (i == 0 || a[i-1] == b[i-1])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_6(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert ((i == 0) || a[i-1] == b[i-1]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_7(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert ((i == 0 || a[i-1] == b[i-1])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_8(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_9(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_10(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_11(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_12(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_13(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_14(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && 0 <= i); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_15(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_16(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; i <= k < a_len ==> a_len == b_len); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_17(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_18(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; i <= k < a_len ==> (k < a_len)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_19(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; i <= k < a_len ==> (a_len == b_len)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_20(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_21(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == b[k]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_22(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_23(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_24(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_25(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_26(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_27(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_28(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_29(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_30(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_31(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_32(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_33(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_34(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_35(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_36(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\exists integer k; 0 <= k < i ==> a[k] != b[k]); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_37(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_38(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len); */
}

/*@ requires (0 <= i <= a_len) && (b_len == a_len) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)) && (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)) && ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
    assigns \nothing;
*/
void check_AB_L0_39(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (0 <= i); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_BA_L0_0(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (0 <= i <= a_len); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_BA_L0_1(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (b_len == a_len); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_BA_L0_2(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == b[k]); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_BA_L0_3(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre)); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_BA_L0_4(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert (\forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre)); */
}

/*@ requires (i == 0 || a[i-1] == b[i-1]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len && \forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (a_len == b_len && \forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (a_len == b_len && \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len && (i == 0 || a[i-1] == b[i-1])) && ((i == 0) || a[i-1] == b[i-1]) && ((i == 0 || a[i-1] == b[i-1])) && (a_len == b_len) && (a_len == b_len ==> \forall integer k; i <= k < a_len ==> a_len == b_len) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> a[k] == b[k]) && (a_len == b_len ==> \forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (a_len == b_len ==> \exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (a_len == b_len ==> (i == 0 || a[i-1] == b[i-1])) && (a_len == b_len && 0 <= i) && (a_len == b_len && (\forall integer k; 0 <= k < i ==> a[k] == b[k])) && (\forall integer k; i <= k < a_len ==> a_len == b_len) && (\forall integer k; i <= k < a_len ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; i <= k < a_len ==> (k < a_len)) && (\forall integer k; i <= k < a_len ==> (a_len == b_len)) && (\forall integer k; i <= k < a_len ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> a[k] == b[k]) && (\forall integer k; 0 <= k < i ==> a[k] == b[k] || a[k] != b[k]) && (\forall integer k; 0 <= k < i ==> a[k] - b[k] == 0) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> \false) && (\forall integer k; 0 <= k < i ==> a[k] != b[k] ==> 0 == 0) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] || a[k] != b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] == b[k])) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] == b[k] ==> 1 == 1)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0)) && (\forall integer k; 0 <= k < i ==> (a[k] - b[k] == 0 || a[k] - b[k] != 0)) && (\forall integer k; 0 <= k < i ==> (a[k] != b[k] ==> \false)) && (\forall integer k; 0 <= k < i ==> !(a[k] != b[k])) && (\forall integer k; 0 <= k < a_len ==> (k < i ==> a[k] == b[k])) && (\exists integer k; 0 <= k < i ==> a[k] != b[k]) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> \false) && (\exists integer k; 0 <= k < i && a[k] != b[k] ==> 0 <= k < a_len) && (0 <= i);
    assigns \nothing;
*/
void check_BA_L0_5(int *a, int a_len, int *b, int b_len, int i, int k) {
    /*@ assert ((!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k])); */
}

