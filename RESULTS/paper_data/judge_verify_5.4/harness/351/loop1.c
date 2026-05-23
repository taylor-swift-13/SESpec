#include <limits.h>

/*@ requires ((\at(number,Pre) > 0) ==> (0 <= ret)) && ((\at(number,Pre) > 0) ==> (total >= 0)) && ((\at(number,Pre) > 0) ==> (total <= \at(number,Pre))) && ((\at(number,Pre) > 0) ==> (number == \at(number,Pre))) && ((!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(i == 0)&&(number == \at(number,Pre)))) && (number == \at(number,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int number, int ret, int total) {
    /*@ assert (ret > 0 ==> (i & 1) == 0 || (i & 1) == 1); */
    /*@ assert (number == 0 || total <= number); */
    /*@ assert (total > 0 ==> total == (number >> ret)); */
    /*@ assert (total == number >> ret); */
    /*@ assert (total == 0 ==> ret >= 0); */
    /*@ assert (total == (number >> ret)); */
    /*@ assert (total == (number >> ret) || total == 0); */
    /*@ assert (total <= number); */
    /*@ assert (total + ret <= number); */
    /*@ assert (total + ret <= number || ret <= number); */
    /*@ assert (total + ret <= number || 0 <= total); */
    /*@ assert (total + ret <= number || 0 <= total + ret); */
    /*@ assert (total + ret <= number || 0 <= i); */
    /*@ assert (total + ret <= number || 0 < total + (1 << ret)); */
    /*@ assert (total + ret <= number + ret); */
    /*@ assert (total + ret <= number + 32); */
    /*@ assert (total + ret - 32 <= number); */
    /*@ assert (ret == 0 || total == (number >> ret)); */
    /*@ assert (ret == 0 || total <= (number >> (ret - 1))); */
    /*@ assert (ret == 0 || total < number); */
    /*@ assert (ret == 0 || total < (number >> (ret - 1))); */
    /*@ assert (ret == 0 || (number >> ret) <= total); */
    /*@ assert (ret == 0 ==> i == 0); */
    /*@ assert (ret <= number || 0 <= i); */
    /*@ assert (ret <= number + 1 || 0 <= i); */
    /*@ assert (ret <= 32 || ret <= number + 1); */
    /*@ assert (ret <= 32 ==> total == (number >> ret)); */
    /*@ assert (ret % 2 == 0 || ret % 2 == 1); */
    /*@ assert (number == total << ret || number >= total); */
    /*@ assert (number == 0 || total < (number + 1)); */
    /*@ assert (number == (total << ret) || number >= total); */
    /*@ assert (i == 0 || i != 0); */
    /*@ assert (i == 0 || (i & 1) == 1); */
    /*@ assert (i == 0 || (i & 1) == 1 || (i & 1) == 0); */
    /*@ assert (i == 0 || (i & 1) == 0 || (i & 1) == 1); */
    /*@ assert (i == 0 || (i & (1 << ret)) == 0 || (i & (1 << ret)) != 0); */
    /*@ assert (i == 0 || (\exists integer k; 0 <= k < ret && i == (i | (1 << k)))); */
    /*@ assert (i == (i | 0)); */
    /*@ assert (\forall integer k; ret <= k < 32 ==> (i & (1 << k)) == 0); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (i & (1 << k)) == 0 || (i & (1 << k)) != 0); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2) == 1 ==> (i & (1 << k)) == 0 || (i & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2) == 1 ==> ((i & (1 << k)) == 0 || (i & (1 << k)) != 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2) == 0 ==> (i & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2) == 0 ==> (i & (1 << k)) != 0 || (i & (1 << k)) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2) == 0 ==> ((i & (1 << k)) != 0 || (i & (1 << k)) == 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (i & (1 << k)) == 0 || (i & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (i & (1 << k)) != 0 || (i & (1 << k)) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((i & (1 << k)) == 0 || (i & (1 << k)) != 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((i & (1 << k)) != 0 || (i & (1 << k)) == 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (i & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (i & (1 << k)) != 0 || (i & (1 << k)) == 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((i & (1 << k)) != 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((i & (1 << k)) != 0 || (i & (1 << k)) == 0))); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> ((i & (1 << k)) == 0 || (i & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (((k % 2) == 0) ==> (i & (1 << k)) != 0)); */
    /*@ assert (\forall integer k; 0 <= k < ret ==> (((k % 2) == 0) ==> ((i & (1 << k)) != 0))); */
    /*@ assert (0 <= total || ret <= 32); */
    /*@ assert (0 <= total || 0 <= i); */
    /*@ assert (0 <= total + ret || 0 <= i); */
    /*@ assert (0 <= ret); */
    /*@ assert ((ret > 0) ==> (i & (1 << (ret - 1))) == 0 || (i & (1 << (ret - 1))) != 0); */
    /*@ assert ((ret > 0) ==> (i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0); */
    /*@ assert ((ret % 2 == 1) ==> (i & (1 << ret)) == 0 || (i & (1 << ret)) != 0); */
    /*@ assert ((ret % 2 == 1) ==> (i & (1 << ret)) != 0 || (i & (1 << ret)) == 0); */
    /*@ assert ((ret % 2 == 1) ==> (i & (1 << (ret-1))) != 0); */
    /*@ assert ((ret % 2 == 1) ==> (i & (1 << (ret - 1))) != 0); */
    /*@ assert ((ret % 2 == 1) ==> (i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0); */
    /*@ assert ((ret % 2 == 1) ==> ((i & (1 << ret)) == 0 || (i & (1 << ret)) != 0)); */
    /*@ assert ((ret % 2 == 1) ==> ((i & (1 << ret)) != 0 || (i & (1 << ret)) == 0)); */
    /*@ assert ((ret % 2 == 1) ==> ((i & (1 << (ret - 1))) != 0)); */
    /*@ assert ((ret % 2 == 1) ==> ((i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0)); */
    /*@ assert ((ret % 2 == 0) || (ret % 2 == 1)); */
    /*@ assert ((ret % 2 == 0) ==> (i & (1 << ret)) != 0 || (i & (1 << ret)) == 0); */
    /*@ assert ((ret % 2 == 0) ==> (i & (1 << (ret - 1))) == 0 || (i & (1 << (ret - 1))) != 0); */
    /*@ assert ((ret % 2 == 0) ==> ((i & 1) == 0 || (i & 1) == 1)); */
    /*@ assert ((ret % 2 == 0) ==> ((i & (1 << ret)) == 0 || (i & (1 << ret)) != 0)); */
    /*@ assert ((ret % 2 == 0) ==> ((i & (1 << ret)) != 0 || (i & (1 << ret)) == 0)); */
    /*@ assert ((ret % 2 == 0) ==> ((i & (1 << (ret - 1))) == 0 || (i & (1 << (ret - 1))) != 0)); */
    /*@ assert ((ret % 2 == 0) ==> ((i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0)); */
    /*@ assert ((number >> ret) == total); */
    /*@ assert ((number >> ret) <= number); */
    /*@ assert ((i & 1) == 0 || (i & 1) == 1); */
}

/*@ requires (ret > 0 ==> (i & 1) == 0 || (i & 1) == 1) && (number == 0 || total <= number) && (total > 0 ==> total == (number >> ret)) && (total == number >> ret) && (total == 0 ==> ret >= 0) && (total == (number >> ret)) && (total == (number >> ret) || total == 0) && (total <= number) && (total + ret <= number) && (total + ret <= number || ret <= number) && (total + ret <= number || 0 <= total) && (total + ret <= number || 0 <= total + ret) && (total + ret <= number || 0 <= i) && (total + ret <= number || 0 < total + (1 << ret)) && (total + ret <= number + ret) && (total + ret <= number + 32) && (total + ret - 32 <= number) && (ret == 0 || total == (number >> ret)) && (ret == 0 || total <= (number >> (ret - 1))) && (ret == 0 || total < number) && (ret == 0 || total < (number >> (ret - 1))) && (ret == 0 || (number >> ret) <= total) && (ret == 0 ==> i == 0) && (ret <= number || 0 <= i) && (ret <= number + 1 || 0 <= i) && (ret <= 32 || ret <= number + 1) && (ret <= 32 ==> total == (number >> ret)) && (ret % 2 == 0 || ret % 2 == 1) && (number == total << ret || number >= total) && (number == 0 || total < (number + 1)) && (number == (total << ret) || number >= total) && (i == 0 || i != 0) && (i == 0 || (i & 1) == 1) && (i == 0 || (i & 1) == 1 || (i & 1) == 0) && (i == 0 || (i & 1) == 0 || (i & 1) == 1) && (i == 0 || (i & (1 << ret)) == 0 || (i & (1 << ret)) != 0) && (i == 0 || (\exists integer k; 0 <= k < ret && i == (i | (1 << k)))) && (i == (i | 0)) && (\forall integer k; ret <= k < 32 ==> (i & (1 << k)) == 0) && (\forall integer k; 0 <= k < ret ==> (i & (1 << k)) == 0 || (i & (1 << k)) != 0) && (\forall integer k; 0 <= k < ret ==> ((k % 2) == 1 ==> (i & (1 << k)) == 0 || (i & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2) == 1 ==> ((i & (1 << k)) == 0 || (i & (1 << k)) != 0))) && (\forall integer k; 0 <= k < ret ==> ((k % 2) == 0 ==> (i & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2) == 0 ==> (i & (1 << k)) != 0 || (i & (1 << k)) == 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2) == 0 ==> ((i & (1 << k)) != 0 || (i & (1 << k)) == 0))) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (i & (1 << k)) == 0 || (i & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (i & (1 << k)) != 0 || (i & (1 << k)) == 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((i & (1 << k)) == 0 || (i & (1 << k)) != 0))) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((i & (1 << k)) != 0 || (i & (1 << k)) == 0))) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (i & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (i & (1 << k)) != 0 || (i & (1 << k)) == 0)) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((i & (1 << k)) != 0))) && (\forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((i & (1 << k)) != 0 || (i & (1 << k)) == 0))) && (\forall integer k; 0 <= k < ret ==> ((i & (1 << k)) == 0 || (i & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> (((k % 2) == 0) ==> (i & (1 << k)) != 0)) && (\forall integer k; 0 <= k < ret ==> (((k % 2) == 0) ==> ((i & (1 << k)) != 0))) && (0 <= total || ret <= 32) && (0 <= total || 0 <= i) && (0 <= total + ret || 0 <= i) && (0 <= ret) && ((ret > 0) ==> (i & (1 << (ret - 1))) == 0 || (i & (1 << (ret - 1))) != 0) && ((ret > 0) ==> (i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0) && ((ret % 2 == 1) ==> (i & (1 << ret)) == 0 || (i & (1 << ret)) != 0) && ((ret % 2 == 1) ==> (i & (1 << ret)) != 0 || (i & (1 << ret)) == 0) && ((ret % 2 == 1) ==> (i & (1 << (ret-1))) != 0) && ((ret % 2 == 1) ==> (i & (1 << (ret - 1))) != 0) && ((ret % 2 == 1) ==> (i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0) && ((ret % 2 == 1) ==> ((i & (1 << ret)) == 0 || (i & (1 << ret)) != 0)) && ((ret % 2 == 1) ==> ((i & (1 << ret)) != 0 || (i & (1 << ret)) == 0)) && ((ret % 2 == 1) ==> ((i & (1 << (ret - 1))) != 0)) && ((ret % 2 == 1) ==> ((i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0)) && ((ret % 2 == 0) || (ret % 2 == 1)) && ((ret % 2 == 0) ==> (i & (1 << ret)) != 0 || (i & (1 << ret)) == 0) && ((ret % 2 == 0) ==> (i & (1 << (ret - 1))) == 0 || (i & (1 << (ret - 1))) != 0) && ((ret % 2 == 0) ==> ((i & 1) == 0 || (i & 1) == 1)) && ((ret % 2 == 0) ==> ((i & (1 << ret)) == 0 || (i & (1 << ret)) != 0)) && ((ret % 2 == 0) ==> ((i & (1 << ret)) != 0 || (i & (1 << ret)) == 0)) && ((ret % 2 == 0) ==> ((i & (1 << (ret - 1))) == 0 || (i & (1 << (ret - 1))) != 0)) && ((ret % 2 == 0) ==> ((i & (1 << (ret - 1))) != 0 || (i & (1 << (ret - 1))) == 0)) && ((number >> ret) == total) && ((number >> ret) <= number) && ((i & 1) == 0 || (i & 1) == 1);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int number, int ret, int total) {
    /*@ assert ((\at(number,Pre) > 0) ==> (0 <= ret)); */
    /*@ assert ((\at(number,Pre) > 0) ==> (total >= 0)); */
    /*@ assert ((\at(number,Pre) > 0) ==> (total <= \at(number,Pre))); */
    /*@ assert ((\at(number,Pre) > 0) ==> (number == \at(number,Pre))); */
    /*@ assert ((!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(i == 0)&&(number == \at(number,Pre)))); */
    /*@ assert (number == \at(number,Pre)); */
}
