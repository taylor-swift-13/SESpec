class SVCOMP_linear_0143__227 {
static void foo227() {
    //@ ensures true;

int x;
int y;
y = 0;

x = 0;
 
    //@ maintaining x >= 0;
    //@ decreases 99 - x;

while (x < 99) {
if (y % 2 == 0)
x += 10;
else
x -= 5;
}

}
}