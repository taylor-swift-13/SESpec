int isEven(int x);
int isOdd(int x);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (x % 2 == 0);
*/
int isEven(int x) {

         	return x%2 == 0;
}

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (x % 2 != 0);
*/
int isOdd(int x) {

         	return x%2 != 0;
}
