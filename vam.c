#include <stdio.h>
typedef struct Alunos
{
    char nome [50];
    char regiao;
    int custo;
} Alunos;

void bubbleSortCusto(Alunos *alunos, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (alunos[j].custo > alunos[j + 1].custo)
            {
                Alunos tmp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = tmp;
            }
        }
    }
}

void bubbleSortRegiao(Alunos *alunos, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (alunos[j].custo == alunos[j + 1].custo)
            {
                if (alunos[j].regiao > alunos[j + 1].regiao)
                {
                    Alunos tmp = alunos[j];
                    alunos[j] = alunos[j + 1];
                    alunos[j + 1] = tmp;
                }
            }
        }
    }
}
void bubbleSortNome(Alunos *alunos, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (alunos[j].custo == alunos[j + 1].custo && alunos[j].regiao == alunos[j + 1].regiao)
            {
                if (alunos[j].nome > alunos[j + 1].nome)
                {
                    Alunos tmp = alunos[j];
                    alunos[j] = alunos[j + 1];
                    alunos[j + 1] = tmp;
                }
            }
        }
    }
}
//mostar alunos
void mostrar(Alunos *alunos, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", alunos[i].nome);
    }
}


int main (void){
    int q;
    scanf("%d", &q);
    Alunos alunos[q];
    for (int i = 0; i < q; i++)
    {
        scanf("%s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].custo);
    }
    //printf("Nao ordenados\n");
    //mostrar(alunos, q);
    bubbleSortCusto(alunos, q);
    bubbleSortRegiao(alunos, q);
    bubbleSortNome(alunos, q);
    //printf("Ordenados\n");
    mostrar(alunos, q);
    return 0;
}