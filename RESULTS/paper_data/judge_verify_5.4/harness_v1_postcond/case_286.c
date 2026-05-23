#include <limits.h>
#include <stdlib.h>



/*@requires j + 1 > 0;*/
int stub_A(int j);

/*@loop invariant \forall integer k; 2 <= k < p ==> r[k] >= r[k - 2];
		loop invariant r_len == j + 1;
		loop invariant r[p - 2] <= r[p - 1];
		loop invariant r[1] == 1;
		loop invariant r[0] == 0;
		loop invariant r[0] == 0 && r[1] == 1;
		loop invariant p == 2 || r[p-1] == r[p-2] + 2 * r[p-3];
		loop invariant p == 2 || r[p - 1] >= r[p - 2];
		loop invariant p == 2 || r[p - 1] == r[p - 2] + 2 * r[p - 3];
		loop invariant \forall integer k; 2 <= k < p ==> r[k] >= r[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> r[k] >= 0;
		loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k-1] + 2 * r[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2];
		loop invariant \forall integer k; 1 <= k < p ==> r[k] >= r[k - 1];
		loop invariant \forall integer k; 0 <= k < p ==> r[k] >= 0;
		loop invariant \forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k-1] + 2 * r[k-2]));
		loop invariant \forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k - 1] + 2 * r[k - 2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 1]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k-1] + 2 * r[k-2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k - 1] + 2 * r[k - 2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> r[k] == 0) && (k == 1 ==> r[k] == 1);
		loop invariant \forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 2]);
		loop invariant \forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 1]);
		loop invariant \forall integer k; 0 <= k < p ==> (k < 2 || r[k] == r[k - 1] + 2 * r[k - 2]);
		loop invariant 2 <= p;
		loop invariant 0 <= r[p - 1];
		loop invariant 0 <= p;
		loop assigns r[2..j];
		loop assigns r[0..j];
		loop assigns p;*/
int stub_B(int j);

/*@loop invariant \forall integer k; 2 <= k < p ==> r[k] >= r[k - 2];
		loop invariant r_len == j + 1;
		loop invariant r[p - 2] <= r[p - 1];
		loop invariant r[1] == 1;
		loop invariant r[0] == 0;
		loop invariant r[0] == 0 && r[1] == 1;
		loop invariant p == 2 || r[p-1] == r[p-2] + 2 * r[p-3];
		loop invariant p == 2 || r[p - 1] >= r[p - 2];
		loop invariant p == 2 || r[p - 1] == r[p - 2] + 2 * r[p - 3];
		loop invariant \forall integer k; 2 <= k < p ==> r[k] >= r[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> r[k] >= 0;
		loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k-1] + 2 * r[k-2];
		loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2];
		loop invariant \forall integer k; 1 <= k < p ==> r[k] >= r[k - 1];
		loop invariant \forall integer k; 0 <= k < p ==> r[k] >= 0;
		loop invariant \forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k-1] + 2 * r[k-2]));
		loop invariant \forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k - 1] + 2 * r[k - 2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 1]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k-1] + 2 * r[k-2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k - 1] + 2 * r[k - 2]));
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> r[k] == 0) && (k == 1 ==> r[k] == 1);
		loop invariant \forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 2]);
		loop invariant \forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 1]);
		loop invariant \forall integer k; 0 <= k < p ==> (k < 2 || r[k] == r[k - 1] + 2 * r[k - 2]);
		loop invariant 2 <= p;
		loop invariant 0 <= r[p - 1];
		loop invariant 0 <= p;
		loop assigns r[2..j];
		loop assigns r[0..j];
		loop assigns p;*/
int check_A_implies_B(int j) {
    return stub_A(j);
}

/*@requires j + 1 > 0;*/
int check_B_implies_A(int j) {
    return stub_B(j);
}
