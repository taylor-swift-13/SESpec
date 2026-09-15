#include <limits.h>

/*@ requires (0 <= i) && (difference == seqNums[1] - seqNums[0]) && (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference) && (\forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre)) && ((i <= seqNums_len) ==> (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference)) && ((i == 1) || (\exists integer k; 1 <= k < i && seqNums[k] - seqNums[k - 1] == difference)) && ((!(i < seqNums_len)) ==> (\forall integer k; 1 <= k < seqNums_len ==> seqNums[k] - seqNums[k - 1] == difference));
    assigns \nothing;
*/
void check_A_implies_B(int *difference, int i, int k, int *seqNums, int seqNums_len) {
    /*@ assert (seqNums_len > 1 ==> 0 < i); */
    /*@ assert (seqNums_len > 1 ==> seqNums[i-1] - seqNums[0] == (i-1) * difference); */
    /*@ assert (seqNums_len > 1 ==> seqNums[i - 1] == seqNums[0] + (i - 1) * difference); */
    /*@ assert (seqNums_len > 1 ==> seqNums[i - 1] - seqNums[0] == (i - 1) * difference); */
    /*@ assert (seqNums_len > 1 ==> seqNums[1] - seqNums[0] == difference); */
    /*@ assert (seqNums_len > 1 ==> seqNums[0] + (i-1) * difference == seqNums[i-1]); */
    /*@ assert (seqNums_len > 1 ==> i >= 1); */
    /*@ assert (seqNums_len > 1 ==> i > 0); */
    /*@ assert (seqNums_len > 1 ==> i == 1 || seqNums[i-1] - seqNums[i-2] == difference); */
    /*@ assert (seqNums_len > 1 ==> i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference); */
    /*@ assert (seqNums_len > 1 ==> i <= seqNums_len); */
    /*@ assert (seqNums_len > 1 ==> i < seqNums_len + 1); */
    /*@ assert (seqNums_len > 1 ==> i - 1 < seqNums_len); */
    /*@ assert (seqNums_len > 1 ==> difference == seqNums[1] - seqNums[0]); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k]); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference); */
    /*@ assert (seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference); */
    /*@ assert (seqNums_len > 1 ==> 1 <= i); */
    /*@ assert (seqNums_len > 1 ==> 1 <= i <= seqNums_len); */
    /*@ assert (seqNums_len > 1 ==> 0 <= i - 1 < seqNums_len); */
    /*@ assert (seqNums_len > 1 ==> 0 < i <= seqNums_len); */
    /*@ assert (seqNums_len > 1 ==> (i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference)); */
    /*@ assert (seqNums[1] - seqNums[0] == difference); */
    /*@ assert (i > 1 ==> seqNums[i-1] - seqNums[i-2] == difference); */
    /*@ assert (i > 1 ==> seqNums[i - 1] - seqNums[i - 2] == difference); */
    /*@ assert (i == 1 || seqNums[i-1] - seqNums[i-2] == difference); */
    /*@ assert (i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference); */
    /*@ assert (i == 1 ==> difference == seqNums[1] - seqNums[0]); */
    /*@ assert (difference == seqNums[1] - seqNums[0]); */
    /*@ assert (\forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference); */
    /*@ assert (\forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference); */
    /*@ assert (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference); */
    /*@ assert (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference); */
    /*@ assert (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference); */
    /*@ assert (\forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference); */
    /*@ assert (\forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[k] == 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= i - 1); */
    /*@ assert (0 < i); */
}

/*@ requires (seqNums_len > 1 ==> 0 < i) && (seqNums_len > 1 ==> seqNums[i-1] - seqNums[0] == (i-1) * difference) && (seqNums_len > 1 ==> seqNums[i - 1] == seqNums[0] + (i - 1) * difference) && (seqNums_len > 1 ==> seqNums[i - 1] - seqNums[0] == (i - 1) * difference) && (seqNums_len > 1 ==> seqNums[1] - seqNums[0] == difference) && (seqNums_len > 1 ==> seqNums[0] + (i-1) * difference == seqNums[i-1]) && (seqNums_len > 1 ==> i >= 1) && (seqNums_len > 1 ==> i > 0) && (seqNums_len > 1 ==> i == 1 || seqNums[i-1] - seqNums[i-2] == difference) && (seqNums_len > 1 ==> i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference) && (seqNums_len > 1 ==> i <= seqNums_len) && (seqNums_len > 1 ==> i < seqNums_len + 1) && (seqNums_len > 1 ==> i - 1 < seqNums_len) && (seqNums_len > 1 ==> difference == seqNums[1] - seqNums[0]) && (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference) && (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference) && (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference) && (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference) && (seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference) && (seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k]) && (seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference) && (seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference) && (seqNums_len > 1 ==> 1 <= i) && (seqNums_len > 1 ==> 1 <= i <= seqNums_len) && (seqNums_len > 1 ==> 0 <= i - 1 < seqNums_len) && (seqNums_len > 1 ==> 0 < i <= seqNums_len) && (seqNums_len > 1 ==> (i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference)) && (seqNums[1] - seqNums[0] == difference) && (i > 1 ==> seqNums[i-1] - seqNums[i-2] == difference) && (i > 1 ==> seqNums[i - 1] - seqNums[i - 2] == difference) && (i == 1 || seqNums[i-1] - seqNums[i-2] == difference) && (i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference) && (i == 1 ==> difference == seqNums[1] - seqNums[0]) && (difference == seqNums[1] - seqNums[0]) && (\forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference) && (\forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference) && (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference) && (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference) && (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference) && (\forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k]) && (\forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference) && (\forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[k] == 0) && (\forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference) && (1 <= i) && (0 <= i - 1) && (0 < i);
    assigns \nothing;
*/
void check_B_implies_A(int *difference, int i, int k, int *seqNums, int seqNums_len) {
    /*@ assert (0 <= i); */
    /*@ assert (difference == seqNums[1] - seqNums[0]); */
    /*@ assert (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference); */
    /*@ assert (\forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre)); */
    /*@ assert ((i <= seqNums_len) ==> (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference)); */
    /*@ assert ((i == 1) || (\exists integer k; 1 <= k < i && seqNums[k] - seqNums[k - 1] == difference)); */
    /*@ assert ((!(i < seqNums_len)) ==> (\forall integer k; 1 <= k < seqNums_len ==> seqNums[k] - seqNums[k - 1] == difference)); */
}
