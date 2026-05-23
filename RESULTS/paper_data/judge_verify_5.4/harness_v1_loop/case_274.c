#include <limits.h>

/*@logic integer sum_even_even(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_even(arr, lo, hi - 1)
               + ((hi - 1) % 2 == 0 && arr[hi - 1] % 2 == 0 ? arr[hi - 1] : 0);*/

/*@ requires (0 <= i <= n) && (count == sum_even_even(arr, 0, i)) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int arr, int arr_len, int count, int i, int k, int n) {
    /*@ assert (count >= 0 ==> count <= i * 2147483647) && (count == 0 || count > 0 || count < 0) && (\forall integer k) && (i <= n || 0 <= count) && (i <= n ==> count <= count + i) && (i % 2 == 0 || i % 2 == 1) && (count >= 0 || count <= 0) && (count >= 0 || count < 0) && (count >= 0 || \true) && (count >= 0 || \exists integer k) && (count >= 0 ==> count + i >= 0) && (count == count) && (count == count + 0) && (count == 0 || count < 0 || count > 0) && (count == 0 || count % 2 == 0) && (count == 0 || count % 2 == 0 || count % 2 == 1) && (count == 0 || count != 0) && (count == 0 || \exists integer k) && (count <= i * 2147483647) && (count <= count + i) && (count % 2 == 0) && (count % 2 == 0 || count % 2 == 1) && (count % 2 == 0 || count % 2 != 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (0 <= i) && (-i * 2147483648 <= count); */
}

/*@ requires (count >= 0 ==> count <= i * 2147483647) && (count == 0 || count > 0 || count < 0) && (\forall integer k) && (i <= n || 0 <= count) && (i <= n ==> count <= count + i) && (i % 2 == 0 || i % 2 == 1) && (count >= 0 || count <= 0) && (count >= 0 || count < 0) && (count >= 0 || \true) && (count >= 0 || \exists integer k) && (count >= 0 ==> count + i >= 0) && (count == count) && (count == count + 0) && (count == 0 || count < 0 || count > 0) && (count == 0 || count % 2 == 0) && (count == 0 || count % 2 == 0 || count % 2 == 1) && (count == 0 || count != 0) && (count == 0 || \exists integer k) && (count <= i * 2147483647) && (count <= count + i) && (count % 2 == 0) && (count % 2 == 0 || count % 2 == 1) && (count % 2 == 0 || count % 2 != 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (0 <= i) && (-i * 2147483648 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int arr, int arr_len, int count, int i, int k, int n) {
    /*@ assert (0 <= i <= n) && (count == sum_even_even(arr, 0, i)) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (\forall integer k); */
}
