#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "pet.h"

int main(int argc, char *argv[]) {
    int opcao, opcaoCliente,clientes = 0, opcaoPet;
    Cliente c;
	Pet p;
	 // Declaração da variável Cliente
    // Inicializa espaço para salvar cliente
	if (!inicializarClientes() || !inicializarPets()) {
        printf("Erro ao inicializar sistema!\n");
        return 1;
    }
    do {
    	printf("--------------MENU--------------\n");
        printf("0 - Sair\n"
        "1 - Cliente\n"
        "2 - Pet\n"
        "3 - Servico\n"
        "Digite a opcao desejada:\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                do {
                    printf("\n--------------Menu Cliente--------------\n");
                    printf("1 - Listar\n"
                           "2 - Cadastrar\n"
                           "3 - Atualizar\n"
                           "4 - Excluir\n"
                           "0 - Voltar\n"
                           "Digite a opcao desejada: ");
                    scanf("%d", &opcaoCliente);
					int i;
                    switch(opcaoCliente) {
                        case 1:
                        	if(clientes <= 0){
                        		printf("\nNenhum clinte encontrado!\n");
								sleep(2);
                        		break;
							}
							printf("\nCODIGO\t \t\tNOME\t\t \tTELEFONE");
                            for (i = 0; i < quantidadeClientes(); i++) {
                                Cliente* cliente = obterClientePeloIndice(i);
                                if (cliente != NULL) {
                                    printf("\n%d\t \t\t%s\t\t \t%d\t", cliente->codigo, cliente->nome, cliente->telefone);
                                }
                            }
                            break;
                        case 2:
                             printf("Informe o código: ");
                            scanf("%d", &c.codigo);
                            printf("Informe o nome: ");
                            scanf("%s", &c.nome);
                            printf("Informe o telefone: ");
                            scanf("%d", &c.telefone);
                            if (!salvarCliente(c)) {
                                printf("\nErro ao salvar cliente.\n");
                            } else {
                            	printf("\nCliente cadastrado com sucesso!\n");
                            	sleep(2);
                            	clientes++;
							}
                            
                            break;
                        case 3:
                            printf("Informe código do cliente que deseja atualizar: ");
                            scanf("%d", &c.codigo);
                            printf("Novo nome: ");
                            scanf("%s", &c.nome);
                            printf("Novo telefone: ");
                            scanf("%d", &c.telefone);
                            if (!atualizarCliente(c)) {
                                printf("Cliente não encontrado.\n");
                            }
                            break;
                        case 4:
                            printf("Informe o código do cliente a excluir: ");
                            int codigo;
                            scanf("%d", &codigo);
                            if (!apagarClientePeloCodigo(codigo)) {
                                printf("Cliente não encontrado.\n");
                            }
                            clientes--;
                            break;
                    }
                } while(opcaoCliente != 0); 
            	break;
            case 2:
                do {
                    printf("\n--------------Menu Pet--------------\n");
                    printf("1 - Listar\n2 - Cadastrar\n3 - Atualizar\n4 - Excluir\n0 - Sair\n");
                    scanf("%d", &opcaoPet);
                    switch(opcaoPet) {
                        case 1:
                            if (quantidadePets() <= 0) {
                                printf("\nNenhum pet encontrado!\n");
                            } else {
                                printf("\nCODIGO\t\tNOME\t\tTIPO\tIDADE\n");
                                for (int i = 0; i < quantidadePets(); i++) {
                                    Pet* pet = obterPetPeloIndice(i);
                                    if (pet) printf("%d\t%s\t\t%s\t\t%d\n", pet->codigo, pet->nome, pet->tipo, pet->idade);
                                }
                            }
                            break;
                        case 2:
                            printf("Informe o codigo: ");
                            scanf("%d", &p.codigo);
                            printf("Informe o nome: ");
                            scanf("%s", p.nome);
                            printf("Informe o tipo: ");
                            scanf("%s", p.tipo);
                            printf("Informe a idade: ");
                            scanf("%d", &p.idade);
                            printf("Informe o codigo do dono: ");
                            scanf("%d", &p.codigoDono);
                            salvarPet(p);
                            printf("\nPet cadastrado com sucesso!\n");
                            break;
                        case 3:
                            printf("Informe o codigo do pet que deseja atualizar: ");
                            scanf("%d", &p.codigo);
                            printf("Novo nome: ");
                            scanf("%s", p.nome);
                            printf("Novo tipo: ");
                            scanf("%s", p.tipo);
                            printf("Nova idade: ");
                            scanf("%d", &p.idade);
                            if (atualizarPet(p)) {
                                printf("Pet atualizado com sucesso!\n");
                            } else {
                                printf("Pet nao encontrado.\n");
                            }
                            break;
                        case 4:
                            printf("Informe o codigo do pet a excluir: ");
                            scanf("%d", &p.codigo);
                            if (apagarPetPeloCodigo(p.codigo)) {
                                printf("Pet excluido com sucesso!\n");
                            } else {
                                printf("Pet nao encontrado.\n");
                            }
                            break;
                    }
                } while(opcaoPet != 0);
			    break;
			case 3:
                do {
                    printf("\n--------------Menu Servicos--------------\n");
                    printf("1 - Listar\n2 - Cadastrar\n3 - Atualizar\n4 - Excluir\n0 - Sair\n");
                    scanf("%d", &opcaoServico);
                    switch(opcaoServico) {
                        case 1:
                            if (quantidade() <= 0) {
                                printf("\nNenhum pet encontrado!\n");
                            } else {
                                printf("\nCODIGO\t\tNOME\t\tTIPO\tIDADE\n");
                                for (int i = 0; i < quantidadePets(); i++) {
                                    Pet* pet = obterPetPeloIndice(i);
                                    if (pet) printf("%d\t%s\t\t%s\t\t%d\n", pet->codigo, pet->nome, pet->tipo, pet->idade);
                                }
                            }
                            break;
                        case 2:
                            printf("Informe o codigo: ");
                            scanf("%d", &p.codigo);
                            printf("Informe o nome: ");
                            scanf("%s", p.nome);
                            printf("Informe o tipo: ");
                            scanf("%s", p.tipo);
                            printf("Informe a idade: ");
                            scanf("%d", &p.idade);
                            printf("Informe o codigo do dono: ");
                            scanf("%d", &p.codigoDono);
                            salvarPet(p);
                            printf("\nPet cadastrado com sucesso!\n");
                            break;
                        case 3:
                            printf("Informe o codigo do pet que deseja atualizar: ");
                            scanf("%d", &p.codigo);
                            printf("Novo nome: ");
                            scanf("%s", p.nome);
                            printf("Novo tipo: ");
                            scanf("%s", p.tipo);
                            printf("Nova idade: ");
                            scanf("%d", &p.idade);
                            if (atualizarPet(p)) {
                                printf("Pet atualizado com sucesso!\n");
                            } else {
                                printf("Pet nao encontrado.\n");
                            }
                            break;
                        case 4:
                            printf("Informe o codigo do pet a excluir: ");
                            scanf("%d", &p.codigo);
                            if (apagarPetPeloCodigo(p.codigo)) {
                                printf("Pet excluido com sucesso!\n");
                            } else {
                                printf("Pet nao encontrado.\n");
                            }
                            break;
                    }
                } while(opcaoPet != 0);
			    break;
        }
    } while(opcao != 0);

    encerrarClientes();
    encerrarPets();
    return 0;
}


