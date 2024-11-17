#include "pet.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "servico.h"
#include "cliente.h"

#define TAMANHO_INICIAL 5

static Pet* pets = NULL;
static int tamanhoPets = TAMANHO_INICIAL;
static int totalPets = 0;

bool inicializarPets() {
    pets = malloc(tamanhoPets * sizeof(Pet));
    if (pets == NULL) {
        printf("Erro ao alocar memória\n");
        return false;
    }
    return true;
}

bool salvarPet(Pet p) {
    if (totalPets >= tamanhoPets) {
        tamanhoPets *= 2;
        Pet* temp = realloc(pets, tamanhoPets * sizeof(Pet));
        if (temp == NULL) {
            printf("Erro ao alocar memória\n");
            return false;
        }
        pets = temp;
    }
    pets[totalPets++] = p;
    return true;
}

bool encerrarPets() {
    free(pets);
    pets = NULL;
    totalPets = 0;
    return true;
}

int quantidadePets() {
    return totalPets;
}

Pet* obterPetPeloIndice(int indice) {
    if (indice < 0 || indice >= totalPets) return NULL;
    return &pets[indice];
}

Pet* obterPetPeloCodigo(int codigo) {
    for (int i = 0; i < totalPets; i++) {
        if (pets[i].codigo == codigo) return &pets[i];
    }
    return NULL;
}

bool atualizarPet(Pet p) {
    Pet* pet = obterPetPeloCodigo(p.codigo);
    if (pet) {
        *pet = p;
        return true;
    }
    return false;
}

bool apagarPetPeloCodigo(int codigo) {
    for (int i = 0; i < totalPets; i++) {
        if (pets[i].codigo == codigo) {
            pets[i] = pets[--totalPets];
            if (totalPets < tamanhoPets / 2 && tamanhoPets > TAMANHO_INICIAL) {
                tamanhoPets /= 2;
                pets = realloc(pets, tamanhoPets * sizeof(Pet));
            }
            return true;
        }
    }
    return false;
}

bool apagarPetPeloNome(const char* nome) {
    for (int i = 0; i < totalPets; i++) {
        if (strcmp(pets[i].nome, nome) == 0) {
            pets[i] = pets[--totalPets];
            if (totalPets < tamanhoPets / 2 && tamanhoPets > TAMANHO_INICIAL) {
                tamanhoPets /= 2;
                pets = realloc(pets, tamanhoPets * sizeof(Pet));
            }
            return true;
        }
    }
    return false;
}

int verificarServicosAssociados(int codigoPet) {
    int i;
    for (i = 0; i < quantidadeServicos(); i++) {
        Servico* servico = obterServicoPeloIndice(i);
        if (servico && servico->codigoPet == codigoPet) {
            return 1;  // Retorna 1 se houver serviços associados
        }
    }
    return 0;  // Retorna 0 se não houver serviços associados
}
