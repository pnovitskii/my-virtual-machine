#include "vm.h"

StackMachine::StackMachine(std::vector<int> byteCode) : bytecode(byteCode), count(0) { 
    std::cout << "\nStack Virtual Machine is running...\n"; 
}

void StackMachine::push(int elem) {
    stack.insert(stack.begin(), elem);
}

int StackMachine::pop() {
    int elem = stack.front();
    stack.erase(stack.begin());
    return elem;
}

void StackMachine::printStack() {
    std::cout << "Stack: ";
    if (!stack.empty()) { // Проверяем, что вектор не пустой
        for (int i : stack) {
            std::cout << i << " ";
        }
    } else {
        std::cout << "(empty)"; // Выводим сообщение, если вектор пустой
    }
    std::cout << std::endl;
}

void StackMachine::executeBytecode() {
        while (count < bytecode.size()) {
            if (bytecode[count] == 0x00) { // idle
                std::cout << "IDLE" << std::endl;
                count++;
                printStack();
                continue;
            }

            if (bytecode[count] == 0xFF) { // push
                std::cout << "PUSH" << std::endl;
                push(bytecode[count + 1]);
                count += 2;
                printStack();
                continue;
            }

            if (bytecode[count] == 0x01) { // add
                std::cout << "ADD" << std::endl;
                int result = pop() + pop();
                push(result);
                count++;
                printStack();
                continue;
            }

            if (bytecode[count] == 0x02) { // subtract
                std::cout << "SUBTRACT" << std::endl;
                int result = pop() - pop();
                push(result);
                count++;
                printStack();
                continue;
            }

            if (bytecode[count] == 0x03) { // multiply
                std::cout << "MULTIPLY" << std::endl;
                int result = pop() * pop();
                push(result);
                count++;
                printStack();
                continue;
            }

            if (bytecode[count] == 0x04) { // divide
                std::cout << "DIVIDE" << std::endl;
                int divisor = pop();
                int dividend = pop();
                if (divisor != 0) {
                    int result = dividend / divisor;
                    push(result);
                } else {
                    std::cerr << "Error: Division by zero" << std::endl;
                }
                count++;
                printStack();
                continue;
            }

            if (bytecode[count] == 0x1F) { // if nonzero
                std::cout << "IF" << std::endl;
                int arg1 = pop();
                if (arg1 != 0) {
                    int arg2 = pop();
                    count += arg2;            
                }
                count++;
                printStack();
                continue;
            }
        }

        std::cout << "bytecode is completed" << std::endl;
    }