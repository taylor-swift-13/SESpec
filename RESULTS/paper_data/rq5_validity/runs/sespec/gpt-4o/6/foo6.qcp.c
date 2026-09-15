#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (is_sorted : Z -> Z -> Z -> Prop) */
/*@ Extern Coq (is_permutation : Z -> Z -> Z -> Z -> Prop) */

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) /*@
With a_l aux_l
Require store_int_array(a, a_len, a_l) && store_int_array(aux, aux_len, aux_l)
Ensure emp
*/
{
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;
   
  /*0*/ 
 /*@ Inv
    (lo <= i && i <= mid) &&
    (mid <= j && j <= hi) &&
    (lo <= k && k <= hi) &&
    (forall (x:Z), lo <= x && x < k => aux[x] == (x < i ? a[x] : (x < j ? a[j - (mid - i)] : a[i + (x - j)]))) &&
    (is_sorted(aux, lo, k)) &&
    (is_permutation(a, aux, lo, k))
    */
for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    /*@ Inv
    (lo <= k && k <= hi) &&
    (forall (x:Z), lo <= x && x < k => a[x] == aux[x])
    */
for (int k = lo; k < hi; k++) a[k] = aux[k];
}

void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi) /*@
With a_v aux_v
Require *(a) == a_v && *(aux) == aux_v
Ensure emp
*/
{
    if (hi - lo <= 1) return;
    int mid = lo + (hi - lo) / 2;
    foo28_helper5_c6(a, a_len, aux, aux_len, lo, mid);
    foo28_helper5_c6(a, a_len, aux, aux_len, mid, hi);
    foo28_helper4_c6(a, a_len, aux, aux_len, lo, mid, hi);
}

void foo6(int *a, int a_len) 
/*@
With a_v
Require *(a) == a_v
Ensure emp
*/{
    int *aux = (int *)malloc(sizeof(int) * a_len);
    foo28_helper5_c6(a, a_len, aux, a_len, 0, a_len);
}