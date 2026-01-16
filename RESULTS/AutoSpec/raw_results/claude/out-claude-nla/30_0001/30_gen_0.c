
int main30(int x,int y,int n) {
    // variable declarations
	int z=0;
	int w=0;
	int p=0;

    //precondition
    // loop body
	/*@
	/*@
	  loop invariant n >= 0;
	  loop invariant z == (/* original n value */ - n) * x * x;
	  loop invariant w == (/* original n value */ - n) * y * y;
	  loop invariant p == (/* original n value */ - n) * x * y;
	  loop assigns n, z, w, p;
	*/
	*/
	while(n > 0) {
		z = z + x * x;
		w = w + y * y;
		p = p + x * y;
		n -= 1;
	}
    // post-condition
	// @ assert z * w >= p * p;
}
