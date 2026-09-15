#include <limits.h>

/*@ requires positions_len >= 0;
  requires \valid_read(positions + (0..positions_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures positions_len == 0 ==> \result >= 0 ;
  ensures \forall integer k; 0 <= k < positions_len ==> \result >= positions[k];
  ensures \result == 0 ==> (\forall integer k ; 0 <= k < positions_len ==> positions[k] <= 0); */
int stub_A(int * positions, int positions_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * positions, int positions_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * positions, int positions_len) {
    return stub_A(positions, positions_len);
}

/*@ requires positions_len >= 0;
  requires \valid_read(positions + (0..positions_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures positions_len == 0 ==> \result >= 0 ;
  ensures \forall integer k; 0 <= k < positions_len ==> \result >= positions[k];
  ensures \result == 0 ==> (\forall integer k ; 0 <= k < positions_len ==> positions[k] <= 0); */
int check_B_implies_A(int * positions, int positions_len) {
    return stub_B(positions, positions_len);
}
