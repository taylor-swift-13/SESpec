
/*@
  assigns \nothing;
  ensures (size < 0) ==> \result == -1;
  ensures (size >= 0 && size >= 4) ==> \result == 0;
  ensures (0 <= size && size < 4) ==> \result == 1;
*/
int foo8_c16(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    int i = a[size];
    (void)i;
    return 1;
}
