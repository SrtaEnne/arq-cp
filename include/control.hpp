#ifndef CONTROL_H
#define CONTROL_H

#include "memory.hpp"
#include "ula.hpp"
#include "instruction.hpp"

class PC {
    private:
    int pt = 0;                 // Apontador
    Memory *memory;              // Memória
    ULA ula;                    // Unidade Lógico Aritmética

    int currentState;           // Estado atual
    int nextState;              // Próximo estado
    bool lastState;             // É o último estado?

    Instruction::Code inst;     // Instrução atual
    int param;                  // Parâmetro da instrução
    int clock = 0;              // Contagem de ciclos do relógio

    public:
    PC (Memory &mem, ULA ula) : memory{&mem}, ula{ula}, currentState{0}, lastState{false} { }

    // Função de transferência de estado.
    void FTE();

    // Função de saída.
    void FS();

    // Executa a instrução carregada;
    void executeInstruction (Instruction instruction);

    // Atualiza, de fato, o estado
    void updateState () {
        currentState = nextState;
    }

    void printInfo () {
        std::cout << "APONTADOR: " << pt << std::endl;
        std::cout << "ACUMULADOR: " << memory->getAccumulator() << std::endl << std::endl;
    }

    // Chegou ao fim do programa?
    bool reachedEnd () { return pt == 127 || lastState; }
};

#endif