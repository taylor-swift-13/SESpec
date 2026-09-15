int getInvCount(int * indices, int indices_len, int num);

/*@ 
  requires indices != \null;
  requires 0 <= indices_len;
  requires 0 <= num <= indices_len;
  requires \valid_read(indices + (0..num-1));
  requires num*(num-1)/2 <= \max_int;
  assigns \nothing;
  ensures 0 <= \result <= num*(num-1)/2;
  ensures \result ==
    (\sum integer i; 0 <= i < num;
       (\sum integer j; i < j < num;
           (indices[i] > indices[j] ? 1 : 0)));
*/
int getInvCount(int * indices, int indices_len, int num) {

		int ret = 0;

		/*@ 
		  loop invariant 0 <= index <= num;
		  loop invariant 0 <= ret;
		  loop invariant ret ==
		    (\sum integer i; 0 <= i < index;
		       (\sum integer j; i < j < num;
		           (indices[i] > indices[j] ? 1 : 0)));
		  loop assigns ret, index;
		  loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			  loop invariant index + 1 <= c <= num;
			  loop invariant 0 <= ret;
			  loop invariant ret ==
			    (\sum integer i; 0 <= i < index;
			       (\sum integer j; i < j < num;
			           (indices[i] > indices[j] ? 1 : 0)))
			    +
			    (\sum integer j; index < j < c;
			           (indices[index] > indices[j] ? 1 : 0));
			  loop assigns ret, c;
			  loop variant num - c;
			*/
			for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
}
