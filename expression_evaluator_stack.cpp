#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
stack<char> operators;
stack<int> operands;

void evaluate(char* expression);
int main() {
    cout << "Enter expression: " << endl;
    char* expression = new char[255];
    cin.getline(expression, 255);
    while(strcmp(expression, "quit") != 0){
        evaluate(expression);
        cout << "Enter expression: " << endl;
        cin.getline(expression, 255);
    }

    return 0;
}

void evaluate(char* expression){
    for(int i = 0; i < strlen(expression); i++){
        char c = expression[i];
        if(c == '+' || c == '-' || c == '*'){
            operators.push(c);
        } else if(c >= '0' && c <= '9'){
            int value = (int)c - (int)'0';
            while(expression[i + 1] >= '0' && expression[i + 1] <= '9'){
                value = value * 10 + ((int)expression[i+1] - (int)'0');
                i++;
            }
            operands.push(value);
        } else if(c == ')'){
            char op = operators.top();
            operators.pop();
            if(op == '+'){
                int val1 = operands.top();
                operands.pop();

                int val2 = operands.top();
                operands.pop();

                operands.push(val1 + val2);
            } else if(op == '-'){
                int val1 = operands.top();
                operands.pop();

                int val2 = operands.top();
                operands.pop();

                operands.push(val2 - val1);
            } else {
                int val1 = operands.top();
                operands.pop();

                int val2 = operands.top();
                operands.pop();

                operands.push(val1 * val2);
            }
        }
    }

    cout << operands.top() << endl;
    operands.pop();
}


