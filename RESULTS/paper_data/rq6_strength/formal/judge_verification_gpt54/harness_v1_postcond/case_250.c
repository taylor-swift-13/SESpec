#include <limits.h>
#include <stddef.h>


/*@ 
  logic integer dummy_logic = 0;
*/

/*@requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures start == \old(start);
  ensures stop == \old(stop);
  ensures \result >= \old(start);
  ensures \result >= \old(start);
  ensures \old(start) > \old(stop) ==> \result >= \old(start);*/
int stub_A(int * args, int args_len, int start, int stop);

/*@loop invariant total <= stop;
		loop invariant total < stop + 1;
		loop invariant total - result <= stop - start + 2;
		loop invariant total - result <= stop - start + 1;
		loop invariant total - result <= stop - start + 1 || start - 1 <= total;
		loop invariant total - result <= stop - start + 1 || start - 1 <= mid;
		loop invariant total - result <= stop - start + 1 || result <= total + 1;
		loop invariant total - result <= stop - start + 1 || result <= stop + 1;
		loop invariant total - result <= stop - start + 1 || mid <= stop;
		loop invariant total - result < stop - start + 2;
		loop invariant total - result < stop - start + 2 || start <= total + 1;
		loop invariant total - result < stop - start + 2 || result <= stop + 1;
		loop invariant total - result < stop - start + 1;
		loop invariant total - result < stop - start + 1 || result <= total + 1;
		loop invariant start <= result;
		loop invariant start - 1 <= total || total - result < stop - start + 2;
		loop invariant result <= total + 1 || total - result < stop - start + 2;
		loop invariant result <= total + 1 || result - start <= stop - total + 1;
		loop invariant result - total <= stop - start + 1 || total - result < stop - start + 2;
		loop invariant result - start <= stop - total + 1 || total - result < stop - start + 2;
		loop invariant result - start <= stop - total + 1 || start <= total + 1;
		loop invariant result - start <= stop - total + 1 || start - 1 <= total;
		loop invariant result - start <= stop - total + 1 || result <= stop + 1;
		loop invariant result - start <= stop - total + 1 || result - total <= stop - start + 1;
		loop invariant result - start <= stop - total + 1 || mid <= stop;
		loop invariant mid <= stop || total - result < stop - start + 2;
		loop invariant \forall integer k; start <= k <= total ==> k >= start;
		loop invariant \forall integer k; start <= k <= total ==> k <= stop;
		loop invariant \forall integer k; start <= k <= stop ==> k >= start;
		loop invariant \forall integer k; start <= k <= stop ==> k <= stop;
		loop invariant 0 <= start || total - result < stop - start + 2;
		loop invariant 0 <= result - start;
		loop assigns total;
		loop assigns result;
		loop assigns mid;*/
int stub_B(int * args, int args_len, int start, int stop);

/*@loop invariant total <= stop;
		loop invariant total < stop + 1;
		loop invariant total - result <= stop - start + 2;
		loop invariant total - result <= stop - start + 1;
		loop invariant total - result <= stop - start + 1 || start - 1 <= total;
		loop invariant total - result <= stop - start + 1 || start - 1 <= mid;
		loop invariant total - result <= stop - start + 1 || result <= total + 1;
		loop invariant total - result <= stop - start + 1 || result <= stop + 1;
		loop invariant total - result <= stop - start + 1 || mid <= stop;
		loop invariant total - result < stop - start + 2;
		loop invariant total - result < stop - start + 2 || start <= total + 1;
		loop invariant total - result < stop - start + 2 || result <= stop + 1;
		loop invariant total - result < stop - start + 1;
		loop invariant total - result < stop - start + 1 || result <= total + 1;
		loop invariant start <= result;
		loop invariant start - 1 <= total || total - result < stop - start + 2;
		loop invariant result <= total + 1 || total - result < stop - start + 2;
		loop invariant result <= total + 1 || result - start <= stop - total + 1;
		loop invariant result - total <= stop - start + 1 || total - result < stop - start + 2;
		loop invariant result - start <= stop - total + 1 || total - result < stop - start + 2;
		loop invariant result - start <= stop - total + 1 || start <= total + 1;
		loop invariant result - start <= stop - total + 1 || start - 1 <= total;
		loop invariant result - start <= stop - total + 1 || result <= stop + 1;
		loop invariant result - start <= stop - total + 1 || result - total <= stop - start + 1;
		loop invariant result - start <= stop - total + 1 || mid <= stop;
		loop invariant mid <= stop || total - result < stop - start + 2;
		loop invariant \forall integer k; start <= k <= total ==> k >= start;
		loop invariant \forall integer k; start <= k <= total ==> k <= stop;
		loop invariant \forall integer k; start <= k <= stop ==> k >= start;
		loop invariant \forall integer k; start <= k <= stop ==> k <= stop;
		loop invariant 0 <= start || total - result < stop - start + 2;
		loop invariant 0 <= result - start;
		loop assigns total;
		loop assigns result;
		loop assigns mid;*/
int check_A_implies_B(int * args, int args_len, int start, int stop) {
    return stub_A(args, args_len, start, stop);
}

/*@requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures start == \old(start);
  ensures stop == \old(stop);
  ensures \result >= \old(start);
  ensures \result >= \old(start);
  ensures \old(start) > \old(stop) ==> \result >= \old(start);*/
int check_B_implies_A(int * args, int args_len, int start, int stop) {
    return stub_B(args, args_len, start, stop);
}
