#include <iostream>
#include <fstream>

#include "../include/instruction.hpp"
#include "../include/memory.hpp"

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

    std::string element;            // Elementos que serão lidos do arquivo de entrada
    while (input >> element) {
        if (Instruction::isInstruction(element)) {
            Instruction::Code type = Instruction::stringToInstruction(element);

            if (type == Instruction::Code::NOP || type == Instruction::Code::NOT || type == Instruction::Code::HLT) {
                Instruction inst(type);
                soft.push_back(inst);
            } else {
                int addr;
                input >> addr;
                Instruction inst(type, addr);
                soft.push_back(inst);
            }
        }
    }

    // Cria uma instância da memória com o programa lido.
    Memory mem(soft);
    
}