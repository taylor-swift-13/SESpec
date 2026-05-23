#include <limits.h>



/*@requires args_len > 0;
  requires 0 <= array <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 ==> 1 <= \result;
  ensures array > 1 ==> \forall integer k; 1 <= k < \result ==> args[k - 1] == k;
  ensures array > 1 && \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && \result == array ==> \forall integer k; 1 <= k < array ==> args[k - 1] == k;
  ensures \result == 1 || array > 1;*/
int stub_A(int * args, int args_len, int array);

/*@loop invariant remaining == find || remaining == find + 1 || find == 1;
		loop invariant remaining == 1 ==> find == 1;
		loop invariant remaining <= array || remaining - find <= 1;
		loop invariant remaining <= array + 1 || remaining - find <= 1;
		loop invariant remaining - find <= 1;
		loop invariant find == remaining - 1 || find == remaining;
		loop invariant find == remaining - 1 || find == 1;
		loop invariant find == 1 || find == remaining || find == remaining - 1;
		loop invariant find == 1 || find == remaining - 1;
		loop invariant find == 1 || find == remaining - 1 || find == remaining;
		loop invariant find == 1 || find < remaining;
		loop invariant find == 1 || (1 <= find <= remaining);
		loop invariant find <= remaining;
		loop invariant find <= remaining + 1;
		loop invariant find <= array || remaining - find <= 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k || args[k - 1] != k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find <= remaining;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find != k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1 || find == 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == 1 || find == k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= remaining;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find != k;
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k || args[k - 1] != k);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find != k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == k - 1 || find == 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == 1 || find == k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= remaining);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find != k);
		loop invariant 1 <= remaining;
		loop invariant 1 <= find;
		loop assigns remaining;
		loop assigns find;*/
int stub_B(int * args, int args_len, int array);

/*@loop invariant remaining == find || remaining == find + 1 || find == 1;
		loop invariant remaining == 1 ==> find == 1;
		loop invariant remaining <= array || remaining - find <= 1;
		loop invariant remaining <= array + 1 || remaining - find <= 1;
		loop invariant remaining - find <= 1;
		loop invariant find == remaining - 1 || find == remaining;
		loop invariant find == remaining - 1 || find == 1;
		loop invariant find == 1 || find == remaining || find == remaining - 1;
		loop invariant find == 1 || find == remaining - 1;
		loop invariant find == 1 || find == remaining - 1 || find == remaining;
		loop invariant find == 1 || find < remaining;
		loop invariant find == 1 || (1 <= find <= remaining);
		loop invariant find <= remaining;
		loop invariant find <= remaining + 1;
		loop invariant find <= array || remaining - find <= 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k || args[k - 1] != k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find <= remaining;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find != k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1 || find == 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == 1 || find == k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= remaining;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k - 1;
		loop invariant \forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find != k;
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k || args[k - 1] != k);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find != k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == k - 1 || find == 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == 1 || find == k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= remaining);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k - 1);
		loop invariant \forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find != k);
		loop invariant 1 <= remaining;
		loop invariant 1 <= find;
		loop assigns remaining;
		loop assigns find;*/
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@requires args_len > 0;
  requires 0 <= array <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 ==> 1 <= \result;
  ensures array > 1 ==> \forall integer k; 1 <= k < \result ==> args[k - 1] == k;
  ensures array > 1 && \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && \result == array ==> \forall integer k; 1 <= k < array ==> args[k - 1] == k;
  ensures \result == 1 || array > 1;*/
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
