double convertTemperature(double celsius);

/*@
  behavior nan_input:
    assumes \is_NaN(celsius);
    ensures \is_NaN(\result);

  behavior not_nan:
    assumes !\is_NaN(celsius);
    ensures \result == celsius * 1.80 + 32.00;

  complete behaviors nan_input, not_nan;
  disjoint behaviors nan_input, not_nan;

  assigns \nothing;
*/
double convertTemperature(double celsius) {

        return celsius * 1.80 + 32.00;
}
