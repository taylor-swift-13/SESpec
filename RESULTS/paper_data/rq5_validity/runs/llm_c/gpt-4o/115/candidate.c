/*@ 
    requires factor != 0;
    ensures \result == 1 <==> (a % factor == 0 && b % factor == 0);
    ensures \result == 0 <==> !(a % factor == 0 && b % factor == 0);
    assigns \nothing;
*/
int isCommonFactor(int a, int b, int factor);

int isCommonFactor(int a, int b, int factor) {

        return a % factor == 0 && b % factor == 0;
}
