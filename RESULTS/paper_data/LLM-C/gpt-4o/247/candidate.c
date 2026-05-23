/*@
    requires \valid(indices + (0 .. indices_len - 1));
    requires 0 <= num <= indices_len;
    ensures \result >= 0;
    ensures \result == \sum(0, num - 1, \lambda integer i; \sum(i + 1, num - 1, \lambda integer j; indices[i] > indices[j] ? 1 : 0));
    assigns \nothing;
*/
int getInvCount(int * indices, int indices_len, int num);

int getInvCount(int * indices, int indices_len, int num) {

		int ret = 0;

		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop invariant ret == \sum(0, index - 1, \lambda integer i; \sum(i + 1, num - 1, \lambda integer j; indices[i] > indices[j] ? 1 : 0));
		    loop assigns index, ret;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= c <= num;
			    loop invariant ret >= 0;
			    loop invariant ret == \sum(0, index - 1, \lambda integer i; \sum(i + 1, num - 1, \lambda integer j; indices[i] > indices[j] ? 1 : 0))
			                     + \sum(index + 1, c - 1, \lambda integer j; indices[index] > indices[j] ? 1 : 0);
			    loop assigns c, ret;
			*/
			for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
}
