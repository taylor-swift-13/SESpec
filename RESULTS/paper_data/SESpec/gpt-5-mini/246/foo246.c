
/*@
  requires \valid(&args[0] + (0 .. args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires 0 <= num && num <= args_len;
  assigns \nothing;
  ensures (\forall integer i; 0 <= i && i < num ==>
              (\forall integer j; i < j && j < num ==> ((args[i] > args[j]) <==> \at(args[i],Pre) > \at(args[j],Pre))));
*/
int foo246(int * args, int args_len, int num) {

	int ret = 0;

	/*@
	  loop invariant 0 <= index && index <= \at(num,Pre);
	  loop invariant 0 <= ret;
	  loop invariant \valid(&args[0] + (0 .. args_len-1));
	  loop invariant \forall integer p; 0 <= p && p < args_len ==> 0 <= args[p] && args[p] <= 100;
	  loop invariant (\forall integer i; 0 <= i && i < index ==>
	                     (\forall integer j; i < j && j < \at(num,Pre) ==>
	                         0 <= args[i] && args[i] <= 100));
	  loop invariant (!(index < \at(num,Pre))) ==> ((ret >= 0) && (num == \at(num,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)));
	  loop invariant num == \at(num,Pre);
	  loop invariant args_len == \at(args_len,Pre);
	  loop invariant args == \at(args,Pre);
	  loop invariant \forall integer q; 0 <= q && q < args_len ==> args[q] == \at(args[q], Pre);
	  loop assigns index, ret;
	*/
	for (int index = 0; index < num; index++) {

		/*@
		  loop invariant 0 <= index && index <= num;
		  loop invariant \valid(&args[0] + (0 .. args_len-1));
		  loop invariant 0 <= ret;
		  loop invariant (\forall integer i; 0 <= i && i < index ==>
		                     (\forall integer j; i < j && j < num ==>
		                          0 <= args[i] && args[i] <= 100));
		  loop invariant (\forall integer p; 0 <= p && p < args_len ==> args[p] == \at(args[p], Pre));
		  loop assigns k, ret;
		*/
		for (int k = index + 1; k < num; k++) {
			if (args[index] > args[k]) {
				ret++;
			}
		}

	}

	return ret;
}
