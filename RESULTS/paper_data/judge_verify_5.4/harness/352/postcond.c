#include <limits.h>

/*@ ensures \exists integer ret_62, total_61; (total_61 <= 0) && (0 <= ret_62) && (total_61 == number >> ret_62) ==> (\result == (number ^ 0));

assigns \nothing; */
int stub_A(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@ ensures \exists integer ret_62, total_61; (total_61 <= 0) && (0 <= ret_62) && (total_61 == number >> ret_62) ==> (\result == (number ^ 0));

assigns \nothing; */
int check_B_implies_A(int number) {
    return stub_B(number);
}
