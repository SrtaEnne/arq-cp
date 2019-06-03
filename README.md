# Circuitos Programáveis

## 1. Apresentação

Trabalho da matéria de Arquitetura de Computadores, ministrada pelo professor Márcio Eduardo Kreutz, que consiste em projetar um simulador de modelos Parte de Controle (PC) e Parte Operativa (PO) para arquiteturas de conjuntos de instruções dos processadores Neander, Cesar e Ramsés. Nesse repositório está a implementação somente do Neander.

## 2. Compilação

Para compilar esse projeto, você deve utilizar o [CMake](https://cmake.org).
CMake é uma família de ferramentas de código aberto e multiplataforma criada para compilar, testar e criar pacotes de programas.
Basicamente, CMake lê o script (`CMakeLists.txt`) com informações do projeto e **cria um Makefile automaticamente**, de acordo com as configurações do seu sistema.
Depois disso, você deve rodar o comando `make`, como de costume.

Para compilar o simulador, basta executar `cmake .` na raiz do projeto e logo após `make`. Assim, o executável será gerado dentro da pasta `bin`.

## 3. Execução

Para executar o simulador, basta rodar o executável seguido do caminho para o arquivo de entrada. Por exemplo, para executar o programa de soma de dois números que está localizado na pasta `data`, você executaria, na raiz do projeto, o comando:

`./bin/neander ./data/sum.txt`

Se quiser a saída em texto, basta adicionar `> nome-do-arquivo.txt`. Ou seja, ficaria assim:

`./bin/neander ./data/sum.txt > nome-do-arquivo.txt`

## 4. Arquivo de Entrada

O arquivo de entrada deve seguir o seguinte padrão:

    <Endereço do Registrador> <Valor do Registrador>

Por convenção, em `Endereço do Registrador`, você deve utilizar os endereços de 0 a 127 para salvar o programa e de 128 a 255 para salvar dados nos registradores.
O `Valor do Registrador` pode ser um número decimal ou um texto com a instrução a ser executada.
O registradores possuem por padrão o valor `0` guardado neles, você não precisa definir no arquivo de entrada registradores que não são diferentes de `0` inicialmente.

## 5. Instruções do Neander

| DECIMAL | INSTRUÇÃO | COMENTÁRIO                               |
|---------|-----------|------------------------------------------|
| 0       | NOP       | nenhuma operação                         |
| 1       | STA end   | armazena acumulador                      |
| 2       | LDA end   | carrega acumulador                       |
| 3       | ADD end   | soma                                     |
| 4       | OR end    | "ou" lógico                              |
| 5       | AND end   | "e" lógico                               |
| 6       | NOT       | inverte o acumulador                     |
| 7       | JMP end   | desvio incondicional                     |
| 8       | JN end    | desvio condicional (acumulador negativo) |
| 9       | JZ end    | desvio condicional (acumulador nulo)     |
| 10      | HLT       | término de execução                      |

## 6. Autoria

Os autores desse projeto são **Carlos Eduardo Alves Sarmento** _<cealvesarmento@gmail.com>_, **Jemima Dias Nascimento** _<jemima.dias@imd.ufrn.br>_ e **Nátaly Enne da Costa Gonçalo** _<ennenataly@gmail.com>_.

## 7. Relatório

O relatório desse projeto pode ser acessador através [deste link](https://docs.google.com/document/d/1GN5y_fh1M9KTwxSecDsW2NrL8zrxTzQexTYy7AZ6ack/edit?usp=sharing).