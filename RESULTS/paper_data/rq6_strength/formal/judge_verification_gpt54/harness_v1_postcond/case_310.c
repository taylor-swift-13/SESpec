#include <limits.h>



/*@requires num < 0;
  assigns \nothing;
  ensures \result == -1 <==> num < 0;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> \result >= 0;
  ensures num >= 0 ==> \result * \result <= num;
  ensures num >= 0 ==> (\result + 1) * (\result + 1) > num;*/
int stub_A(int num);

/*@loop invariant right <= num;
        loop invariant right <= num && right >= -1;
        loop invariant right < num + 1;
        loop invariant right * right > num ==> right >= 0;
        loop invariant right * right <= num || right * right > num;
        loop invariant right * right <= num ==> right <= num;
        loop invariant right * right <= (num + 1) * (num + 1);
        loop invariant right * right <= (num + 1) * (num + 1) || right * right > num;
        loop invariant right * right <= (num + 1) * (num + 1) || left * left > num;
        loop invariant left == 0 || right >= 0;
        loop invariant left == 0 || right >= -1;
        loop invariant left <= right + 5;
        loop invariant left <= right + 4;
        loop invariant left <= right + 3;
        loop invariant left <= right + 3 || right < 0;
        loop invariant left <= right + 2;
        loop invariant left <= right + 2 || right < 0;
        loop invariant left <= right + 1;
        loop invariant left <= right + 1 || right < 0;
        loop invariant left <= right + 1 || left == right + 2;
        loop invariant left <= num;
        loop invariant left <= num || right <= num;
        loop invariant left <= num + 1;
        loop invariant left <= num + 1 && right >= -1;
        loop invariant left <= num + 1 && right <= num;
        loop invariant left <= num + 1 && 0 <= right;
        loop invariant left <= num && 0 <= left;
        loop invariant left - right <= 5;
        loop invariant left - right <= 4;
        loop invariant left - right <= 3;
        loop invariant left - right <= 2;
        loop invariant left - right <= 2 || left * left <= (num + 1) * (num + 1);
        loop invariant left - right <= 1;
        loop invariant left - right < 2;
        loop invariant left * left > num ==> left >= 0;
        loop invariant left * left > num ==> left > 0;
        loop invariant left * left <= (num + 2) * (num + 2);
        loop invariant left * left <= (num + 1) * (num + 1);
        loop invariant left * left <= (num + 1) * (num + 1) || right * right > num;
        loop invariant left * left <= (num + 1) * (num + 1) || left * left > num;
        loop invariant left * left <= (num + 1) * (num + 1) && 0 <= left;
        loop invariant left * left < (num + 1) * (num + 1);
        loop invariant 0 <= right;
        loop invariant 0 <= right || right == -1;
        loop invariant 0 <= right * right;
        loop invariant 0 <= right && right <= num;
        loop invariant 0 <= left;
        loop invariant 0 <= left && left <= num + 1;
        loop invariant 0 <= left && 0 <= right;
        loop invariant -1 <= right;
        loop invariant -1 <= right && right <= num;
        loop assigns right;
        loop assigns left;*/
int stub_B(int num);

/*@loop invariant right <= num;
        loop invariant right <= num && right >= -1;
        loop invariant right < num + 1;
        loop invariant right * right > num ==> right >= 0;
        loop invariant right * right <= num || right * right > num;
        loop invariant right * right <= num ==> right <= num;
        loop invariant right * right <= (num + 1) * (num + 1);
        loop invariant right * right <= (num + 1) * (num + 1) || right * right > num;
        loop invariant right * right <= (num + 1) * (num + 1) || left * left > num;
        loop invariant left == 0 || right >= 0;
        loop invariant left == 0 || right >= -1;
        loop invariant left <= right + 5;
        loop invariant left <= right + 4;
        loop invariant left <= right + 3;
        loop invariant left <= right + 3 || right < 0;
        loop invariant left <= right + 2;
        loop invariant left <= right + 2 || right < 0;
        loop invariant left <= right + 1;
        loop invariant left <= right + 1 || right < 0;
        loop invariant left <= right + 1 || left == right + 2;
        loop invariant left <= num;
        loop invariant left <= num || right <= num;
        loop invariant left <= num + 1;
        loop invariant left <= num + 1 && right >= -1;
        loop invariant left <= num + 1 && right <= num;
        loop invariant left <= num + 1 && 0 <= right;
        loop invariant left <= num && 0 <= left;
        loop invariant left - right <= 5;
        loop invariant left - right <= 4;
        loop invariant left - right <= 3;
        loop invariant left - right <= 2;
        loop invariant left - right <= 2 || left * left <= (num + 1) * (num + 1);
        loop invariant left - right <= 1;
        loop invariant left - right < 2;
        loop invariant left * left > num ==> left >= 0;
        loop invariant left * left > num ==> left > 0;
        loop invariant left * left <= (num + 2) * (num + 2);
        loop invariant left * left <= (num + 1) * (num + 1);
        loop invariant left * left <= (num + 1) * (num + 1) || right * right > num;
        loop invariant left * left <= (num + 1) * (num + 1) || left * left > num;
        loop invariant left * left <= (num + 1) * (num + 1) && 0 <= left;
        loop invariant left * left < (num + 1) * (num + 1);
        loop invariant 0 <= right;
        loop invariant 0 <= right || right == -1;
        loop invariant 0 <= right * right;
        loop invariant 0 <= right && right <= num;
        loop invariant 0 <= left;
        loop invariant 0 <= left && left <= num + 1;
        loop invariant 0 <= left && 0 <= right;
        loop invariant -1 <= right;
        loop invariant -1 <= right && right <= num;
        loop assigns right;
        loop assigns left;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num < 0;
  assigns \nothing;
  ensures \result == -1 <==> num < 0;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> \result >= 0;
  ensures num >= 0 ==> \result * \result <= num;
  ensures num >= 0 ==> (\result + 1) * (\result + 1) > num;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
