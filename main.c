#include "Cliente.h"
#include "Restaurante.h"
#include "Pratos.h"
#include "Pedidos.h"
#include "Feedbacks.h"
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
    } while(op > 1 && op < 10);
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

int ConfirmaEmail(char *email) { //confirma se email tem @ e já existe na lista
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
    //if (cpf[11] != '-') return 1;
    //if (cpf[3] != '.' || cpf[7] != '.') return 1;
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

int ConfirmaId(int id) {
    return 0;
} //COMPLETAR ESSA FUNCAO DE ALGUM JEITO - MUDAR ID PARA CHAR?

int main () {
    int menuprincp, menucli1, menucli2, menurest1, menurest2;
    int controle, opcli, cod, opfeed;
    char auxcat[30], auxsenha[10];
    ListaC *lCli;
    ListaR *lRest;
    ListaP *lPrat;
    ListaF *lFeed;
    FilaPed *fPed; //TA DANDO PROBLEMA NO TAD DA FILA - CRIAR OUTRO PROJETO? TO FAZENDO ERRADO? PENSAR ALGUM JEITO
    lCli = criarCliente();
    lRest = criarRest();
    lPrat = criarP();
    lFeed = criarF();
    Cliente c1;
    Restaurante r1;
    Pratos p1;
    Feedback f1;
    Feedback f2 = {"0", "Nenhuma avaliacao ate o momento.", lCli, lRest, fPed};
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
                liberarmemoriaC(lCli);
                liberarmemoriaR(lRest);
                liberarmemoriaP(lPrat);
                liberarmemoriaF(lFeed);
                break;
            case 1: //parte do cliente
                do {
                    printf("\n\n-------- Area do cliente --------");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    printf("\n0. Retornar");
                    Opcao();
                    scanf("%d", &menucli1);
                    system("cls");
                    switch (menucli1) {
                        case 0: //saida do menu do cliente
                            break;
                        case 1: //tela de login do cliente
                            do {
                                printf("\nInsira seu email: ");
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
                                setbuf(stdin, NULL);
                                fgets(auxsenha, 9, stdin);
                                auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                controle = ConfirmaSenha(auxsenha);
                                if(controle){
                                    printf("\nSenha invalida. Tente novamente.");
                                } else if (strcmp(auxsenha, c1.senha)) {
                                    printf("\nSenha incorreta, digite novamente.");
                                    controle = 1;
                                }
                            }while(controle);
                            do { //inicio da funcionalidade com o cliente logado
                                system("cls");
                                printf("\n\n-------- %s, bem vindo(a) --------", c1.nome);
                                printf("\n0. Retornar");
                                printf("\n1. Opcoes de restaurantes");
                                printf("\n2. Historico de pedidos"); //FAZER QUANDO FILA DE PEDIDOS ESTIVER PRONTA
                                printf("\n3. Feedbacks");
                                printf("\n4. Excluir conta");
                                Opcao();
                                scanf("%d", &menucli2);
                                system("cls");
                                switch (menucli2) {
                                    case 0: break;
                                    case 1: //mostra restaurantes
                                    do {
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
                                            case 1:
                                                printf("\nDigite o numero da identificacao do restaurante: ");
                                                scanf("%d", &opcli);
                                                controle = achaRest(lRest, opcli, &r1);
                                                if (controle) {
                                                    printf("\nCodigo incorreto, digite novamente.");
                                                    opcli = 2;
                                                    break;
                                                } else {
                                                    do {
                                                        printf("\n-------- Menu --------");
                                                        mostrarPratos(r1.cardapio);
                                                        printf("\nDeseja fazer um pedido?");
                                                        printf("\n0. Nao, desejo retornar.");
                                                        printf("\n0. Sim, desejo pedir.");
                                                        Opcao();
                                                        scanf("%d", &opcli);
                                                        switch (opcli) {
                                                            case 0: //retorno a tela do cliente
                                                                break;
                                                            case 1: //pedido
                                                                printf("\nDigite o codigo do prato: ");
                                                                scanf("%d", &opcli);
                                                                controle = buscaPrato(r1.cardapio, opcli, &p1);
                                                                if (controle) {
                                                                    printf("\nOpcao invalida, digite novamente.");
                                                                    opcli = 2;
                                                                    break;
                                                                } else {
                                                                    //funcao inserir pedido
                                                                }
                                                        }
                                                        printf("\nPedir de novo?");
                                                        printf("\n0. Nao, desejo retornar.");
                                                        printf("\n1. Sim, desejo olhar os pratos novamente.");
                                                        Opcao();
                                                        scanf("%d", &opcli);
                                                    } while (opcli);
                                                }
                                        }
                                        printf("\nOlhar restaurantes novamente?");
                                        printf("\n0. Nao, desejo retornar.");
                                        printf("\n1. Sim, desejo olhar os restaurantes novamente.");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        system("cls");
                                    } while(opcli);
                                    break;
                                    case 2:
                                        //historico de pedidos e feedbacks de pedidos
                                    case 3: //feedbacks
                                        system("cls");
                                        printf("\n-------- Feedbacks dos estabelecimentos --------");
                                        printf("\nEscolha a categoria do restaurante que deseja consultar ou dar feedbacks.");
                                        Restaurantes(auxcat);
                                        printf("\nDeseja olhar a pagina de feedbacks ou avaliar algum restaurante?");
                                        printf("\n0. Nao, desejo retornar");
                                        printf("\n1. Olhar feedbacks");
                                        printf("\n2. Fazer um feedback");
                                        Opcao();
                                        scanf("%d", &opfeed);
                                        switch (opfeed) {
                                            case 0:
                                                break;
                                            case 1:
                                                system("cls");
                                                printf("\n-------- Restaurantes disponiveis --------");
                                                mostrarR(lRest, auxcat);
                                                printf("\nDigite o numero da identificacao do restaurante: ");
                                                scanf("%d", &opcli);
                                                controle = achaRest(lRest, opcli, &r1);
                                                if (controle) {
                                                    printf("\nCodigo incorreto, digite novamente.");
                                                    opcli = 2;
                                                    break;
                                                } else {
                                                    do { //mostrar feedbacks do restaurante escolhido
                                                        //TA DANDO ERRO -> TA FECHANDO O PROGRAMA -> PENSAR EM JEITO PARA RETORNAR AO MENU PRINCIPAL
                                                        system("cls");
                                                        printf("\n-------- Feedbacks --------");
                                                        mostrarFeedRest(lFeed, f1);
                                                        printf("\nVolte ao pressionar qualquer tecla.");
                                                        setbuf(stdin, NULL);
                                                        fgetc(stdin); //recebe qualquer caractere do teclado
                                                        system("cls");
                                                        menucli2 = 0;
                                                    } while(opcli);
                                                }
                                        }
                                    case 4: //excluir conta
                                        printf("\n-------- Exclusao da conta --------");
                                        printf("\n %s, deseja excluir sua conta?", c1.nome);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        while (opcli) {
                                            printf("\nSenha necessaria para delecao de conta, digite-a: ");
                                            fgets(auxsenha, 9, stdin);
                                            auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                            if (strcmp(auxsenha, c1.senha) == 0) {
                                                controle = removerCliente(lCli, c1);
                                                if (controle) {
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
                            //fim da funcionalidade com o cliente logado
                            //registro do cliente
                        case 2:
                            system("cls");
                            printf("-------- Dados --------\n");
                            printf("\nInsira seu nome: ");
                            setbuf(stdin, NULL);
                            fgets(c1.nome, 50, stdin);
                            c1.nome[strcspn(c1.nome, "\n")] = '\0';
                            do {
                                printf("\nFormato do CPF: XXX.XXX.XXX-XX");
                                printf("\nDigite seu CPF: ");
                                fflush(stdin);
                                fgets(c1.cpf, 15, stdin);
                                c1.cpf[strcspn(c1.cpf, "\n")] = '\0';
                                controle = ConfirmaCPF(c1.cpf);
                                if (controle) {
                                    printf("\nCPF invalido, tente novamente.");
                                } else if (procuraCliente(lCli, c1.cpf) == 0) {
                                    printf("\nCPF existente em alguma conta, tente novamente.");
                                    controle = 1;
                                }
                            } while(controle);
                            do {
                                //TA APARECENDO COMO SE EU TIVESSE DIGITADO O EMAIL E TIVESSE DADO ERRADO
                                printf("\nInsira seu email: ");
                                fflush(stdin);
                                fgets(c1.email, 50, stdin);
                                controle = ConfirmaEmail(c1.email);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                if (controle) {
                                    printf("\nEmail invalido, tente novamente.");
                                } else if(buscaEmailCliente(lCli, c1.email) == 0) {
                                    printf("\nEmail ja cadastrado, tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha com numeros e letras de 8 caracteres: ");
                                fgets(c1.senha, 9, stdin);
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
            case 2: //tela do restaurante
                do {
                    printf("\n\n-------- Area do prestador de servico --------");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    printf("\n0. Retornar");
                    Opcao();
                    scanf("%d", &menurest1);
                    system("cls");
                    switch (menurest1) {
                        case 0: //saida do menu do restaurante
                            break;
                        case 1: //login restaurante
                            do {
                                printf("\nInsira o email: ");
                                setbuf(stdin, NULL);
                                fgets(r1.email, 30, stdin);
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
                                fgets(auxsenha, 9, stdin);
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
                            //inicio da funcionalidade com restaurante logado
                            do { //menu de funcionalidades
                                printf("\n\n-------- %s, bem vindo(a) --------", r1.nomeRest);
                                printf("\n0. Retornar");
                                printf("\n1. Ver meu cardapio");
                                printf("\n2. Pedidos em minha loja"); //FAZER QUANDO EU FIZER A FILA DE PEDIDOS
                                printf("\n3. Cadastrar prato");
                                printf("\n4. Alteracao de prato");
                                printf("\n5. Excluir prato");
                                printf("\n6. Feedbacks da minha loja");
                                printf("\n7. Excluir conta");
                                Opcao();
                                scanf("%d", &menurest2);
                                system("cls");
                                switch (menurest2) {
                                    case 0: //retornar a tela principal
                                        break;
                                    case 1: //mostra cardapio
                                    // TA DANDO ERRO, PENSAR EM OUTRO JEITO DE VOLTAR AO MENU PRINCIPAL SEM QUE ENCERRE O PROGRAMA
                                        printf("\n-------- Meu cardapio --------");
                                        mostrarPratos(r1.cardapio);
                                        printf("\nVolte ao pressionar qualquer tecla.");
                                        fflush(stdin);
                                        fgetc(stdin); //recebe qualquer caractere do teclado
                                        system("cls");
                                        break;
                                    case 2: //fazer quando tiver fila pedidos
                                        printf("-------- Pedidos da loja --------");
                                    case 3: //cadastrar prato
                                        printf("\n-------- Cadastro de prato --------");
                                        printf("\nNome do prato: ");
                                        setbuf(stdin, NULL);
                                        fgets(p1.nome, 30, stdin);
                                        p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                        printf("\nPreco do prato: ");
                                        scanf("%f", &p1.preco);
                                        printf("\nIngredientes do prato: ");
                                        setbuf(stdin, NULL);
                                        fgets(p1.ingredientes, 300, stdin);
                                        p1.ingredientes[strcspn(p1.ingredientes, "\n")] = '\0';
                                        printf("\nNumero de identificacao (inteiro): ");
                                        scanf("%d", &p1.codigo);
                                        controle = inserirPrato(lPrat, p1);
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
                                        controle = buscaPrato(lPrat, cod, &p1);
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
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo nome: ");
                                                    setbuf(stdin, NULL);
                                                    fgets(p1.nome, 30, stdin);
                                                    p1.nome[strcspn(p1.nome, "\n")] = '\0';
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
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo preco: ");
                                                    scanf("%f", &p1.preco);
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
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovos ingredientes: ");
                                                    setbuf(stdin, NULL);
                                                    fgets(p1.ingredientes, 300, stdin);
                                                    p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        do {
                                            printf("\nCodigo: %d", p1.codigo);
                                            printf("\nAlterar codigo?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo codigo: ");
                                                    scanf("%d", &p1.codigo);
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
                                    case 5:
                                        printf("\n-------- Exclusao de pratos --------");
                                        printf("\nDigite o codigo do prato: ");
                                        scanf("%d", &cod);
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
                                    case 6: //fazer parte de feedbacks
                                        printf("\n");
                                    case 7:
                                        printf("\n-------- Exclusao de conta de prestador de servico --------");
                                        printf("\nDeseja excluir sua conta, %s?", r1.nomeRest);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        while (opcli) {
                                            printf("\nSenha necessaria para exclusao. Digite-a: ");
                                            fgets(auxsenha, 9, stdin);
                                            auxsenha[strcspn(auxsenha, "\n")] = '\0';
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
                            break; //fim das funcionalidades com restaurante logado
                        case 2: //registro do restaurante
                            printf("\n-------- Registro de restaurante --------");
                            printf("\nNome do restaurante: ");
                            setbuf(stdin, NULL);
                            fgets(r1.nomeRest, 29, stdin);
                            r1.nomeRest[strcspn(r1.nomeRest, "\n")] = '\0';
                            do{
                                printf("\nFormato de digitacao do CNPJ: XX.XXX.XXX/XXXX-XX");
                                printf("\nCNPJ do restaurante: ");
                                setbuf(stdin, NULL);
                                fgets(r1.CNPJ, 18, stdin);
                                controle = ConfirmaCNPJ(r1.CNPJ);
                                if (controle) {
                                    printf("\nCNPJ no formato invalido. Tente novamente.");
                                } else if (buscaItemRest(lRest, r1.CNPJ) == 0) {
                                    controle = 1;
                                    printf("\nCNPJ ja existente. Tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nEmail: ");
                                // TA DANDO ERRO - TA APARECENDO COMO SE EU TIVESSE DIGITADO ALGUM EMAIL ANTES
                                fflush(stdin);
                                fgets(r1.email, 30, stdin);
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
                                printf("\nIdentificacao: ");
                                scanf("%d", &r1.identificacao);
                                controle = ConfirmaId(r1.identificacao);
                                if (controle) {
                                    printf("\nIdentificacao invalida. Tente novamente.");
                                } else if(achaRestId(lRest, r1.identificacao) == 0) {
                                    controle = 1;
                                    printf("\nIdentificacao ja pertence a outro restaurante. Tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha com letras e numeros de 8 caracteres: ");
                                setbuf(stdin, NULL);
                                fgets(r1.senha, 9, stdin);
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
                                inserirFeed(lFeed, f2); //insere feedback padrao de 0 feedbacks
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
    system("pause");
    return 0;
}