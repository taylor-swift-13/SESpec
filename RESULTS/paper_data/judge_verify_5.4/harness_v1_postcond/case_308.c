#include <limits.h>


/*@ 
  logic integer max_prefix(int* positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (positions[lo] > max_prefix(positions, lo + 1, hi) ? positions[lo] : max_prefix(positions, lo + 1, hi));
*/

/*@requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < positions_len ==> positions[k] <= \result;*/
int stub_A(int * positions, int positions_len);

/*@loop invariant result >= positions[0] || index == 0;
		loop invariant result >= 0 || result == 0;
		loop invariant result > 0 ==> \exists integer k; 0 <= k < index && positions[k] == result;
		loop invariant result > 0 ==> (\exists integer k; 0 <= k < index && positions[k] == result);
		loop invariant result == 0 || result >= positions[0];
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || \forall integer k; 0 <= k < index ==> result >= positions[k];
		loop invariant result == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= result;
		loop invariant result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k];
		loop invariant result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] >= result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] == result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0;
		loop invariant result == 0 || (\forall integer k; 0 <= k < index ==> result >= positions[k]);
		loop invariant result == 0 || (\forall integer k; 0 <= k < index ==> positions[k] <= result);
		loop invariant result == 0 || (\forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]);
		loop invariant result == 0 || (\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result);
		loop invariant result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result);
		loop invariant result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0);
		loop invariant result == 0 ==> \forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> result >= positions[k] || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k] || result == 0;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] > 0 ==> positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= result || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= 0 || result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> result >= positions[k]);
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> positions[k] <= result);
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] <= 0 || result >= positions[k]);
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] <= 0 || positions[k] <= result);
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result;
		loop invariant \exists integer k; 0 <= k < index && result == positions[k] || result == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k];
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> result > 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 && result == positions[k] || result == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == result || result == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0 || result == 0;
		loop invariant 0 <= result;
		loop invariant 0 <= index;
		loop assigns result;
		loop assigns index;*/
int stub_B(int * positions, int positions_len);

/*@loop invariant result >= positions[0] || index == 0;
		loop invariant result >= 0 || result == 0;
		loop invariant result > 0 ==> \exists integer k; 0 <= k < index && positions[k] == result;
		loop invariant result > 0 ==> (\exists integer k; 0 <= k < index && positions[k] == result);
		loop invariant result == 0 || result >= positions[0];
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || \forall integer k; 0 <= k < index ==> result >= positions[k];
		loop invariant result == 0 || \forall integer k; 0 <= k < index ==> positions[k] <= result;
		loop invariant result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k];
		loop invariant result == 0 || \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] >= result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] == result;
		loop invariant result == 0 || \exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0;
		loop invariant result == 0 || (\forall integer k; 0 <= k < index ==> result >= positions[k]);
		loop invariant result == 0 || (\forall integer k; 0 <= k < index ==> positions[k] <= result);
		loop invariant result == 0 || (\forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k]);
		loop invariant result == 0 || (\exists integer k; 0 <= k < index && positions[k] > 0 && positions[k] == result);
		loop invariant result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result);
		loop invariant result == 0 || (\exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0);
		loop invariant result == 0 ==> \forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> result >= positions[k] || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] > 0 ==> result >= positions[k] || result == 0;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] > 0 ==> positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= result || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= 0 || result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= 0 || positions[k] <= result;
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> result >= positions[k]);
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> positions[k] <= result);
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] <= 0 || result >= positions[k]);
		loop invariant \forall integer k; 0 <= k < index ==> (positions[k] <= 0 || positions[k] <= result);
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k];
		loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result;
		loop invariant \exists integer k; 0 <= k < index && result == positions[k] || result == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> result >= positions[k];
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 ==> result > 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] > 0 && result == positions[k] || result == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == result || result == 0;
		loop invariant \exists integer k; 0 <= k < index && positions[k] == result && positions[k] > 0 || result == 0;
		loop invariant 0 <= result;
		loop invariant 0 <= index;
		loop assigns result;
		loop assigns index;*/
int check_A_implies_B(int * positions, int positions_len) {
    return stub_A(positions, positions_len);
}

/*@requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < positions_len ==> positions[k] <= \result;*/
int check_B_implies_A(int * positions, int positions_len) {
    return stub_B(positions, positions_len);
}
