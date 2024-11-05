#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main(int argc, char *argv[]) {
    int opcao, opcaoCliente,clientes = 0;
    Cliente c; // Declaração da variável Cliente
    // Inicializa espaço para salvar cliente
	if (inicializarClientes()==false)
	{
		printf("Cliente não inicializado!");
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
                           "0 - Sair\n"
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
        }
    } while(opcao != 0);

    return 0;
}

