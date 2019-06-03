#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>

class Instruction {    
    public:
    enum Code {
        NOP, 
        STA,
        LDA,
        ADD,
        OR,
        AND,
        NOT,
        JMP,
        JN,
        JZ,
        HLT
    };

    Code type;      // Tipo da instrução

    // Construtor padrão
    Instruction (Code t) : type{t} {}    

    // Recebe uma string com o nome da instrução e retorna o enumerator correspondente.
    static Code stringToInstruction (std::string str) {
        if (str == "STA")
        return Instruction::Code::STA;
        else if (str == "LDA")
            return Instruction::Code::LDA;
        else if (str == "ADD")
            return Instruction::Code::ADD;
        else if (str == "OR")
            return Instruction::Code::OR;
        else if (str == "AND")
            return Instruction::Code::AND;
        else if (str == "NOT")
            return Instruction::Code::NOT;
        else if (str == "JMP")
            return Instruction::Code::JMP;
        else if (str == "JN")
            return Instruction::Code::JN;
        else if (str == "JZ")
            return Instruction::Code::JZ;
        else if (str == "HLT")
            return Instruction::Code::HLT;
        else
            return Instruction::Code::NOP;  
    }

    // Recebe uma string e retorna se corresponde ao nome de uma instrução ou não.
    static bool isInstruction (std::string str) {
        return str == "NOP" || str == "STA" || str == "LDA" || str == "ADD" ||
                str == "OR" || str == "AND" || str == "NOT" || str == "JMP" ||
                str == "JN" || str == "JZ" || str == "HLT";
    }

    Code getType () { return type; }
};

#endif