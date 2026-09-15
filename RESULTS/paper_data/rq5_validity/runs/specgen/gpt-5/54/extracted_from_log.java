class SVCOMP_linear_0144__228 {
    //@ ensures true;
    static void foo228() {

int x;
int y = 0;

x = 0;

//@ maintaining 0 <= x && x <= 100;
//@ decreases 100 - x;
while (x < 99) {
if(y % 2 == 0){
x = x + 2;
}
else{
x = x + 1;
}
}

}
}