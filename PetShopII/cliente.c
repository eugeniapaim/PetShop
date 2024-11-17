#include "cliente.h"
#include "pet.h"
#include "servico.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_INICIAL 5

Cliente* clientes = NULL;  // Array de clientes

int tamanhoClientes = TAMANHO_INICIAL;  // Capacidade do array
int totalClientes = 2;  // Total de clientes cadastrados

// Função para inicializar o array de clientes
bool inicializarClientes() {
    clientes = malloc(tamanhoClientes * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro ao alocar memória\n");
        return false;
    }
    return true;
}

// Função para salvar um novo cliente
bool salvarCliente(Cliente c) {
    // Verifica se é necessário aumentar a capacidade do array
    
	if (totalClientes >= tamanhoClientes) {
        tamanhoClientes *= 2; // Dobre a capacidade
        Cliente* temp = realloc(clientes, tamanhoClientes * sizeof(Cliente));
        if (temp == NULL) {
            printf("Erro ao alocar memória\n");
            return false;
        }
        clientes = temp;
    }
    clientes[totalClientes++] = c;  // Adiciona o novo cliente
    
    return true;
}

// Função para encerrar e liberar memória dos clientes
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

// Obtém um cliente pelo índice
Cliente* obterClientePeloIndice(int indice) {
    if (indice < 0 || indice >= totalClientes) return NULL;
    return &clientes[indice];
}

// Obtém um cliente pelo código
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

// Apaga um cliente pelo código
bool apagarClientePeloCodigo(int codigo) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigo) {
            clientes[i] = clientes[--totalClientes];  // Substitui pelo último cliente
            // Reduz a capacidade do array se necessário
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
bool apagarClientePeloNome(char* nomee) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(clientes[i].nome, nomee) == 0) {
            clientes[i] = clientes[--totalClientes];  // Substitui pelo último cliente
            // Reduz a capacidade do array se necessário
            if (totalClientes < tamanhoClientes / 2 && tamanhoClientes > TAMANHO_INICIAL) {
                tamanhoClientes /= 2;
                clientes = realloc(clientes, tamanhoClientes * sizeof(Cliente));
            }
            return true;
        }
    }
    return false;
}

// Função para verificar se algum pet de um cliente possui serviços associados
bool verificarPetsComServicos(int clienteCodigo) {
    for (int i = 0; i < quantidadePets(); i++) {
        Pet* pet = obterPetPeloIndice(i);
        if (pet && pet->codigoDono == clienteCodigo) {  // Pet pertencente ao cliente
            // Verificar se o pet tem serviços associados
            if (quantidadeServicosDoPet(pet->codigo) > 0) {  // Exemplo de como verificar serviços do pet
                return true;  // Pet com serviço encontrado
            }
        }
    }
    return false;  // Nenhum pet com serviço associado encontrado
}
