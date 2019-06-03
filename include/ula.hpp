#ifndef ULA_H
#define ULA_H

#include "util.hpp"

class ULA {
    private:
    int inA = 0, inB = 0;   // Variáveis de entrada
    int outN = 0;           // Saída numérica
    bool outL = false;      // Saída lógica

    public:
    ULA () {}

    void setA (int val) { inA = val; }

    void setB (int val) { inB = val; }

    int getNumeric () { return outN; }

    bool getLogic () { return outL; }

    void doOperation (int op);

    bool isNegative () { return inA < 0; }

    bool isZero () { return inA == 0; }
};

#endif