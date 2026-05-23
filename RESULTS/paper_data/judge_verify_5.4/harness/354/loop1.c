#include <limits.h>

/*@ requires (0 <= even) && ((\at(num,Pre) > 0) ==> (sum == (\at(num,Pre) >> even))) && ((!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(result == 0)&&(even == 0)&&(num == \at(num,Pre)))) && (num == \at(num,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int even, int k, int num) {
    /*@ assert (sum == 0 || sum <= (num >> even)); */
    /*@ assert (sum == (num >> even) || sum == 0); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> (((result >> k) & 1) == 1)) || ((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)))); */
    /*@ assert ((even % 2 == 1) ==> ((result >> even) & 1) == 1 || ((result >> even) & 1) == 0); */
    /*@ assert (sum == 0 || sum == (num >> even)); */
    /*@ assert (sum == 0 ==> even >= 0); */
    /*@ assert (sum == (num >> even)); */
    /*@ assert (sum <= num); */
    /*@ assert (result == 0 || result != 0); */
    /*@ assert (result == 0 ==> sum == (num >> even)); */
    /*@ assert (result == 0 ==> \forall integer k; 0 <= k < even ==> (k % 2 == 0 ==> ((result >> k) & 1) == 0)); */
    /*@ assert (result <= (1 << even) || 0 <= sum); */
    /*@ assert (even == 0 || sum == (num >> even)); */
    /*@ assert (even == 0 || sum < num); */
    /*@ assert (even == 0 || even > 0); */
    /*@ assert (even <= 32 || 0 <= sum); */
    /*@ assert (even <= 32 ==> sum == (num >> even)); */
    /*@ assert (even % 2 == 0 || even % 2 == 1); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (k % 2 == 1 ==> ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (k % 2 == 1 ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (k % 2 == 0 ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((result >> k) & 1) == (((k % 2 == 1) && ((num >> k) & 1) == 1) ? 1 : ((result >> k) & 1))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 1))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 1 || ((result >> k) & 1) == 0))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> ((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> ((result >> k) & 1) == 1))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> (((result >> k) & 1) == 1)))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> (((result >> k) & 1) == 1)) && ((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) && (((result >> k) & 1) == 1)) || (k % 2 == 0))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) && (((num >> k) & 1) == 1)) ==> (((result >> k) & 1) == 1))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 0)) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1))); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 0) ==> ((result >> k) & 1) == 0) || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < even ==> (((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)))); */
    /*@ assert (0 <= sum || even <= 32); */
    /*@ assert (0 <= sum || 0 <= result); */
    /*@ assert (0 <= result || 0 <= sum); */
    /*@ assert (0 <= even); */
    /*@ assert (0 <= even + 31); */
    /*@ assert ((sum == 0) ==> even >= 0); */
    /*@ assert ((sum == 0) ==> (result | num) == (num | result)); */
    /*@ assert ((sum == 0) ==> (even >= 0)); */
    /*@ assert ((even == 0) || (sum == (num >> even))); */
    /*@ assert ((even == 0) ==> sum == num); */
    /*@ assert ((even % 2 == 1) ==> ((result & (1 << even)) == 0 || (result & (1 << even)) != 0)); */
    /*@ assert ((even % 2 == 1) ==> (((result >> even) & 1) == 0 || ((result >> even) & 1) == 1)); */
    /*@ assert ((even % 2 == 0) || (even % 2 == 1)); */
    /*@ assert ((even % 2 == 0) ==> (result & 1) == 0 || (result & 1) == 1); */
    /*@ assert ((even % 2 == 0) ==> ((result & 1) == 0 || (result & 1) == 1)); */
    /*@ assert ((even % 2 == 0) ==> ((result & (1 << even)) == 0 || (result & (1 << even)) != 0)); */
}

/*@ requires (sum == 0 || sum <= (num >> even)) && (sum == (num >> even) || sum == 0) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> (((result >> k) & 1) == 1)) || ((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)))) && ((even % 2 == 1) ==> ((result >> even) & 1) == 1 || ((result >> even) & 1) == 0) && (sum == 0 || sum == (num >> even)) && (sum == 0 ==> even >= 0) && (sum == (num >> even)) && (sum <= num) && (result == 0 || result != 0) && (result == 0 ==> sum == (num >> even)) && (result == 0 ==> \forall integer k; 0 <= k < even ==> (k % 2 == 0 ==> ((result >> k) & 1) == 0)) && (result <= (1 << even) || 0 <= sum) && (even == 0 || sum == (num >> even)) && (even == 0 || sum < num) && (even == 0 || even > 0) && (even <= 32 || 0 <= sum) && (even <= 32 ==> sum == (num >> even)) && (even % 2 == 0 || even % 2 == 1) && (\forall integer k; 0 <= k < even ==> (k % 2 == 1 ==> ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < even ==> (k % 2 == 1 ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)) && (\forall integer k; 0 <= k < even ==> (k % 2 == 0 ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < even ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1) && (\forall integer k; 0 <= k < even ==> ((result >> k) & 1) == (((k % 2 == 1) && ((num >> k) & 1) == 1) ? 1 : ((result >> k) & 1))) && (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)) && (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 1))) && (\forall integer k; 0 <= k < even ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 1 || ((result >> k) & 1) == 0))) && (\forall integer k; 0 <= k < even ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < even ==> ((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1))) && (\forall integer k; 0 <= k < even ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> ((result >> k) & 1) == 1))) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> (((result >> k) & 1) == 1)))) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) ==> (((result >> k) & 1) == 1)) && ((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)))) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) && (((result >> k) & 1) == 1)) || (k % 2 == 0))) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 1) && (((num >> k) & 1) == 1)) ==> (((result >> k) & 1) == 1))) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 0)) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1))) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 0) ==> ((result >> k) & 1) == 0) || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < even ==> (((k % 2 == 0) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)))) && (0 <= sum || even <= 32) && (0 <= sum || 0 <= result) && (0 <= result || 0 <= sum) && (0 <= even) && (0 <= even + 31) && ((sum == 0) ==> even >= 0) && ((sum == 0) ==> (result | num) == (num | result)) && ((sum == 0) ==> (even >= 0)) && ((even == 0) || (sum == (num >> even))) && ((even == 0) ==> sum == num) && ((even % 2 == 1) ==> ((result & (1 << even)) == 0 || (result & (1 << even)) != 0)) && ((even % 2 == 1) ==> (((result >> even) & 1) == 0 || ((result >> even) & 1) == 1)) && ((even % 2 == 0) || (even % 2 == 1)) && ((even % 2 == 0) ==> (result & 1) == 0 || (result & 1) == 1) && ((even % 2 == 0) ==> ((result & 1) == 0 || (result & 1) == 1)) && ((even % 2 == 0) ==> ((result & (1 << even)) == 0 || (result & (1 << even)) != 0));
    assigns \nothing;
*/
void check_B_implies_A(int even, int k, int num) {
    /*@ assert (0 <= even); */
    /*@ assert ((\at(num,Pre) > 0) ==> (sum == (\at(num,Pre) >> even))); */
    /*@ assert ((!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(result == 0)&&(even == 0)&&(num == \at(num,Pre)))); */
    /*@ assert (num == \at(num,Pre)); */
}
