#include "Clientes.h"
#include "Restaurantes.h"
#include "Prato.h"
#include "Pedido.h"
#include "Feedback.h"
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

void Restaurantes(char *auxcat) {
    int op;
    do {
        printf("\n1. Comida japonesa");
        printf("\n2. Comida brasileira");
        printf("\n3. Pizzas");
        printf("\n4. Hamburgueres");
        printf("\n5. Vegetarianos");
        printf("\n6. Comida arabe");
        printf("\n7. Doces e bolos");
        printf("\n8. Comida italiana");
        printf("\n9. Padaria");
        printf("\n10. Nenhuma listada");
        Opcao();
        scanf("%d", &op);
        switch (op) {
            case 1:
                strcpy(auxcat, "Comida japonesa");
                break;
            case 2:
                strcpy(auxcat, "Comida brasileira");
                break;
            case 3:
                strcpy(auxcat, "Pizzas");
                break;
            case 4:
                strcpy(auxcat, "Hamburgueres");
                break;
            case 5:
                strcpy(auxcat, "Vegetarianos");
                break;
            case 6:
                strcpy(auxcat, "Comida arabe");
                break;
            case 7:
                strcpy(auxcat, "Doces e bolos");
                break;
            case 8:
                strcpy(auxcat, "Comida italiana");
                break;
            case 9:
                strcpy(auxcat, "Padaria");
                break;
            case 10:
                strcpy(auxcat, "Nenhuma listada");
                break;
            default:
                printf("\nOpcao invalida! Digite alguma valida.");
        }
    } while(op < 1 && op > 10);
}

int ConfirmaSenha(char *s) {
    int i = 0, num = 0, tam = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '1' && s[i] <= '9') {
            num++;
        }
        tam++;
    }
    if (num && tam >= 8) return 0;
    return 1;
}

int ConfirmaEmail(char *email) {
    int auxarroba = 0, auxponto = 0, i;
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

int ConfirmaCPF(char *cpf) {
    int i, tam = 0;
    for (i = 0; cpf[i] != '\0'; i++) {
        tam++;
    }
    if (cpf[11] != '-') return 1;
    if (cpf[3] != '.' || cpf[7] != '.') return 1;
    if(tam<14) return 1;
    return 0;
}

int ConfirmaCNPJ(char *cnpj) {
    int i, tam = 0;
    for (i = 0; cnpj[i] != '\0'; i++) {
        tam++;
    }
    if (tam!= 17) return 1;
    if (cnpj[2] != '.' || cnpj[6] != '.') return 1;
    if (cnpj[10] != '/') return 1;
    return 0;
}

/*int ConfirmaEstrelas(char *est) {
    int i, tam = 0, num = 0;
    for (i = 0; est[i] != '\0'; i++) {
        if (est[i] >= '0' && est[i] <= '5') num++; //deve ser um numero obrigatoriamente entre 0 e 5
        tam++;
    }
    if ((num = 1) && (tam = 1)) return 0; //avaliacao deve ser dada
    return 1;
} feedback em prod*/ 

int main () {
    int menuprincp, menucli1, menucli2, menurest1, menurest2;
    int controle, opcli, cod, ret, quantidade, opc;
    char auxcat[30], auxsenha[10];
    ListaC *lCli;
    ListaR *lRest;
    ListaP *lPr;
    lCli = criarCliente();
    lRest = criarRest();
    lPr = criarP();
    Cliente c1;
    Cliente c2 = {"123.123.123-12", "Administrador", "admin@email.com", "admin123"}; //usuario para teste em prod
    controle = inserirCliente(lCli, c2); //usuario para teste em prod
    Restaurante r1;
    Restaurante r2 = {"Japaroll", "Comida japonesa", "12.345.678/0003-00", "admin@email.com", "admin123", 11, NULL, NULL}; //usuario para teste em prod
    controle = inserirRest(lRest, r2); //usuario para teste em prod
    Pratos p1;
    do
    {
        //inicio do programa
        Inicio();
        Opcao();
        scanf("%d", &menuprincp);
        system("cls");
        switch (menuprincp)
        {
            case 0: //caso usuario queira sair
                system("cls");
                Fim();
                break;
            case 1: //parte do cliente
                do {
                    printf("\n\n-------- Area do cliente --------");
                    printf("\n0. Retornar");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    Opcao();
                    scanf("%d", &menucli1);
                    setbuf(stdin, NULL);
                    system("cls");
                    switch (menucli1) {
                        case 0: //saida do menu do cliente
                            break;
                        case 1: //tela de login do cliente
                            do {
                                setbuf(stdin, NULL);
                                printf("\nInsira seu email: ");
                                setbuf(stdin, NULL);
                                fgets(c1.email, 50, stdin);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                setbuf(stdin, NULL);
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
                                setbuf(stdin, NULL);
                                printf("\nSenha: ");
                                setbuf(stdin, NULL);
                                fgets(auxsenha, 9, stdin);
                                auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaSenha(auxsenha);
                                if(controle){
                                    printf("\nSenha invalida. Tente novamente.");
                                } else if (strcmp(auxsenha, c1.senha)) {
                                    printf("\nSenha incorreta, digite novamente.");
                                    controle = 1;
                                }
                            }while(controle);
                            //CLIENTE LOGADO
                            do { 
                                system("cls");
                                printf("\n\n-------- %s, bem vindo(a) --------", c1.nome);
                                printf("\n0. Retornar"); 
                                printf("\n1. Faca seu pedido!"); 
                                printf("\n2. Pagamento e finalizacao de pedidos");
                                printf("\n3. Historico de pedidos entregues");
                                printf("\n4. Feedbacks"); //em producao
                                printf("\n5. Excluir conta");
                                Opcao();
                                scanf("%d", &menucli2);
                                system("cls");
                                switch (menucli2) {
                                    case 0: //saida
                                        break;
                                    case 1: //para fazer pedidos
                                        do {
                                            printf("\n-------- Nossos servicos --------");
                                            Restaurantes(auxcat);
                                            system("cls");
                                            printf("\n-------- Restaurantes disponiveis --------");
                                            mostrarR(lRest, auxcat);
                                            printf("\nDeseja olhar o cardapio de algum restaurante?");
                                            printf("\n0. Nao, desejo retornar ");
                                            printf("\n1. Sim, quero olhar");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1: //fazer pedido
                                                    printf("\nDigite o numero da identificacao do restaurante: ");
                                                    scanf("%d", &opcli);
                                                    ret = achaRest(lRest, opcli, &r1);
                                                    if (ret) {
                                                        printf("\nCodigo incorreto. Tente novamente.");
                                                        opcli = 1;
                                                        break;
                                                    } else {
                                                        do {
                                                            printf("\n-------- Menu --------");
                                                            mostrarPratos(r1.cardapio);
                                                            printf("\n------------------------");
                                                            printf("\n");
                                                            printf("\nDeseja fazer um pedido?");
                                                            printf("\n0. Nao, desejo retornar.");
                                                            printf("\n1. Sim, desejo pedir.");
                                                            printf("\nDigite sua opcao: ");
                                                            scanf("%d", &opcli);
                                                            setbuf(stdin, NULL);
                                                            switch (opcli) {
                                                                case 0: 
                                                                    break;
                                                                case 1: 
                                                                    printf("\nDigite o codigo do prato: ");
                                                                    scanf("%d", &opcli);
                                                                    fflush(stdin);
                                                                    printf("\nQuantidade: ");
                                                                    scanf("%d", &quantidade);
                                                                    fflush(stdin);
                                                                    acharPrato(lRest, opcli, &r1);
                                                                    controle = buscaPrato(r1.cardapio, opcli, &p1);
                                                                    system("cls");
                                                                    if (controle) {
                                                                        printf("\nErro na realizacao do pedido.");
                                                                        opcli = 1;
                                                                        break;
                                                                    } else {
                                                                        p1.quantidade = quantidade;
                                                                        p1.restauranteorigem = r1.identificacao;
                                                                        ret = inserirPrato(c1.carrinho, p1);
                                                                        if (ret) {
                                                                            printf("\nErro ao realizar pedido.");
                                                                        } else {
                                                                            printf("\nPedido realizado.");
                                                                        }
                                                                    }
                                                            }
                                                            printf("\n");
                                                            printf("\nPedir de novo?");
                                                            printf("\n0. Nao, desejo retornar.");
                                                            printf("\n1. Sim, desejo olhar os pratos novamente.");
                                                            Opcao();
                                                            scanf("%d", &opcli);
                                                            system("cls");
                                                        } while (opcli);
                                                    }
                                            }
                                            printf("\nOlhar outros restaurantes?");
                                            printf("\n0. Nao, desejo retornar.");
                                            printf("\n1. Sim, desejo olhar os restaurantes novamente.");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            system("cls");
                                        } while(opcli);
                                        break;
                                    case 2: //carrinho e pagamento
                                        printf("\n-------- Pagamento R$ --------");
                                        mostrarPCliente(c1.carrinho);
                                        float pag = carrinho(c1.carrinho);
                                        printf("\nTotal: %.2f reais", pag);
                                        printf("\n-------------------------");
                                        printf("\n");
                                        opc = 1;
                                        while (opc && (listaVaziaP(c1.carrinho) == 1)) {
                                            printf("\nCancelar algum item?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opc);
                                            fflush(stdin);
                                            switch (opc) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNumero do item que deseja cancelar: ");
                                                    scanf("%d", &opc);
                                                    fflush(stdin);
                                                    controle = buscaPrato(c1.carrinho, opc, &p1);
                                                    if (controle == 0) {
                                                        controle = removerPrato(c1.carrinho, p1);
                                                        if (controle == 0) {
                                                            opc = 0;
                                                            system("cls");
                                                            printf("\nPedido cancelado.");
                                                        } else {
                                                            opc = 1;
                                                            system("cls");
                                                            printf("\nErro ao cancelar pedido.");
                                                        }
                                                    } else {
                                                        system("cls");
                                                        printf("\nOpcao invalida. Tente novamente.");
                                                    }
                                                    break;
                                                default:
                                                    system("cls");
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        }
                                        opc = 1;
                                        while(opc && (listaVaziaP(c1.carrinho)) != 0) {
                                            printf("\nEfetuar pagamento e finalizar compra?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opc);
                                            fflush(stdin);
                                            switch(opc) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    while(listaVaziaP(c1.carrinho) == 1) { 
                                                        retornarPrato(c1.carrinho, &p1);
                                                        achaRest(lRest, p1.restauranteorigem, &r1);
                                                        inserirPedido(r1.pedidos, c1, p1);
                                                        inserirPrato(c1.pedidos, p1);
                                                        ret = removerPrato(c1.carrinho, p1);
                                                    }
                                                    if (ret == 0) {
                                                        opc = 0;
                                                        system("cls");
                                                        printf("\nPedido saindo para entrega.");
                                                    } else {
                                                        system("cls");
                                                        printf("\nErro ao realizar pedido.");
                                                    }
                                                    break;
                                                default: 
                                                system("cls");
                                                printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        }
                                        printf("\nPressione qualquer tecla para voltar.");
                                        fflush(stdin);
                                        getc(stdin);
                                        fflush(stdin);
                                        system("cls");
                                        break;
                                    case 3: //confirmacao de pedidos
                                        printf("\n-------- Pedidos a serem confirmados --------");
                                        mostrarPCliente(c1.pedidos);
                                        printf("\n-------- Pedidos entregues  --------");
                                        mostrarPCliente(c1.entregues);
                                        opc = 1;
                                        int auxx;
                                        auxx = listaVaziaP(c1.entregues);
                                        while (auxx == 0) {
                                            auxx = 1;
                                            printf("\nHouve algum pedido recebido?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opc);
                                            fflush(stdin);
                                            switch(opc) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNumero do pedido recebido: ");
                                                    int op;
                                                    scanf("%d", &op);
                                                    fflush(stdin);
                                                    controle = buscaPrato(c1.pedidos, op, &p1);
                                                    if (controle == 0) {
                                                        controle = removerPrato(c1.pedidos, p1);
                                                        controle = inserirPrato(c1.entregues, p1);
                                                        if (controle == 0) {
                                                            opc = 0;
                                                            system("cls");
                                                            printf("\nPedido dado como entregue. Obrigada por pedir!");
                                                        } else {
                                                            opc = 0;
                                                            system("cls");
                                                            printf("\nErro ao realizar confirmacao.");
                                                        }
                                                    } else {
                                                        opc = 1;
                                                        system("cls");
                                                        printf("\nCodigo do pedido incorreto. Tente novamente.");
                                                    }
                                                    break;
                                                default: 
                                                    opc = 1;
                                                    system("cls");
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        }
                                        printf("\nPressione qualquer tecla para retornar.");
                                        fflush(stdin);
                                        getc(stdin);
                                        fflush(stdin);
                                        system("cls");
                                        break;
                                    case 4: //feedbacks
                                        printf("\nFuncao feedbacks em desenvolvimento.");
                                        break;
                                    case 5: //excluir conta
                                        printf("\n-------- Exclusao da conta --------");
                                        printf("\n %s, deseja excluir sua conta?", c1.nome);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        fflush(stdin);
                                        while (opcli) {
                                            printf("\nSenha necessaria para delecao de conta, digite-a: ");
                                            fgets(auxsenha, 9, stdin);
                                            auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                            fflush(stdin);
                                            if (strcmp(auxsenha, c1.senha) == 0) {
                                                ret = removerCliente(lCli, c1);
                                                if (ret) {
                                                    system("cls");
                                                    printf("\nErro na exclusao da conta.");
                                                } else {
                                                    opcli = 0;
                                                    menucli2 = 0;
                                                    system("cls");
                                                    printf("\nConta excluida.");
                                                }
                                            } else {
                                                system("cls");
                                                printf("\nSenha incorreta. Tente novamente.");
                                            }
                                        }
                                        break;
                                    default:
                                        printf("\nOpcao invalida. Tente novamente.");
                                }
                            } while(menucli2);
                            break;
                            //CLIENTE DESLOGADO
                            //registro do cliente
                        case 2:
                            system("cls");
                            printf("-------- Dados --------\n");
                            printf("\nInsira seu nome: ");
                            setbuf(stdin, NULL);
                            fgets(c1.nome, 50, stdin);
                            c1.nome[strcspn(c1.nome, "\n")] = '\0';
                            setbuf(stdin, NULL);
                            do {
                                printf("\nFormato do CPF: XXX.XXX.XXX-XX");
                                printf("\nDigite seu CPF: ");
                                fflush(stdin);
                                fgets(c1.cpf, 15, stdin);
                                c1.cpf[strcspn(c1.cpf, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaCPF(c1.cpf);
                                if (controle) {
                                    printf("\nCPF invalido, tente novamente.");
                                } else if (procuraCliente(lCli, c1.cpf) == 0) {
                                    printf("\nCPF existente em alguma conta, tente novamente.");
                                    controle = 1;
                                }
                            } while(controle);
                            do {
                                setbuf(stdin, NULL);
                                printf("\nInsira seu email: ");
                                fflush(stdin);
                                fgets(c1.email, 50, stdin);
                                controle = ConfirmaEmail(c1.email);
                                setbuf(stdin, NULL);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                if (controle) {
                                    printf("\nEmail invalido, tente novamente.");
                                } else if(buscaEmailCliente(lCli, c1.email) == 0) {
                                    controle = 1;
                                    printf("\nEmail ja cadastrado, tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha com numeros e letras de 8 caracteres: ");
                                setbuf(stdin, NULL);
                                fgets(c1.senha, 9, stdin);
                                setbuf(stdin, NULL);
                                c1.senha[strcspn(c1.senha, "\n")] = '\0';
                                controle = ConfirmaSenha(c1.senha);
                                if (controle) {
                                    printf("\nSenha invalida. Tente novamente.");
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
                //RESTAURANTE
            case 2: 
                do {
                    printf("\n\n-------- Area do prestador de servico --------");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    printf("\n0. Retornar");
                    Opcao();
                    scanf("%d", &menurest1);
                    setbuf(stdin, NULL);
                    system("cls");
                    switch (menurest1) {
                        case 0: //saida do menu do restaurante
                            break;
                        case 1: //login restaurante
                            do {
                                printf("\nInsira o email: ");
                                setbuf(stdin, NULL);
                                fgets(r1.email, 30, stdin);
                                setbuf(stdin, NULL);
                                r1.email[strcspn(r1.email, "\n")] = '\0';
                                controle = ConfirmaEmail(r1.email);
                                if (controle) {
                                    printf("\nEmail incorreto. Digite novamente.");
                                } else if (buscaEmailRest(lRest, r1.email) != 0) {
                                    controle = 1;
                                    printf("\nEmail nao cadastrado. Digite novamente.");
                                }
                            } while(controle);
                            buscaRest(lRest, r1.email, &r1);
                            do {
                                printf("\nInsira a senha: ");
                                setbuf(stdin, NULL);
                                fgets(auxsenha, 9, stdin);
                                setbuf(stdin, NULL);
                                auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                controle = ConfirmaSenha(auxsenha);
                                if (controle) {
                                    printf("\nSenha invalida. Tente novamente.");
                                } else if (strcmp(auxsenha, r1.senha) != 0) {
                                    printf("\nSenha incorreta. Tente novamente.");
                                    controle = 1;
                                }
                            } while(controle);
                            system("cls");
                            //RESTAURANTE LOGADO
                            do { //menu de funcionalidades
                                printf("\n\n-------- %s, bem vindo(a) --------", r1.nomeRest);
                                printf("\n0. Retornar");
                                printf("\n1. Ver meu cardapio");
                                printf("\n2. Pedidos em minha loja");
                                printf("\n3. Cadastrar prato");
                                printf("\n4. Alteracao de prato");
                                printf("\n5. Excluir prato");
                                printf("\n6. Feedbacks da minha loja"); //em producao
                                printf("\n7. Excluir conta");
                                Opcao();
                                scanf("%d", &menurest2);
                                setbuf(stdin, NULL);
                                system("cls");
                                switch (menurest2) {
                                    case 0: //retornar a tela principal
                                        break;
                                    case 1: //mostra cardapio
                                        printf("\n-------- Meu cardapio --------");
                                        mostrarPratos(r1.cardapio);
                                        printf("\nVolte ao pressionar qualquer tecla.");
                                        fflush(stdin);
                                        fgetc(stdin);
                                        setbuf(stdin, NULL);
                                        system("cls");
                                        break;
                                    case 2: //mostra meus pedidos
                                        do {
                                            printf("-------- Pedidos da loja --------");
                                            mostrarPedidos(r1.pedidos);
                                            printf("\nPressione qualquer tecla para sair.");
                                            fflush(stdin);
                                            getc(stdin);
                                            setbuf(stdin, NULL);
                                            system("cls");
                                        } while (opc);
                                        break;
                                    case 3: //cadastrar prato
                                        printf("\n-------- Cadastro de prato --------");
                                        printf("\nNome do prato: ");
                                        setbuf(stdin, NULL);
                                        fgets(p1.nome, 30, stdin);
                                        p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                        setbuf(stdin, NULL);
                                        printf("\nPreco do prato: ");
                                        scanf("%f", &p1.preco);
                                        setbuf(stdin, NULL);
                                        printf("\nIngredientes do prato: ");
                                        setbuf(stdin, NULL);
                                        fgets(p1.ingredientes, 300, stdin);
                                        p1.ingredientes[strcspn(p1.ingredientes, "\n")] = '\0';
                                        setbuf(stdin, NULL);
                                        p1.codigo = geracaoCod(lRest);
                                        p1.restauranteorigem = r1.identificacao;
                                        controle = inserirPrato(r1.cardapio, p1);
                                        if (controle) {
                                            system("cls");
                                            printf("\nErro na insercao do prato.");
                                        } else {
                                            system("cls");
                                            printf("\nPrato inserido.");
                                        }
                                        break;
                                    case 4: //alterar prato
                                        printf("\n-------- Alteracao de prato --------");
                                        printf("\nDigite o codigo do prato: ");
                                        scanf("%d", &cod);
                                        setbuf(stdin, NULL);
                                        controle = buscaPrato(lPr, cod, &p1);
                                        if (controle) {
                                            printf("\nCodigo incorreto, digite novamente.");
                                            break;
                                        }
                                        do {
                                            printf("\nNome: %s", p1.nome);
                                            printf("\nAlterar nome?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            setbuf(stdin, NULL);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo nome: ");
                                                    setbuf(stdin, NULL);
                                                    fgets(p1.nome, 30, stdin);
                                                    p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                                    setbuf(stdin, NULL);
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        do {
                                            printf("\nPreco: %2.f", p1.preco);
                                            printf("\nAlterar preco?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            setbuf(stdin, NULL);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo preco: ");
                                                    scanf("%f", &p1.preco);
                                                    setbuf(stdin, NULL);
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        do {
                                            printf("\nIngredientes: %s", p1.ingredientes);
                                            printf("\nAlterar ingredientes?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            setbuf(stdin, NULL);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovos ingredientes: ");
                                                    setbuf(stdin, NULL);
                                                    fgets(p1.ingredientes, 300, stdin);
                                                    p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                                    setbuf(stdin, NULL);
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        controle = removerPrato(r1.cardapio,p1);
                                        if (controle) {
                                            system("cls");
                                            printf("\nErro na modificacao do prato.");
                                        } else {
                                            controle = inserirPrato(r1.cardapio, p1);
                                            if (controle) {
                                                system("cls");
                                                printf("\nErro na modificacao do prato.");
                                            } else {
                                                system("cls");
                                                printf("\nPrato alterado.");
                                            }
                                        }
                                        break;
                                    case 5: //exclusao de prato
                                        printf("\n-------- Exclusao de pratos --------");
                                        printf("\nDigite o codigo do prato: ");
                                        scanf("%d", &cod);
                                        setbuf(stdin, NULL);
                                        controle = buscaPrato(r1.cardapio, cod, &p1);
                                        if (controle) {
                                            printf("\nPrato nao encontrado. Codigo invalido.");
                                            break;
                                        }
                                        printf("\nDeseja excluir o prato %s?", p1.nome);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        setbuf(stdin, NULL);
                                        while (opcli) {
                                            controle = removerPrato(r1.cardapio, p1);
                                            if (controle) {
                                                system("cls");
                                                printf("\nErro ao remover prato.");
                                            } else {
                                                opcli = 0;
                                                system("cls");
                                                printf("\nPrato excluido.");
                                            }
                                        }
                                        break;
                                    case 6: //feedbacks
                                        printf("\nFuncao feedbacks em desenvolvimento.");
                                        break;
                                    case 7: //excluir conta
                                        printf("\n-------- Exclusao de conta de prestador de servico --------");
                                        printf("\nDeseja excluir sua conta, %s?", r1.nomeRest);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        setbuf(stdin, NULL);
                                        while (opcli) {
                                            printf("\nSenha necessaria para exclusao. Digite-a: ");
                                            setbuf(stdin, NULL);
                                            fgets(auxsenha, 9, stdin);
                                            auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                            setbuf(stdin, NULL);
                                            if (strcmp(auxsenha, r1.senha) == 0) {
                                                controle = removerRest(lRest, r1);
                                                if (controle) {
                                                    system("cls");
                                                    printf("\nErro na delecao da conta.");
                                                } else {
                                                    opcli = 0;
                                                    menurest2 = 0;
                                                    system("cls");
                                                    printf("\nConta excluida.");
                                                }
                                            } else {
                                                system("cls");
                                                printf("\nSenha incorreta. Digite novamente.");
                                            }
                                        }
                                        break;
                                    default:
                                        printf("\nOpcao invalida. Digite novamente.");
                                }
                            } while(menurest2);
                            break;
                            //RESTAURANTE DESLOGADO
                        case 2: //registro restaurante
                            printf("\n-------- Registro de restaurante --------");
                            printf("\nNome do restaurante: ");
                            setbuf(stdin, NULL);
                            fgets(r1.nomeRest, 29, stdin);
                            setbuf(stdin, NULL);
                            r1.nomeRest[strcspn(r1.nomeRest, "\n")] = '\0';
                            do{
                                printf("\nFormato de digitacao do CNPJ: XX.XXX.XXX/XXXX-XX");
                                printf("\nCNPJ do restaurante: ");
                                setbuf(stdin, NULL);
                                fgets(r1.CNPJ, 18, stdin);
                                setbuf(stdin, NULL);
                                r1.CNPJ[strcspn(r1.CNPJ, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaCNPJ(r1.CNPJ);
                                if (controle) {
                                    printf("\nCNPJ no formato invalido. Tente novamente.");
                                } else if (buscaItemRest(lRest, r1.CNPJ) == 0) {
                                    controle = 1;
                                    printf("\nCNPJ ja existente. Tente novamente.");
                                }
                            } while(controle);
                            do {
                                setbuf(stdin, NULL);
                                printf("\nEmail: ");
                                fflush(stdin);
                                fgets(r1.email, 30, stdin);
                                setbuf(stdin, NULL);
                                controle = ConfirmaEmail(r1.email);
                                r1.email[strcspn(r1.email, "\n")] = '\0';
                                if (controle) {
                                    printf("\nEmail invalido. Tente novamente.");
                                } else if (buscaEmailRest(lRest, r1.email) == 0) {
                                    controle = 1;
                                    printf("\nEmail ja existente. Tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha com letras e numeros de 8 caracteres: ");
                                setbuf(stdin, NULL);
                                fgets(r1.senha, 9, stdin);
                                setbuf(stdin, NULL);
                                controle = ConfirmaSenha(r1.senha);
                                if (controle) {
                                    printf("\nSenha invalida. Tente novamente.");
                                }
                            } while(controle);
                            printf("\nEscolha qual categoria se enquadra no seu restaurante: ");
                            Restaurantes(auxcat);
                            strcpy(r1.categoria, auxcat);
                            controle = inserirRest(lRest, r1);
                            system("cls");
                            if (controle == 0) {
                                printf("\nRestaurante cadastrado.");
                            } else {
                                printf("\nErro ao inserir restaurante.");
                            }
                            break;
                        default:
                            printf("\nOpcao invalida. Tente novamente.");
                    }
                } while(menurest1);
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.");
        }
    } while (menuprincp);
    //fim do programa
    printf("\n");
    system("pause");
    return 0;
}