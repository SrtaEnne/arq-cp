#include "../include/ula.hpp"

void ULA::doOperation (int op) {
    switch (op) {
        // SOMA
        case 0:
        outN = inA + inB;
        break;
        
        // OU
        case 1:
        outN = Util::binaryOR(inA, inB);
        break;

        // E
        case 2:
        outN = Util::binaryAND(inA, inB);
        break;

        default:
        break;
    }
}