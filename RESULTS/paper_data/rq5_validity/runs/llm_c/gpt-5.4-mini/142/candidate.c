/*@
    ensures \result == (x % 2 == 0);
    assigns \nothing;
*/
int isEven(int x);

/*@
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
int isOdd(int x);

int isEven(int x) {

         	return x%2 == 0;
}

/*@
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
int isOdd(int x) {

         	return x%2 != 0;
}
