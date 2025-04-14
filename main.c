#include "exchange.h"
#include <stdio.h>
#include <string.h>

int main(){
    Saldos saldos;
    char cpf[12];
    int usuario_logado;

    usuario_logado = login(cpf);
    if(usuario_logado == -1){
        return 1;
    }

    if(!carregar_users(cpf, &saldos)){
        printf("Erro ao carregar usuário\n");
        return 1;
    }

    int opcao;
    do{
        opcao = menu();

        switch (opcao){
            case 1:
                printf("===== Saldo atual: =====\n");
                printf("Reais: %.2f\n", saldos.reais);
                printf("Bitcoin: %.7f\n", saldos.bitcoin);
                printf("Ethereum: %.7f\n", saldos.ethereum);
                printf("Ripple: %.7f\n", saldos.ripple);
                printf("\n");
                break;
            case 2:
                printf("Consultar Extrato\n");
                break;
            case 3:
                printf("Depositar Reais\n");
                break;
            case 4:
                printf("Sacar Reais\n");
                break;
            case 5:
                printf("Comprar Criptomoedas\n");
                break;
            case 6:
                printf("Vender Criptomoedas\n");
                break;
            case 7:
                printf("Atualizar Cotação\n");
                break;
            case 8:
                printf("Fechando Programa\n");
                if (!salvar_users(cpf, &saldos)) {
                    printf("Erro ao salvar dados!\n");
                    return 1;
                }
                break;
            default:
                printf("Digite uma opção válida\n");
                break;
        }
    }while (opcao != 8);
    return 0;
}