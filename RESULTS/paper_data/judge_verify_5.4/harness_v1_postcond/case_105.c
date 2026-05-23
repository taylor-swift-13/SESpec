#include <limits.h>
#include <stdlib.h>


/*@ logic integer fibo(integer n) =
      n <= 1 ? n : fibo(n - 1) + fibo(n - 2);
*/

/*@ensures n < 0 ==> \result == -1;
  ensures n == 0 ==> \result == 0;*/
int stub_A(int n);

/*@loop invariant index == 2 || fib[index - 1] >= fib[index - 2];
		loop invariant index == 2 || fib[index - 1] == fib[index - 2] + fib[index - 3];
		loop invariant index == 2 ==> fib[0] == 0 && fib[1] == 1;
		loop invariant index <= n + 1;
		loop invariant index <= fib_len;
		loop invariant index - 2 <= n - 1;
		loop invariant fib_len == n + 1;
		loop invariant fib[index-2] <= fib[index-1];
		loop invariant fib[index - 2] <= fib[index - 1];
		loop invariant fib[1] == 1;
		loop invariant fib[0] == 0;
		loop invariant fib[0] == 0 && fib[1] == 1;
		loop invariant fib[0] == 0 && fib[1] == 1 && index >= 2;
		loop invariant fib[0] == 0 && fib[1] == 1 && fib_len == n + 1;
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k-2];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k-1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 2];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k-2] + fib[k-1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k-1] + fib[k-2];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k - 2] + fib[k - 1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k - 1] + fib[k - 2];
		loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= fib[k-1];
		loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= fib[k - 1];
		loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= 1;
		loop invariant \forall integer k; 0 <= k < index ==> fib[k] >= 0;
		loop invariant \forall integer k; 0 <= k < 2 ==> fib[k] >= 0;
		loop invariant 2 <= index;
		loop invariant 2 <= index || index == 2;
		loop invariant 2 <= index || fib_len <= 2;
		loop invariant 2 <= index ==> fib[index-1] >= fib[index-2];
		loop invariant 2 <= index ==> fib[index - 1] >= fib[index - 2];
		loop invariant 2 <= index ==> fib[0] == 0 && fib[1] == 1;
		loop invariant 0 <= n;
		loop invariant 0 <= index;
		loop invariant 0 <= index - 2;
		loop assigns index;
		loop assigns fib[2..n];
		loop assigns fib[2..fib_len-1];
		loop assigns fib[0..n];
		loop assigns fib[0..fib_len-1];*/
int stub_B(int n);

/*@loop invariant index == 2 || fib[index - 1] >= fib[index - 2];
		loop invariant index == 2 || fib[index - 1] == fib[index - 2] + fib[index - 3];
		loop invariant index == 2 ==> fib[0] == 0 && fib[1] == 1;
		loop invariant index <= n + 1;
		loop invariant index <= fib_len;
		loop invariant index - 2 <= n - 1;
		loop invariant fib_len == n + 1;
		loop invariant fib[index-2] <= fib[index-1];
		loop invariant fib[index - 2] <= fib[index - 1];
		loop invariant fib[1] == 1;
		loop invariant fib[0] == 0;
		loop invariant fib[0] == 0 && fib[1] == 1;
		loop invariant fib[0] == 0 && fib[1] == 1 && index >= 2;
		loop invariant fib[0] == 0 && fib[1] == 1 && fib_len == n + 1;
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k-2];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k-1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 2];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k-2] + fib[k-1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k-1] + fib[k-2];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k - 2] + fib[k - 1];
		loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k - 1] + fib[k - 2];
		loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= fib[k-1];
		loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= fib[k - 1];
		loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= 1;
		loop invariant \forall integer k; 0 <= k < index ==> fib[k] >= 0;
		loop invariant \forall integer k; 0 <= k < 2 ==> fib[k] >= 0;
		loop invariant 2 <= index;
		loop invariant 2 <= index || index == 2;
		loop invariant 2 <= index || fib_len <= 2;
		loop invariant 2 <= index ==> fib[index-1] >= fib[index-2];
		loop invariant 2 <= index ==> fib[index - 1] >= fib[index - 2];
		loop invariant 2 <= index ==> fib[0] == 0 && fib[1] == 1;
		loop invariant 0 <= n;
		loop invariant 0 <= index;
		loop invariant 0 <= index - 2;
		loop assigns index;
		loop assigns fib[2..n];
		loop assigns fib[2..fib_len-1];
		loop assigns fib[0..n];
		loop assigns fib[0..fib_len-1];*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ensures n < 0 ==> \result == -1;
  ensures n == 0 ==> \result == 0;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
