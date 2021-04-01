#ifndef LISTAPROTOTIPOS_H_INCLUDED
#define LISTAPROTOTIPOS_H_INCLUDED
#endif // LISTAPROTOTIPOS_H_INCLUDED
#define MAX 3

struct veiculo{ //TIPO DE LISTA QUE IREMOS TRABALHAR, TIPO STRUCT DE 10 BYTES
    int id;
    char nome[50];
    char marca[50];
    int ano;
};
typedef struct lista Lista; //ESTRUTURA LISTA COM O TIPO DE DADOS IREMOS MANIPULAR

struct veiculo dados_veiculo; //ESTRUTURA LISTA QUE VAI RECEBER DADOS PARA O CADASTRAMENTO

    //INICIALIZANDO A LISTA
Lista* cria_lista();

    //LIBERAR LISTA
void liberar_lista(Lista* li);

    //MENU
void menu(Lista* li);

    //CADASTRAR
void cadastrar(Lista* li);

    //Inserir Final
void inserir_final(Lista* li, struct veiculo *aux);

    //Imprimir dados
void imprimir_lista(Lista* li);

    //tamanho lista
int tamanho_lista(Lista* li);

    //LOGIN E SENHA
void loginSenha(Lista* li);

    //DELETAR UM CADASTRO
void deletar(Lista* li);

    //OPEÇÕES
void opcoes(Lista* li);

    //ALTERAR SENHA
void alterar_senha(Lista* li);

    //IMPRIMIR DADOS
void salvar_aquivo(Lista* li);

    //INFORMAÇÕES DO SISTEMA
informa_sistem(Lista* li);

    //SAIR DO PROGRAMA
void sair(Lista* li);


