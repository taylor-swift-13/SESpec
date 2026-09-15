double foo18(double celsius);


/*@
   requires \true;
   assigns \nothing;
*/
double foo18(double celsius) {
        return celsius * 1.80 + 32.00;
}