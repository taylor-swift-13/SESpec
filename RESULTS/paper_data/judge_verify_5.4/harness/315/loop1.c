#include <limits.h>

/*@ requires (l >= 1) && (s == \at(s,Pre)) && (foo315 >= 0);
    assigns \nothing;
*/
void check_A_implies_B(int foo315, int l, int maxVolume, int s, int t) {
    /*@ assert (l * (s - l) * 0 <= maxVolume); */
    /*@ assert (0 < l); */
    /*@ assert (maxVolume >= 0 || l <= s); */
    /*@ assert (maxVolume >= 0 || l <= s + 1); */
    /*@ assert (maxVolume == 0 || maxVolume > 0); */
    /*@ assert (l <= s + 1 ==> maxVolume >= 0); */
    /*@ assert (\forall integer t; 1 <= t < l ==> maxVolume >= t * (s - t) * 0); */
    /*@ assert (\forall integer t; 1 <= t < l ==> maxVolume >= 0); */
    /*@ assert (\forall integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0); */
    /*@ assert (\exists integer t; 1 <= t <= l ==> maxVolume >= 0); */
    /*@ assert (\exists integer t; 1 <= t < l ==> maxVolume >= 0); */
    /*@ assert (\exists integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0); */
    /*@ assert (1 <= l); */
    /*@ assert (1 <= l || maxVolume == 0); */
    /*@ assert (0 <= maxVolume); */
    /*@ assert (0 <= l); */
    /*@ assert (0 <= l && 0 <= maxVolume); */
}

/*@ requires (l * (s - l) * 0 <= maxVolume) && (0 < l) && (maxVolume >= 0 || l <= s) && (maxVolume >= 0 || l <= s + 1) && (maxVolume == 0 || maxVolume > 0) && (l <= s + 1 ==> maxVolume >= 0) && (\forall integer t; 1 <= t < l ==> maxVolume >= t * (s - t) * 0) && (\forall integer t; 1 <= t < l ==> maxVolume >= 0) && (\forall integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0) && (\exists integer t; 1 <= t <= l ==> maxVolume >= 0) && (\exists integer t; 1 <= t < l ==> maxVolume >= 0) && (\exists integer t; 1 <= t < l ==> maxVolume >= 0 || maxVolume == 0) && (1 <= l) && (1 <= l || maxVolume == 0) && (0 <= maxVolume) && (0 <= l) && (0 <= l && 0 <= maxVolume);
    assigns \nothing;
*/
void check_B_implies_A(int foo315, int l, int maxVolume, int s, int t) {
    /*@ assert (l >= 1); */
    /*@ assert (s == \at(s,Pre)); */
    /*@ assert (foo315 >= 0); */
}
