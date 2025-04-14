#include "exchange.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BANCO_USUARIOS "usuarios.txt"

struct usuario usuarios[10] = {
    {"1234567890", "12345"},
    {"9876543211", "54321"}
};

int totalUsuarios = 2;

int carregar_users(char* cpf, Saldos* saldos){
    char filename[20];
    sprintf(filename, "CPF_%s.txt", cpf);
    
    FILE* file = fopen(filename, "r");
    
    if(file == NULL){
        file = fopen(filename, "w");
        if(file == NULL){
            return 0;
        }
        
        fprintf(file, "CPF: %s\n", cpf);
        fprintf(file, "Reais: 0.00\n");
        fprintf(file, "Bitcoin: 0.0000000\n");
        fprintf(file, "Ethereum: 0.0000000\n");
        fprintf(file, "Ripple: 0.0000000\n");
        fclose(file);
        
        saldos->reais = 0;
        saldos->bitcoin = 0;
        saldos->ethereum = 0;
        saldos->ripple = 0;
        return 1;
    }

    char linha[50];
    while (fgets(linha, sizeof(linha), file) != NULL){
        if(strstr(linha, "Reais:")){
            sscanf(linha, "Reais: %f", &saldos->reais);
        } 
        else if(strstr(linha, "Bitcoin:")){
            sscanf(linha, "Bitcoin: %f", &saldos->bitcoin);
        }
        else if(strstr(linha, "Ethereum:")){
            sscanf(linha, "Ethereum: %f", &saldos->ethereum);
        }
        else if(strstr(linha, "Ripple:")){
            sscanf(linha, "Ripple: %f", &saldos->ripple);
        }
    }
    fclose(file);
    return 1;
}

int salvar_users(char* cpf, Saldos* saldos){
    char filename[20];
    sprintf(filename, "CPF_%s.txt", cpf);
    
    FILE* file = fopen(filename, "w");
    if(file == NULL){
        return 0; 
    }
    
    fprintf(file, "Reais: %.2f\n", saldos->reais);
    fprintf(file, "Bitcoin: %f\n", saldos->bitcoin);
    fprintf(file, "Ethereum: %f\n", saldos->ethereum);
    fprintf(file, "Ripple: %f\n", saldos->ripple);
    
    fclose(file);
    return 1;
}

int login(char* cpf_out){
    char cpf[12];
    char senha[7];

    printf("=======Login====\n");
    printf("= CPF: ");
    scanf("%s", cpf);

    printf("= Senha: ");
    scanf(" %s", senha);

    for(int i = 0; i < totalUsuarios; i++){
        if(strcmp(usuarios[i].cpf, cpf) == 0 &&
            strcmp(usuarios[i].senha, senha) == 0){
                printf("= Login concluído com sucesso =\n");
                strcpy(cpf_out, cpf);
                return 1;
        }
    }
    printf("= Login inválido =\n");
    return -1;
}

int depositar(Saldos* saldos){
    float valor;
    printf("\n");
    printf("============ Depositar ============\n");
    printf("= Digite o valor para depositar: ");
    scanf("%f", &valor);
    
    if(valor <= 0){
        printf("\n");
        printf("= Digite um valor positivo\n");
        return 0;
    }
    
    saldos->reais += valor;
    printf("\n");
    printf("=====================\n");
    printf("= Deposito realizado\n", valor);
    return 1;
}

int menu(){
    int opcao;
    printf("\n");
    printf("========= Menu ========\n");
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