#include "../include/control.hpp"

void PC::FTE () {
    switch (currentState) {
        case 0:
        // Se a instrução for HLT.
        if (inst == Instruction::Code::HLT) {
            lastState = true;
            nextState = 4; 
        }
        // Se a instrução não tiver parâmetro.
        else if (inst == Instruction::Code::NOP && inst == Instruction::Code::NOT)
            nextState = 1;
        // Se a instrução tiver parâmetro.
        else
            nextState = 2;
        break;

        case 1:
        // Retorna para o início.
        nextState = 0;
        break;

        case 2:
        // Executa a instrução com parâmetro.
        nextState = 3;
        break;

        case 3:
        // Retorna para o início.
        nextState = 0;
        break;
    
        default:
        break;
    }
}

void PC::FS () {
    switch (currentState) {
        // Lê o registrador na posição do apontador.
        case 0:        
        clock += 3;
        inst = (Instruction::Code)memory->readR(pt);
        FTE();
        break;

        // Executa instrução sem parâmetro.
        case 1:
        {
            Instruction instruction(inst);
            executeInstruction(instruction);
            FTE();
        }
        break;

        // Lê o parâmetro da instrução.
        case 2:
        clock += 3;
        pt++;
        param = memory->readR(pt);
        FTE();
        break;

        // Executa instrução com parâmetro.
        case 3:
        {
            Instruction instruction(inst);
            executeInstruction(instruction);
            FTE();
        }
        break;
        
        default:
        break;
    }
}

void PC::executeInstruction (Instruction instruct) {
    ula.setA(memory->getAccumulator());
    std::cout << "CONTADOR DE PROGRAMA: " << pt << std::endl;
    std::cout << "REGISTRADOR DE INSTRUÇÃO: " << inst << std::endl;
    ula.setA(memory->getAccumulator());
    std::cout << "NEGATIVE: " << ula.isNegative() << std::endl;
    std::cout << "ZERO: " << ula.isZero() << std::endl;
    std::cout << "BANCO DE REGISTRADORES: [ENDEREÇO] [VALOR]" << std::endl;

    for (int i = 128; i < 256; i++) {
        int value = memory->readR(i);        
        if (value == 0) break;
        std::cout << i << "\t" << value << std::endl;
    }

    std::cout << "MEMÓRIA DE DADOS: " << memory->getAccumulator() << std::endl;

    switch (instruct.getType()) {
        // Armazena o acumulador em um registrador.
        case Instruction::Code::STA:
        clock += 3;
        memory->store(param);
        break;

        // Carrega o valor de um registrador para o acumulador.
        case Instruction::Code::LDA:
        clock += 3;
        memory->load(param);
        break;

        // Soma o acumulador com o valor de um registrador.
        case Instruction::Code::ADD:
        {
            clock += 3;
            int value = memory->readR(param);

            clock += 1;
            ula.setA(memory->getAccumulator());
            ula.setB(value);        
            ula.doOperation(0);

            memory->setAccumulator(ula.getNumeric());
        }
        break;

        // Realizar um OR bit por bit entre o acumulador e um valor salvo em um endereço
        case Instruction::Code::OR:
        {
        clock += 3;
        int value = memory->readR(param);

        clock += 1;
        ula.setA(memory->getAccumulator());
        ula.setB(value);       
        ula.doOperation(1);

        memory->setAccumulator(ula.getNumeric());
        }
        break;

        // Realizar um AND bit por bit entre o acumulador e um valor salvo em um endereço
        case Instruction::Code::AND:
        {
        clock += 3;
        int value = memory->readR(param);

        clock += 1;
        ula.setA(memory->getAccumulator());
        ula.setB(value);       
        ula.doOperation(2);

        memory->setAccumulator(ula.getNumeric());
        }   
        break;        

        // Inverte o sinal do acumulador
        case Instruction::Code::NOT:
        memory->setAccumulator(memory->getAccumulator() * -1);   
        break;

        // Pula o apontador para o endereço passado.
        case Instruction::Code::JMP:
        pt = param;     
        break;

        // Pula o apontador caso o acumulador seja negativo
        case Instruction::Code::JN:
        clock += 1;
        ula.setA(memory->getAccumulator());
        
        if (ula.isNegative())
            pt = param;
        break;

        // Pula o apontador caso o acumulador seja igual a zero
        case Instruction::Code::JZ:
        clock += 1;
        ula.setA(memory->getAccumulator());
        
        if (ula.isZero())
            pt = param;
        break;
                
        default:
        break;
    }

    std::cout << std::endl;
}