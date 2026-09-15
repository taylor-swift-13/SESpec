/*@ 
    requires a > 0 && b > 0 && m > 0;
    ensures \result == 1 <==> (m % a == 0 && m % b == 0);
    ensures \result == 0 <==> !(m % a == 0 && m % b == 0);
    assigns \nothing;
*/
int isCommonMultiple(int a, int b, int m);

int isCommonMultiple(int a, int b, int m) {

        return m % a == 0 && m % b == 0;
}
