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
    std::vector<Instruction> mem;   // Memória 
    int acc = 0;                    // Acumulador
    int pt = 0;                     // Apontador

    public:
    Registers regs;                 // Registradores

    // Construtor padrão.
    Memory (std::vector<Instruction> software) : mem{software} {
        int index = 0;

        for (Instruction inst : mem) {
            regs.write(index++, (int)inst.getType());
            
            if (inst.getAddress() != -1)
                regs.write(index++, inst.getAddress());
        }

        for (int i = 0; i < index; i++) {
            std::cout << regs.read(i) << " ";
        }

        std::cout << std::endl;
    }

    // Lê um dado na memória. Recebe o endereço.
    int read (int address);

    // Escreve um dado na memória. Recebe o endereço e o valor.
    void write (int address, int value);

    // Lê o acumulador da memória.
    int getAccumulator ();

    // Lê o apontador da memória.
    int getPointer ();

    // Edita o acumulador da memória.
    void setAccumulator (int address);

    // Edita o apontador da memória.
    void setPointer (int address);
};

#endif