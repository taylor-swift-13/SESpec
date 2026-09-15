#include <limits.h>


/*@
  logic integer max0(int* a, integer lo, integer hi) =
    lo >= hi ? 0 :
    (max0(a, lo, hi - 1) >= a[hi - 1] ? max0(a, lo, hi - 1) : a[hi - 1]);
*/

/*@requires positions_len >= 0;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
  assigns \nothing;
  ensures \result == max0(positions, 0, positions_len);
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0;*/
int stub_A(int * positions, int positions_len);

/*@loop invariant largest >= positions[index-1] || index == 0;
		loop invariant largest >= positions[index - 1] || index == 0;
		loop invariant largest == 0 || largest >= positions[index-1];
		loop invariant largest == 0 || largest > 0;
		loop invariant largest == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= largest;
		loop invariant largest == 0 || \forall integer k; 0 <= k < index ==> largest >= positions[k];
		loop invariant largest == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k];
		loop invariant largest == 0 || \forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0;
		loop invariant largest == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0;
		loop invariant largest == 0 || (\forall integer k; 0 <= k < index ==> largest >= positions[k]);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0);
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index ==> largest >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> largest >= positions[k] || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index && positions[k] > largest ==> positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k];
		loop invariant \forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> largest > 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> largest == positions[k];
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest ==> largest >= 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest ==> largest > 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0 || largest == 0;
		loop invariant 0 <= largest;
		loop invariant 0 <= index;
		loop invariant (\forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0);
		loop invariant (\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest);
		loop invariant (\forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k]);
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0) ==> largest > 0;
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && positions[k] > 0 && largest == positions[k]);
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && largest == positions[k] && positions[k] > 0);
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest) || largest == 0;
		loop invariant (\exists integer k; 0 <= k < index && positions[k] == largest) || largest == 0;
		loop assigns largest;
		loop assigns index;*/
int stub_B(int * positions, int positions_len);

/*@loop invariant largest >= positions[index-1] || index == 0;
		loop invariant largest >= positions[index - 1] || index == 0;
		loop invariant largest == 0 || largest >= positions[index-1];
		loop invariant largest == 0 || largest > 0;
		loop invariant largest == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= largest;
		loop invariant largest == 0 || \forall integer k; 0 <= k < index ==> largest >= positions[k];
		loop invariant largest == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k];
		loop invariant largest == 0 || \forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0;
		loop invariant largest == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0;
		loop invariant largest == 0 || (\forall integer k; 0 <= k < index ==> largest >= positions[k]);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0);
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index ==> largest >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> largest >= positions[k] || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index && positions[k] > largest ==> positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k];
		loop invariant \forall integer k; 0 <= k < index && positions[k] <= 0 ==> largest >= 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> largest > 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> largest == positions[k];
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest ==> largest >= 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest ==> largest > 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == largest && positions[k] > 0 || largest == 0;
		loop invariant 0 <= largest;
		loop invariant 0 <= index;
		loop invariant (\forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0);
		loop invariant (\forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= largest);
		loop invariant (\forall integer k; 0 <= k < index && positions[k] > 0 ==> largest >= positions[k]);
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0) ==> largest > 0;
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && positions[k] > 0 && largest == positions[k]);
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0) ==> (\exists integer k; 0 <= k < index && largest == positions[k] && positions[k] > 0);
		loop invariant (\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == largest) || largest == 0;
		loop invariant (\exists integer k; 0 <= k < index && positions[k] == largest) || largest == 0;
		loop assigns largest;
		loop assigns index;*/
int check_A_implies_B(int * positions, int positions_len) {
    return stub_A(positions, positions_len);
}

/*@requires positions_len >= 0;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
  assigns \nothing;
  ensures \result == max0(positions, 0, positions_len);
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0;*/
int check_B_implies_A(int * positions, int positions_len) {
    return stub_B(positions, positions_len);
}
