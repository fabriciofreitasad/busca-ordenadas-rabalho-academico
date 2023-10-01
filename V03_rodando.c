#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <time.h>

void preencherArray(int lista[],int tamanho){
    for (int i = 0; i < tamanho; i++){
        lista[i] = rand();
    }
}

void imprimirListaDezPrimerios(int lista[],int tamanho){
    int maxPrint = 10;

    printf("\n\t# Primeiros %d elementos: #\n ", maxPrint);
    for (int i = 0; i < maxPrint; i++){
        printf("%d ", lista[i]);
    }

    if (tamanho > maxPrint * 2){
        printf("...\n");
        printf("\n\t# Ultimos %d elementos: #\n ", maxPrint);
        for (int i = tamanho - maxPrint; i < tamanho; i++){
            printf("%d ", lista[i]);
        }
    }
    printf("\n");
}

void bubbleSort(int lista[],int tamanho){
    int i,j,aux;
    for ( i = 0; i < tamanho - 1; i++){
        for ( j = 0; j < tamanho - i - 1; j++){
            if (lista[j] > lista[j + 1]){
                // Trocar os elementos
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

void inserttionSort(int lista[],int tamanho){
    int i, j, aux;

    for(i=0; i<tamanho-1; i++){
        if(lista[i] > lista[i+1]){
            aux = lista[i+1];
            lista[i+1] = lista[i];
            lista[i]=aux;
            j=i-1;
            while(j>=0){
                if(aux<lista[j]){
                    lista[j+1]= lista[j];
                    lista[j]=aux;
                }
                else{
                    break;
                }
                j=j-1;
            }
        }
    }
}

void selectionSort(int lista[],int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (lista[j] < lista[indiceMenor]) {
                indiceMenor = j;
            }
        }
        int temp = lista[i];
        lista[i] = lista[indiceMenor];
        lista[indiceMenor] = temp;
    }
}

void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

void quick_sort(int vetor[], int inicio, int fim){

    int pivo, esq, dir, meio, aux;
    esq = inicio;
    dir = fim;

    meio =  (int) ((esq + dir) / 2);
    pivo = vetor[meio];

    while(dir > esq){

        while(vetor[esq] < pivo){
            esq = esq + 1;
        }

        while(vetor[dir] > pivo){
            dir = dir - 1;
        }

        if(esq <= dir){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;

            esq = esq + 1;
            dir = dir - 1;

        }

    }
    if(inicio < dir){
        quick_sort(vetor, inicio, dir);
    }
    if(esq < fim){
         quick_sort(vetor, esq, fim);
    }
}


void shell_sort(int vetor[],int tamanho){
    int i, j, atual;
    int h = 1;

    while(h < tamanho){
        h = 3*h+1;
    }
    while(h > 1){
        h = h / 3;
        for(i = h; i < tamanho; i++){
            atual = vetor[i];
            j = i - h;
            while( (j >=0) && (atual < vetor[j])){
                vetor[j + h] = vetor[j];

                j = j - h;
            }
            vetor[j + h] = atual;
        }
    }
}

void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);


  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}


// Função principal
int main(){
    setlocale(LC_ALL,"");
    int tamanho =100000;
    int opcao;
    int lista[tamanho];
    int i;
    clock_t inicio, fim;
    double tempo;

    srand(time(NULL));

    do{
        printf("\n");
        printf("(1) Preencher a lista com numeros aleatorios\n");
        printf("(2) Ordenar a lista pelo metodo Bubble Sort\n");
        printf("(3) Ordenar a lista pelo metodo Insertion Sort\n");
        printf("(4) Ordenar a lista pelo metodo Selection Sort\n");
        printf("(5) Ordenar a lista pelo metodo Heap Sort\n");
        printf("(6) Ordenar a lista pelo metodo Quick Sort\n");
        printf("(7) Ordenar a lista pelo metodo Merge Sort\n");
        printf("(8) Ordenar a lista pelo metodo Shell Sort\n");
        printf("(9) Imprimir o lista\n");
        printf("(0) SAIR\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            inicio = clock();
            preencherArray(lista,tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto: [## %f ##] segundos **\n ", tempo);
            printf("\n#######################################################################\n");
            break;

        case 2:
            inicio = clock();
            bubbleSort(lista,tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para Bubble Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 3:
            inicio = clock();
            inserttionSort(lista,tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para Insertion Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 4:
            inicio = clock();
            selectionSort(lista,tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para selection Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 5:
            inicio = clock();
            heapsort(lista,tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para heap Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 6:
            inicio = clock();
            quick_sort(lista, 0, tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para Quick Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 7:
            inicio = clock();
            mergesort(lista, tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para Merge Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 8:
            inicio = clock();
            shell_sort(lista,tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\n\t** Tempo gasto para Shell Sort: [## %f ##] segundos **\n ", tempo);
            imprimirListaDezPrimerios(lista,tamanho);
            printf("\n#######################################################################\n");
            break;

        case 9:
            imprimirListaDezPrimerios(lista,tamanho);
            break;

        default:
            printf("\n\tOpção Inválida.\n");
        }
    }
    while (opcao != 0);

    return 0;
}
