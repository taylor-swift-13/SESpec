double foo18(double celsius);


/*@
  requires \true; // No specific precondition for the input.
  assigns \nothing; // The function does not modify any caller-visible state.
*/
double foo18(double celsius) {
    return celsius * 1.80 + 32.00;
}