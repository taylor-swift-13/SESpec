#include <limits.h>

/*@ requires array >= 0;
  requires array > 0 ==> \valid_read(data + (0 .. array - 1));
  assigns \nothing;
  ensures array <= 0 ==> \result == 0;
  ensures array > 0 ==> 0 <= \result <= array;
  
  ensures \result >= 0; */
int stub_A(int * data, int data_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * data, int data_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * data, int data_len, int array) {
    return stub_A(data, data_len, array);
}

/*@ requires array >= 0;
  requires array > 0 ==> \valid_read(data + (0 .. array - 1));
  assigns \nothing;
  ensures array <= 0 ==> \result == 0;
  ensures array > 0 ==> 0 <= \result <= array;
  
  ensures \result >= 0; */
int check_B_implies_A(int * data, int data_len, int array) {
    return stub_B(data, data_len, array);
}
