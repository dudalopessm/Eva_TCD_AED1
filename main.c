#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inicio() { //funcao para mostrar o inicio
    printf("\n\n-------- Bem vindo(a) --------");
    printf("\n");
    printf("\n\nEu sou a Eva, sua gerenciadora de pedidos inteligente ( o.o )");
    printf("\nOpcoes disponiveis:");
    printf("\n");
    printf("\n0. Sair do aplicativo");
    printf("\n1. Menu para clientes");
    printf("\n2. Menu para prestadores de servico");
    printf("\n");
}

void Fim() { //funcao para mostrar tela de fim
    printf("\n\nEncerrando...");
    printf("\nSalvando...");
    printf("\nAte a proxima!");
}

void Opcao() { //sempre que for pedir opcao
    printf("\nDigite a opcao desejada: ");
}

int ConfirmaSenha(int senha1) { //TERMINAR FUNCAO DE CONFIRMACAO DE SENHA -> MUDAR SENHA PARA CHAR?
    return 0;
}

int ConfirmaEmail(char *email) { //confirma se email tem @ e já existe na lista
    int comp, auxarroba = 0, auxponto = 0, i;
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            auxarroba++;
        } else if (email[i] == '.' && auxarroba == 1) {
            auxponto++;
        }
    }
    if (auxarroba != 1) return 2;
    if (auxponto != 1) return 3;
    return 0;
}

int confirmaCPF(char *cpf) {
    int i, tam = 0;
    for (i = 0; cpf[i] != '\0'; i++) {
        tam++;
    }
    if(tam<11) return -1;
    return 0;
}


int main () {
    int menuprincp, menucli1, menucli2, menurest1, menurest2;
    int controle, senhaaux;
    ListaC *lCli;
    lCli = criarCliente();
    Cliente c1;
    do
    {
        //inicio do programa
        Inicio();
        Opcao();
        scanf("%d", &menuprincp);
        system("cls");
        switch (menuprincp)
        {
            case 0: //caso cliente queira sair
                system("cls");
                Fim();
                liberarmemoriaC(lCli);
                break;
            case 1: //parte do cliente
                do {
                    printf("\n\n-------- Area do cliente --------");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    printf("\n0. Retornar");
                    printf("\nDigite sua opcao abaixo: ");
                    scanf("%d", &menucli1);
                    system("cls");
                    switch (menucli1) {
                        case 0:
                            break;
                        case 1:
                            do {
                                printf("\nInsira seu email:");
                                setbuf(stdin, NULL);
                                fgets(c1.email, 50, stdin);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                controle = ConfirmaEmail(c1.email);
                                if (controle) {
                                    printf("\nEmail invalido, digite novamente.");
                                } else if (buscaEmailCliente(lCli, c1.email) != 0) {
                                    controle = 1;
                                    printf("\nEmail nao cadastrado, digite novamente.");
                                }
                            } while(controle);
                            buscaCliente(lCli, c1.email, &c1);
                            do {
                                printf("\nSenha: ");
                                scanf("%d", &senhaaux);
                                controle = ConfirmaSenha(senhaaux);
                                if(controle){
                                    printf("\nDeu errado.");
                                } else if (senhaaux != c1.senha) {
                                    printf("\nSenha incorreta, digite novamente.");
                                    controle = 1;
                                }
                            }while(controle);
                            do { //funcionalidade pro cliente mexer
                                system("cls");
                                printf("\n\nBem vindo(a), %s", c1.nome);
                                printf("\nDigite sua opcao: ");
                                scanf("%d", &menucli2);
                            } while(menucli2);
                            //fim da funcionalidade com o cliente logado
                        case 2:
                            system("cls");
                            printf("-------- Dados --------\n");
                            printf("\nInsira seu nome: ");
                            setbuf(stdin, NULL);
                            fgets(c1.nome, 50, stdin);
                            c1.nome[strcspn(c1.nome, "\n")] = '\0';
                            do {
                                printf("\nDigite seu CPF: ");
                                setbuf(stdin, NULL);
                                fgets(c1.cpf, 12, stdin);
                                controle = confirmaCPF(c1.cpf);
                                if (controle) {
                                    printf("\nCPF invalido, tente novamente.");
                                } else if (procuraCliente(lCli, c1.cpf) == 0) {
                                    printf("\nCPF existente em alguma conta, tente novamente.");
                                    controle = 1;
                                }
                            } while(controle);
                            do {
                                printf("\nInsira seu email:");
                                setbuf(stdin, NULL);
                                fgets(c1.email, 50, stdin);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                if (controle) {
                                    printf("\nEmail invalido, tente novamente.");
                                } else if(buscaEmailCliente(lCli, c1.email) == 0) {
                                    printf("\nEmail ja cadastrado, tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha apenas com numeros: ");
                                scanf("%d", &c1.senha);
                                controle = ConfirmaSenha(c1.senha);
                                if (controle) {
                                    printf("\nSenha invalida, tente novamente.");
                                }
                            } while(controle);
                            controle = inserirCliente(lCli, c1);
                            system("cls");
                            if (controle == 0) {
                                printf("\n\nCadastro efetuado.");
                            } else {
                                printf("Erro ao cadastrar");
                            }
                            break;
                        default:
                            printf("\n\nOpcao invalida, digite novamente.");
                    }
                } while (menucli1);
                break;
            case 2:
                do {
                    printf("\n\n-------- Area do prestador de servico --------");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    printf("\n0. Retornar");
                    printf("\nDigite sua opcao abaixo: ");
                    scanf("%d", &menurest1);
                    system("cls");
                    switch (menurest1) {
                        case 0:
                            break;
                        case 1: //login restaurante
                            printf("\nInsira o email: ");
                    }
                } while(menurest1);
        }
    } while (menuprincp);
    printf("\n\n");
    system("pause");
    //colocar case default no switch?
    return 0;
}