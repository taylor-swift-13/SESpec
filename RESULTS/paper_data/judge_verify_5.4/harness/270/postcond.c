#include <limits.h>
#include <stdlib.h>

/*@ logic integer foo270_seq(integer m, integer count) =
      count == 2 ? m * m :
      count > 2 ? ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007 :
      1; */

/*@ requires count == 2;
  
  
  ensures count == 2 ==> \result == m * m;
  ensures count > 2 ==> \result == ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007; */
int stub_A(int count, int m);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int count, int m);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int count, int m) {
    return stub_A(count, m);
}

/*@ requires count == 2;
  
  
  ensures count == 2 ==> \result == m * m;
  ensures count > 2 ==> \result == ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007; */
int check_B_implies_A(int count, int m) {
    return stub_B(count, m);
}
