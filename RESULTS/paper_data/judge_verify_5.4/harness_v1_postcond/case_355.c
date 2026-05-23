#include <limits.h>


/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */

/*@ensures !(\at(num,Pre) > 0) ==> (\result == \at(num,Pre));
  assigns \nothing;*/
int stub_A(int num);

/*@loop invariant sum > 0 ==> (sum + result) >= result;
		loop invariant sum > 0 ==> (result & 1) == 0 || (result & 1) == 1;
		loop invariant sum <= result + sum;
		loop invariant end == end;
		loop invariant (sum > 0) ==> (result & 1) == 0 || (result & 1) == 1;
		loop invariant (sum == 0) ==> result <= num + 1;
		loop invariant sum >= 0 ==> result + sum <= num + 31;
		loop invariant sum > 0 ==> sum + result <= num + 32;
		loop invariant sum > 0 ==> sum + result <= num + 1;
		loop invariant sum > 0 ==> result >= 0;
		loop invariant sum > 0 ==> result <= num;
		loop invariant sum > 0 ==> result <= num + 1;
		loop invariant sum > 0 ==> result < num + 1;
		loop invariant sum > 0 ==> end == end;
		loop invariant sum > 0 ==> (result % 2 == 0 || result % 2 == 1);
		loop invariant sum > 0 ==> (end & 1) == 0 || (end & 1) == 1;
		loop invariant sum == 0 ==> result >= 0;
		loop invariant sum == 0 ==> result == 0 || result > 0;
		loop invariant sum == 0 ==> result <= num + 1;
		loop invariant sum == 0 ==> end == end;
		loop invariant sum <= num;
		loop invariant sum <= num - result + 32;
		loop invariant sum <= num - result + 1;
		loop invariant sum <= num - result + 1 || sum + result <= num + 1;
		loop invariant sum <= num - result + 1 || result <= num;
		loop invariant sum <= num - result + 1 || result <= num + 1;
		loop invariant sum <= num - result + 1 || 0 <= sum;
		loop invariant sum < num - result + 1;
		loop invariant sum + result <= num + 32;
		loop invariant sum + result <= num + 1;
		loop invariant sum + result <= num + 1 || sum == 0;
		loop invariant sum + result <= num + 1 || result <= num + 1;
		loop invariant sum + result <= num + 1 || 0 <= sum;
		loop invariant sum + result < num + 1;
		loop invariant result >= 0 ==> sum + result <= num + 32;
		loop invariant result > 0 ==> sum < num;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 ==> end == 0;
		loop invariant result <= num || sum + result <= num + 1;
		loop invariant result <= num || 0 <= end;
		loop invariant result <= num ==> sum + result <= num + 32;
		loop invariant result <= num + 1 || 0 <= end;
		loop invariant result <= num + 1 ==> sum + result <= num + 1;
		loop invariant result + sum <= num + result;
		loop invariant result + sum <= num + 32;
		loop invariant result + sum <= num + 31;
		loop invariant result + sum <= num + 1;
		loop invariant result + sum <= num + 1 || sum == 0;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant end <= (1 << 31);
		loop invariant 0 <= sum || 0 <= end;
		loop invariant 0 <= result;
		loop invariant 0 <= end || sum <= num - result + 1;
		loop invariant 0 <= end || sum + result <= num + 1;
		loop invariant 0 <= end || result <= num;
		loop invariant 0 <= end || result <= num + 1;
		loop invariant 0 <= end || 0 <= sum;
		loop invariant (sum > 0) ==> result <= num + 1;
		loop invariant (sum > 0) ==> result < num + 1;
		loop invariant (sum > 0) ==> (result <= num + 1);
		loop invariant (sum == 0) ==> result >= 0;
		loop invariant (sum == 0) ==> end == end;
		loop invariant (sum == 0) ==> (result >= 0);
		loop invariant (sum == 0) ==> (result == 0 || result > 0);
		loop invariant (sum == 0) ==> (end == end);
		loop invariant (result & 1) == 0 || (result & 1) == 1;
		loop invariant (result % 2 == 0) || (result % 2 == 1);
		loop invariant (end & 1) == 0 || (end & 1) == 1;
		loop assigns sum;
		loop assigns result;
		loop assigns end;*/
int stub_B(int num);

/*@loop invariant sum > 0 ==> (sum + result) >= result;
		loop invariant sum > 0 ==> (result & 1) == 0 || (result & 1) == 1;
		loop invariant sum <= result + sum;
		loop invariant end == end;
		loop invariant (sum > 0) ==> (result & 1) == 0 || (result & 1) == 1;
		loop invariant (sum == 0) ==> result <= num + 1;
		loop invariant sum >= 0 ==> result + sum <= num + 31;
		loop invariant sum > 0 ==> sum + result <= num + 32;
		loop invariant sum > 0 ==> sum + result <= num + 1;
		loop invariant sum > 0 ==> result >= 0;
		loop invariant sum > 0 ==> result <= num;
		loop invariant sum > 0 ==> result <= num + 1;
		loop invariant sum > 0 ==> result < num + 1;
		loop invariant sum > 0 ==> end == end;
		loop invariant sum > 0 ==> (result % 2 == 0 || result % 2 == 1);
		loop invariant sum > 0 ==> (end & 1) == 0 || (end & 1) == 1;
		loop invariant sum == 0 ==> result >= 0;
		loop invariant sum == 0 ==> result == 0 || result > 0;
		loop invariant sum == 0 ==> result <= num + 1;
		loop invariant sum == 0 ==> end == end;
		loop invariant sum <= num;
		loop invariant sum <= num - result + 32;
		loop invariant sum <= num - result + 1;
		loop invariant sum <= num - result + 1 || sum + result <= num + 1;
		loop invariant sum <= num - result + 1 || result <= num;
		loop invariant sum <= num - result + 1 || result <= num + 1;
		loop invariant sum <= num - result + 1 || 0 <= sum;
		loop invariant sum < num - result + 1;
		loop invariant sum + result <= num + 32;
		loop invariant sum + result <= num + 1;
		loop invariant sum + result <= num + 1 || sum == 0;
		loop invariant sum + result <= num + 1 || result <= num + 1;
		loop invariant sum + result <= num + 1 || 0 <= sum;
		loop invariant sum + result < num + 1;
		loop invariant result >= 0 ==> sum + result <= num + 32;
		loop invariant result > 0 ==> sum < num;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 ==> end == 0;
		loop invariant result <= num || sum + result <= num + 1;
		loop invariant result <= num || 0 <= end;
		loop invariant result <= num ==> sum + result <= num + 32;
		loop invariant result <= num + 1 || 0 <= end;
		loop invariant result <= num + 1 ==> sum + result <= num + 1;
		loop invariant result + sum <= num + result;
		loop invariant result + sum <= num + 32;
		loop invariant result + sum <= num + 31;
		loop invariant result + sum <= num + 1;
		loop invariant result + sum <= num + 1 || sum == 0;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant end <= (1 << 31);
		loop invariant 0 <= sum || 0 <= end;
		loop invariant 0 <= result;
		loop invariant 0 <= end || sum <= num - result + 1;
		loop invariant 0 <= end || sum + result <= num + 1;
		loop invariant 0 <= end || result <= num;
		loop invariant 0 <= end || result <= num + 1;
		loop invariant 0 <= end || 0 <= sum;
		loop invariant (sum > 0) ==> result <= num + 1;
		loop invariant (sum > 0) ==> result < num + 1;
		loop invariant (sum > 0) ==> (result <= num + 1);
		loop invariant (sum == 0) ==> result >= 0;
		loop invariant (sum == 0) ==> end == end;
		loop invariant (sum == 0) ==> (result >= 0);
		loop invariant (sum == 0) ==> (result == 0 || result > 0);
		loop invariant (sum == 0) ==> (end == end);
		loop invariant (result & 1) == 0 || (result & 1) == 1;
		loop invariant (result % 2 == 0) || (result % 2 == 1);
		loop invariant (end & 1) == 0 || (end & 1) == 1;
		loop assigns sum;
		loop assigns result;
		loop assigns end;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@ensures !(\at(num,Pre) > 0) ==> (\result == \at(num,Pre));
  assigns \nothing;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
