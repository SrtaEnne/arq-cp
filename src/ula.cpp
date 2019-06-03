#include "../include/ula.hpp"

void ULA::doOperation (int op) {
    switch (op) {
        // SOMA
        case 0:
        outN = inA + inB;
        std::cout << "OPERAÇÃO DA ULA: SOMA" << std::endl;
        break;
        
        // OU
        case 1:
        std::cout << "OPERAÇÃO DA ULA: OR" << std::endl;
        outN = Util::binaryOR(inA, inB);
        break;

        // E
        case 2:
        std::cout << "OPERAÇÃO DA ULA: AND" << std::endl;
        outN = Util::binaryAND(inA, inB);
        break;

        default:
        break;
    }
}