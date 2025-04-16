#ifndef EXCHANGE_H
#define EXCHANGE_H

typedef struct Saldos {
    float reais;
    float bitcoin;
    float ethereum;
    float ripple;
} Saldos;

struct usuario {
    char cpf[12];
    char senha[7];
    Saldos saldos;
};

int login(char* cpf_out);
int menu();
int carregar_users(char* cpf, Saldos* saldos);
int salvar_users(char* cpf, Saldos* saldos);
int depositar(Saldos* saldos);
char* validar_senha(char* cpf);
int sacar(char* senha_usuario, Saldos* saldos);
int comprar_criptomoedas(Saldos* saldos);
int vender_criptomoedas(Saldos* saldos);

#endif
