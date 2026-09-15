class SVCOMP_linear_0143__227 {
    //@ ensures true;
    static void foo227() {

int x;
int y;

x = 0;
y = 0;

//@ maintaining x % 5 == 0;
//@ maintaining 0 <= x && x <= 100;
//@ decreases 100 - x;
while (x < 99) {
if (y % 2 == 0)
x += 10;
else
x -= 5;
}

}
}