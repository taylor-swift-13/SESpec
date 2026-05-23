#include <limits.h>

/*@ requires (1 <= b <= s - l + 2) && (foo315 >= 0) && (s == \at(s,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *b, int foo315, int l, int maxVolume, int s, int *t) {
    /*@ assert (maxVolume >= l * b * (s - l - b) || b <= s - l + 1); */
    /*@ assert (maxVolume >= 0 || l <= s); */
    /*@ assert (maxVolume >= 0 || l <= s + 1); */
    /*@ assert (maxVolume >= 0 || l + b <= s + 1); */
    /*@ assert (maxVolume == 0 || maxVolume > 0); */
    /*@ assert (l <= s); */
    /*@ assert (l <= s + 1); */
    /*@ assert (l <= s + 1 ==> maxVolume >= 0); */
    /*@ assert (l + b <= s + 2); */
    /*@ assert (l + b <= s + 2 || l + b <= s + 1); */
    /*@ assert (l + b <= s + 2 || l * (b - 1) * (s - l - (b - 1)) <= maxVolume); */
    /*@ assert (l + b <= s + 2 || b - l <= s + 1); */
    /*@ assert (l + b <= s + 2 || 0 <= b); */
    /*@ assert (l + b <= s + 1 || maxVolume >= 0); */
    /*@ assert (l + b <= s + 1 || 0 <= l); */
    /*@ assert (l + b <= s + 1 || 0 <= b); */
    /*@ assert (l * b * (s - l - b) <= maxVolume || l + b <= s + 1); */
    /*@ assert (l * b * (s - l - b) <= maxVolume || b <= s - l + 1); */
    /*@ assert (l * (b - 1) * (s - l - (b - 1)) <= maxVolume); */
    /*@ assert (l * (b - 1) * (s - l - (b - 1)) <= maxVolume || l + b <= s + 1); */
    /*@ assert (l * (b - 1) * (s - l - (b - 1)) <= maxVolume || b == 1); */
    /*@ assert (b <= s - l + 2); */
    /*@ assert (b - l <= s + 1); */
    /*@ assert (b - l <= s + 1 || l + b <= s + 1); */
    /*@ assert (b - l <= s + 1 || l * (b - 1) * (s - l - (b - 1)) <= maxVolume); */
    /*@ assert (b - l <= s + 1 || 0 <= b); */
    /*@ assert (b - l < s + 1); */
    /*@ assert (\forall integer t; 1 <= t < l ==> maxVolume >= t * (s - t) * 0); */
    /*@ assert (\forall integer t; 1 <= t < l ==> maxVolume >= 0); */
    /*@ assert (\forall integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0); */
    /*@ assert (\forall integer t; 1 <= t < b ==> maxVolume >= l * t * (s - l - t)); */
    /*@ assert (\forall integer t; 1 <= t < b ==> maxVolume >= 0); */
    /*@ assert (\forall integer t; 1 <= t < b ==> l * t * (s - l - t) <= maxVolume); */
    /*@ assert (\forall integer t; 1 <= t < b ==> l * t * (s - l - t) <= maxVolume || maxVolume == 0); */
    /*@ assert (\exists integer t; 1 <= t <= b ==> maxVolume >= l * t * (s - l - t)); */
    /*@ assert (\exists integer t; 1 <= t <= b ==> maxVolume >= 0); */
    /*@ assert (\exists integer t; 1 <= t <= b ==> maxVolume >= 0 || maxVolume == 0); */
    /*@ assert (\exists integer t; 1 <= t < l ==> maxVolume >= 0); */
    /*@ assert (\exists integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0); */
    /*@ assert (1 <= l); */
    /*@ assert (1 <= l || maxVolume >= 0); */
    /*@ assert (1 <= b); */
    /*@ assert (1 <= b || l + b <= s + 1); */
    /*@ assert (1 < l + b); */
    /*@ assert (0 <= s); */
    /*@ assert (0 <= maxVolume); */
    /*@ assert (0 <= l); */
    /*@ assert (0 <= l || b <= s - l + 1); */
    /*@ assert (0 <= b); */
    /*@ assert (0 <= b || l + b <= s + 1); */
    /*@ assert (0 <= b || l * (b - 1) * (s - l - (b - 1)) <= maxVolume); */
    /*@ assert (0 < l); */
    /*@ assert (0 < b); */
}

/*@ requires (maxVolume >= l * b * (s - l - b) || b <= s - l + 1) && (maxVolume >= 0 || l <= s) && (maxVolume >= 0 || l <= s + 1) && (maxVolume >= 0 || l + b <= s + 1) && (maxVolume == 0 || maxVolume > 0) && (l <= s) && (l <= s + 1) && (l <= s + 1 ==> maxVolume >= 0) && (l + b <= s + 2) && (l + b <= s + 2 || l + b <= s + 1) && (l + b <= s + 2 || l * (b - 1) * (s - l - (b - 1)) <= maxVolume) && (l + b <= s + 2 || b - l <= s + 1) && (l + b <= s + 2 || 0 <= b) && (l + b <= s + 1 || maxVolume >= 0) && (l + b <= s + 1 || 0 <= l) && (l + b <= s + 1 || 0 <= b) && (l * b * (s - l - b) <= maxVolume || l + b <= s + 1) && (l * b * (s - l - b) <= maxVolume || b <= s - l + 1) && (l * (b - 1) * (s - l - (b - 1)) <= maxVolume) && (l * (b - 1) * (s - l - (b - 1)) <= maxVolume || l + b <= s + 1) && (l * (b - 1) * (s - l - (b - 1)) <= maxVolume || b == 1) && (b <= s - l + 2) && (b - l <= s + 1) && (b - l <= s + 1 || l + b <= s + 1) && (b - l <= s + 1 || l * (b - 1) * (s - l - (b - 1)) <= maxVolume) && (b - l <= s + 1 || 0 <= b) && (b - l < s + 1) && (\forall integer t; 1 <= t < l ==> maxVolume >= t * (s - t) * 0) && (\forall integer t; 1 <= t < l ==> maxVolume >= 0) && (\forall integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0) && (\forall integer t; 1 <= t < b ==> maxVolume >= l * t * (s - l - t)) && (\forall integer t; 1 <= t < b ==> maxVolume >= 0) && (\forall integer t; 1 <= t < b ==> l * t * (s - l - t) <= maxVolume) && (\forall integer t; 1 <= t < b ==> l * t * (s - l - t) <= maxVolume || maxVolume == 0) && (\exists integer t; 1 <= t <= b ==> maxVolume >= l * t * (s - l - t)) && (\exists integer t; 1 <= t <= b ==> maxVolume >= 0) && (\exists integer t; 1 <= t <= b ==> maxVolume >= 0 || maxVolume == 0) && (\exists integer t; 1 <= t < l ==> maxVolume >= 0) && (\exists integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0) && (1 <= l) && (1 <= l || maxVolume >= 0) && (1 <= b) && (1 <= b || l + b <= s + 1) && (1 < l + b) && (0 <= s) && (0 <= maxVolume) && (0 <= l) && (0 <= l || b <= s - l + 1) && (0 <= b) && (0 <= b || l + b <= s + 1) && (0 <= b || l * (b - 1) * (s - l - (b - 1)) <= maxVolume) && (0 < l) && (0 < b);
    assigns \nothing;
*/
void check_B_implies_A(int *b, int foo315, int l, int maxVolume, int s, int *t) {
    /*@ assert (1 <= b <= s - l + 2); */
    /*@ assert (foo315 >= 0); */
    /*@ assert (s == \at(s,Pre)); */
}
