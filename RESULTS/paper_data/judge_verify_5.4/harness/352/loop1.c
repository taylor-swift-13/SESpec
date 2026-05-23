#include <limits.h>

/*@ requires (0 <= ret) && (total == (\at(number,Pre) >> ret)) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int k, int number, int ret, int total) {
    /*@ assert (total == 0 || total <= number); */
    /*@ assert (total == 0 || total == (number >> ret)); */
    /*@ assert (total == 0 || total <= (number >> ret)); */
    /*@ assert (total == 0 || total < number + 1); */
    /*@ assert (total == 0 || total < (number + 1)); */
    /*@ assert (total == 0 || total < (1 << 31)); */
    /*@ assert (total == 0 ==> ret >= 0); */
    /*@ assert (total == (number >> ret)); */
    /*@ assert (total == (number >> ret) || total == 0); */
    /*@ assert (total <= number); */
    /*@ assert (total <= number || number <= 0); */
    /*@ assert (total <= number || number < 0); */
    /*@ assert (total <= (number >> ret) || total == 0); */
    /*@ assert (total <= (number >> ret) || number < 0); */
    /*@ assert (ret == 0 || total < number); */
    /*@ assert (ret == 0 ==> result == 0); */
    /*@ assert (ret <= number + 1 || total <= number); */
    /*@ assert (ret <= number + 1 || ret <= 32); */
    /*@ assert (ret <= 32 || ret <= number + 1); */
    /*@ assert (ret <= 32 || 0 <= total); */
    /*@ assert (ret <= 32 ==> total <= number); */
    /*@ assert (ret <= 32 ==> total <= (number >> ret) || total == 0); */
    /*@ assert (ret + total <= number + 32); */
    /*@ assert (ret + total <= number + 1); */
    /*@ assert (ret % 2 == 1 ==> (result & (1 << (ret-1))) != 0 || result == 0); */
    /*@ assert (ret % 2 == 1 ==> ((result >> (ret-1)) & 1) == 1 || result == 0); */
    /*@ assert (ret % 2 == 1 ==> ((result >> (ret - 1)) & 1) == 1 || result == 0); */
    /*@ assert (ret % 2 == 1 ==> ((result & (1 << (ret-1))) != 0 || result == 0)); */
    /*@ assert (ret % 2 == 1 ==> ((result & (1 << (ret - 1))) != 0 || result == 0)); */
    /*@ assert (ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (ret % 2 == 0 ==> (result & 1) == 1 || result == 0); */
    /*@ assert (ret % 2 == 0 ==> ((result >> 0) & 1) == 1 || result == 0); */
    /*@ assert (result == 0 || total < number || total == number); */
    /*@ assert (result == 0 || result < (1 << 31)); */
    /*@ assert (result == 0 || (result & 1) == 1); */
    /*@ assert (result == 0 ==> ret == 0); */
    /*@ assert (result == 0 ==> ret == 0 || total == number); */
    /*@ assert (result == 0 ==> ret == 0 || total == 0); */
    /*@ assert (result == (number ^ (number ^ result))); */
    /*@ assert (result < (1 << 31)); */
    /*@ assert (result < (1 << 31) || ret >= 31); */
    /*@ assert (result < (1 << 31) || ret <= 31); */
    /*@ assert (result < (1 << 31) || result == 0); */
    /*@ assert (result < (1 << (ret + 1)) || ret <= number + 1); */
    /*@ assert (result < (1 << (ret + 1)) || 0 <= total); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (k % 2 == 1 ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || result == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result & (1 << k)) != 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (((k % 2 == 0) ==> ((result >> k) & 1) == 1) || ((result >> k) & 1) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0); */
    /*@ assert (0 <= total || ret <= 32); */
    /*@ assert (0 <= total || 0 <= result); */
    /*@ assert (0 <= total <= number || number <= 0); */
    /*@ assert (0 <= total <= number || number < 0); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= result || ret <= number + 1); */
    /*@ assert (0 <= result || 0 <= total); */
    /*@ assert ((ret % 2 == 1) ==> ((result >> (ret-1)) & 1) == 1 || result == 0); */
    /*@ assert ((ret % 2 == 1) ==> ((result & 1) == 1 || result == 0)); */
    /*@ assert ((ret % 2 == 1) ==> ((result & (1 << (ret-1))) != 0 || result == 0)); */
    /*@ assert ((ret % 2 == 1) ==> ((result & (1 << (ret - 1))) != 0 || result == 0)); */
    /*@ assert ((ret % 2 == 0) ==> ((result & 1) == 1 || result == 0)); */
}

/*@ requires (total == 0 || total <= number) && (total == 0 || total == (number >> ret)) && (total == 0 || total <= (number >> ret)) && (total == 0 || total < number + 1) && (total == 0 || total < (number + 1)) && (total == 0 || total < (1 << 31)) && (total == 0 ==> ret >= 0) && (total == (number >> ret)) && (total == (number >> ret) || total == 0) && (total <= number) && (total <= number || number <= 0) && (total <= number || number < 0) && (total <= (number >> ret) || total == 0) && (total <= (number >> ret) || number < 0) && (ret == 0 || total < number) && (ret == 0 ==> result == 0) && (ret <= number + 1 || total <= number) && (ret <= number + 1 || ret <= 32) && (ret <= 32 || ret <= number + 1) && (ret <= 32 || 0 <= total) && (ret <= 32 ==> total <= number) && (ret <= 32 ==> total <= (number >> ret) || total == 0) && (ret + total <= number + 32) && (ret + total <= number + 1) && (ret % 2 == 1 ==> (result & (1 << (ret-1))) != 0 || result == 0) && (ret % 2 == 1 ==> ((result >> (ret-1)) & 1) == 1 || result == 0) && (ret % 2 == 1 ==> ((result >> (ret - 1)) & 1) == 1 || result == 0) && (ret % 2 == 1 ==> ((result & (1 << (ret-1))) != 0 || result == 0)) && (ret % 2 == 1 ==> ((result & (1 << (ret - 1))) != 0 || result == 0)) && (ret % 2 == 0 || ret % 2 == 1) && (ret % 2 == 0 ==> (result & 1) == 1 || result == 0) && (ret % 2 == 0 ==> ((result >> 0) & 1) == 1 || result == 0) && (result == 0 || total < number || total == number) && (result == 0 || result < (1 << 31)) && (result == 0 || (result & 1) == 1) && (result == 0 ==> ret == 0) && (result == 0 ==> ret == 0 || total == number) && (result == 0 ==> ret == 0 || total == 0) && (result == (number ^ (number ^ result))) && (result < (1 << 31)) && (result < (1 << 31) || ret >= 31) && (result < (1 << 31) || ret <= 31) && (result < (1 << 31) || result == 0) && (result < (1 << (ret + 1)) || ret <= number + 1) && (result < (1 << (ret + 1)) || 0 <= total) && (\forall integer k; 0 <= k < ret ==> (k % 2 == 1 ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || result == 0)) && (\forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)) && (\forall integer k; 0 <= k < ret ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1))) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result & (1 << k)) != 0))) && (\forall integer k; 0 <= k < ret ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1)) && (\forall integer k; 0 <= k < ret ==> (((k % 2 == 0) ==> ((result >> k) & 1) == 1) || ((result >> k) & 1) == 0)) && (\forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0) && (0 <= total || ret <= 32) && (0 <= total || 0 <= result) && (0 <= total <= number || number <= 0) && (0 <= total <= number || number < 0) && (0 <= ret) && (0 <= result || ret <= number + 1) && (0 <= result || 0 <= total) && ((ret % 2 == 1) ==> ((result >> (ret-1)) & 1) == 1 || result == 0) && ((ret % 2 == 1) ==> ((result & 1) == 1 || result == 0)) && ((ret % 2 == 1) ==> ((result & (1 << (ret-1))) != 0 || result == 0)) && ((ret % 2 == 1) ==> ((result & (1 << (ret - 1))) != 0 || result == 0)) && ((ret % 2 == 0) ==> ((result & 1) == 1 || result == 0));
    assigns \nothing;
*/
void check_B_implies_A(int k, int number, int ret, int total) {
    /*@ assert (0 <= ret); */
    /*@ assert (total == (\at(number,Pre) >> ret)); */
    /*@ assert (number == \at(number,Pre)); */
}
