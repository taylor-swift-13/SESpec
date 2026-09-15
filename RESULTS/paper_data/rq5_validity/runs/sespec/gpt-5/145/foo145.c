long long foo70_helper1_c145(short x);
long long foo70_helper2_c145(int x);
long long foo70_helper3_c145(long long x);
long long foo70_helper4_c145(int x, int y);
long long foo70_helper5_c145(int x, int y, int z);
long long foo145(int w, int x, int y, int z);


/*@
  assigns \nothing;
  ensures \result == (long long)w + (long long)x + (long long)y + (long long)z;
  ensures ((long long)w + (long long)x + (long long)y + (long long)z) == 0 ==> \result == 0;
  ensures ((long long)w + (long long)x + (long long)y + (long long)z) > 0 ==> \result > 0;
  ensures ((long long)w + (long long)x + (long long)y + (long long)z) < 0 ==> \result < 0;
*/
long long foo145(int w, int x, int y, int z) {

	long trapeziumPerimeter = (long)w + (long)x + (long)y + (long)z;
	return trapeziumPerimeter;
}