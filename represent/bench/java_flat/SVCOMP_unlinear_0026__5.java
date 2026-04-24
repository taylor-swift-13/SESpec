class SVCOMP_unlinear_0026__5 {
static int main5(int x,int y) {

int a,b,p,q,r,s;
int x, y;

a = x;
b = y;
p = 1;
q = 0;
r = 0;
s = 1;

while(a!=b){
if (a>b) {
a = a-b;
p = p-q;
r = r-s;
}
else {
b = b-a;
q = q-p;
s = s-r;
}
}

return 0;
}
}
