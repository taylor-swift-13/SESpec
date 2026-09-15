#include <limits.h>

/*@ logic integer even_count(integer n) =
    n <= 0 ? 0 : even_count(n - 1) + ((n % 2 == 0) ? 1 : 0); */
/*@ logic integer even_sum(integer n) =
    n <= 0 ? 0 : even_sum(n - 1) + ((n % 2 == 0) ? n : 0); */

/*@ requires size >= 2;
  requires even_count(size) > 0;
  assigns \nothing;
  
  ensures even_count(size) > 0;
  ensures \result >= 0;
  ensures \result <= even_sum(size); */
int stub_A(int size);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int size);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int size) {
    return stub_A(size);
}

/*@ requires size >= 2;
  requires even_count(size) > 0;
  assigns \nothing;
  
  ensures even_count(size) > 0;
  ensures \result >= 0;
  ensures \result <= even_sum(size); */
int check_B_implies_A(int size) {
    return stub_B(size);
}
