double foo100(double celsius);


/*@
  requires celsius == celsius; // exclude NaN inputs
  assigns \nothing;
*/
double foo100(double celsius) {
        return celsius * 1.80 + 32.00;
}