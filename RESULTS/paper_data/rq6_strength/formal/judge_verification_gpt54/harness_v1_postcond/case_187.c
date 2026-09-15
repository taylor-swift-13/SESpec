#include <limits.h>


/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires size > 0;
  requires size <= array_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size != 0 ==> \result >= 1;*/
int stub_A(int size, int * array, int array_len);

/*@loop invariant max <= c && max >= 1;
		loop invariant c > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f);
		loop invariant max >= 1 || c == 0;
		loop invariant max >= 1 ==> f <= array[0];
		loop invariant max >= 1 ==> c >= 1;
		loop invariant max >= 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k];
		loop invariant max >= 1 && f <= array[0];
		loop invariant max >= 1 && c >= 0;
		loop invariant max > 1 ==> max <= c;
		loop invariant max > 1 ==> c > 1;
		loop invariant max > 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f;
		loop invariant max > 1 ==> \exists integer k; 1 <= k < c && array[k] == f;
		loop invariant max > 1 ==> \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant max > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f);
		loop invariant max == 1 || max > 1;
		loop invariant max == 1 ==> f <= array[c-1];
		loop invariant max == 1 ==> f <= array[0];
		loop invariant max == 1 ==> c >= 1;
		loop invariant max == 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k];
		loop invariant max == 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f;
		loop invariant max == 1 ==> \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant max == 1 ==> (\forall integer k; 0 <= k < c ==> f <= array[k]);
		loop invariant max <= c;
		loop invariant max <= c + 1;
		loop invariant f == array[0] || f <= array[c-1];
		loop invariant f == array[0] || \exists integer k; 0 <= k < c && f == array[k];
		loop invariant f == array[0] || (\exists integer k; 0 <= k < c && f == array[k]);
		loop invariant f <= array[c-1];
		loop invariant f <= array[c-1] || c == 1;
		loop invariant f <= array[c-1] || c <= size;
		loop invariant f <= array[c-1] || 0 <= max;
		loop invariant f <= array[c-1] || 0 < size;
		loop invariant f <= array[0];
		loop invariant f <= array[0] || f == array[0];
		loop invariant f <= array[0] || f <= array[c];
		loop invariant f <= array[0] || f <= array[c-1];
		loop invariant f <= array[0] || c == 1;
		loop invariant c > 1 ==> max >= 1;
		loop invariant c > 1 ==> \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant c == 1 ==> max == 1;
		loop invariant c == 1 ==> f == array[0];
		loop invariant c <= size || 0 <= max;
		loop invariant c <= size ==> max >= 1;
		loop invariant \forall integer k; 1 <= k < c ==> f <= array[k];
		loop invariant \forall integer k; 0 <= k < c ==> f <= array[k];
		loop invariant \forall integer k; 0 <= k < c ==> f <= array[k] || array[k] == f;
		loop invariant \forall integer k; 0 <= k < c ==> f <= array[k] || array[k] < f;
		loop invariant \forall integer k; 0 <= k < c ==> array[k] >= f;
		loop invariant \forall integer k; 0 <= k < c ==> array[k] >= f || array[k] == f;
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] >= f);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] == f || array[k] > f);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] == f ==> max >= 1);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] < f ==> max >= 1);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] < f ==> \false);
		loop invariant \forall integer k; 0 <= k < c && array[k] == f ==> max >= 1;
		loop invariant \forall integer i; 0 <= i < c ==> f <= array[i];
		loop invariant \forall integer i; 0 <= i < c ==> (array[i] == f ==> max >= 1);
		loop invariant \forall integer i; 0 <= i < c && array[i] == f ==> max >= 1;
		loop invariant \exists integer k; 0 <= k < c ==> array[k] <= f;
		loop invariant \exists integer k; 0 <= k < c && f == array[k];
		loop invariant \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant \exists integer i; 0 <= i < c && f == array[i];
		loop invariant 1 <= max;
		loop invariant 1 <= c;
		loop invariant 1 <= c || size == 0;
		loop invariant 0 <= max;
		loop invariant 0 <= c;
		loop invariant 0 < size || 0 <= max;
		loop invariant 0 < size ==> 1 <= max;
		loop invariant 0 < size ==> 0 < max;
		loop invariant 0 < max;
		loop invariant 0 < c;
		loop invariant (max == 1) || (max > 1);
		loop invariant (max == 1) || (\exists integer k; 0 <= k < c && array[k] == f);
		loop invariant (\forall integer k; 0 <= k < c ==> array[k] >= f);
		loop invariant (\exists integer i; 0 <= i < c && f == array[i]);
		loop assigns max;
		loop assigns f;
		loop assigns c;*/
int stub_B(int size, int * array, int array_len);

/*@loop invariant max <= c && max >= 1;
		loop invariant c > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f);
		loop invariant max >= 1 || c == 0;
		loop invariant max >= 1 ==> f <= array[0];
		loop invariant max >= 1 ==> c >= 1;
		loop invariant max >= 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k];
		loop invariant max >= 1 && f <= array[0];
		loop invariant max >= 1 && c >= 0;
		loop invariant max > 1 ==> max <= c;
		loop invariant max > 1 ==> c > 1;
		loop invariant max > 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f;
		loop invariant max > 1 ==> \exists integer k; 1 <= k < c && array[k] == f;
		loop invariant max > 1 ==> \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant max > 1 ==> (\exists integer k; 0 <= k < c && array[k] == f);
		loop invariant max == 1 || max > 1;
		loop invariant max == 1 ==> f <= array[c-1];
		loop invariant max == 1 ==> f <= array[0];
		loop invariant max == 1 ==> c >= 1;
		loop invariant max == 1 ==> \forall integer k; 0 <= k < c ==> f <= array[k];
		loop invariant max == 1 ==> \forall integer k; 0 <= k < c ==> array[k] >= f;
		loop invariant max == 1 ==> \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant max == 1 ==> (\forall integer k; 0 <= k < c ==> f <= array[k]);
		loop invariant max <= c;
		loop invariant max <= c + 1;
		loop invariant f == array[0] || f <= array[c-1];
		loop invariant f == array[0] || \exists integer k; 0 <= k < c && f == array[k];
		loop invariant f == array[0] || (\exists integer k; 0 <= k < c && f == array[k]);
		loop invariant f <= array[c-1];
		loop invariant f <= array[c-1] || c == 1;
		loop invariant f <= array[c-1] || c <= size;
		loop invariant f <= array[c-1] || 0 <= max;
		loop invariant f <= array[c-1] || 0 < size;
		loop invariant f <= array[0];
		loop invariant f <= array[0] || f == array[0];
		loop invariant f <= array[0] || f <= array[c];
		loop invariant f <= array[0] || f <= array[c-1];
		loop invariant f <= array[0] || c == 1;
		loop invariant c > 1 ==> max >= 1;
		loop invariant c > 1 ==> \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant c == 1 ==> max == 1;
		loop invariant c == 1 ==> f == array[0];
		loop invariant c <= size || 0 <= max;
		loop invariant c <= size ==> max >= 1;
		loop invariant \forall integer k; 1 <= k < c ==> f <= array[k];
		loop invariant \forall integer k; 0 <= k < c ==> f <= array[k];
		loop invariant \forall integer k; 0 <= k < c ==> f <= array[k] || array[k] == f;
		loop invariant \forall integer k; 0 <= k < c ==> f <= array[k] || array[k] < f;
		loop invariant \forall integer k; 0 <= k < c ==> array[k] >= f;
		loop invariant \forall integer k; 0 <= k < c ==> array[k] >= f || array[k] == f;
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] >= f);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] == f || array[k] > f);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] == f ==> max >= 1);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] < f ==> max >= 1);
		loop invariant \forall integer k; 0 <= k < c ==> (array[k] < f ==> \false);
		loop invariant \forall integer k; 0 <= k < c && array[k] == f ==> max >= 1;
		loop invariant \forall integer i; 0 <= i < c ==> f <= array[i];
		loop invariant \forall integer i; 0 <= i < c ==> (array[i] == f ==> max >= 1);
		loop invariant \forall integer i; 0 <= i < c && array[i] == f ==> max >= 1;
		loop invariant \exists integer k; 0 <= k < c ==> array[k] <= f;
		loop invariant \exists integer k; 0 <= k < c && f == array[k];
		loop invariant \exists integer k; 0 <= k < c && array[k] == f;
		loop invariant \exists integer i; 0 <= i < c && f == array[i];
		loop invariant 1 <= max;
		loop invariant 1 <= c;
		loop invariant 1 <= c || size == 0;
		loop invariant 0 <= max;
		loop invariant 0 <= c;
		loop invariant 0 < size || 0 <= max;
		loop invariant 0 < size ==> 1 <= max;
		loop invariant 0 < size ==> 0 < max;
		loop invariant 0 < max;
		loop invariant 0 < c;
		loop invariant (max == 1) || (max > 1);
		loop invariant (max == 1) || (\exists integer k; 0 <= k < c && array[k] == f);
		loop invariant (\forall integer k; 0 <= k < c ==> array[k] >= f);
		loop invariant (\exists integer i; 0 <= i < c && f == array[i]);
		loop assigns max;
		loop assigns f;
		loop assigns c;*/
int check_A_implies_B(int size, int * array, int array_len) {
    return stub_A(size, array, array_len);
}

/*@requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires size > 0;
  requires size <= array_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size != 0 ==> \result >= 1;*/
int check_B_implies_A(int size, int * array, int array_len) {
    return stub_B(size, array, array_len);
}
