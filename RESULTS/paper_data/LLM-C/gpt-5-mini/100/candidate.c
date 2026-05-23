double convertTemperature(double celsius);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == celsius * 1.80 + 32.00;
*/
double convertTemperature(double celsius) {

        return celsius * 1.80 + 32.00;
}
