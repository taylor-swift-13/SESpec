#include <limits.h>

/*@ assigns \nothing;
  ensures \result == (long long)((long)w + (long)x + (long)y + (long)z);
  ensures \result == (long long)((long)\old(w) + (long)\old(x) + (long)\old(y) + (long)\old(z)); */
long long stub_A(int w, int x, int y, int z);

/*@ requires \true;
ensures \result == 4L * (long)x;
ensures \result == 4 * (long)x;
assigns \nothing; */
long long stub_B(int w, int x, int y, int z);

/*@ requires \true;
ensures \result == 4L * (long)x;
ensures \result == 4 * (long)x;
assigns \nothing; */
long long check_A_implies_B(int w, int x, int y, int z) {
    return stub_A(w, x, y, z);
}

/*@ assigns \nothing;
  ensures \result == (long long)((long)w + (long)x + (long)y + (long)z);
  ensures \result == (long long)((long)\old(w) + (long)\old(x) + (long)\old(y) + (long)\old(z)); */
long long check_B_implies_A(int w, int x, int y, int z) {
    return stub_B(w, x, y, z);
}
