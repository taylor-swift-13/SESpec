int foo74(int n);

int foo74(int n) {

        int temp = n;
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
