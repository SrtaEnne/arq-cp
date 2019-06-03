#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <iostream>

class Util {
    public:
    typedef std::vector<int> binary;

    private:
    static binary decimalToBinary (int number) {
        binary result;    // Lista a ser retornada
        int rem;          // Resto da divisão

        std::cout << "Converted " << number << " to binary -> ";

        while (number != 0) {
            rem = number % 2;
            number /= 2;
            result.push_back(rem);
        }

        
        for (int e : result) {
            std::cout << e;
        }
        std::cout << std::endl;
        return result;
    }

    static int binaryToDecimal (binary number) {
        int power = 1, result = 0;

        for (int alg : number) {
            result += alg * power;
            power *= 2;
        }

        std::cout << "Converted ";
        
        for (int e : number) {
            std::cout << e;
        }
        std::cout << " to decimal -> " << result << std::endl;        

        return result;
    }

    public:
    static int binaryOR (int a, int b) {
        std::cout << a << " || " << b << std::endl;
        binary longest, shortest, result;
        
        if (a >= b) {
            longest = decimalToBinary(a);
            shortest = decimalToBinary(b);
        } else {
            longest = decimalToBinary(b);
            shortest = decimalToBinary(a);
        }

        for (int i = 0; i < (int)longest.size(); i++) {
            int alg;

            if (i < (int)shortest.size()) {
                alg = shortest[i] || longest[i];
            } else {
                alg = longest[i];
            }

            result.push_back(alg);
        }

        return binaryToDecimal(result);
    }

    static int binaryAND (int a, int b) {
        std::cout << a << " && " << b << std::endl;
        binary longest, shortest, result;
        
        if (a >= b) {
            longest = decimalToBinary(a);
            shortest = decimalToBinary(b);
        } else {
            longest = decimalToBinary(b);
            shortest = decimalToBinary(a);
        }

        for (int i = 0; i < (int)longest.size(); i++) {
            int alg;

            if (i < (int)shortest.size()) {
                alg = shortest[i] && longest[i];
            } else {
                alg = 0;
            }

            result.push_back(alg);
        }

        return binaryToDecimal(result);
    }
};

#endif