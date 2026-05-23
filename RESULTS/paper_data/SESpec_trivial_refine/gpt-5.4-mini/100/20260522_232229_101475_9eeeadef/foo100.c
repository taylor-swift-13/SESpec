double foo100(double celsius);


/*@
  assigns \nothing;
  ensures \true;
*/
double foo100(double celsius) {
  return celsius * 1.80 + 32.00;
}