#ifndef VM_H
#define VM_H

#include <iostream>
#include <vector>

class StackMachine {
    std::vector<int> stack;
    std::vector<int> bytecode;
    size_t count;

public:
    StackMachine(std::vector<int> byteCode);
    void push(int elem);
    int pop();
    void executeBytecode();
    void printStack();

};

#endif
