#include <limits.h>



/*@requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  requires array >= 0;
  requires array <= positions_len;
  assigns positions[0..array-1];
  ensures (\forall integer k; 0 <= k < array ==> \at(positions[k],Pre) == k + 1) ==> 1 <= \result <= array + 1;
  ensures (\exists integer k; 0 <= k < array && \at(positions[k],Pre) != k + 1) ==> 1 <= \result <= array + 1;*/
int stub_A(int * positions, int positions_len, int array);

/*@loop invariant ret == array ==> \forall integer k; 0 <= k < array ==> positions[k] == k + 1;
		loop invariant ret == 0 || positions[ret-1] == ret;
		loop invariant ret == 0 || positions[ret - 1] == ret;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] == positions[k];
		loop invariant \forall integer k; ret <= k < array ==> positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] != k + 1 || positions[k] == k + 1;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] == positions[k];
		loop invariant \forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] <= 0 || positions[k] > array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] > 0;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] > 0 && positions[k] <= array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == positions[k];
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] <= array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] != 0;
		loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == positions[k];
		loop invariant \forall integer k; 0 <= k < array ==> positions[k] == positions[k];
		loop invariant 0 <= ret;
		loop assigns ret;
		loop assigns positions[0..positions_len-1];
		loop assigns positions[0..array-1];*/
int stub_B(int * positions, int positions_len, int array);

/*@loop invariant ret == array ==> \forall integer k; 0 <= k < array ==> positions[k] == k + 1;
		loop invariant ret == 0 || positions[ret-1] == ret;
		loop invariant ret == 0 || positions[ret - 1] == ret;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] == positions[k];
		loop invariant \forall integer k; ret <= k < array ==> positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] != k + 1 || positions[k] == k + 1;
		loop invariant \forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] == positions[k];
		loop invariant \forall integer k; ret <= k < array ==> positions[k] != k + 1 ==> positions[k] <= 0 || positions[k] > array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] > 0;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] > 0 && positions[k] <= array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == positions[k];
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] <= array;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] <= 0 || positions[k] > array || positions[k] == k + 1;
		loop invariant \forall integer k; 0 <= k < ret ==> positions[k] != 0;
		loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == positions[k];
		loop invariant \forall integer k; 0 <= k < array ==> positions[k] == positions[k];
		loop invariant 0 <= ret;
		loop assigns ret;
		loop assigns positions[0..positions_len-1];
		loop assigns positions[0..array-1];*/
int check_A_implies_B(int * positions, int positions_len, int array) {
    return stub_A(positions, positions_len, array);
}

/*@requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  requires array >= 0;
  requires array <= positions_len;
  assigns positions[0..array-1];
  ensures (\forall integer k; 0 <= k < array ==> \at(positions[k],Pre) == k + 1) ==> 1 <= \result <= array + 1;
  ensures (\exists integer k; 0 <= k < array && \at(positions[k],Pre) != k + 1) ==> 1 <= \result <= array + 1;*/
int check_B_implies_A(int * positions, int positions_len, int array) {
    return stub_B(positions, positions_len, array);
}
