#include <limits.h>



/*@requires positions_len >= 0;
  requires \valid_read(positions + (0..positions_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures positions_len == 0 ==> \result >= 0 ;
  ensures \forall integer k; 0 <= k < positions_len ==> \result >= positions[k];
  ensures \result == 0 ==> (\forall integer k ; 0 <= k < positions_len ==> positions[k] <= 0);*/
int stub_A(int * positions, int positions_len);

/*@loop invariant largest >= positions[count-1] || count == 0;
		loop invariant largest >= positions[0] || count == 0;
		loop invariant largest >= 0 || count == 0;
		loop invariant largest == 0 || \exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0;
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0);
		loop invariant largest == 0 || (\exists integer i; 0 <= i < count && positions[i] == largest);
		loop invariant count > 0 ==> largest >= positions[count-1] || positions[count-1] <= 0;
		loop invariant count == 0 ==> largest == 0;
		loop invariant \forall integer k; count <= k < positions_len ==> positions[k] >= 0 || positions[k] <= largest;
		loop invariant \forall integer k; count <= k < positions_len ==> positions[k] == positions[k];
		loop invariant \forall integer k; count <= k < positions_len ==> 0 <= positions[k] || positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] > 0 ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= positions_len || positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] < 0;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest || largest == 0;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= 0 || positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> largest >= positions[k];
		loop invariant \forall integer k; 0 <= k < count ==> largest >= positions[k] || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] > largest ==> positions[k] <= 0);
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] > 0 ==> positions[k] <= largest);
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] <= largest || positions[k] <= 0);
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] <= 0 || positions[k] <= largest);
		loop invariant \forall integer k; 0 <= k < count && positions[k] > largest ==> positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < count && positions[k] > 0 ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count && positions[k] <= 0 ==> largest >= 0;
		loop invariant \forall integer i; 0 <= i < count ==> positions[i] <= largest || positions[i] <= 0;
		loop invariant \forall integer i; 0 <= i < count && positions[i] > 0 ==> positions[i] <= largest;
		loop invariant \exists integer k; 0 <= k < count ==> positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] > 0 ==> largest > 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] == largest ==> largest > 0;
		loop invariant \exists integer i; 0 <= i < count && positions[i] == largest || largest == 0;
		loop invariant 0 <= largest;
		loop invariant 0 <= count;
		loop assigns largest;
		loop assigns count;*/
int stub_B(int * positions, int positions_len);

/*@loop invariant largest >= positions[count-1] || count == 0;
		loop invariant largest >= positions[0] || count == 0;
		loop invariant largest >= 0 || count == 0;
		loop invariant largest == 0 || \exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest;
		loop invariant largest == 0 || \exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0;
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest);
		loop invariant largest == 0 || (\exists integer k; 0 <= k < count && positions[k] == largest && positions[k] > 0);
		loop invariant largest == 0 || (\exists integer i; 0 <= i < count && positions[i] == largest);
		loop invariant count > 0 ==> largest >= positions[count-1] || positions[count-1] <= 0;
		loop invariant count == 0 ==> largest == 0;
		loop invariant \forall integer k; count <= k < positions_len ==> positions[k] >= 0 || positions[k] <= largest;
		loop invariant \forall integer k; count <= k < positions_len ==> positions[k] == positions[k];
		loop invariant \forall integer k; count <= k < positions_len ==> 0 <= positions[k] || positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] > 0 ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= positions_len || positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest || positions[k] < 0;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest || largest == 0;
		loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= 0 || positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count ==> largest >= positions[k];
		loop invariant \forall integer k; 0 <= k < count ==> largest >= positions[k] || positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] > largest ==> positions[k] <= 0);
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] > 0 ==> positions[k] <= largest);
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] <= largest || positions[k] <= 0);
		loop invariant \forall integer k; 0 <= k < count ==> (positions[k] <= 0 || positions[k] <= largest);
		loop invariant \forall integer k; 0 <= k < count && positions[k] > largest ==> positions[k] <= 0;
		loop invariant \forall integer k; 0 <= k < count && positions[k] > 0 ==> positions[k] <= largest;
		loop invariant \forall integer k; 0 <= k < count && positions[k] <= 0 ==> largest >= 0;
		loop invariant \forall integer i; 0 <= i < count ==> positions[i] <= largest || positions[i] <= 0;
		loop invariant \forall integer i; 0 <= i < count && positions[i] > 0 ==> positions[i] <= largest;
		loop invariant \exists integer k; 0 <= k < count ==> positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] > 0 ==> largest > 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] > 0 && positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] == largest || largest == 0;
		loop invariant \exists integer k; 0 <= k < count && positions[k] == largest ==> largest > 0;
		loop invariant \exists integer i; 0 <= i < count && positions[i] == largest || largest == 0;
		loop invariant 0 <= largest;
		loop invariant 0 <= count;
		loop assigns largest;
		loop assigns count;*/
int check_A_implies_B(int * positions, int positions_len) {
    return stub_A(positions, positions_len);
}

/*@requires positions_len >= 0;
  requires \valid_read(positions + (0..positions_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures positions_len == 0 ==> \result >= 0 ;
  ensures \forall integer k; 0 <= k < positions_len ==> \result >= positions[k];
  ensures \result == 0 ==> (\forall integer k ; 0 <= k < positions_len ==> positions[k] <= 0);*/
int check_B_implies_A(int * positions, int positions_len) {
    return stub_B(positions, positions_len);
}
