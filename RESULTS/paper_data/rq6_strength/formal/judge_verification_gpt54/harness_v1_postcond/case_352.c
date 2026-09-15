#include <limits.h>



/*@ensures \exists integer ret_62, total_61; (total_61 <= 0) && (0 <= ret_62) && (total_61 == number >> ret_62) ==> (\result == (number ^ 0));

assigns \nothing;*/
int stub_A(int number);

/*@loop invariant total == 0 || total <= number;
		loop invariant total == 0 || total == (number >> ret);
		loop invariant total == 0 || total <= (number >> ret);
		loop invariant total == 0 || total < number + 1;
		loop invariant total == 0 || total < (number + 1);
		loop invariant total == 0 || total < (1 << 31);
		loop invariant total == 0 ==> ret >= 0;
		loop invariant total == (number >> ret);
		loop invariant total == (number >> ret) || total == 0;
		loop invariant total <= number;
		loop invariant total <= number || number <= 0;
		loop invariant total <= number || number < 0;
		loop invariant total <= (number >> ret) || total == 0;
		loop invariant total <= (number >> ret) || number < 0;
		loop invariant ret == 0 || total < number;
		loop invariant ret == 0 ==> result == 0;
		loop invariant ret <= number + 1 || total <= number;
		loop invariant ret <= number + 1 || ret <= 32;
		loop invariant ret <= 32 || ret <= number + 1;
		loop invariant ret <= 32 || 0 <= total;
		loop invariant ret <= 32 ==> total <= number;
		loop invariant ret <= 32 ==> total <= (number >> ret) || total == 0;
		loop invariant ret + total <= number + 32;
		loop invariant ret + total <= number + 1;
		loop invariant ret % 2 == 1 ==> (result & (1 << (ret-1))) != 0 || result == 0;
		loop invariant ret % 2 == 1 ==> ((result >> (ret-1)) & 1) == 1 || result == 0;
		loop invariant ret % 2 == 1 ==> ((result >> (ret - 1)) & 1) == 1 || result == 0;
		loop invariant ret % 2 == 1 ==> ((result & (1 << (ret-1))) != 0 || result == 0);
		loop invariant ret % 2 == 1 ==> ((result & (1 << (ret - 1))) != 0 || result == 0);
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 2 == 0 ==> (result & 1) == 1 || result == 0;
		loop invariant ret % 2 == 0 ==> ((result >> 0) & 1) == 1 || result == 0;
		loop invariant result == 0 || total < number || total == number;
		loop invariant result == 0 || result < (1 << 31);
		loop invariant result == 0 || (result & 1) == 1;
		loop invariant result == 0 ==> ret == 0;
		loop invariant result == 0 ==> ret == 0 || total == number;
		loop invariant result == 0 ==> ret == 0 || total == 0;
		loop invariant result == (number ^ (number ^ result));
		loop invariant result < (1 << 31);
		loop invariant result < (1 << 31) || ret >= 31;
		loop invariant result < (1 << 31) || ret <= 31;
		loop invariant result < (1 << 31) || result == 0;
		loop invariant result < (1 << (ret + 1)) || ret <= number + 1;
		loop invariant result < (1 << (ret + 1)) || 0 <= total;
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 1 ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || result == 0);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1;
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1));
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result & (1 << k)) != 0));
		loop invariant \forall integer k; 0 <= k < ret ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> (((k % 2 == 0) ==> ((result >> k) & 1) == 1) || ((result >> k) & 1) == 0);
		loop invariant \forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0;
		loop invariant 0 <= total || ret <= 32;
		loop invariant 0 <= total || 0 <= result;
		loop invariant 0 <= total <= number || number <= 0;
		loop invariant 0 <= total <= number || number < 0;
		loop invariant 0 <= ret;
		loop invariant 0 <= result || ret <= number + 1;
		loop invariant 0 <= result || 0 <= total;
		loop invariant (ret % 2 == 1) ==> ((result >> (ret-1)) & 1) == 1 || result == 0;
		loop invariant (ret % 2 == 1) ==> ((result & 1) == 1 || result == 0);
		loop invariant (ret % 2 == 1) ==> ((result & (1 << (ret-1))) != 0 || result == 0);
		loop invariant (ret % 2 == 1) ==> ((result & (1 << (ret - 1))) != 0 || result == 0);
		loop invariant (ret % 2 == 0) ==> ((result & 1) == 1 || result == 0);
		loop assigns total;
		loop assigns ret;
		loop assigns result;*/
int stub_B(int number);

/*@loop invariant total == 0 || total <= number;
		loop invariant total == 0 || total == (number >> ret);
		loop invariant total == 0 || total <= (number >> ret);
		loop invariant total == 0 || total < number + 1;
		loop invariant total == 0 || total < (number + 1);
		loop invariant total == 0 || total < (1 << 31);
		loop invariant total == 0 ==> ret >= 0;
		loop invariant total == (number >> ret);
		loop invariant total == (number >> ret) || total == 0;
		loop invariant total <= number;
		loop invariant total <= number || number <= 0;
		loop invariant total <= number || number < 0;
		loop invariant total <= (number >> ret) || total == 0;
		loop invariant total <= (number >> ret) || number < 0;
		loop invariant ret == 0 || total < number;
		loop invariant ret == 0 ==> result == 0;
		loop invariant ret <= number + 1 || total <= number;
		loop invariant ret <= number + 1 || ret <= 32;
		loop invariant ret <= 32 || ret <= number + 1;
		loop invariant ret <= 32 || 0 <= total;
		loop invariant ret <= 32 ==> total <= number;
		loop invariant ret <= 32 ==> total <= (number >> ret) || total == 0;
		loop invariant ret + total <= number + 32;
		loop invariant ret + total <= number + 1;
		loop invariant ret % 2 == 1 ==> (result & (1 << (ret-1))) != 0 || result == 0;
		loop invariant ret % 2 == 1 ==> ((result >> (ret-1)) & 1) == 1 || result == 0;
		loop invariant ret % 2 == 1 ==> ((result >> (ret - 1)) & 1) == 1 || result == 0;
		loop invariant ret % 2 == 1 ==> ((result & (1 << (ret-1))) != 0 || result == 0);
		loop invariant ret % 2 == 1 ==> ((result & (1 << (ret - 1))) != 0 || result == 0);
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 2 == 0 ==> (result & 1) == 1 || result == 0;
		loop invariant ret % 2 == 0 ==> ((result >> 0) & 1) == 1 || result == 0;
		loop invariant result == 0 || total < number || total == number;
		loop invariant result == 0 || result < (1 << 31);
		loop invariant result == 0 || (result & 1) == 1;
		loop invariant result == 0 ==> ret == 0;
		loop invariant result == 0 ==> ret == 0 || total == number;
		loop invariant result == 0 ==> ret == 0 || total == 0;
		loop invariant result == (number ^ (number ^ result));
		loop invariant result < (1 << 31);
		loop invariant result < (1 << 31) || ret >= 31;
		loop invariant result < (1 << 31) || ret <= 31;
		loop invariant result < (1 << 31) || result == 0;
		loop invariant result < (1 << (ret + 1)) || ret <= number + 1;
		loop invariant result < (1 << (ret + 1)) || 0 <= total;
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 1 ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || result == 0);
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1;
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> ((result >> k) & 1) == 0 || ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 1) ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1));
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result >> k) & 1) == 1 || ((result >> k) & 1) == 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> ((result & (1 << k)) != 0));
		loop invariant \forall integer k; 0 <= k < ret ==> (((result >> k) & 1) == 0 || ((result >> k) & 1) == 1);
		loop invariant \forall integer k; 0 <= k < ret ==> (((k % 2 == 0) ==> ((result >> k) & 1) == 1) || ((result >> k) & 1) == 0);
		loop invariant \forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0;
		loop invariant 0 <= total || ret <= 32;
		loop invariant 0 <= total || 0 <= result;
		loop invariant 0 <= total <= number || number <= 0;
		loop invariant 0 <= total <= number || number < 0;
		loop invariant 0 <= ret;
		loop invariant 0 <= result || ret <= number + 1;
		loop invariant 0 <= result || 0 <= total;
		loop invariant (ret % 2 == 1) ==> ((result >> (ret-1)) & 1) == 1 || result == 0;
		loop invariant (ret % 2 == 1) ==> ((result & 1) == 1 || result == 0);
		loop invariant (ret % 2 == 1) ==> ((result & (1 << (ret-1))) != 0 || result == 0);
		loop invariant (ret % 2 == 1) ==> ((result & (1 << (ret - 1))) != 0 || result == 0);
		loop invariant (ret % 2 == 0) ==> ((result & 1) == 1 || result == 0);
		loop assigns total;
		loop assigns ret;
		loop assigns result;*/
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@ensures \exists integer ret_62, total_61; (total_61 <= 0) && (0 <= ret_62) && (total_61 == number >> ret_62) ==> (\result == (number ^ 0));

assigns \nothing;*/
int check_B_implies_A(int number) {
    return stub_B(number);
}
