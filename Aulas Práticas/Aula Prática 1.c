#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pontos
{
    int x;
    int y;

} pontos;

void InicioParametros(pontos *p, int x, int y)
{
    p->x = x;
    p->y = y;
}

void LeituraParametros(pontos *p)
{

    printf("Digite o ponto X:");
    scanf("%d", &p->x);
    printf("Digite o ponto y:");
    scanf("%d", &p->y);
}

int AnalisarQuadrante(pontos p)
{
    if ((p.x > 0) && (p.y > 0))
    {
        return 1;
    }
    else if ((p.x < 0) && (p.y > 0))
    {
        return 2;
    }
    else if ((p.x < 0) && (p.y < 0))
    {
        return 3;
    }
    else if ((p.x > 0) && (p.y < 0))
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

int VerificarQuadrante(pontos p, int quad)
{
    if (AnalisarQuadrante(p) == 1 && quad == 1)
    {
        return 1;
    }
    else if (AnalisarQuadrante(p) == 2 && quad == 2)
    {
        return 2;
    }
    else if (AnalisarQuadrante(p) == 3 && quad == 3)
    {
        return 3;
    }
    else if (AnalisarQuadrante(p) == 4 && quad == 4)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

void AlterarValores(pontos *p, int x1, int y1)
{
    p->x = &x1;
    p->y = &y1;
}

float distancia(pontos p1, pontos p2)
{
    float distancia;
    distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distancia;
}

int MaiorPonto(pontos p)
{
    if (p.x > p.y)
    {
        return p.x;
    }
    else if (p.x < p.y)
    {
        return p.y;
    }
    else
    {
        return 0;
    }
}

int main()
{

    pontos ponto1, ponto2;
    int opcao, quadranteDesejado;

    while (1)
    {
        printf("\nMenu:\n");
        printf("\n[1] Iniciar parâmetros do ponto\n");
        printf("[2] Ler parâmetros do ponto\n");
        printf("[3] Analisar quadrante de um ponto\n");
        printf("[4] Verificar se um ponto está em um quadrante\n");
        printf("[5] Alterar valores de um ponto\n");
        printf("[6] Calcular distância entre dois pontos\n");
        printf("[7] Encontrar a maior coordenada de um ponto\n");
        printf("[8] Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite os valores para iniciar o ponto 1:\n");
            int x1, y1;
            scanf("%d %d", &x1, &y1);
            InicioParametros(&ponto1, x1, y1);
            break;
        case 2:
            printf("Digite os valores para os pontos:\n");
            LeituraParametros(&ponto1);
            break;
        case 3:
            printf("Quadrante do ponto 1: %d\n", AnalisarQuadrante(ponto1));
            printf("Quadrante do ponto 2: %d\n", AnalisarQuadrante(ponto2));
            break;
        case 4:
            printf("Digite o número do quadrante desejado (1 a 4): ");
            scanf("%d", &quadranteDesejado);
            if (VerificarQuadrante(ponto1, quadranteDesejado))
            {
                printf("Os pontos está no quadrante %d\n", quadranteDesejado);
            }
            else
            {
                printf("Os pontos  NÃO está no quadrante %d\n", quadranteDesejado);
            }
            break;
        case 5:
            printf("Digite os novos valores para o ponto 2:\n");
            int novoX, novoY;
            scanf("%d %d", &novoX, &novoY);
            AlterarValores(&ponto2, novoX, novoY);
            break;
        case 6:
            printf("Distância entre os pontos: %.2f\n", distancia(ponto1, ponto2));
            break;
        case 7:
            printf("Maior coordenada dos pontos: %d\n", MaiorPonto(ponto2));
            break;
        case 8:
            printf("Encerrando o programa.\n");
            return 0;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}