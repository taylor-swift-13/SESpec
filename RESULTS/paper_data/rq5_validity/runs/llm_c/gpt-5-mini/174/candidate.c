int findRotationCount(int * a, int a_len);

/*@
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    /* Array is a rotation of a strictly increasing sequence:
       there exists an index rot such that, starting from rot,
       the sequence strictly increases modulo a_len. */
    requires \exists integer rot;
        0 <= rot < a_len &&
        (\forall integer k; 0 <= k < a_len-1 ==>
            a[(rot + k) % a_len] < a[(rot + k + 1) % a_len]);
    assigns \nothing;
    ensures 0 <= \result < a_len;
    /* result is the index of the minimal element */
    ensures \forall integer j; 0 <= j < a_len ==> a[\result] <= a[j];
*/
int findRotationCount(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        /*@
            loop invariant 0 <= start <= a_len;
            loop invariant -1 <= end < a_len;
            loop invariant start <= end + 1;
            /* The rotation index remains within [start..end] */
            loop invariant \exists integer rot;
                0 <= rot < a_len &&
                (\forall integer k; 0 <= k < a_len-1 ==>
                    a[(rot + k) % a_len] < a[(rot + k + 1) % a_len]) &&
                start <= rot <= end;
            loop assigns start, end;
            loop variant end - start + 1;
        */
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && a[mid] > a[mid + 1]) {
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                return mid;
            }
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
}
