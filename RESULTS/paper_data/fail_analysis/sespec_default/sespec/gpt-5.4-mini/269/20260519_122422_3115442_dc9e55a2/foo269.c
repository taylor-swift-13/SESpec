
/*@ 
  assigns \nothing;
  ensures dim < 3 ==> \result == (dim == 0 ? 1 : (dim == 1 ? w : w * w));
*/
int foo269(int dim, int w) {
    return (dim == 0 ? 1 : (dim == 1 ? w : w * w));
}
