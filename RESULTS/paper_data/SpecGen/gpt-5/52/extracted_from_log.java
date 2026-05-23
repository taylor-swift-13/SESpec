class SVCOMP_linear_0099__188 {
//@ ensures \result == 0;
static /*@ spec_public @*/ int unknown() {
return 0;
}

//@ ensures true;
static /*@ spec_public @*/ void foo188() {

int x;
int y;
int z;
int w;

x = 0;
y = 0;
z = 0;
w = 0;

//@ maintaining x >= 0 && w >= 0 && z >= 0;
//@ maintaining x <= w;
//@ maintaining z == 10 * w;
//@ maintaining z >= 10 * x;
//@ maintaining y % 2 == 0;
while(unknown() != 0){
if(x >= 4){
x = x + 1;
y = y + 2;

}
else if(y > 10 * w && z >= 100 * x){
y = 0 - y;
}
else{
x = x + 1;
y = y + 100;
}
w = w + 1;
z = z + 10;
}

}
}