#include <limits.h>

/*@ ensures by2 - by1 > 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures by2 - by1 > 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures by2 - ay1 > 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures ay2 - by1 > 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures ay2 - ay1 > 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - by1 > 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures by2 - by1 > 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures by2 - ay1 > 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures ay2 - by1 > 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures ay2 - ay1 > 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - by1 > 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures by2 - by1 > 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures by2 - ay1 > 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures ay2 - by1 > 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures ay2 - ay1 > 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures by2 - by1 > 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures by2 - by1 > 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures by2 - ay1 > 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures ay2 - by1 > 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures ay2 - ay1 > 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;


assigns \nothing; */
int stub_A(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

/*@ requires by1 <= by2;
requires bx1 <= bx2;
requires ay1 <= ay2;
requires ax1 <= ax2;
requires ((ay2 < by2?ay2:by2) - (ay1>by1?ay1:by1)) >= 0;
requires ((ax2 < bx2?ax2:bx2) - (ax1>bx1?ax1:bx1)) >= 0;
ensures \result >= 0;
ensures \result <= (bx2 - bx1) * (by2 - by1);
ensures \result <= (ax2 - ax1) * (ay2 - ay1);
assigns \nothing; */
int stub_B(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

/*@ requires by1 <= by2;
requires bx1 <= bx2;
requires ay1 <= ay2;
requires ax1 <= ax2;
requires ((ay2 < by2?ay2:by2) - (ay1>by1?ay1:by1)) >= 0;
requires ((ax2 < bx2?ax2:bx2) - (ax1>bx1?ax1:bx1)) >= 0;
ensures \result >= 0;
ensures \result <= (bx2 - bx1) * (by2 - by1);
ensures \result <= (ax2 - ax1) * (ay2 - ay1);
assigns \nothing; */
int check_A_implies_B(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    return stub_A(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
}

/*@ ensures by2 - by1 > 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures by2 - by1 > 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures by2 - ay1 > 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures ay2 - by1 > 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == (ax2 - ax1) * 0;

ensures ay2 - ay1 > 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - by1 > 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures by2 - by1 > 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures by2 - ay1 > 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures ay2 - by1 > 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && ax2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == (ax2 - bx1) * 0;

ensures ay2 - ay1 > 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && ax2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 < bx2 ==> \result == 0 * 0;

ensures by2 - by1 > 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures by2 - by1 > 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures by2 - ay1 > 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - ax1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures ay2 - by1 > 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - ax1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - ax1 > 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == (bx2 - ax1) * 0;

ensures ay2 - ay1 > 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - ax1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 > bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures by2 - by1 > 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures by2 - by1 > 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - by1);

ensures by2 - by1 <= 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures by2 - ay1 > 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures by2 - ay1 > 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (by2 - ay1);

ensures by2 - ay1 <= 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 >= by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - by1 > 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - bx1 > 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures ay2 - by1 > 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - by1);

ensures ay2 - by1 <= 0 && bx2 - bx1 <= 0 && ay1 <= by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;

ensures ay2 - ay1 > 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - bx1 > 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == (bx2 - bx1) * 0;

ensures ay2 - ay1 > 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * (ay2 - ay1);

ensures ay2 - ay1 <= 0 && bx2 - bx1 <= 0 && ay1 > by1 && ay2 < by2 && ax1 <= bx1 && ax2 >= bx2 ==> \result == 0 * 0;


assigns \nothing; */
int check_B_implies_A(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    return stub_B(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
}
