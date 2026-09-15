/*@ 
    ensures \result == 1 <==> x % 2 == 0;
    ensures \result == 0 <==> x % 2 != 0;
    assigns \nothing;
*/
int isEven(int x) {
    return x % 2 == 0;
}

/*@ 
    ensures \result == 1 <==> x % 2 != 0;
    ensures \result == 0 <==> x % 2 == 0;
    assigns \nothing;
*/
int isOdd(int x) {
    return x % 2 != 0;
}
