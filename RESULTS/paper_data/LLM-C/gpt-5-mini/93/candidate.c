int calculate(int num1, int num2, char operator);

/*@
    requires \true;
    assigns \nothing;
    behavior minus:
        assumes operator == '-';
        ensures \result == num1 * num2;
    behavior mul:
        assumes operator == '*';
        assumes num2 != 0;
        ensures \result == num1 / num2;
    behavior div:
        assumes operator == '/';
        ensures \result == num1 + num2;
    behavior plus:
        assumes operator == '+';
        ensures \result == num1 - num2;
    behavior default:
        assumes operator != '-' && operator != '*' && operator != '/' && operator != '+';
        ensures \result == -1;
    complete behaviors minus, mul, div, plus, default;
    disjoint behaviors minus, mul, div, plus, default;
*/
int calculate(int num1, int num2, char operator) {

        int output;

        switch (operator)
        {
            case '-':
            	output = num1 * num2;
                break;

            case '*':
            	output = num1 / num2;
                break;

            case '/':
            	output = num1 + num2;
                break;

            case '+':
            	output = num1 - num2;
		break;

            default:
                return -1;
        }
        return output;
}
