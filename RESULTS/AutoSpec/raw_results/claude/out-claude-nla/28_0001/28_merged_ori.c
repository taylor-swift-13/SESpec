/*@
requires x >= 0 && y >= x;
*/
int main28(int x,int y) {
    // variable declarations
	
	int z=0;
	int w=0;
	int p=0;
    
    // loop body
	/*@
	loop invariant z == x * w;
	loop invariant w <= y;
	loop invariant p == x * w * (w + 1) / 2;
	loop invariant 0 <= w;
	loop assigns z;
	loop assigns w;
	loop assigns p;
	/*@;
	*/
	while(w < y) {
		z += x;
		p += z;
		w += 1;
	}
    // post-condition
	// @ assert p == x * (1 + y) * y / 2;

	return 0;
}
