#include <iostream>
#include <fstream>

#include "../include/instruction.hpp"
#include "../include/memory.hpp"
#include "../include/ula.hpp"
#include "../include/control.hpp"

int main (int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Nenhum arquivo de entrada foi passado!" << std::endl;
        return 1;
    }

    std::ifstream input;
    input.open(argv[1]);

    if(!input.is_open())
        std::cout << "Não foi possível ler o arquivo em [" << argv[1] << "]!" << std::endl;
    
    std::vector<Instruction> soft;  // Lista com as instruções do programa.

    Memory mem;                     // Instância da memória
    int addr;                       // Endereço do registrador a ser lido
    std::string element;            // Elementos que serão lidos do arquivo de entrada

    while (input >> addr >> element) {
        if (Instruction::isInstruction(element)) {
            Instruction::Code inst = Instruction::stringToInstruction(element);
            mem.writeR(addr, (int)inst);
        } else {
            mem.writeR(addr, std::stoi(element));
        }
    }
    
    ULA ula;
    PC pc(mem, ula);

    while (!pc.reachedEnd()) {
        pc.FS();
        pc.FTE();
        pc.updateState();
    }
}