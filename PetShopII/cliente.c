#include "cliente.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_INICIAL 5

Cliente* clientes = NULL;  // Array de clientes

int tamanhoClientes = TAMANHO_INICIAL;  // Capacidade do array
int totalClientes = 0;  // Total de clientes cadastrados

// Fun��o para inicializar o array de clientes
bool inicializarClientes() {
    clientes = malloc(tamanhoClientes * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro ao alocar mem�ria\n");
        return false;
    }
    return true;
}

// Fun��o para salvar um novo cliente
bool salvarCliente(Cliente c) {
    // Verifica se � necess�rio aumentar a capacidade do array
    
	if (totalClientes >= tamanhoClientes) {
        tamanhoClientes *= 2; // Dobre a capacidade
        Cliente* temp = realloc(clientes, tamanhoClientes * sizeof(Cliente));
        if (temp == NULL) {
            printf("Erro ao alocar mem�ria\n");
            return false;
        }
        clientes = temp;
    }
    clientes[totalClientes++] = c;  // Adiciona o novo cliente
    
    return true;
}

// Fun��o para encerrar e liberar mem�ria dos clientes
bool encerrarClientes() {
    free(clientes);
    clientes = NULL;
    totalClientes = 0;
    return true;
}

// Retorna a quantidade total de clientes
int quantidadeClientes() {
    return totalClientes;
}

// Obt�m um cliente pelo �ndice
Cliente* obterClientePeloIndice(int indice) {
    if (indice < 0 || indice >= totalClientes) return NULL;
    return &clientes[indice];
}

// Obt�m um cliente pelo c�digo
Cliente* obterClientePeloCodigo(int codigo) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigo) return &clientes[i];
    }
    return NULL;
}

// Atualiza um cliente existente
bool atualizarCliente(Cliente c) {
    Cliente* cliente = obterClientePeloCodigo(c.codigo);
    if (cliente) {
        *cliente = c;  // Atualiza os dados do cliente
        return true;
    }
    return false;
}

// Apaga um cliente pelo c�digo
bool apagarClientePeloCodigo(int codigo) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigo) {
            clientes[i] = clientes[--totalClientes];  // Substitui pelo �ltimo cliente
            // Reduz a capacidade do array se necess�rio
            if (totalClientes < tamanhoClientes / 2 && tamanhoClientes > TAMANHO_INICIAL) {
                tamanhoClientes /= 2;
                clientes = realloc(clientes, tamanhoClientes * sizeof(Cliente));
            }
            return true;
        }
    }
    return false;
}

// Apaga um cliente pelo nome
bool apagarClientePeloNome(const char* nome) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            clientes[i] = clientes[--totalClientes];  // Substitui pelo �ltimo cliente
            // Reduz a capacidade do array se necess�rio
            if (totalClientes < tamanhoClientes / 2 && tamanhoClientes > TAMANHO_INICIAL) {
                tamanhoClientes /= 2;
                clientes = realloc(clientes, tamanhoClientes * sizeof(Cliente));
            }
            return true;
        }
    }
    return false;
}

