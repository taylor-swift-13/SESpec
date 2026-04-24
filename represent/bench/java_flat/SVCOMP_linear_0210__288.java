class SVCOMP_linear_0210__288 {
static void foo288(int x, int y) {

while (x < y) {
if ((x < 0 && y < 0)){
x = x + 7;
y = y - 10;
}
else if ((x < 0 && y >= 0)){
x = x + 7;
y = y + 3;
}
else {
x = x + 10;
y = y + 3;
}

}

}
}
