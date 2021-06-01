#include<stdio.h>
#include<stdlib.h>

typedef struct Elemento
{
    int numero;
    struct Elemento *conjunto;
}Elemento;

int casos =1;
int religioes;

Elemento *encontraConjunto(Elemento *x)
{
    if(x->conjunto == x)
        return x;
    return encontraConjunto(x->conjunto);
}

Elemento *find(int chave, int tam, Elemento **vetor)
{
    for(int i=0; i<tam; i++)
    {
        if(vetor[i]->numero == chave)
            return vetor[i];
    }
    return NULL;
}

void Union(Elemento * a, Elemento * b)
{
    if(encontraConjunto(a)==encontraConjunto(b))
        return;
    else 
    {
        a = encontraConjunto(a);
        b = encontraConjunto(b);
        b->conjunto = a;
        religioes --; 
    }
}

int main()
{
    int m, n;
    


    while(1)
    {
        scanf("%d %d", &m, &n);
        //printf("m: %d, n: %d\n", m, n);
        if (m == 0 && n==0){break;}
        
        
        Elemento ** vetor = (Elemento **) malloc(n * sizeof(Elemento));
        
        //inicializando a lista com os elementos
        for(int i = 0; i<m; i++)
        {
            Elemento * elemTemp = (Elemento *) malloc(sizeof(Elemento));
            elemTemp->numero = i +1;
            elemTemp->conjunto = elemTemp; //cada elemento comeca no seu proprio conjunto
            vetor[i]=elemTemp;
        }
        religioes = m; // começamos com a maior quant de religioes possiveis

        for(int i =0; i<n; i++)
        {
            
            int a, b;
            scanf("%d %d", &a, &b); //estudantes a e b
            Union(find(a, m, vetor), find(b, m, vetor));
        }
        printf("Case %d: %d\n", casos++, religioes);
    }
    
    return 0;

}