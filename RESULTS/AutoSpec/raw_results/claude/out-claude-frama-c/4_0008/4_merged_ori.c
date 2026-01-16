/*@
requires a == 0 ==> (0 + 0) != 0; // actually sum = 0, so division by zero would occur, so a must not be zero;
requires a != 0 ==> (5 + 5) != 0;
ensures \result == 1;
assigns \nothing;
*/
int func(int a) {
    int x, y;
    int sum, res;
    if (a == 0){
        x = 0; y = 0;
    }
    else {
        x = 5; y = 5;
    }
    sum = x + y; 
    res = 10/sum; 
    return res;
}

int moo4() {
    int a = func(4);
    // @ assert a == 1;
    return 0;
}