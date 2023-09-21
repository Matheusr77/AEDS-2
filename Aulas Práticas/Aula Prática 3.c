#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[57];
    int matricula;
    float n1;
    float n2;
    float n3;
    float media;
};

int buscaSequencial(int valor, int *vetor, int tamanho)
{

    int i = tamanho;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == valor)
        {
            return i;
        }
    }

    return -1;
}

int buscaSequencialPorMatricula(struct aluno alunos[], int num_alunos, int matricula)
{
    for (int i = 0; i < num_alunos; i++)
    {
        if (alunos[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;
}

void preencherVetor(int *vetor, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite um valor para a casa %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }
}

void ordenacao(int vetor[], int n)
{

    int aux;
    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (vetor[i + 1] < vetor[i])
            {
                // Trocar vetor[i] com vetor[i+1]
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

int buscaBinaria(int valor, int vetor[], int tamanho)
{

    int i;
    int esq = 0;
    int dir = tamanho - 1;

    do
    {
        i = (esq + dir) / 2;
        if (valor > vetor[i])
        {
            esq = i + 1;
        }

        else
        {
            dir = i - 1;
        }

    } while (valor != vetor[i] && esq <= dir);

    if (valor == vetor[i])
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int buscaBinariaPorMatricula(int matricula, struct aluno alunos[], int num_alunos)
{
    int esq = 0;
    int dir = num_alunos - 1;
    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        if (alunos[meio].matricula == matricula)
        {
            return meio;
        }
        else if (alunos[meio].matricula < matricula)
        {
            esq = meio + 1;
        }
        else
        {
            dir = meio - 1;
        }
    }
    return -1;
}

void imprimeAluno(struct aluno aluno)
{
    printf("\nNome: %s", aluno.nome);
    printf("\nMatricula: %d", aluno.matricula);
    printf("\nNota 1: %.2f", aluno.n1);
    printf("\nNota 2: %.2f", aluno.n2);
    printf("\nNota 3: %.2f", aluno.n3);
    printf("\nMedia: %.2f\n", aluno.media);
}

int main()
{

    int valor;
    int matricula;
    int tamanho;
    int *vetor;
    int escolha;
    int atv;

    printf("Você deseja ver a atividade 1 ou 2: ");
    scanf("%d", &atv);

    if (atv == 1)
    {

        printf("\n\nO que você deseja fazer:\n\n[1] Busca sequencial no vetor\n[2] Busca binária no vetor\n[3] Preencher dados de alunos\n\nEscolha: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:

            printf("\n\nQual o tamanho do vetor: ");
            scanf("%d", &tamanho);

            vetor = (int *)malloc(tamanho * sizeof(int));

            preencherVetor(vetor, tamanho);

            printf("\nQual o valor você deseja procurar: ");
            scanf("%d", &valor);

            int resultado = buscaSequencial(valor, vetor, tamanho);

            if (resultado == -1)
            {
                printf("\nNão foi encontrado nenhum valor.");
            }

            else
            {
                printf("\nO valor foi encontrado na posição: %d", resultado);
            }

            break;

        case 2:

            printf("Qual o tamanho do vetor: ");
            scanf("%d", &tamanho);

            vetor = (int *)malloc(tamanho * sizeof(int));

            preencherVetor(vetor, tamanho);

            ordenacao(vetor, tamanho);

            printf("\nQual o valor você deseja procurar: ");
            scanf("%d", &valor);

            int resultado_2 = buscaBinaria(valor, vetor, tamanho);

            if (resultado_2 == -1)
            {
                printf("\nNão foi encontrado nenhum valor.");
            }

            else
            {
                printf("\nO valor foi encontrado na posição: %d", resultado_2);
            }

            break;

        case 3:

            int num_alunos;

            printf("Quantos alunos você deseja cadastrar: ");
            scanf("%d", &num_alunos);

            struct aluno *alunos = (struct aluno *)malloc(num_alunos * sizeof(struct aluno));

            setbuf(stdin, NULL);

            for (int i = 0; i < num_alunos; i++)
            {
                setbuf(stdin, NULL);

                printf("\n\nDigite o nome do aluno %s: ", i + 1);
                fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

                printf("\nDigite a matricula do aluno %d: ", i + 1);
                scanf("%d", &alunos[i].matricula);

                printf("\nDigite a nota 1 do aluno %d:", i + 1);
                scanf("%f", &alunos[i].n1);

                printf("\nDigite a nota 2 do aluno %d:", i + 1);
                scanf("%f", &alunos[i].n2);

                printf("\nDigite a nota 3 do aluno %d:", i + 1);
                scanf("%f", &alunos[i].n3);

                alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
            }

            break;

        default:

            printf("Escolha inválida.\n");

            break;
        }

        return 0;
    }

    else if (atv == 2)
    {
        printf("\n\nPara a atividade 2 primeiramente você deve preencher a struct");

        int num_alunos;

        printf("\n\nQuantos alunos você deseja cadastrar: ");
        scanf("%d", &num_alunos);

        struct aluno *alunos = (struct aluno *)malloc(num_alunos * sizeof(struct aluno));

        setbuf(stdin, NULL);

        for (int i = 0; i < num_alunos; i++)
        {
            setbuf(stdin, NULL);

            printf("\n\nDigite o nome do aluno %d: ", i + 1);
            fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

            printf("Digite a matricula do aluno %d: ", i + 1);
            scanf("%d", &alunos[i].matricula);

            printf("Digite a nota 1 do aluno %d: ", i + 1);
            scanf("%f", &alunos[i].n1);

            printf("Digite a nota 2 do aluno %d: ", i + 1);
            scanf("%f", &alunos[i].n2);

            printf("Digite a nota 3 do aluno %d: ", i + 1);
            scanf("%f", &alunos[i].n3);

            alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        }

        int escolha;
        do
        {
            printf("\n\nO que você deseja fazer:\n[1] Busca sequencial por matrícula\n[2] Busca binária por matrícula\n[3] Imprimir informações de um aluno\n[0] Sair\nEscolha: ");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                printf("\nQual o valor de matrícula você deseja procurar: ");
                scanf("%d", &matricula);

                int result = buscaSequencialPorMatricula(alunos, num_alunos, matricula);

                if (result == -1)
                {
                    printf("\nNão foi encontrado nenhum aluno com essa matrícula.");
                }
                else
                {
                    imprimeAluno(alunos[result]);
                }
                break;

            case 2:

                printf("\nQual o valor de matrícula você deseja procurar: ");
                scanf("%d", &matricula);

                int result_binaria = buscaBinariaPorMatricula(matricula, alunos, num_alunos);

                if (result_binaria == -1)
                {
                    printf("\nNão foi encontrado nenhum aluno com essa matrícula.");
                }
                else
                {
                    imprimeAluno(alunos[result_binaria]);
                }

                break;

            case 3:

                printf("\nDigite a matrícula do aluno que deseja imprimir: ");
                scanf("%d", &matricula);

                int alunoIndex = buscaSequencialPorMatricula(alunos, num_alunos, matricula);

                if (alunoIndex == -1)
                {
                    printf("\nAluno não encontrado.");
                }
                else
                {
                    imprimeAluno(alunos[alunoIndex]);
                }

                break;

            default:

                printf("Escolha inválida.\n");
                break;
            }
        } while (escolha != 0);
    }

    return 0;
}