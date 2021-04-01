#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaPrototipos.h"

struct lista{
    int qtd;
    struct veiculo dados[MAX];
};

int senha = 12345;
int tentativa = 0;

    //FUNÇÃO CRIANDO A LISTA
Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
        if(li != NULL){
            li->qtd = 0;
        }
        return li;
}

    //FUNÇÃO LIBERANDO LISTA
void liberar_lista(Lista* li){
    if(li == NULL){
        printf("ERRO\n");
    }
    free(li);
}

    //FUNÇÃO-TELA QUANTIDADE DE DADOS GRAVADOS NA LISTA
int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

    //FUNÇÃO-TELA PARA GERENCIAR LOGIN DO SISTEMA
void loginSenha(Lista* li){
    int digsenha;

    if(tentativa >= 3){
        system("cls");
        printf("\t\t\t --------------------\n");
        printf("\t\t\t|VOCÊ FOI BLOQUEADO! |\n");
        printf("\t\t\t --------------------\n\n");

        printf("\t ------------------------------------------------------------\n");
        printf("\t|POR FAVOR ENTRAR EM CONTATO COM A CENTRAL PARA DESBLOQUEIO! |\n");
        printf("\t ------------------------------------------------------------\n\n\n");

        printf("CONTATO:\n \t* EMAIL CENTRAL: f_silvadealmeida@hotmail.com\n \t* FONE: (18)99136 - 2515 : Fernando Almeida.\n\n");
        system("pause");
        exit(1);
    }
    system("cls");
    printf("\t -----------------------------------------\n");
    printf("\t| PARA ACESSAR DIGITE A SENHA DO SISTEMA: |\n");
    printf("\t -----------------------------------------\n");
    printf("|LOGIN: Topcar\n");
    printf("|SENHA: ");

    scanf("%d", &digsenha);
    fflush(stdin);

    if(senha == digsenha){
        system("cls");
        printf("\t --------------------------------------------------------\n");
        printf("\t| LOGIN EFETUADO COM SUCESSO NO SISTEMA TOPCAR VEICULOS! |\n");
        printf("\t --------------------------------------------------------\n\n");
        system("pause");
        menu(li);
    }else{
        tentativa += 1;
        system("cls");
        printf("\t -----------------------------------------\n");
        printf("\t| ERRO!, SENHA INCORRETA TENTE NOVAMENTE! |\n");
        printf("\t -----------------------------------------\n\n");
        system("pause");
        loginSenha(li);
    }
}

    //FUNÇÃO-TELA MENU PRINCIPAL DO SISTEMA TOPCAR VEICULOS
void menu(Lista* li){
  system("cls");
  int op;
    int opcao;
    printf("\t -----------------------------------------------\n");
    printf("\t| BEM VINDO AO MENU DA GARAGEM TOPCAR VEICULOS! |\n");
    printf("\t -----------------------------------------------\n\n");

    printf("\t ---------------------------\n");
    printf("\t| INFORME A OPÇÃO DESEJADA  |\n");
    printf("\t ---------------------------\n\n");
    printf(" 1- Cadastrar um veiculo.\n 2- Listar os veiculos\n 3- Deletar cadastro de um veiculo\n 4- Opções\n 5- Sair do sistema\n >:");
    scanf("%d", &op);
    fflush(stdin);
    setbuf(stdin, NULL);

    switch(op){
    case 1:
        cadastrar(li);
        break;
    case 2:
        imprimir_lista(li);
        break;
    case 3:
        deletar(li);
        break;
    case 4:
        opcoes(li);
        break;
    case 5:
        sair(li);
        break;
    default:
        printf("ERRO!\n");
        system("pause");
        menu(li);
        break;
    }
}

    //FUNÇÃO-TELA DE CADASTRO DO SISTEMA TOPCAR VEICULOS
void cadastrar(Lista* li){
    system("cls");
    printf("\t ------------------------------------------------\n");
    printf("\t| BEM VINDO A TELA DE CADASTRAMENTO DE VEICULOS  |\n");
    printf("\t ------------------------------------------------\n\n");

    if(li->qtd >= MAX){
        system("cls");
		printf("\t ---------------------------\n");
		printf("\t| LISTA DE REGISTROS CHEIA!  |\n");
		printf("\t ---------------------------\n\n");
		system("pause");
		menu(li);
    }else{
        dados_veiculo.id = li->qtd;
        printf("ID: %d\n", dados_veiculo.id);
        printf("INFORME NOME DO VEÍCULO: ");
        gets(dados_veiculo.nome);
        setbuf(stdin,NULL);

        printf("INFORME A MARCA DO VEÍCULO: ");
        gets(dados_veiculo.marca);
        setbuf(stdin,NULL);

        do{
            printf("ANO: ");
            scanf("%d", &dados_veiculo.ano);
            fflush(stdin);
        }while(dados_veiculo.ano < 1995 || dados_veiculo.ano > 2021);

        inserir_final(li, &dados_veiculo);
        printf("\t\tCADASTROU EFETUADO COM SUCESSO! ...\n");
        system("pause");
        menu(li);
    }
}

    //FUNÇÃO-TELA DE CADASTRAMENTO
void inserir_final(Lista* li, struct veiculo *aux){
    if(li == NULL) printf("ERRO ALOCAÇÃO");
    if(li->qtd == MAX) printf("LISTA CHEIA");
        li->dados[li->qtd] = *aux;
        li->qtd++;
}

    //FUNÇÃO-TELA LISTAGEM DE DADOS NA TELA DO USUARIO
void imprimir_lista(Lista* li){
    if(li == NULL) printf("ERRO ALOCAÇÃO\n");
    if(li->qtd == 0){
        system("cls");
		printf("\t ---------------------------\n");
		printf("\t| LISTA DE REGISTROS VAZIA!  |\n");
		printf("\t ---------------------------\n\n");
		system("pause");
        menu(li);
    }else{
        system("cls");
        printf("\t -------------------------------\n");
        printf("\t| BEM VINDO A TELA DE LISTAGEM  |\n");
        printf("\t -------------------------------\n\n");
            int i;

        for(i=0; i< li->qtd; i++){
            printf(" ============================\n");
            printf("|Codigo Id:.. %d\n",li->dados[i].id);
            printf("|Nome:....... %s\n",li->dados[i].nome);
            printf("|Marca:...... %s\n", li->dados[i].marca);
            printf("|Ano:........ %d\n", li->dados[i].ano);

        }
            printf(" ============================\n");
    }
    system("pause");
    menu(li);
}

    //FUNÇÃO-TELA DELETAR REGISTRO DA LISTA
void deletar(Lista* li){
    system("cls");
    int id, i=0;
    if(li->qtd == 0) {
		system("cls");
		printf("\t -------------------------------------------------\n");
		printf("\t| NÃO TEM REGISTROS PARA DELETAR, RETORNE AO MENU |\n");
		printf("\t -------------------------------------------------\n\n");
		system("pause");
		menu(li);
    }else{
        printf("\t\tBem vindo a tela de DELETAR\n\n");
        printf("Lista dos Veiculos cadastrados:\n");

        for(int i=0;i<li->qtd;i++){
            printf("ID: %d / NOME: %s\n", li->dados[i].id, li->dados[i].nome);
        }
            printf("Escolha o ID do veiculo que deseja deletar: ");
            scanf("%d", &id);
            setbuf(stdin, NULL);

        while(i<li->qtd && li->dados[i].id != id){
            i++;
        }
        int k;
        for(k=i; k < li->qtd -1; k++){
            li->dados[k] = li->dados[k+1];
            li->dados[k].id--;
        }
        li->qtd--;
        printf("\t CADASTRO DELETADO COM SUCESSO!\n");
    }
        system("pause");
        menu(li);
}

    //FUNÇÃO-TELA GERENCIAR MAIS OPÇÕES DO SISTEMA
void opcoes(Lista* li){
    system("cls");
    int op;
    printf("\t ----------------------------\n");
    printf("\t| BEM VINDO A TELA DE OPÇÕES |\n");
    printf("\t ----------------------------\n\n");

    printf(" ---------------------------\n");
    printf("| ESCOLHA A OPÇÃO DESEJADA: |\n");
    printf(" ---------------------------\n\n");
    printf(" 1- Alterar a senha\n 2- Salvar Lista de veiculos em Arquivo\n 3- Informações do sistema\n 4- Voltar ao menu\n>:");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    switch(op){
        case 1:
            alterar_senha(li);
            break;
        case 2:
            salvar_arquivo(li);
            break;
        case 3:
            informa_sistem(li);
            break;
        case 4:
            menu(li);
            break;
        default:
            printf("ERRO!\n");
            system("pause");
            opcoes(li);
            break;
    }
}

    //FUNÇÃO-TELA GERENCIAR SENHA-ALTERAR SENHA
void alterar_senha(Lista* li){
        system("cls");
    int novasenha;

    printf("\t ----------------\n");
    printf("\t| ALTERAR SENHA: |\n");
    printf("\t ----------------\n\n");
    printf("Digite a senha atual: ");
    scanf("%d", &novasenha);
    setbuf(stdin, NULL);

    if(senha == novasenha){
        printf("Digite a nova senha: ");
        scanf("%d", &novasenha);
        setbuf(stdin, NULL);
        senha = novasenha;
        printf("Senha alterada com sucesso!\n");
        system("pause");
        loginSenha(li);
    }else{
        printf("ERRO! digite novamente!\n");
        system("pause");
        opcoes(li);
    }
}

    //FUNÇÃO-TELA SALVANDO ARQUIVOS EM .TXT
void salvar_arquivo(Lista* li){
    if(li->qtd == 0){
        system("cls");
		printf("\t ---------------------------\n");
		printf("\t| LISTA DE REGISTROS VAZIA!  |\n");
		printf("\t ---------------------------\n\n");
		system("pause");
        menu(li);
    }else{
        char arquivo[30];
	    printf("Informe o Nome do arquivo para salvar: ");
	    gets(arquivo);
	    fflush(stdin);
	    strcat(arquivo,".txt"); //MOSTRAR QUAIS EXTENSOES PODEMOS SALVAR .TXT / .DOC

	    FILE *f;
	    f = fopen(arquivo, "w");
            if(f == NULL){
                printf("ERRO CRIAÇÃO DO ARQUIVO");
                system("pause");
                opcoes(li);
            }
        printf("\t --------------------------------------------------------------\n");
        printf("\t| LISTA ESTA PRONTA PARA SER IMPRIMIDA SEGUE OS DADOS A BAIXO  |\n");
        printf("\t --------------------------------------------------------------\n\n");

        fprintf(f,"\t\t--- LISTA DE VEÍCULOS - TOPCAR---\n\n");
        for(int i=0; i< li->qtd; i++){
            printf(" ============================\n");
            printf("|Codigo Id:.. %d\n",li->dados[i].id);
            fprintf(f,"|Codigo Id:.. %d\n",li->dados[i].id);

            printf("|Nome:....... %s\n",li->dados[i].nome);
            fprintf(f,"|Nome:....... %s\n",li->dados[i].nome);

            printf("|Marca:...... %s\n", li->dados[i].marca);
            fprintf(f,"|Marca:...... %s\n",li->dados[i].marca);

            printf("|Ano:........ %d\n", li->dados[i].ano);
            fprintf(f,"|Ano:........ %d\n\n",li->dados[i].ano);
        }
            printf(" ============================\n");
            printf("\t\t---ARQUIVO: %s SALVO COM SUCESSO!---\n\n", arquivo);
        system("pause");
        fclose(f);
        opcoes(li);
    }
}

    //FUNÇÃO-TELA INFORMAÇÕES DO SISTEMA TOPCAR VEICULOS
informa_sistem(Lista* li){
    system("cls");
    printf("\t --------------------------\n");
    printf("\t| INFORMAÇÕES DO SISTEMA   |\n");
    printf("\t --------------------------\n\n");

    printf(" * Sistema de controle \n * Aplicação - Linguagem C - LISTA Estatica Sequencial\n * Software Livre\n * Version 2.0\n\n");
    printf("\t &Copyright - Fernando Almeida.\n\n");
    system("pause");

    menu(li);
}

    //FUNÇÃO-TELA ENCERRANDO O SISTEMA TOPCAR VEICULOS
void sair(Lista* li){
    system("cls");
    printf("\t -----------------------\n");
    printf("\t| ENCERRANDO O SISTEMA! |\n");
    printf("\t -----------------------\n\n");
    printf("Aguarde: ");
    for (int c=10; c>0; c--){
       printf("%d - ", c);
       Sleep(500); //Valor em Milissegundos
	}
	printf("Encerrado! - Obrigado!\n\n");
	system("pause");
	liberar_lista(li);
	exit(1);
}
