/*@
    requires \true;
    ensures \result == celsius * 1.80 + 32.00;
    assigns \nothing;
*/
double convertTemperature(double celsius);

double convertTemperature(double celsius) {

        return celsius * 1.80 + 32.00;
}
