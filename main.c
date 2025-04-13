#include "exchange.h"
#include <stdio.h>

int main(){
    if(login()){
        int opcao;
        do{
            opcao = menu();

            switch(opcao){
                case 1:
                    printf("Consultar Saldo\n");
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
                    break;
                default:
                    printf("Digite uma opcao válida\n");
                    break;
            }
        } while(opcao != 8);
    }
    return 0;
}