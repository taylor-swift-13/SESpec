#include <limits.h>


/*@
  logic integer oddcount(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : oddcount(args, lo, hi - 1) + ((args[hi - 1] % 2) != 0 ? 1 : 0);

  logic integer oddret(int* args, integer lo, integer hi) =
             : (((args[hi - 1] % 2) != 0) && ((oddcount(args, lo, hi - 1) + 1) % 2 != 0))
               ? args[hi - 1]
               : oddret(args, lo, hi - 1);
*/

/*@requires array >= 0;
  requires \valid_read(args + (0..array-1));
  assigns \nothing;
  ensures array == 0 ==> \result == 0;
  ensures \result == oddret(args, 0, array);*/
int stub_A(int * args, int args_len, int array);

/*@loop invariant start > 0 ==> ret == args[index - 1] || ret != 0;
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 0);
		loop invariant start > 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start > 0 ==> ret != 0;
		loop invariant start > 0 ==> ret != 0 || ret == args[index - 1];
		loop invariant start > 0 ==> (ret == 0 || ret % 2 != 0);
		loop invariant start > 0 ==> (\exists integer k; 0 <= k < index && args[k] % 2 != 0);
		loop invariant start == index || start < index;
		loop invariant start == index ==> ret == 0 || ret != 0;
		loop invariant start == index - (index - start);
		loop invariant start == 0 || start >= 1;
		loop invariant start == 0 || start > 0;
		loop invariant start == 0 || start <= index;
		loop invariant start == 0 || ret != 0;
		loop invariant start == 0 ==> ret == 0;
		loop invariant start <= index;
		loop invariant start <= index + 1;
		loop invariant start <= array || start <= index + 1;
		loop invariant start < index + 1;
		loop invariant start % 2 == 1 ==> ret == args[index - 1] || ret != 0;
		loop invariant start % 2 == 1 ==> ret != 0;
		loop invariant start % 2 == 0 || start % 2 == 1;
		loop invariant start % 2 == 0 || start % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k]);
		loop invariant start % 2 != 0 ==> ret == args[index-1] || ret != 0;
		loop invariant start % 2 != 0 ==> ret == args[index - 1] || ret != 0;
		loop invariant start % 2 != 0 ==> ret != 0;
		loop invariant start % 2 != 0 ==> ret != 0 || ret == args[index - 1];
		loop invariant ret == 0 || ret == args[index-1] || ret % 2 != 0;
		loop invariant ret == 0 || ret == args[index-1] || ret != 0;
		loop invariant ret == 0 || ret == args[index - 1] || ret % 2 != 0;
		loop invariant ret == 0 || ret == args[index - 1] || ret != 0;
		loop invariant ret == 0 || ret % 2 != 0;
		loop invariant ret == 0 || ret % 2 != 0 || ret == args[index - 1];
		loop invariant ret == 0 || ret != 0;
		loop invariant ret == 0 || \exists integer k; 0 <= k < index && args[k] == ret;
		loop invariant ret == 0 || (ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k]);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && (args[k] % 2 != 0) && ret == args[k]);
		loop invariant ret == 0 ==> start == 0;
		loop invariant ret == 0 ==> start == 0 || start > 0;
		loop invariant ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret;
		loop invariant ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0;
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant index == start + (index - start);
		loop invariant index <= array || start <= index + 1;
		loop invariant index % 2 == 0 || index % 2 != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] == 0 || args[k] != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start >= 1;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start > 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> k < array;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> args[k] != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] != 0 || args[k] == 0;
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 == 0 || args[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> ret == args[k] || ret != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> k < array);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> args[k] != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> 0 <= k < array);
		loop invariant \forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0;
		loop invariant \forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> 0 <= k < array;
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start >= 1;
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start > 0;
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret == args[k];
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret != 0;
		loop invariant 0 <= start;
		loop invariant 0 <= ret || start <= array;
		loop invariant 0 <= ret || index <= array;
		loop invariant 0 <= index;
		loop invariant 0 <= index ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant 0 <= index - start;
		loop invariant (start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant (start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k]);
		loop invariant (start % 2 != 0) ==> ret != 0;
		loop invariant (\forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0);
		loop invariant (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1));
		loop invariant (\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0);
		loop assigns start;
		loop assigns ret;
		loop assigns index;*/
int stub_B(int * args, int args_len, int array);

/*@loop invariant start > 0 ==> ret == args[index - 1] || ret != 0;
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 0);
		loop invariant start > 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start > 0 ==> ret != 0;
		loop invariant start > 0 ==> ret != 0 || ret == args[index - 1];
		loop invariant start > 0 ==> (ret == 0 || ret % 2 != 0);
		loop invariant start > 0 ==> (\exists integer k; 0 <= k < index && args[k] % 2 != 0);
		loop invariant start == index || start < index;
		loop invariant start == index ==> ret == 0 || ret != 0;
		loop invariant start == index - (index - start);
		loop invariant start == 0 || start >= 1;
		loop invariant start == 0 || start > 0;
		loop invariant start == 0 || start <= index;
		loop invariant start == 0 || ret != 0;
		loop invariant start == 0 ==> ret == 0;
		loop invariant start <= index;
		loop invariant start <= index + 1;
		loop invariant start <= array || start <= index + 1;
		loop invariant start < index + 1;
		loop invariant start % 2 == 1 ==> ret == args[index - 1] || ret != 0;
		loop invariant start % 2 == 1 ==> ret != 0;
		loop invariant start % 2 == 0 || start % 2 == 1;
		loop invariant start % 2 == 0 || start % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret % 2 != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || ret != 0;
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0);
		loop invariant start % 2 == 0 ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k]);
		loop invariant start % 2 != 0 ==> ret == args[index-1] || ret != 0;
		loop invariant start % 2 != 0 ==> ret == args[index - 1] || ret != 0;
		loop invariant start % 2 != 0 ==> ret != 0;
		loop invariant start % 2 != 0 ==> ret != 0 || ret == args[index - 1];
		loop invariant ret == 0 || ret == args[index-1] || ret % 2 != 0;
		loop invariant ret == 0 || ret == args[index-1] || ret != 0;
		loop invariant ret == 0 || ret == args[index - 1] || ret % 2 != 0;
		loop invariant ret == 0 || ret == args[index - 1] || ret != 0;
		loop invariant ret == 0 || ret % 2 != 0;
		loop invariant ret == 0 || ret % 2 != 0 || ret == args[index - 1];
		loop invariant ret == 0 || ret != 0;
		loop invariant ret == 0 || \exists integer k; 0 <= k < index && args[k] == ret;
		loop invariant ret == 0 || (ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k]);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && (args[k] % 2 != 0) && ret == args[k]);
		loop invariant ret == 0 ==> start == 0;
		loop invariant ret == 0 ==> start == 0 || start > 0;
		loop invariant ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret;
		loop invariant ret != 0 ==> \exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0;
		loop invariant ret != 0 ==> (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant index == start + (index - start);
		loop invariant index <= array || start <= index + 1;
		loop invariant index % 2 == 0 || index % 2 != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] == 0 || args[k] != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start >= 1;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> start > 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> k < array;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] % 2 != 0 ==> args[k] != 0;
		loop invariant \forall integer k; 0 <= k < index ==> args[k] != 0 || args[k] == 0;
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 == 0 || args[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> ret == args[k] || ret != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> k < array);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> args[k] != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> 0 <= k < array);
		loop invariant \forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0;
		loop invariant \forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> 0 <= k < array;
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start >= 1;
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> start > 0;
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret == args[k];
		loop invariant \exists integer k; 0 <= k < index && args[k] % 2 != 0 ==> ret != 0;
		loop invariant 0 <= start;
		loop invariant 0 <= ret || start <= array;
		loop invariant 0 <= ret || index <= array;
		loop invariant 0 <= index;
		loop invariant 0 <= index ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant 0 <= index - start;
		loop invariant (start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] == ret && args[k] % 2 != 0);
		loop invariant (start % 2 == 0) ==> ret == 0 || (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && ret == args[k]);
		loop invariant (start % 2 != 0) ==> ret != 0;
		loop invariant (\forall integer k; 0 <= k < index ==> args[k] % 2 == 0 || args[k] % 2 != 0);
		loop invariant (\forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> start >= 1));
		loop invariant (\forall integer k; 0 <= k < index && args[k] % 2 != 0 ==> args[k] != 0);
		loop assigns start;
		loop assigns ret;
		loop assigns index;*/
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@requires array >= 0;
  requires \valid_read(args + (0..array-1));
  assigns \nothing;
  ensures array == 0 ==> \result == 0;
  ensures \result == oddret(args, 0, array);*/
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
