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
	/*@ 
	  loop invariant 0 <= w <= y;
	  loop invariant z == x * w;
	  loop invariant p == x * w * (w + 1) / 2;
	  loop assigns w, z, p;
	*/
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
