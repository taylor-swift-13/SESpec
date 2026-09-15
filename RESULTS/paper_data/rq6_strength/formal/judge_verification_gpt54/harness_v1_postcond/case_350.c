#include <limits.h>


/*@ logic integer selected_even_bits(integer x) =
      x <= 0 ? 0 : ((x % 2 == 1) ? 1 : 0) + 4 * selected_even_bits(x / 4); */

/*@assigns \nothing;
   ensures num <= 0 ==> \result == num;*/
int stub_A(int num);

/*@loop invariant ret > 0 ==> total == (num >> ret) || total == 0;
		loop invariant total == 0 || total == (num >> ret);
		loop invariant total == 0 ==> ret >= 0;
		loop invariant total == (num >> ret);
		loop invariant total == (num >> ret) || total == 0;
		loop invariant total <= num;
		loop invariant ret > 0 ==> total == (num >> ret);
		loop invariant ret > 0 ==> total <= num;
		loop invariant ret > 0 ==> total < num;
		loop invariant ret > 0 ==> total < num || total == 0;
		loop invariant ret > 0 ==> result != 0 || total == num;
		loop invariant ret > 0 ==> (result & 1) != 0 || result == 0;
		loop invariant ret == 32 || total == (num >> ret);
		loop invariant ret == 0 || total < num;
		loop invariant ret == 0 ==> total == num;
		loop invariant ret == 0 ==> result == 0;
		loop invariant ret <= 32 ==> total == (num >> ret);
		loop invariant ret <= 32 ==> total + ret <= num + 32;
		loop invariant ret <= 32 ==> (result & 1) != 0 || ret == 0;
		loop invariant ret + total <= num + 32;
		loop invariant ret + total <= num + 32 || ret <= 32;
		loop invariant ret + total <= num + 32 || ret <= 31;
		loop invariant ret + total <= num + 32 || 0 <= result;
		loop invariant ret + total < num + 32;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 2 == 0 ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant ret % 2 == 0 ==> (result & 1) != 0 || ret == 0;
		loop invariant ret % 2 == 0 ==> (result & 1) != 0 || result == 0;
		loop invariant ret % 2 == 0 ==> ((result & 1) != 0 || ret == 0);
		loop invariant result == 0 || (result & 1) != 0;
		loop invariant \forall integer k; ret <= k < 32 ==> (result & (1 << k)) == 0;
		loop invariant \forall integer k; ret <= k < 31 ==> (result & (1 << k)) == 0;
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0;
		loop invariant 0 <= total || ret <= 32;
		loop invariant 0 <= total || ret <= 31;
		loop invariant 0 <= total || ret + total <= num + 32;
		loop invariant 0 <= total || 0 <= result;
		loop invariant 0 <= ret;
		loop invariant (ret % 2 == 0) ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant (ret % 2 == 0) ==> (result & 1) != 0 || ret == 0;
		loop invariant (ret % 2 == 0) ==> ((result & 1) != 0 || ret == 0);
		loop invariant (result & 1) != 0 || ret == 0;
		loop invariant (result & 1) != 0 || result == 0;
		loop invariant (result & 1) != 0 ==> ret > 0;
		loop assigns total;
		loop assigns ret;
		loop assigns result;*/
int stub_B(int num);

/*@loop invariant ret > 0 ==> total == (num >> ret) || total == 0;
		loop invariant total == 0 || total == (num >> ret);
		loop invariant total == 0 ==> ret >= 0;
		loop invariant total == (num >> ret);
		loop invariant total == (num >> ret) || total == 0;
		loop invariant total <= num;
		loop invariant ret > 0 ==> total == (num >> ret);
		loop invariant ret > 0 ==> total <= num;
		loop invariant ret > 0 ==> total < num;
		loop invariant ret > 0 ==> total < num || total == 0;
		loop invariant ret > 0 ==> result != 0 || total == num;
		loop invariant ret > 0 ==> (result & 1) != 0 || result == 0;
		loop invariant ret == 32 || total == (num >> ret);
		loop invariant ret == 0 || total < num;
		loop invariant ret == 0 ==> total == num;
		loop invariant ret == 0 ==> result == 0;
		loop invariant ret <= 32 ==> total == (num >> ret);
		loop invariant ret <= 32 ==> total + ret <= num + 32;
		loop invariant ret <= 32 ==> (result & 1) != 0 || ret == 0;
		loop invariant ret + total <= num + 32;
		loop invariant ret + total <= num + 32 || ret <= 32;
		loop invariant ret + total <= num + 32 || ret <= 31;
		loop invariant ret + total <= num + 32 || 0 <= result;
		loop invariant ret + total < num + 32;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant ret % 2 == 0 ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant ret % 2 == 0 ==> (result & 1) != 0 || ret == 0;
		loop invariant ret % 2 == 0 ==> (result & 1) != 0 || result == 0;
		loop invariant ret % 2 == 0 ==> ((result & 1) != 0 || ret == 0);
		loop invariant result == 0 || (result & 1) != 0;
		loop invariant \forall integer k; ret <= k < 32 ==> (result & (1 << k)) == 0;
		loop invariant \forall integer k; ret <= k < 31 ==> (result & (1 << k)) == 0;
		loop invariant \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret ==> ((k % 2 == 0) ==> (result & (1 << k)) != 0);
		loop invariant \forall integer k; 0 <= k < ret && k % 2 == 0 ==> (result & (1 << k)) != 0;
		loop invariant 0 <= total || ret <= 32;
		loop invariant 0 <= total || ret <= 31;
		loop invariant 0 <= total || ret + total <= num + 32;
		loop invariant 0 <= total || 0 <= result;
		loop invariant 0 <= ret;
		loop invariant (ret % 2 == 0) ==> \forall integer k; 0 <= k < ret ==> (k % 2 == 0 ==> (result & (1 << k)) != 0);
		loop invariant (ret % 2 == 0) ==> (result & 1) != 0 || ret == 0;
		loop invariant (ret % 2 == 0) ==> ((result & 1) != 0 || ret == 0);
		loop invariant (result & 1) != 0 || ret == 0;
		loop invariant (result & 1) != 0 || result == 0;
		loop invariant (result & 1) != 0 ==> ret > 0;
		loop assigns total;
		loop assigns ret;
		loop assigns result;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@assigns \nothing;
   ensures num <= 0 ==> \result == num;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
