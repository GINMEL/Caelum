#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "lexer.h"
#include "ihandler.h"

#include <string>
#include <vector>
#include <stack>

class Interpreter{
private:
    std::stack<unsigned long long> callStack;
    std::vector<unsigned long long> memory;
    std::vector<std::vector<bool>> registers;
    std::unordered_map<size_t, int> labelMap;
    std::vector<std::vector<unsigned long long>> code;
    std::vector<bool> flags;

    Lexer lexer;
    size_t hash = 0, ptr = 0;
    int temp1Size=0, temp2Size=0;
    int temp1Type=0, temp2Type=0;
    unsigned long long temp1, temp2;
    InstructionHandler* instrHandler;

public:
    Interpreter();
    ~Interpreter();

    void setRegister(int, unsigned long long);
    unsigned long long getRegister(int);
    int getRegSize(int);

    void setFlag(int, bool);
    bool getFlag(int);
    
    void build(const std::string&);
    void resolveLabels();
    void execute();

    void PUSH(unsigned long long);
    unsigned long long POP();

    void setPointer(size_t);
    size_t getPointer() noexcept;

    unsigned long long getMemory(unsigned long long);
};

#endif