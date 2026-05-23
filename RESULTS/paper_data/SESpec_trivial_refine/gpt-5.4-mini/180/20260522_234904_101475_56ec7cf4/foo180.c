
/*@
  requires count >= 0;
  requires count <= rot_len;
  requires count == 0 || \valid_read(rot + (0 .. count-1));
  assigns \nothing;
  ensures 0 <= \result <= count;
*/
int foo180(int * rot, int rot_len, int count) {

	if (count == 0) {
		return 0;
	}
	int r = 0, top = count - 1;

	/*@
	  loop invariant 0 <= r <= top < count;
	  loop invariant \valid_read(rot + (0 .. count-1));
	  loop assigns r, top;
	*/
	while (r < top) {
		if (rot[r] < rot[top]) {
			return r + 1;
		}
		int i = (r + top) / 2;
		if (rot[i] > rot[r]) {
			r = i;
		} else {
			top = i;
		}
	}

	return r + 1;
}
