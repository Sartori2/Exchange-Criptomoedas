#include "exchange.h"
#include <stdio.h>
#include <string.h>

struct usuario usuarios[] = {
    {"1234567890", "12345"},
    {"9876543211", "54321"}
};

int totalUsuarios = 2;

int login(){
    char cpf[11];
    char senha[6];

    printf("=======Login====\n");
    printf("= CPF: ");
    scanf("%s", cpf);

    printf("= Senha: ");
    scanf(" %s", senha);

    for(int i = 0; i < totalUsuarios; i++){
        if(strcmp(usuarios[i].cpf, cpf) == 0 &&
            strcmp(usuarios[i].senha, senha) == 0){
                printf("= Login concluído com sucesso =\n");
                return 1;
        }
    }
    printf("= Login inválido =\n");
    return 0;
}

int menu(){
    int opcao;
    printf("============Menu===========\n");
    printf("1: Consultar Saldo\n");
    printf("2: Consultar Extrato\n");
    printf("3: Depositar Reais\n");
    printf("4: Sacar Reais\n");
    printf("5: Comprar Criptomoedas\n");
    printf("6: Vender Criptomoedas\n");
    printf("7: Atualizar Cotação\n");
    printf("8: Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}