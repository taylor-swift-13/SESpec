#include <limits.h>

long long foo70_helper1_c145(short x);
long long foo70_helper2_c145(int x);
long long foo70_helper3_c145(long long x);
long long foo70_helper4_c145(int x, int y);
long long foo70_helper5_c145(int x, int y, int z);




long long Perimeter_2(int x);
long long Perimeter_3(long long x);
long long Perimeter_4(int x, int y);
long long Perimeter_5(int x, int y, int z);
long long Perimeter_6(int w, int x, int y, int z);

/*@assigns \nothing;
  ensures \result == (long long)((long)w + (long)x + (long)y + (long)z);
  ensures \result == (long long)((long)\old(w) + (long)\old(x) + (long)\old(y) + (long)\old(z));*/
long long stub_A(int w, int x, int y, int z);

/*@requires \true;
ensures \result == 4L * (long)x;
ensures \result == 4 * (long)x;
assigns \nothing;*/
long long stub_B(int w, int x, int y, int z);

/*@requires \true;
ensures \result == 4L * (long)x;
ensures \result == 4 * (long)x;
assigns \nothing;*/
long long check_A_implies_B(int w, int x, int y, int z) {
    return stub_A(w, x, y, z);
}

/*@assigns \nothing;
  ensures \result == (long long)((long)w + (long)x + (long)y + (long)z);
  ensures \result == (long long)((long)\old(w) + (long)\old(x) + (long)\old(y) + (long)\old(z));*/
long long check_B_implies_A(int w, int x, int y, int z) {
    return stub_B(w, x, y, z);
}
