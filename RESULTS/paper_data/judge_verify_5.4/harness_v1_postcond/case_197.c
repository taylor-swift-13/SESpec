#include <limits.h>
#include <stdlib.h>


/*@
predicate dummy1 = \true;
*/

predicate dummy2 = \true;

/*@loop invariant 0 <= k <= c;
              loop invariant arr[0] == 1;
              loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
              loop assigns k, arr[c];
              loop variant c - k;*/
int stub_A(int n);

/*@loop invariant k <= c;
			loop invariant c >= 1 || n == 0;
			loop invariant c == 0 || arr[c] >= 0;
			loop invariant c == 0 || 0 <= arr[c];
			loop invariant c == 0 ==> arr[0] == 1;
			loop invariant c <= n;
			loop invariant c <= n + 1;
			loop invariant c - k >= 0 || c == 0;
			loop invariant arr_len == n + 1;
			loop invariant arr[c] == 0 || arr[c] >= 0;
			loop invariant arr[0] == 1;
			loop invariant arr[0] <= arr[c] || 0 <= c + 1;
			loop invariant \forall integer t; k <= t < c ==> arr[t] >= 0;
			loop invariant \forall integer t; k <= t < c ==> arr[t] == 0 || arr[t] >= 0;
			loop invariant \forall integer t; k <= t < c ==> arr[c] >= 0;
			loop invariant \forall integer t; 0 <= t < k ==> arr[t] >= 0;
			loop invariant \forall integer t; 0 <= t < k ==> arr[t] == arr[t];
			loop invariant \forall integer t; 0 <= t < c ==> arr[t] >= 0;
			loop invariant \forall integer t; 0 <= t < c ==> arr[t] == arr[t];
			loop invariant \forall integer j; 0 <= j < c ==> arr[j] >= 0;
			loop invariant \forall integer j; 0 <= j < c ==> arr[j] == arr[j];
			loop invariant \forall integer i; 0 <= i < k ==> arr[i] >= 0;
			loop invariant \forall integer i; 0 <= i < k ==> arr[i] == arr[i];
			loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
			loop invariant \forall integer i; 0 <= i < c ==> arr[i] == arr[i];
			loop invariant 1 <= c;
			loop invariant 1 <= c + 1;
			loop invariant 0 <= k;
			loop invariant 0 <= c;
			loop invariant 0 <= c - k;
			loop invariant 0 <= c - k || arr[0] <= arr[c];
			loop invariant 0 <= c - k || 0 <= c + 1;
			loop invariant 0 <= c + 1;
			loop invariant 0 <= arr[c];
			loop invariant 0 < c + 1;
			loop assigns k;
			loop assigns arr[0..n];*/
int stub_B(int n);

/*@loop invariant k <= c;
			loop invariant c >= 1 || n == 0;
			loop invariant c == 0 || arr[c] >= 0;
			loop invariant c == 0 || 0 <= arr[c];
			loop invariant c == 0 ==> arr[0] == 1;
			loop invariant c <= n;
			loop invariant c <= n + 1;
			loop invariant c - k >= 0 || c == 0;
			loop invariant arr_len == n + 1;
			loop invariant arr[c] == 0 || arr[c] >= 0;
			loop invariant arr[0] == 1;
			loop invariant arr[0] <= arr[c] || 0 <= c + 1;
			loop invariant \forall integer t; k <= t < c ==> arr[t] >= 0;
			loop invariant \forall integer t; k <= t < c ==> arr[t] == 0 || arr[t] >= 0;
			loop invariant \forall integer t; k <= t < c ==> arr[c] >= 0;
			loop invariant \forall integer t; 0 <= t < k ==> arr[t] >= 0;
			loop invariant \forall integer t; 0 <= t < k ==> arr[t] == arr[t];
			loop invariant \forall integer t; 0 <= t < c ==> arr[t] >= 0;
			loop invariant \forall integer t; 0 <= t < c ==> arr[t] == arr[t];
			loop invariant \forall integer j; 0 <= j < c ==> arr[j] >= 0;
			loop invariant \forall integer j; 0 <= j < c ==> arr[j] == arr[j];
			loop invariant \forall integer i; 0 <= i < k ==> arr[i] >= 0;
			loop invariant \forall integer i; 0 <= i < k ==> arr[i] == arr[i];
			loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
			loop invariant \forall integer i; 0 <= i < c ==> arr[i] == arr[i];
			loop invariant 1 <= c;
			loop invariant 1 <= c + 1;
			loop invariant 0 <= k;
			loop invariant 0 <= c;
			loop invariant 0 <= c - k;
			loop invariant 0 <= c - k || arr[0] <= arr[c];
			loop invariant 0 <= c - k || 0 <= c + 1;
			loop invariant 0 <= c + 1;
			loop invariant 0 <= arr[c];
			loop invariant 0 < c + 1;
			loop assigns k;
			loop assigns arr[0..n];*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@loop invariant 0 <= k <= c;
              loop invariant arr[0] == 1;
              loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
              loop assigns k, arr[c];
              loop variant c - k;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
