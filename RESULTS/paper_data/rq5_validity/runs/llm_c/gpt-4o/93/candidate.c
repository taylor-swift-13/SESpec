/*@ 
    requires operator == '+' || operator == '-' || operator == '*' || operator == '/';
    requires operator == '*' ==> num2 != 0; // Division by zero is not allowed
    ensures operator == '+' ==> \result == num1 - num2;
    ensures operator == '-' ==> \result == num1 * num2;
    ensures operator == '*' ==> \result == num1 / num2;
    ensures operator == '/' ==> \result == num1 + num2;
    ensures \result == -1 ==> !(operator == '+' || operator == '-' || operator == '*' || operator == '/');
    assigns \nothing;
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
