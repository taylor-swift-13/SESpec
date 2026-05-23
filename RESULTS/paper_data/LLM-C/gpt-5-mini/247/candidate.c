int getInvCount(int * indices, int indices_len, int num);

/*@
    requires num >= 0;
    requires num <= indices_len;
    requires \valid(indices + (0 .. num-1));
    assigns \nothing;
    ensures \result == \num_of integer i,j; 0 <= i < j < num && indices[i] > indices[j];
*/
int getInvCount(int * indices, int indices_len, int num) {

		int ret = 0;

		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop assigns index, ret;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= c <= num;
			    loop invariant ret >= 0;
			    loop assigns c, ret;
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
