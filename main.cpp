#include "vm.h"

/*
    Supported Instructions:
    - Idle (0x00): Do nothing and move to the next instruction.
    - Push (0xFF): Push the value following the push instruction onto the stack.
    - Add (0x01): Pop two values from the stack, add them, and push the result onto the stack.
    - Subtract (0x02): Pop two values from the stack, subtract the second one popped from the first one popped, and push the result onto the stack.
    - Multiply (0x03): Pop two values from the stack, multiply them, and push the result onto the stack.
    - Divide (0x04): Pop two values from the stack, divide the first one popped by the second one popped, and push the result onto the stack. Outputs an error message if division by zero occurs.
    - If Nonzero (0x1F): Pop a value from the stack. If it's nonzero, pop another value from the stack and jump forward in the bytecode sequence by that amount.
*/ 

int main() {
    std::vector<int> bytecode = {
        0xFF, 0x03,   // push 3
        0x00,         // 
        0xFF, 0x01,   // push 1
        0xFF, 0x02,   // push 2
        0x01,         // add 2 1  (3)
        0x00,         // idle
        0xFF, 0x01,   // push 1
        0x1F,         // if ( 0 =! ARG1 ) -> skip ARG2 bytes 
        0x00,         // 
        0x00,         // 
        0x00,         // 
        0x00,         // 
        0xFF, 0x0A,   // PUSH 10
        0xFF, 0x01,   // PUSH 1
        0x02,         // SUB 10 1  (-9)
        0xFF, 0x02,   // PUSH 2
        0x03,         // MUL 2 -9  (-18)
        0xFF, -0x02,  // PUSH -2
        0x04,         // DIVIDE -18 -2  (9)
        0xFF, 0x08,   // PUSH 9
        0x02,
        0x1F,
        0xFF, 0x01,
        0x01,
        0x00
    };
    StackMachine machine(bytecode);
    machine.executeBytecode();
    return 0;
}
