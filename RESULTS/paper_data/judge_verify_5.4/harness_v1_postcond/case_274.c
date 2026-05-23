#include <limits.h>


/*@
  logic integer sum_even_even(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_even(arr, lo, hi - 1)
               + ((hi - 1) % 2 == 0 && arr[hi - 1] % 2 == 0 ? arr[hi - 1] : 0);
*/

/*@requires n >= 0;
  requires \valid_read(arr + (0..n-1));
  assigns \nothing;
  ensures \result == sum_even_even(arr, 0, n);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == sum_even_even(arr, 0, n - 1) + ((n - 1) % 2 == 0 && arr[n - 1] % 2 == 0 ? arr[n - 1] : 0);
  ensures \result >= sum_even_even(arr, 0, n);*/
int stub_A(int * arr, int arr_len, int n);

/*@loop invariant count >= 0 ==> count <= i * 2147483647;
        loop invariant count == 0 || count > 0 || count < 0;
        loop invariant \forall integer k; 0 <= k < i ==> (k < arr_len ==> arr[k] == arr[k]);
        loop invariant i <= n || 0 <= count;
        loop invariant i <= n ==> count <= count + i;
        loop invariant i % 2 == 0 || i % 2 == 1;
        loop invariant count >= 0 || count <= 0;
        loop invariant count >= 0 || count < 0;
        loop invariant count >= 0 || \true;
        loop invariant count >= 0 || \exists integer k; 0 <= k < i && arr[k] < 0;
        loop invariant count >= 0 ==> count + i >= 0;
        loop invariant count == count;
        loop invariant count == count + 0;
        loop invariant count == 0 || count < 0 || count > 0;
        loop invariant count == 0 || count % 2 == 0;
        loop invariant count == 0 || count % 2 == 0 || count % 2 == 1;
        loop invariant count == 0 || count != 0;
        loop invariant count == 0 || \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0;
        loop invariant count <= i * 2147483647;
        loop invariant count <= count + i;
        loop invariant count % 2 == 0;
        loop invariant count % 2 == 0 || count % 2 == 1;
        loop invariant count % 2 == 0 || count % 2 != 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= 0 || arr[k] < 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count + 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> \true);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> count >= arr[k] || count < arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> \true);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] == arr[k]));
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0));
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 != 0 ==> \true);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> arr[k] == arr[k];
        loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> (arr[k] % 2 != 0 ==> \true);
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 ==> count >= 0;
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 ==> \true;
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= arr[k];
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= 0;
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> \true;
        loop invariant \exists integer k; 0 <= k < i && arr[k] % 2 == 0 ==> count % 2 == 0;
        loop invariant 0 <= i;
        loop invariant -i * 2147483648 <= count;
        loop assigns i;
        loop assigns count;
        loop assigns arr[0..arr_len-1];*/
int stub_B(int * arr, int arr_len, int n);

/*@loop invariant count >= 0 ==> count <= i * 2147483647;
        loop invariant count == 0 || count > 0 || count < 0;
        loop invariant \forall integer k; 0 <= k < i ==> (k < arr_len ==> arr[k] == arr[k]);
        loop invariant i <= n || 0 <= count;
        loop invariant i <= n ==> count <= count + i;
        loop invariant i % 2 == 0 || i % 2 == 1;
        loop invariant count >= 0 || count <= 0;
        loop invariant count >= 0 || count < 0;
        loop invariant count >= 0 || \true;
        loop invariant count >= 0 || \exists integer k; 0 <= k < i && arr[k] < 0;
        loop invariant count >= 0 ==> count + i >= 0;
        loop invariant count == count;
        loop invariant count == count + 0;
        loop invariant count == 0 || count < 0 || count > 0;
        loop invariant count == 0 || count % 2 == 0;
        loop invariant count == 0 || count % 2 == 0 || count % 2 == 1;
        loop invariant count == 0 || count != 0;
        loop invariant count == 0 || \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0;
        loop invariant count <= i * 2147483647;
        loop invariant count <= count + i;
        loop invariant count % 2 == 0;
        loop invariant count % 2 == 0 || count % 2 == 1;
        loop invariant count % 2 == 0 || count % 2 != 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= 0 || arr[k] < 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> count == count + 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 1 ==> \true);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> count >= arr[k] || count < arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> \true);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] == arr[k]));
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 == 0 ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0));
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 != 0 || arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k % 2 != 0 ==> \true);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] == arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> arr[k] == arr[k];
        loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> (arr[k] % 2 != 0 ==> \true);
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 ==> count >= 0;
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 ==> \true;
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= arr[k];
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> count >= 0;
        loop invariant \exists integer k; 0 <= k < i && k % 2 == 0 && arr[k] % 2 == 0 ==> \true;
        loop invariant \exists integer k; 0 <= k < i && arr[k] % 2 == 0 ==> count % 2 == 0;
        loop invariant 0 <= i;
        loop invariant -i * 2147483648 <= count;
        loop assigns i;
        loop assigns count;
        loop assigns arr[0..arr_len-1];*/
int check_A_implies_B(int * arr, int arr_len, int n) {
    return stub_A(arr, arr_len, n);
}

/*@requires n >= 0;
  requires \valid_read(arr + (0..n-1));
  assigns \nothing;
  ensures \result == sum_even_even(arr, 0, n);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == sum_even_even(arr, 0, n - 1) + ((n - 1) % 2 == 0 && arr[n - 1] % 2 == 0 ? arr[n - 1] : 0);
  ensures \result >= sum_even_even(arr, 0, n);*/
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
