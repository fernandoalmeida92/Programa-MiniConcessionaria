#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "ListaPrototipos.h"



int main()
{
    setlocale(LC_ALL, "portuguese");
    system("cls");

    char str[50] = "SEJA BEM VINDO - SISTEMA TOPCAR VEÍCULOS";
        printf("\n\t\t");
        for(int i =0;i <= strlen(str);i++){
            printf("%c ", str[i]);
            Sleep(20);
        }
        printf("\n\n");
        system("pause");

    Lista *li;
    li = cria_lista();
    loginSenha(li);

    liberar_lista(li);
    system("pause");
    return 0;
}
