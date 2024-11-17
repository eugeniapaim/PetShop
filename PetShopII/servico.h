#ifndef SERVICO_H
#define SERVICO_H

#include <stdbool.h>

struct servico {
    int codigo;           // Código único do serviço
    int codigoPet;        // Código do pet associado
    char descricao[100];  // Descrição do serviço (ex.: "Banho", "Tosa")
    float preco;          // Preço do serviço
    char data[11];        // Data do serviço no formato "dd/mm/aaaa"
};
typedef struct servico Servico;

// Inicialização e encerramento
bool inicializarServicos();
bool encerrarServicos();

// Operações básicas
bool salvarServico(Servico s);
int quantidadeServicos();
int quantidadeServicosDoPet(int codigoPet);
Servico* obterServicoPeloIndice(int indice);
Servico* obterServicoPeloCodigo(int codigo);

// Consultas relacionadas a pets e donos
Servico* obterServicosPorPet(int codigoPet, int* quantidade);
Servico* obterServicosPorDono(int codigoDono, int* quantidade);

// Atualizações e exclusões
bool atualizarServico(Servico s);
bool apagarServicoPeloCodigo(int codigo);

#endif

