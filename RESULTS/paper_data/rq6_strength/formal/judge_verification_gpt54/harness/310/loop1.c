#include <limits.h>

/*@ requires (0 <= left <= num + 1) && (-1 <= right <= num) && (left <= right + 1) && ((0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (0 <= left <= num + 1))) && ((0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (-1 <= right <= num))) && ((!(0 <= \at(num,Pre))) ==> ((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre)))) && (num == \at(num,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *left, int num, int *right) {
    /*@ assert (right <= num); */
    /*@ assert (right <= num && right >= -1); */
    /*@ assert (right < num + 1); */
    /*@ assert (right * right > num ==> right >= 0); */
    /*@ assert (right * right <= num || right * right > num); */
    /*@ assert (right * right <= num ==> right <= num); */
    /*@ assert (right * right <= (num + 1) * (num + 1)); */
    /*@ assert (right * right <= (num + 1) * (num + 1) || right * right > num); */
    /*@ assert (right * right <= (num + 1) * (num + 1) || left * left > num); */
    /*@ assert (left == 0 || right >= 0); */
    /*@ assert (left == 0 || right >= -1); */
    /*@ assert (left <= right + 5); */
    /*@ assert (left <= right + 4); */
    /*@ assert (left <= right + 3); */
    /*@ assert (left <= right + 3 || right < 0); */
    /*@ assert (left <= right + 2); */
    /*@ assert (left <= right + 2 || right < 0); */
    /*@ assert (left <= right + 1); */
    /*@ assert (left <= right + 1 || right < 0); */
    /*@ assert (left <= right + 1 || left == right + 2); */
    /*@ assert (left <= num); */
    /*@ assert (left <= num || right <= num); */
    /*@ assert (left <= num + 1); */
    /*@ assert (left <= num + 1 && right >= -1); */
    /*@ assert (left <= num + 1 && right <= num); */
    /*@ assert (left <= num + 1 && 0 <= right); */
    /*@ assert (left <= num && 0 <= left); */
    /*@ assert (left - right <= 5); */
    /*@ assert (left - right <= 4); */
    /*@ assert (left - right <= 3); */
    /*@ assert (left - right <= 2); */
    /*@ assert (left - right <= 2 || left * left <= (num + 1) * (num + 1)); */
    /*@ assert (left - right <= 1); */
    /*@ assert (left - right < 2); */
    /*@ assert (left * left > num ==> left >= 0); */
    /*@ assert (left * left > num ==> left > 0); */
    /*@ assert (left * left <= (num + 2) * (num + 2)); */
    /*@ assert (left * left <= (num + 1) * (num + 1)); */
    /*@ assert (left * left <= (num + 1) * (num + 1) || right * right > num); */
    /*@ assert (left * left <= (num + 1) * (num + 1) || left * left > num); */
    /*@ assert (left * left <= (num + 1) * (num + 1) && 0 <= left); */
    /*@ assert (left * left < (num + 1) * (num + 1)); */
    /*@ assert (0 <= right); */
    /*@ assert (0 <= right || right == -1); */
    /*@ assert (0 <= right * right); */
    /*@ assert (0 <= right && right <= num); */
    /*@ assert (0 <= left); */
    /*@ assert (0 <= left && left <= num + 1); */
    /*@ assert (0 <= left && 0 <= right); */
    /*@ assert (-1 <= right); */
    /*@ assert (-1 <= right && right <= num); */
}

/*@ requires (right <= num) && (right <= num && right >= -1) && (right < num + 1) && (right * right > num ==> right >= 0) && (right * right <= num || right * right > num) && (right * right <= num ==> right <= num) && (right * right <= (num + 1) * (num + 1)) && (right * right <= (num + 1) * (num + 1) || right * right > num) && (right * right <= (num + 1) * (num + 1) || left * left > num) && (left == 0 || right >= 0) && (left == 0 || right >= -1) && (left <= right + 5) && (left <= right + 4) && (left <= right + 3) && (left <= right + 3 || right < 0) && (left <= right + 2) && (left <= right + 2 || right < 0) && (left <= right + 1) && (left <= right + 1 || right < 0) && (left <= right + 1 || left == right + 2) && (left <= num) && (left <= num || right <= num) && (left <= num + 1) && (left <= num + 1 && right >= -1) && (left <= num + 1 && right <= num) && (left <= num + 1 && 0 <= right) && (left <= num && 0 <= left) && (left - right <= 5) && (left - right <= 4) && (left - right <= 3) && (left - right <= 2) && (left - right <= 2 || left * left <= (num + 1) * (num + 1)) && (left - right <= 1) && (left - right < 2) && (left * left > num ==> left >= 0) && (left * left > num ==> left > 0) && (left * left <= (num + 2) * (num + 2)) && (left * left <= (num + 1) * (num + 1)) && (left * left <= (num + 1) * (num + 1) || right * right > num) && (left * left <= (num + 1) * (num + 1) || left * left > num) && (left * left <= (num + 1) * (num + 1) && 0 <= left) && (left * left < (num + 1) * (num + 1)) && (0 <= right) && (0 <= right || right == -1) && (0 <= right * right) && (0 <= right && right <= num) && (0 <= left) && (0 <= left && left <= num + 1) && (0 <= left && 0 <= right) && (-1 <= right) && (-1 <= right && right <= num);
    assigns \nothing;
*/
void check_B_implies_A(int *left, int num, int *right) {
    /*@ assert (0 <= left <= num + 1); */
    /*@ assert (-1 <= right <= num); */
    /*@ assert (left <= right + 1); */
    /*@ assert ((0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (0 <= left <= num + 1))); */
    /*@ assert ((0 <= \at(num,Pre)) ==> (((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre))) || (-1 <= right <= num))); */
    /*@ assert ((!(0 <= \at(num,Pre))) ==> ((right == \at(num,Pre))&&(left == 0)&&(num == \at(num,Pre)))); */
    /*@ assert (num == \at(num,Pre)); */
}
