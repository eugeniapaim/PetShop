#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>

struct cliente {
    int codigo;
    char nome[50];
    int telefone;
};
typedef struct cliente Cliente;

bool inicializarClientes();
bool encerrarClientes();
bool salvarCliente(Cliente c);
int quantidadeClientes();
Cliente* obterClientePeloIndice(int indice);
Cliente* obterClientePeloCodigo(int codigo);
bool atualizarCliente(Cliente c);
bool apagarClientePeloCodigo(int codigo);
bool apagarClientePeloNome(char* nome);

#endif
