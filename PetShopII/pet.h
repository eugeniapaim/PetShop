#ifndef PET_H
#define PET_H

#include <stdbool.h>

struct pet {
    int codigo;
    char nome[50];
    char tipo[20];
    int idade;
    int codigoDono; // Relaciona o pet ao cliente dono
};
typedef struct pet Pet;

bool inicializarPets();
bool encerrarPets();
bool salvarPet(Pet p);
int quantidadePets();
Pet* obterPetPeloIndice(int indice);
Pet* obterPetPeloCodigo(int codigo);
bool atualizarPet(Pet p);
bool apagarPetPeloCodigo(int codigo);
bool apagarPetPeloNome(const char* nome);

#endif
