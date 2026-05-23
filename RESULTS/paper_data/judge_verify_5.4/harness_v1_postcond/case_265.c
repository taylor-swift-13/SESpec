#include <limits.h>


/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0);

  logic integer selected_odd(int* a, integer lo, integer hi, integer cnt) =
    lo >= hi ? 0 :
    (((a[lo] % 2) != 0) ?
      ((((cnt + 1) % 2) != 0) ? a[lo] : selected_odd(a, lo + 1, hi, cnt + 1)) :
      selected_odd(a, lo + 1, hi, cnt));

  logic integer last_odd(int* a, integer lo, integer hi) =
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires 0 <= array <= ints_len;
  assigns \nothing;
  ensures array <= 0 ==> \result == 0;*/
int stub_A(int * ints, int ints_len, int array);

/*@loop invariant start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant start != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> \exists integer t; 0 <= t <= index && ret == ints[t]);
		loop invariant start > 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start > 0 ==> ret != 0;
		loop invariant start > 0 ==> (ret == 0 || ret % 2 != 0);
		loop invariant start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0);
		loop invariant start == index || start == index - 1 || start <= index;
		loop invariant start == index || start == index + 1 || start <= index;
		loop invariant start == index - (index - start);
		loop invariant start == 0 || start >= 1;
		loop invariant start == 0 || start > 0;
		loop invariant start == 0 || start <= index;
		loop invariant start == 0 || start % 2 == 0 || start % 2 != 0;
		loop invariant start == 0 || ret != 0;
		loop invariant start == 0 ==> ret == 0;
		loop invariant start <= index;
		loop invariant start <= index + 1;
		loop invariant start <= array || 0 <= ret;
		loop invariant start % 2 == 0 || start % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0);
		loop invariant start % 2 != 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start % 2 != 0 ==> ret == 0 || ret != 0;
		loop invariant start % 2 != 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant start % 2 != 0 ==> ret != 0;
		loop invariant start % 2 != 0 ==> ret != 0 || ret == 0;
		loop invariant start != 0 ==> ret == 0 || ret != 0;
		loop invariant ret == 0 || ret % 2 != 0;
		loop invariant ret == 0 || ret != 0;
		loop invariant ret == 0 || \exists integer k; 0 <= k < index ==> ints[k] == ret;
		loop invariant ret == 0 || \exists integer k; 0 <= k < index && ints[k] == ret;
		loop invariant ret == 0 || (ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k]);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && (ints[k] % 2 != 0) && ret == ints[k]);
		loop invariant ret == 0 ==> start == 0;
		loop invariant ret == 0 ==> start == 0 || start > 0;
		loop invariant ret == 0 ==> start == 0 || start % 2 == 0;
		loop invariant ret != 0 ==> start > 0;
		loop invariant ret != 0 ==> ret % 2 != 0;
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0);
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k]);
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret);
		loop invariant index <= array || 0 <= ret;
		loop invariant \forall integer k; 0 <= k < index ==> ints[k] >= 0 || ints[k] < 0;
		loop invariant \forall integer k; 0 <= k < index ==> ints[k] % 2 == 0 || ints[k] % 2 != 0;
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 == 0 || ints[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 1);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 0);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start > 0);
		loop invariant \forall integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1;
		loop invariant \exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1;
		loop invariant \exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start > 0;
		loop invariant 0 <= start;
		loop invariant 0 <= index;
		loop assigns start;
		loop assigns ret;
		loop assigns index;*/
int stub_B(int * ints, int ints_len, int array);

/*@loop invariant start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant start != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> \exists integer t; 0 <= t <= index && ret == ints[t]);
		loop invariant start > 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start > 0 ==> ret != 0;
		loop invariant start > 0 ==> (ret == 0 || ret % 2 != 0);
		loop invariant start > 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0);
		loop invariant start == index || start == index - 1 || start <= index;
		loop invariant start == index || start == index + 1 || start <= index;
		loop invariant start == index - (index - start);
		loop invariant start == 0 || start >= 1;
		loop invariant start == 0 || start > 0;
		loop invariant start == 0 || start <= index;
		loop invariant start == 0 || start % 2 == 0 || start % 2 != 0;
		loop invariant start == 0 || ret != 0;
		loop invariant start == 0 ==> ret == 0;
		loop invariant start <= index;
		loop invariant start <= index + 1;
		loop invariant start <= array || 0 <= ret;
		loop invariant start % 2 == 0 || start % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0);
		loop invariant start % 2 != 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start % 2 != 0 ==> ret == 0 || ret != 0;
		loop invariant start % 2 != 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant start % 2 != 0 ==> ret != 0;
		loop invariant start % 2 != 0 ==> ret != 0 || ret == 0;
		loop invariant start != 0 ==> ret == 0 || ret != 0;
		loop invariant ret == 0 || ret % 2 != 0;
		loop invariant ret == 0 || ret != 0;
		loop invariant ret == 0 || \exists integer k; 0 <= k < index ==> ints[k] == ret;
		loop invariant ret == 0 || \exists integer k; 0 <= k < index && ints[k] == ret;
		loop invariant ret == 0 || (ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k]);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && (ints[k] % 2 != 0) && ret == ints[k]);
		loop invariant ret == 0 ==> start == 0;
		loop invariant ret == 0 ==> start == 0 || start > 0;
		loop invariant ret == 0 ==> start == 0 || start % 2 == 0;
		loop invariant ret != 0 ==> start > 0;
		loop invariant ret != 0 ==> ret % 2 != 0;
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret);
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] == ret && ints[k] % 2 != 0);
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ret == ints[k]);
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && ints[k] % 2 != 0 && ints[k] == ret);
		loop invariant index <= array || 0 <= ret;
		loop invariant \forall integer k; 0 <= k < index ==> ints[k] >= 0 || ints[k] < 0;
		loop invariant \forall integer k; 0 <= k < index ==> ints[k] % 2 == 0 || ints[k] % 2 != 0;
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 == 0 || ints[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 1);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start >= 0);
		loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> start > 0);
		loop invariant \forall integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1;
		loop invariant \exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start >= 1;
		loop invariant \exists integer k; 0 <= k < index && ints[k] % 2 != 0 ==> start > 0;
		loop invariant 0 <= start;
		loop invariant 0 <= index;
		loop assigns start;
		loop assigns ret;
		loop assigns index;*/
int check_A_implies_B(int * ints, int ints_len, int array) {
    return stub_A(ints, ints_len, array);
}

/*@requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires 0 <= array <= ints_len;
  assigns \nothing;
  ensures array <= 0 ==> \result == 0;*/
int check_B_implies_A(int * ints, int ints_len, int array) {
    return stub_B(ints, ints_len, array);
}
