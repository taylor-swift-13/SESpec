int getPairsCount(int * array, int array_len, int num, int p);

/*@ 
  requires array_len >= 0;
  requires num >= 0;
  requires num <= array_len;
  requires \valid_read(array + (0 .. num-1));
  assigns \nothing;
  ensures \result == 
    (\sum integer i; 0 <= i < num;
      \sum integer j; i+1 <= j < num;
        ((array[i] + array[j] == p) ? 1 : 0)));
  ensures 0 <= \result <= (num * (num - 1)) / 2;
*/
int getPairsCount(int * array, int array_len, int num, int p) {

		int ret = 0;
		/*@ 
		  loop invariant 0 <= index <= num;
		  loop invariant 0 <= ret <= (num * (num - 1)) / 2;
		  loop invariant ret ==
		    (\sum integer i; 0 <= i < index;
		      \sum integer j; i+1 <= j < num;
		        ((array[i] + array[j] == p) ? 1 : 0));
		  loop assigns index, ret;
		  loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			  loop invariant index + 1 <= j <= num;
			  loop invariant 0 <= ret <= (num * (num - 1)) / 2;
			  loop invariant ret ==
			    (\sum integer i; 0 <= i < index;
			      \sum integer k; i+1 <= k < num;
			        ((array[i] + array[k] == p) ? 1 : 0))
			    +
			    (\sum integer k; index+1 <= k < j;
			        ((array[index] + array[k] == p) ? 1 : 0));
			  loop assigns j, ret;
			  loop variant num - j;
			*/
			for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}
