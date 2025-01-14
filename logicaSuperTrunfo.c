#include <stdio.h> // biblioteca base
#include <locale.h> // biblioteca para gerenciar inputs de float com . ou ,
#include <string.h> // biblioteca para gerenciar mais facilmente strings, vendo que C nao possui strings
#include <ctype.h> // biblioteca para criar um typedef struct para base da carta

typedef struct //base da carta com todas as informações independente de quantas cartas serao necessarias
{
    char codigo[3];
    int popul;
    float area;
    float PIB;
    int ptturis;
    char nome [20];
    char estado [20];
    float PIBcapita;
    float denspopul;
} Carta; // nome do typedef "Carta"

int main(void) {

    setlocale(LC_ALL, "C"); // padronizando o input de floats por . Ex: 150.1

    Carta cartas[16]; // uma array de cartas usando a estrutura do typedef "Carta" com numero maximo de 16 cartas
    int carta_atual = 0; // começando com o primeiro indice do array

    char carta; // a letra A,B,C ou D da carta
    int numero; // o numero de 1 a 4 da carta

    while (1) //loop infinito para manter as perguntas repetidas a nao ser que o usuario deseje parar de cadastrar cartas
    {
        if(carta_atual >= 16) // caso chegue no limite de cartas, impede uma 17ºa carta de entrar
        {
            printf("Todas as cartas foram registradas\n");
            break;
        }

        printf("Bem vindo ao Cadastro de cartas do SuperTrunfo!\n Por favor, separe as seguintes informações sobre a cidade desejada:\n nome, população, area, PIB, quantidade de pontos turisticos.\n");
    //introdução e instruções ao usuario
    printf("Qual carta gostaria de cadastrar primeiro?\n");
    printf("São Paulo - digite -A-\n");
    printf("Minas Gerais - digite -B-\n");
    printf("Mato Grosso - digite -C-\n");
    printf("Rio de Janeiro - digite -D-\n");

    scanf("%c",&carta);
    carta = toupper(carta);
    while ((getchar()) != '\n'); //limpar o buffer para evitar erros de entrada por \n
    printf("%c\n",carta);

    if (carta < 'A' || carta > 'D') //impede outra letra a nao ser A,B,C ou D de ser usada para cadastro
    {
            printf("Carta inválida!\n");
            continue;
    }

    printf("Agora escolha um número de 1 a 4 para cadastrar sua carta %c\n",carta);
    scanf("%d",&numero);
    printf("%d\n",numero);

    if (numero < 1 || numero > 4) //mesma coisa porem com numeros de 1 a 4
    {
            printf("Número inválido!\n");
            continue;
        }
    Carta novaCarta;//um novo typedef que sera usado como a primeira carta e vai receber as informações de input dos dados das cidades do usuario
    snprintf(novaCarta.codigo, 3, "%c%d", carta, numero);

    if (carta == 'A') strcpy(novaCarta.estado, "São Paulo") ;
        else if (carta == 'B') strcpy(novaCarta.estado, "Minas Gerais");
        else if (carta == 'C') strcpy(novaCarta.estado, "Mato Grosso");
        else if (carta == 'D') strcpy(novaCarta.estado, "Rio de Janeiro");

    printf("Ok, agora vamos registrar as informações dentro da carta %s\n", novaCarta.codigo);
    printf("Qual o nome dessa cidade?\n"); // nome da cidade separado ja dentro do typedef
    scanf("%s",&novaCarta.nome);

    printf("Qual a população de %s?\n",novaCarta.nome); // mesma coisa, população
    scanf("%d",&novaCarta.popul);

    printf("E qual a area (em m²) de %s?\n",novaCarta.nome); // mesma coisa, area
    scanf("%f",&novaCarta.area);

    printf("E qual o PIB de %s?\n",novaCarta.nome); // mesma coisa PIB
    scanf("%f",&novaCarta.PIB);

    printf("Quantos pontos turisticos tem a cidade de %s? (digite 0 se não houver nenhum)\n",novaCarta.nome); // mesma coisa, pontos turisticos
    scanf("%d",&novaCarta.ptturis);

    printf("Perfeito, temos tudo que precisamos! suas informações ficarão salvas da seguinte maneira:\n"); // resumo para o usuario de tudo que foi passado
    printf("A carta %s do estado de %s representa a cidade de %s\n",novaCarta.codigo, novaCarta.estado, novaCarta.nome);
    printf("Que tem as seguintes caracteristicas:\n");
    printf("Uma área de %.2fm²\n Com uma população de %d habitantes\n Um PIB de R$%.2f\n Com %d pontos turisticos\n",novaCarta.area,novaCarta.popul,novaCarta.PIB,novaCarta.ptturis);
    novaCarta.PIBcapita = novaCarta.PIB / (float)novaCarta.popul; //calculo do pib per capita
    printf("o PIB per capita é de R$%.2f\n",novaCarta.PIBcapita);
    novaCarta.denspopul = (float)novaCarta.popul / novaCarta.area; // calculo da densidade populacional
    printf("A densidade populacional é de %.2f\n",novaCarta.denspopul);
    printf("Incrível! Parece uma boa cidade para se morar!\n");
    printf("Seu código para comparar essa carta é %d\n",carta_atual);//codigo a ser usado para comparar as cartas mais abaixo

    cartas[carta_atual++] = novaCarta;//atualiza a array cartas para preparar para receber a proxima carta

    printf("Deseja cadastrar outra carta? (s/n):");
    char resposta;
    while ((getchar()) != '\n'); //limpeza do buffer
    scanf("%c",&resposta);

    if(tolower(resposta) != 's')//caracteres para minusculos, caso nao queira cadastrar, quebra o loop inicial e passa para a proxima parte
    {
        break;
    }

    } // fim do while loop

    printf("Essas são as cartas cadastradas no total:\n"); //resumo de todas as cartas cadastradas

    for(int i = 0; i < carta_atual; i++) //for loop para pegar todas os struct typedefs da array cartas
    {
        Carta c = cartas[i]; // da um nome para a carta puxada e printa ela abaixo, repete o processo até ter puxado todos os numeros da array
        printf("Código: %s | Estado: %s | Cidade: %s | População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d\n",
               c.codigo, c.estado, c.nome, c.popul, c.area, c.PIB, c.ptturis);
    }

    while (1) // loop para poder comparar as cartas varias vezes
    {
        printf("Deseja comparar cartas? (s/n):");
        while ((getchar()) != '\n');
        char resposta;
        scanf("%c",&resposta);

        if(tolower(resposta) != 's')
    {
        break; // quebra o while loop acima caso nao quiser continuar comparando cartas e encerra o programa.
    }
        printf("Ok, qual o código da primeira carta para comparar?\n");//codigo de comparacao da primeira carta
        int compararx;
        scanf("%d",&compararx);

        printf("Ok, estaremos comparando a carta de código comparador %d com qual carta?\n",compararx);//codigo de comparacao da segunda carta
        int comparary;
        scanf("%d",&comparary);

        int cidadex = 0; // integers que usarei pra poder fazer uma melhor de 3 entre as comparações 
        int cidadey = 0;

        while (1)
        {
            printf("Deseja comparar qual propriedade?\n"); //escolhe qual tipo de comparação vai ser feita
        printf("Densidade Populacional - digite A\n");
        printf("PIB per Capita - digite B\n");
        printf("Super Poder (soma de todas as propriedades) - digite C\n");
        printf("População - digite D\n");
        printf("Pontos Turísticos - digite E\n");
        char comparar;
        while ((getchar()) != '\n');
        scanf("%c",&comparar);
        comparar = toupper(comparar);
        
        if(comparar == 'A')//se "A" a comparação sera feita por densidade populacional
        {
            if (cartas[compararx].denspopul > cartas[comparary].denspopul) // se positivo x perde e y ganha
        {
            printf("A cidade de %s tem uma densidade populacional menor, logo melhor para se viver!\n vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
            cidadex = cidadex +1;
        }
        else // o contrario, vitoria do x
        {
            printf("A cidade de %s tem uma densidade populacional menor, logo melhor para se viver!\n vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
            cidadey = cidadey +1;        
        }
        }
        else if(comparar == 'B') // comparação feita por pib per capita
        {
            if(cartas[compararx].PIBcapita > cartas[comparary].PIBcapita) //vitoria do x
            {
                printf("A cidade de %s tem um PIB per capita maior, logo melhor para se viver!\n Vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
                cidadex = cidadex +1;
            }
            else // caso contrario vitoria do y
            {
                printf("A cidade de %s tem um PIB per capita maior, logo melhor para se viver!\n Vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
                cidadey = cidadey +1;
            }
        }
        else if(comparar == 'C') // comparação por numero total
        {
            float superPoder1 = (cartas[compararx].area + cartas[compararx].PIB + (float)cartas[compararx].popul) * (cartas[compararx].ptturis + 1); // coloquei para fazer vezes o numero de pontos turisticos para tentar balancear as cartas e deixar as cartas que tem menor população e menor pib, porem com muitos pontos turisticos terem uma chance de ganhar
            float superPoder2 = (cartas[comparary].area + cartas[comparary].PIB + (float)cartas[comparary].popul) * (cartas[comparary].ptturis + 1); // ainda assim é necessario aumentar para +1 para nao multiplicar por 0 no caso de nao ter pontos turisticos
            if(superPoder1 > superPoder2) // vitoria do x
            {
                printf("A cidade de %s tem um SuperPoder de %.2f que é maior, logo ganha no SuperTrunfo!\n Vitória para %s",cartas[compararx].nome,superPoder1,cartas[compararx].nome);
                cidadex = cidadex +1;
            }
            else // vitoria do y
            {
                printf("A cidade de %s tem um SuperPoder de %.2f que é maior, logo ganha no SuperTrunfo!\n Vitória para %s",cartas[comparary].nome,superPoder2,cartas[comparary].nome);
                cidadey = cidadey +1;
            }
        }
        else if(comparar == 'D')
        {

            if(cartas[compararx].popul > cartas[comparary].popul)
            {
                printf("A cidade de %s tem uma população maior, logo ganhou no Super Trunfo!\n Vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
                cidadex = cidadex +1;
            }
            else
            {
                printf("A cidade de %s tem uma população maior, logo ganhou no Super Trunfo!\n Vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
                cidadey = cidadey +1;
            }

        }
        else if(comparar == 'E')
        {

            if(cartas[compararx].ptturis > cartas[comparary].ptturis)
            {
                printf("A cidade de %s tem mais pontos turísticos, logo ganhou no Super Trunfo!\n Vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
                cidadex = cidadex +1;
            }
            else
            {
                printf("A cidade de %s tem mais pontos turísticos, logo ganhou no Super Trunfo!\n Vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
                cidadey = cidadey +1;
            }

        }
        else if(comparar == 'F')
        {

            if(cartas[compararx].area > cartas[comparary].area)
            {
                printf("A cidade de %s tem maior area, logo ganhou no Super Trunfo!\n Vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
                cidadex = cidadex +1;
            }
            else
            {
                printf("A cidade de %s tem maior area, logo ganhou no Super Trunfo!\n Vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
                cidadey = cidadey +1;
            }

        }
        else
        {
            printf("Letra Invalida\n");
        }
        if(cidadex >=2)
        {
            printf("A cidade %s ganhou na melhor de 3!",cartas[compararx].nome);
            cidadex =0;
            cidadey =0;
            break;
        }
        else if(cidadey >=2)
        {
            printf("A cidade %s ganhou na melhor de 3!",cartas[comparary].nome);
            cidadex =0; //resetando os integers para poder recomeçar a melhor de 3
            cidadey =0;
            break;
        }
        printf("Escolha um segundo atributo para comparar também!"); // volta o loop para escolher uma segunda opção
        }
    }


    return 0;

}
