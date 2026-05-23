#include <limits.h>


/*@
  logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0);

  logic integer last_odd(int* a, integer lo, integer hi) =
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= arrSize <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result % 2 != 0;*/
int stub_A(int * arr, int arr_len, int arrSize);

/*@loop invariant result == 0 || result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result == 0 || result % 2 != 0;
        loop invariant result == 0 || result != 0;
        loop invariant result == 0 || count >= 1;
        loop invariant result == 0 || arrSize > 0;
        loop invariant result == 0 || \exists integer k; 0 <= k < i ==> arr[k] == result;
        loop invariant result == 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0;
        loop invariant result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result;
        loop invariant result == 0 || (result % 2 != 0);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k]);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result);
        loop invariant result == 0 || (\exists integer j; 0 <= j < i && arr[j] == result && arr[j] % 2 != 0);
        loop invariant result != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result != 0 ==> result % 2 != 0;
        loop invariant result != 0 ==> arr[i-1] == result || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0;
        loop invariant result != 0 ==> \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result;
        loop invariant result != 0 ==> (result % 2 != 0);
        loop invariant result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0);
        loop invariant result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result);
        loop invariant count > 0 ==> result == 0 || result % 2 != 0;
        loop invariant count > 0 ==> result == 0 || result != 0;
        loop invariant count > 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count > 0 ==> result != 0;
        loop invariant count > 0 ==> result != 0 || result == arr[i-1];
        loop invariant count > 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count == i || count <= i;
        loop invariant count == i || count < i;
        loop invariant count == 0 || result != 0;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 || count % 2 == 1 || count % 2 == 0;
        loop invariant count == 0 ==> result == 0;
        loop invariant count <= i;
        loop invariant count <= i + 1;
        loop invariant count <= i + 1 || i <= arrSize;
        loop invariant count <= i + 1 || count <= arrSize;
        loop invariant count < i + 1;
        loop invariant count % 2 == i % 2 || count % 2 != i % 2;
        loop invariant count % 2 == 0 || count % 2 == 1;
        loop invariant count % 2 == 0 || count % 2 != 0;
        loop invariant count % 2 == 0 ==> result == 0 || result % 2 != 0;
        loop invariant count % 2 == 0 ==> result == 0 || result != 0;
        loop invariant count % 2 == 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count % 2 == 0 ==> (result == 0 || result % 2 != 0);
        loop invariant count % 2 == 0 ==> (result == 0 || result != 0);
        loop invariant count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k]);
        loop invariant count % 2 <= 1;
        loop invariant count % 2 != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count % 2 != 0 ==> result == arr[i-1] || (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count % 2 != 0 ==> result != 0;
        loop invariant count % 2 != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count % 2 != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count != 0 ==> result == 0 || result != 0;
        loop invariant count != 0 ==> result != 0;
        loop invariant count != 0 ==> result != 0 || result == arr[i-1];
        loop invariant count != 0 ==> result != 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] % 2 == 0 || arr[k] % 2 != 0;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> count >= 1);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> \exists integer j; 0 <= j <= k && arr[j] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> count >= 1;
        loop invariant \forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> (count >= 1);
        loop invariant \exists integer k; 0 <= k < i ==> arr[k] == result;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop invariant 0 <= count % 2;
        loop invariant (result != 0) ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant (count % 2 == 0) ==> (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result));
        loop invariant (count % 2 != 0) ==> result != 0;
        loop invariant (count % 2 != 0) ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0);
        loop invariant (count % 2 != 0) ==> (result != 0);
        loop invariant (count % 2 != 0) ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k]);
        loop invariant (\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0));
        loop assigns result;
        loop assigns i;
        loop assigns count;*/
int stub_B(int * arr, int arr_len, int arrSize);

/*@loop invariant result == 0 || result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result == 0 || result % 2 != 0;
        loop invariant result == 0 || result != 0;
        loop invariant result == 0 || count >= 1;
        loop invariant result == 0 || arrSize > 0;
        loop invariant result == 0 || \exists integer k; 0 <= k < i ==> arr[k] == result;
        loop invariant result == 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0;
        loop invariant result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result;
        loop invariant result == 0 || (result % 2 != 0);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k]);
        loop invariant result == 0 || (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result);
        loop invariant result == 0 || (\exists integer j; 0 <= j < i && arr[j] == result && arr[j] % 2 != 0);
        loop invariant result != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result != 0 ==> result % 2 != 0;
        loop invariant result != 0 ==> arr[i-1] == result || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant result != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0;
        loop invariant result != 0 ==> \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result;
        loop invariant result != 0 ==> (result % 2 != 0);
        loop invariant result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0);
        loop invariant result != 0 ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && arr[k] == result);
        loop invariant count > 0 ==> result == 0 || result % 2 != 0;
        loop invariant count > 0 ==> result == 0 || result != 0;
        loop invariant count > 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count > 0 ==> result != 0;
        loop invariant count > 0 ==> result != 0 || result == arr[i-1];
        loop invariant count > 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count == i || count <= i;
        loop invariant count == i || count < i;
        loop invariant count == 0 || result != 0;
        loop invariant count == 0 || count >= 1;
        loop invariant count == 0 || count > 0;
        loop invariant count == 0 || count % 2 == 1 || count % 2 == 0;
        loop invariant count == 0 ==> result == 0;
        loop invariant count <= i;
        loop invariant count <= i + 1;
        loop invariant count <= i + 1 || i <= arrSize;
        loop invariant count <= i + 1 || count <= arrSize;
        loop invariant count < i + 1;
        loop invariant count % 2 == i % 2 || count % 2 != i % 2;
        loop invariant count % 2 == 0 || count % 2 == 1;
        loop invariant count % 2 == 0 || count % 2 != 0;
        loop invariant count % 2 == 0 ==> result == 0 || result % 2 != 0;
        loop invariant count % 2 == 0 ==> result == 0 || result != 0;
        loop invariant count % 2 == 0 ==> result == 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count % 2 == 0 ==> (result == 0 || result % 2 != 0);
        loop invariant count % 2 == 0 ==> (result == 0 || result != 0);
        loop invariant count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count % 2 == 0 ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k]);
        loop invariant count % 2 <= 1;
        loop invariant count % 2 != 0 ==> result == arr[i-1] || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count % 2 != 0 ==> result == arr[i-1] || (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count % 2 != 0 ==> result != 0;
        loop invariant count % 2 != 0 ==> \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count % 2 != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant count != 0 ==> result == 0 || result != 0;
        loop invariant count != 0 ==> result != 0;
        loop invariant count != 0 ==> result != 0 || result == arr[i-1];
        loop invariant count != 0 ==> result != 0 || \exists integer k; 0 <= k < i && arr[k] == result;
        loop invariant count != 0 ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] % 2 == 0 || arr[k] % 2 != 0;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> count >= 1);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] % 2 != 0 ==> \exists integer j; 0 <= j <= k && arr[j] % 2 != 0);
        loop invariant \forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> count >= 1;
        loop invariant \forall integer k; 0 <= k < i && arr[k] % 2 != 0 ==> (count >= 1);
        loop invariant \exists integer k; 0 <= k < i ==> arr[k] == result;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop invariant 0 <= count % 2;
        loop invariant (result != 0) ==> (\exists integer k; 0 <= k < i && arr[k] == result);
        loop invariant (count % 2 == 0) ==> (result == 0 || (\exists integer k; 0 <= k < i && arr[k] == result));
        loop invariant (count % 2 != 0) ==> result != 0;
        loop invariant (count % 2 != 0) ==> (result == 0 || \exists integer k; 0 <= k < i && arr[k] == result && arr[k] % 2 != 0);
        loop invariant (count % 2 != 0) ==> (result != 0);
        loop invariant (count % 2 != 0) ==> (\exists integer k; 0 <= k < i && arr[k] % 2 != 0 && result == arr[k]);
        loop invariant (\forall integer k; 0 <= k < i ==> (arr[k] % 2 == 0 || arr[k] % 2 != 0));
        loop assigns result;
        loop assigns i;
        loop assigns count;*/
int check_A_implies_B(int * arr, int arr_len, int arrSize) {
    return stub_A(arr, arr_len, arrSize);
}

/*@requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= arrSize <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result % 2 != 0;*/
int check_B_implies_A(int * arr, int arr_len, int arrSize) {
    return stub_B(arr, arr_len, arrSize);
}
