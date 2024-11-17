#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "pet.h"
#include "servico.h"

void inicializarDadosFixos() {
    Cliente c1 = {1, "João Silva", 123456789};
    Cliente c2 = {2, "Maria Oliveira", 987654321};

    Pet p1 = {1, "Rex", "Cachorro", 5, 1}; // Pet de João Silva
    Pet p2 = {2, "Mia", "Gato", 3, 2}; // Pet de Maria Oliveira

    // Adiciona clientes
    salvarCliente(c1);
    salvarCliente(c2);

    // Adiciona pets
    salvarPet(p1);
    salvarPet(p2);

    // Adicionar serviços fixos
    Servico s1 = {1, 1, "Banho", 50.0};  // Serviço para o pet de João
    Servico s2 = {2, 2, "Vacinação", 80.0};  // Serviço para o pet de Maria

    salvarServico(s1);
    salvarServico(s2);
}

int main(int argc, char *argv[]) {
    int opcao, opcaoCliente,clientes = 2, opcaoPet, opcaoServico;
    Cliente c;
	Pet p;
	Servico s;
	 // Declaração da variável Cliente
    // Inicializa espaço para salvar cliente
	if (!inicializarClientes() || !inicializarPets() || !inicializarServicos()) {
        printf("Erro ao inicializar sistema!\n");
        return 1;
    }
    
    inicializarDadosFixos();
    
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
                            printf("Informe codigo do cliente que deseja atualizar: ");
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
                        	printf("\nAO EXCLUIR CLIENTE TODOS OS PETS E SERVICOS A ELE VINCULADO TAMBEM SERAO EXCLUIDOS!\n");
                        	int codigo,escolha;
                        	char nome[20];
                        	printf("1 - Excluir por codigo\n");
                        	printf("2 - Excluir por nome");
                        	scanf("%d", &escolha);
                        	switch(escolha){
                        		case 1:
                        			printf("Informe o código do cliente a excluir: ");
		                            scanf("%d", &codigo);
		                            
		                            if (!apagarClientePeloCodigo(codigo)) {
		                                printf("Cliente não encontrado.\n");
		                            } else {
										printf("Cliente excluido com sucesso!");
									}
		                            clientes--;
		                            break;
		                        case 2:
		                        	printf("Informe o nome do cliente a excluir: ");
		                            scanf("%s", nome);
		                            if(apagarClientePeloNome(nome)==false){
		                            	printf("Cliente não encontrado!");
									} else {
										printf("Cliente excluido com sucesso!");
									}
									clientes--;
									break;
							}
                            
                    }
                } while(opcaoCliente != 0); 
            	break;
            case 2:
                do {
                    printf("\n--------------Menu Pet--------------\n");
                    printf("1 - Listar\n2 - Cadastrar\n3 - Atualizar\n4 - Excluir\n0 - Voltar\n");
                    scanf("%d", &opcaoPet);
                    switch(opcaoPet) {
                        case 1:
                            if (quantidadePets() <= 0) {
                                printf("\nNenhum pet encontrado!\n");
                            } else {
                                printf("\nCODIGO\t \t\tNOME\t\t \t\tTIPO\t\t \tIDADE\n");
                                for (int i = 0; i < quantidadePets(); i++) {
                                    Pet* pet = obterPetPeloIndice(i);
                                    if (pet) printf("%d\t\t\t%s\t\t\t\t%s\t\t\t%d\n", pet->codigo, pet->nome, pet->tipo, pet->idade);
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
                            if (verificarServicosAssociados(p.codigo)==1) {
						        printf("Não é possível excluir o pet porque ele possui serviços associados.\n");
							} if (apagarPetPeloCodigo(p.codigo)) {
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
                    printf("\n--------------Menu Servico--------------\n");
                    printf("1 - Listar\n2 - Cadastrar\n3 - Atualizar\n4 - Excluir\n0 - Voltar\n");
                    scanf("%d", &opcaoServico);
                    switch(opcaoServico) {
                        case 1:
                            if (quantidadeServicos() <= 0) {
                                printf("\nNenhum serviço encontrado!\n");
                            } else {
                                printf("\nCODIGO\t \t\tDESCRICAO\t\t \tPRECO\n");
                                for (int i = 0; i < quantidadeServicos(); i++) {
                                    Servico* servico = obterServicoPeloIndice(i);
                                    if (servico) printf("%d\t\t\t%s\t\t\t%.2f\n", servico->codigo, servico->descricao, servico->preco);
                                }
                            }
                            break;
                        case 2:
                            printf("Informe o código: ");
                            scanf("%d", &s.codigo);
                            printf("Informe a descrição: ");
                            scanf("%s", s.descricao);
                            printf("Informe o preço: ");
                            scanf("%f", &s.preco);
                            salvarServico(s);
                            printf("\nServiço cadastrado com sucesso!\n");
                            break;
                        case 3:
                            printf("Informe o código do serviço que deseja atualizar: ");
                            scanf("%d", &s.codigo);
                            printf("Nova descrição: ");
                            scanf("%s", s.descricao);
                            printf("Novo preço: ");
                            scanf("%f", &s.preco);
                            if (atualizarServico(s)) {
                                printf("Serviço atualizado com sucesso!\n");
                            } else {
                                printf("Serviço não encontrado.\n");
                            }
                            break;
                        case 4:
                            printf("Informe o código do serviço a excluir: ");
                            scanf("%d", &s.codigo);
                            if (apagarServicoPeloCodigo(s.codigo)) {
                                printf("Serviço excluído com sucesso!\n");
                            } else {
                                printf("Serviço não encontrado.\n");
                            }
                            break;
                    }
                } while(opcaoServico != 0);
                break;    
               
        }
    } while(opcao != 0);

    encerrarClientes();
    encerrarPets();
    encerrarServicos();
    return 0;
}

