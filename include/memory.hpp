#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>
#include <iostream>

#include "registers.hpp"
#include "instruction.hpp"

// Memória do processador Neander
class Memory {
    private:
    int acc = 0;                    // Acumulador
    
    public:
    Registers regs;                 // Registradores

    // Construtor padrão.
    Memory () {}

    // Lê um dado no registrador na posição do apontador e guarda no acumulador.
    void load (int address) {
        acc = regs.read(address);
    }

    // Escreve o dado do acumulador no endereço passado.
    void store (int address) {
        regs.write(address, acc);
    }

    // Lê um dado guardado no registrador. Recebe o endereço.
    int readR (int address) {
        return regs.read(address);
    }

    void writeR (int address, int value) {
        regs.write(address, value);
    }

    // Lê o acumulador da memória.
    int getAccumulator () {
        return acc;
    }

    // Lê o apontador da memória.
    int getPointer ();

    // Edita o acumulador. Recebe o novo valor.
    void setAccumulator (int value) {
        acc = value;
    }

    // Edita o apontador da memória.
    void setPointer (int address);
};

#endif