#include <limits.h>

/*@ logic integer selected_even_bits(integer x) =
      x <= 0 ? 0 : ((x % 2 == 1) ? 1 : 0) + 4 * selected_even_bits(x / 4); */

/*@ requires ((\at(num,Pre) > 0) ==> (0 <= ret)) && ((\at(num,Pre) > 0) ==> (0 <= total)) && ((\at(num,Pre) > 0) ==> (total <= \at(num,Pre))) && ((\at(num,Pre) > 0) ==> (num == \at(num,Pre))) && ((!(\at(num,Pre) > 0)) ==> ((total == \at(num,Pre))&&(ret == 0)&&(result == 0)&&(num == \at(num,Pre)))) && ((\at(num,Pre) > 0) ==> (total >= 0)) && (num == \at(num,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int k, int num, int ret, int total) {
    /*@ assert (ret > 0 ==> total == (num >> ret) || total == 0); */
    /*@ assert (total == 0 || total == (num >> ret)); */
    /*@ assert (total == 0 ==> ret >= 0); */
    /*@ assert (total == (num >> ret)); */
    /*@ assert (total == (num >> ret) || total == 0); */
    /*@ assert (total <= num); */
    /*@ assert (ret > 0 ==> total == (num >> ret)); */
    /*@ assert (ret > 0 ==> total <= num); */
    /*@ assert (ret > 0 ==> total < num); */
    /*@ assert (ret > 0 ==> total < num || total == 0); */
    /*@ assert (ret > 0 ==> result != 0 || total == num); */
    /*@ assert (ret > 0 ==> (result & 1) != 0 || result == 0); */
    /*@ assert (ret == 32 || total == (num >> ret)); */
    /*@ assert (ret == 0 || total < num); */
    /*@ assert (ret == 0 ==> total == num); */
    /*@ assert (ret == 0 ==> result == 0); */
    /*@ assert (ret <= 32 ==> total == (num >> ret)); */
    /*@ assert (ret <= 32 ==> total + ret <= num + 32); */
    /*@ assert (ret <= 32 ==> (result & 1) != 0 || ret == 0); */
    /*@ assert (ret + total <= num + 32); */
    /*@ assert (ret + total <= num + 32 || ret <= 32); */
    /*@ assert (ret + total <= num + 32 || ret <= 31); */
    /*@ assert (ret + total <= num + 32 || 0 <= result); */
    /*@ assert (ret + total < num + 32); */
    /*@ assert (ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (ret % 2 == 0 ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)); */
    /*@ assert (ret % 2 == 0 ==> (result & 1) != 0 || ret == 0); */
    /*@ assert (ret % 2 == 0 ==> (result & 1) != 0 || result == 0); */
    /*@ assert (ret % 2 == 0 ==> ((result & 1) != 0 || ret == 0)); */
    /*@ assert (result == 0 || (result & 1) != 0); */
    /*@ assert (\forall integer k; ret <= k < 32 ==> (result & (1 << k)) == 0); */
    /*@ assert (\forall integer k; ret <= k < 31 ==> (result & (1 << k)) == 0); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0); */
    /*@ assert (0 <= total || ret <= 32); */
    /*@ assert (0 <= total || ret <= 31); */
    /*@ assert (0 <= total || ret + total <= num + 32); */
    /*@ assert (0 <= total || 0 <= result); */
    /*@ assert (0 <= ret); */
    /*@ assert ((ret % 2 == 0) ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)); */
    /*@ assert ((ret % 2 == 0) ==> (result & 1) != 0 || ret == 0); */
    /*@ assert ((ret % 2 == 0) ==> ((result & 1) != 0 || ret == 0)); */
    /*@ assert ((result & 1) != 0 || ret == 0); */
    /*@ assert ((result & 1) != 0 || result == 0); */
    /*@ assert ((result & 1) != 0 ==> ret > 0); */
}

/*@ requires (ret > 0 ==> total == (num >> ret) || total == 0) && (total == 0 || total == (num >> ret)) && (total == 0 ==> ret >= 0) && (total == (num >> ret)) && (total == (num >> ret) || total == 0) && (total <= num) && (ret > 0 ==> total == (num >> ret)) && (ret > 0 ==> total <= num) && (ret > 0 ==> total < num) && (ret > 0 ==> total < num || total == 0) && (ret > 0 ==> result != 0 || total == num) && (ret > 0 ==> (result & 1) != 0 || result == 0) && (ret == 32 || total == (num >> ret)) && (ret == 0 || total < num) && (ret == 0 ==> total == num) && (ret == 0 ==> result == 0) && (ret <= 32 ==> total == (num >> ret)) && (ret <= 32 ==> total + ret <= num + 32) && (ret <= 32 ==> (result & 1) != 0 || ret == 0) && (ret + total <= num + 32) && (ret + total <= num + 32 || ret <= 32) && (ret + total <= num + 32 || ret <= 31) && (ret + total <= num + 32 || 0 <= result) && (ret + total < num + 32) && (ret % 2 == 0 || ret % 2 == 1) && (ret % 2 == 0 ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)) && (ret % 2 == 0 ==> (result & 1) != 0 || ret == 0) && (ret % 2 == 0 ==> (result & 1) != 0 || result == 0) && (ret % 2 == 0 ==> ((result & 1) != 0 || ret == 0)) && (result == 0 || (result & 1) != 0) && (\forall integer k; ret <= k < 32 ==> (result & (1 << k)) == 0) && (\forall integer k; ret <= k < 31 ==> (result & (1 << k)) == 0) && (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0) && (0 <= total || ret <= 32) && (0 <= total || ret <= 31) && (0 <= total || ret + total <= num + 32) && (0 <= total || 0 <= result) && (0 <= ret) && ((ret % 2 == 0) ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)) && ((ret % 2 == 0) ==> (result & 1) != 0 || ret == 0) && ((ret % 2 == 0) ==> ((result & 1) != 0 || ret == 0)) && ((result & 1) != 0 || ret == 0) && ((result & 1) != 0 || result == 0) && ((result & 1) != 0 ==> ret > 0);
    assigns \nothing;
*/
void check_B_implies_A(int k, int num, int ret, int total) {
    /*@ assert ((\at(num,Pre) > 0) ==> (0 <= ret)); */
    /*@ assert ((\at(num,Pre) > 0) ==> (0 <= total)); */
    /*@ assert ((\at(num,Pre) > 0) ==> (total <= \at(num,Pre))); */
    /*@ assert ((\at(num,Pre) > 0) ==> (num == \at(num,Pre))); */
    /*@ assert ((!(\at(num,Pre) > 0)) ==> ((total == \at(num,Pre))&&(ret == 0)&&(result == 0)&&(num == \at(num,Pre)))); */
    /*@ assert ((\at(num,Pre) > 0) ==> (total >= 0)); */
    /*@ assert (num == \at(num,Pre)); */
}
