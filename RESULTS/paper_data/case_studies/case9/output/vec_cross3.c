

/*@
  requires \valid(out + (0..2));
  requires \valid_read(a + (0..2));
  requires \valid_read(b + (0..2));
  requires \separated(out + (0..2), a + (0..2));
  requires \separated(out + (0..2), b + (0..2));
  assigns out[0..2];
  ensures out[0] == a[1] * b[2] - a[2] * b[1];
  ensures out[1] == a[2] * b[0] - a[0] * b[2];
  ensures out[2] == a[0] * b[1] - a[1] * b[0];
*/
void vec_cross3(int *out, int *a, int *b)
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
    return;
}