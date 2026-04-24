class SVCOMP_unlinear_0012__2 {
static int main2(int x,int y) {

int q=0;
int r=0;

while(x > y * q + r) {
if (r == y - 1){
r = 0;
q += 1;
}
else{
r += 1;
}

}

return 0;
}
}
