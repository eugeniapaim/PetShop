#include "servico.h"
#include "pet.h"
#include "cliente.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define TAMANHO_INICIAL 5

Servico* servicos = NULL;  // Array dinâmico de serviços
int tamanhoServicos = TAMANHO_INICIAL;  // Capacidade do array
int totalServicos = 0;  // Total de serviços cadastrados

// Inicialização do array de serviços
bool inicializarServicos() {
    servicos = malloc(tamanhoServicos * sizeof(Servico));
    if (servicos == NULL) {
        printf("Erro ao alocar memória para serviços\n");
        return false;
    }
    return true;
}

// Liberação de memória do array de serviços
bool encerrarServicos() {
    free(servicos);
    servicos = NULL;
    totalServicos = 0;
    return true;
}

// Salvar um novo serviço
bool salvarServico(Servico s) {
    // Verifica se é necessário redimensionar o array
    if (totalServicos >= tamanhoServicos) {
        tamanhoServicos *= 2;
        Servico* temp = realloc(servicos, tamanhoServicos * sizeof(Servico));
        if (temp == NULL) {
            printf("Erro ao alocar memória\n");
            return false;
        }
        servicos = temp;
    }
    servicos[totalServicos++] = s;
    return true;
}

// Retorna a quantidade total de serviços
int quantidadeServicos() {
    return totalServicos;
}

//Quantidade de servico por pet
int quantidadeServicosDoPet(int codigoPet) {
    int contador = 0;

    // Lógica para contar quantos serviços o pet com o código `codigoPet` tem
    // Exemplo: percorre um array de serviços e conta os que pertencem ao pet
    for (int i = 0; i < totalServicos; i++) {
        if (servicos[i].codigoPet == codigoPet) {
            contador++;
        }
    }

    return contador;
}

// Obtém um serviço pelo índice
Servico* obterServicoPeloIndice(int indice) {
    if (indice < 0 || indice >= totalServicos) return NULL;
    return &servicos[indice];
}

// Obtém um serviço pelo código
Servico* obterServicoPeloCodigo(int codigo) {
    for (int i = 0; i < totalServicos; i++) {
        if (servicos[i].codigo == codigo) return &servicos[i];
    }
    return NULL;
}

// Obtém serviços relacionados a um pet
Servico* obterServicosPorPet(int codigoPet, int* quantidade) {
    *quantidade = 0;
    Servico* resultados = NULL;

    for (int i = 0; i < totalServicos; i++) {
        if (servicos[i].codigoPet == codigoPet) {
            resultados = realloc(resultados, (*quantidade + 1) * sizeof(Servico));
            if (resultados == NULL) {
                printf("Erro ao alocar memória\n");
                return NULL;
            }
            resultados[*quantidade] = servicos[i];
            (*quantidade)++;
        }
    }
    return resultados;
}

// Obtém serviços relacionados a um dono (com base nos pets dele)
Servico* obterServicosPorDono(int codigoDono, int* quantidade) {
    *quantidade = 0;
    Servico* resultados = NULL;

    for (int i = 0; i < totalServicos; i++) {
        Pet* pet = obterPetPeloCodigo(servicos[i].codigoPet);
        if (pet && pet->codigoDono == codigoDono) {
            resultados = realloc(resultados, (*quantidade + 1) * sizeof(Servico));
            if (resultados == NULL) {
                printf("Erro ao alocar memória\n");
                return NULL;
            }
            resultados[*quantidade] = servicos[i];
            (*quantidade)++;
        }
    }
    return resultados;
}

// Atualizar um serviço existente
bool atualizarServico(Servico s) {
    Servico* servico = obterServicoPeloCodigo(s.codigo);
    if (servico) {
        *servico = s;
        return true;
    }
    return false;
}

// Apagar um serviço pelo código
bool apagarServicoPeloCodigo(int codigo) {
    for (int i = 0; i < totalServicos; i++) {
        if (servicos[i].codigo == codigo) {
            servicos[i] = servicos[--totalServicos];
            if (totalServicos < tamanhoServicos / 2 && tamanhoServicos > TAMANHO_INICIAL) {
                tamanhoServicos /= 2;
                servicos = realloc(servicos, tamanhoServicos * sizeof(Servico));
            }
            return true;
        }
    }
    return false;
}
