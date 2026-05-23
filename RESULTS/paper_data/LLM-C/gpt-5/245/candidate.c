int getPairsCount(int * pairs, int pairs_len, int num, int p);

/*@ 
  requires num >= 0;
  requires \valid_read(pairs + (0 .. num-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (num * (num - 1)) / 2;
  ensures \result == 
    \sum(integer i = 0; i < num; i++) 
      \sum(integer j = i + 1; j < num; j++) 
        ((pairs[i] + pairs[j] == p) ? 1 : 0);
*/
int getPairsCount(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		/*@
		  loop invariant 0 <= index <= num;
		  loop invariant 0 <= ret <= (num * (num - 1)) / 2;
		  loop invariant ret == 
		    \sum(integer i = 0; i < index; i++)
		      \sum(integer j = i + 1; j < num; j++)
		        ((pairs[i] + pairs[j] == p) ? 1 : 0);
		  loop assigns ret;
		  loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			  loop invariant index + 1 <= j <= num;
			  loop invariant 0 <= ret <= (num * (num - 1)) / 2;
			  loop invariant ret == \at(ret, LoopEntry) + 
			    \sum(integer k = index + 1; k < j; k++) 
			      ((pairs[index] + pairs[k] == p) ? 1 : 0);
			  loop assigns ret;
			  loop variant num - j;
			*/
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}
