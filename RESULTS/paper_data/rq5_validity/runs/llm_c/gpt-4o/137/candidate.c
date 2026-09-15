/*@ 
    requires factor != 0;
    ensures \result == 1 <==> (a % factor != 0 || b % factor != 0);
    ensures \result == 0 <==> (a % factor == 0 && b % factor == 0);
    assigns \nothing;
*/
int notCommonFactor(int a, int b, int factor);

int notCommonFactor(int a, int b, int factor) {

        return a % factor != 0 || b % factor != 0;
}
