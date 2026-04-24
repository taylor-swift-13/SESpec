class SVCOMP_linear_0200__279 {
static void foo279(int i, int j) {

while (i < j) {
j = j - i;
if (j < i) {
j = j + i;
i = j - i;
j = j - i;
}
}

}
}
