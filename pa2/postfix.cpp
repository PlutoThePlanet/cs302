#include <iostream>
#include <string>
#include "linkedstack.h"

std::string infixToPostfix(std::string input){
    std::string postfix;
    char temp;
    LinkedStack<char> operatorStack;

    int strLength = input.length();
    for (int i = 0; i < strLength; i++){ //read in one char at a time
        temp = input.at(i);

        std::cout << "index:" << i << std::endl;

        if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
            if(!operatorStack.isEmpty()){
                char topVal = operatorStack.peek();
                if((topVal == '+' || topVal == '-') && (temp == '*' || temp == '/')){ // top operator is smaller
                    std::cout << "operator greater" << std::endl;
                    operatorStack.pop();
                    operatorStack.push(temp);
                    operatorStack.push(topVal);
                }else if((topVal == '*' || topVal == '/') && (temp == '+' || temp == '-')){ // operator going in is smaller
                    std::cout << "operator lesser" << std::endl;
                    operatorStack.push(temp);
                }
            }else{
                std::cout << "number" << std::endl;
                operatorStack.push(temp);
            }
        }else{
            postfix += temp;
        }
    }

    while(!operatorStack.isEmpty()){
        postfix += operatorStack.peek();
        operatorStack.pop();
    }
    return postfix;
}

float solve(float num1, float num2, char op){
    float solution;
    if(op == '*'){
        solution = num1 * num2;
    }else if(op == '/'){
        solution = num1 / num2;
    }else if(op == '+'){
        solution = num1 + num2;
    }else{
        solution = num1 - num2;
    }
    return solution;
}

float evaluate(std::string postfix){
    float solution;
    char temp;
    LinkedStack<char> evalStack;

    int strLength = postfix.length();
    for (int i = 0; i < strLength; i++){ //read in one char at a time
        temp = postfix.at(i);
        if(temp < 10){
            evalStack.push(temp);
        }else{
            float val1 = evalStack.peek();
            evalStack.pop();
            float val2 = evalStack.peek();
            evalStack.pop();
            evalStack.push(solve(val1, val2, temp));
        }
    }

    return solution;
}

int main(){
    std::string equation;
    std::cout << "please enter your equation: " << std::endl;
    std::cin >> equation;

    std::string postfix = infixToPostfix(equation);
    std::cout << postfix << std::endl; // test

    float solution = evaluate(postfix);

    return 0;
}