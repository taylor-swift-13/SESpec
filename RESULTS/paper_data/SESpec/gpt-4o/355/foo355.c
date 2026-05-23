int foo355(int num);


/*@
ensures \exists integer result_67, sum_66, end_65; (sum_66 <= 0) && (result_67 >= 0) && (sum_66 == num >> result_67) && (!(num > 0) ==> sum_66 == num && end_65 == 0 && result_67 == 0 && num == num) ==> (\result == (num | end_65));

assigns \nothing;
*/

int foo355(int num) 
{

    int result = 0;
    int end = 0;
    int sum = num;

    /*@
      loop invariant result >= 0;
      loop invariant num == \at(num,Pre);
      loop invariant sum == \at(num,Pre) >> result;
      loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre)) && (end == 0) && (result == 0) && (num == \at(num,Pre)));
      loop assigns end, sum, result;
    */
    while (sum > 0) {
        if (result % 2 == 1) {
            end |= (1 << result);
        }
        result++;
        sum >>= 1;
    }

    return (num | end);
}