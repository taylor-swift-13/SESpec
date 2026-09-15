#include <limits.h>
#include <stdlib.h>



/*@requires c >= 1;*/
int stub_A(int c);

/*@loop invariant p == 2 || j[p - 1] > 0;
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > j[k - 1] || j[k] > j[k - 2];
		loop invariant p == 2 || \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2];
		loop invariant j_len == c + 1;
		loop invariant j[1] == 1;
		loop invariant j[0] == 2;
		loop invariant j[0] == 2 && j[1] == 1;
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-2] && j[k] >= j[k-1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-1] && j[k] >= j[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 2] && j[k] >= j[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 1] && j[k] >= j[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > j[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > j[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > 0;
		loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k-1] + 2 * j[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2];
		loop invariant \forall integer k; 0 <= k < p ==> j[k] >= 1;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] >= 1 || k == 1;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] >= 0;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] > 0;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] >= 1;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] > 0;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] != 0;
		loop invariant \forall integer k; 0 <= k < p ==> (k == 1 ==> j[k] == 1);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2) && (k == 1 ==> j[k] == 1);
		loop invariant \forall integer k; 0 <= k < 2 ==> j[k] > 0;
		loop invariant \forall integer k; 0 <= k < 2 ==> j[k] == (k == 0 ? 2 : 1);
		loop invariant 2 <= p;
		loop invariant 0 <= p;
		loop assigns p;
		loop assigns j[2..c];
		loop assigns j[0..c];*/
int stub_B(int c);

/*@loop invariant p == 2 || j[p - 1] > 0;
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > j[k - 1] || j[k] > j[k - 2];
		loop invariant p == 2 || \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2];
		loop invariant j_len == c + 1;
		loop invariant j[1] == 1;
		loop invariant j[0] == 2;
		loop invariant j[0] == 2 && j[1] == 1;
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-2] && j[k] >= j[k-1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k-1] && j[k] >= j[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 2] && j[k] >= j[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] >= j[k - 1] && j[k] >= j[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > j[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > j[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] > 0;
		loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k-1] + 2 * j[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2];
		loop invariant \forall integer k; 0 <= k < p ==> j[k] >= 1;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] >= 1 || k == 1;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] >= 0;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] > 0;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] >= 1;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] > 0;
		loop invariant \forall integer k; 0 <= k < p ==> j[k] != 0;
		loop invariant \forall integer k; 0 <= k < p ==> (k == 1 ==> j[k] == 1);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2) && (k == 1 ==> j[k] == 1);
		loop invariant \forall integer k; 0 <= k < 2 ==> j[k] > 0;
		loop invariant \forall integer k; 0 <= k < 2 ==> j[k] == (k == 0 ? 2 : 1);
		loop invariant 2 <= p;
		loop invariant 0 <= p;
		loop assigns p;
		loop assigns j[2..c];
		loop assigns j[0..c];*/
int check_A_implies_B(int c) {
    return stub_A(c);
}

/*@requires c >= 1;*/
int check_B_implies_A(int c) {
    return stub_B(c);
}
