#ifndef REGISTERS_H
#define REGISTERS_H

#include <vector>

// Registradores do processador Neander.
class Registers {
    private:
    int regs[256];          // Registradores
    
    public:
    // Construtor padrão
    Registers() {
        for (int i = 0; i < 256; i++) regs[i] = 0;
    }

    // Lê um dado no registrador. Recebe o endereço.
    int read (int address) {
        return regs[address];
    }

    // Escreve um dado no registrador. Recebe o endereço e o valor.
    void write (int address, int value) {
        regs[address] = value;
    }
};

#endif