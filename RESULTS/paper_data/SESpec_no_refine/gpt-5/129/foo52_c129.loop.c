int foo52_c129(int year);


int foo52_c129(int year) {

        return ((year % 4 == 0) ? ((year % 100 == 0) ? ((year % 400 == 0) ? 1 : 0) : 1) : 0);
}