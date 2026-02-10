#include <stdio.h>
#include <pthread.h>

#define SIZE 1000000
#define THREADS 4

int numeros[SIZE];
int resultados[THREADS];

void* soma_paralela(void* arg) {
  int id = *((int*) arg);
  //separa o início e o fim do array para que as threads façam a soma
  int start = id * (SIZE / THREADS);
  int end = (id + 1) * (SIZE / THREADS);
  //realiza a soma em si
  int soma = 0;
  for (int i = start; i < end; i++) {
    soma += numeros[i];
  }
  resultados[id] = soma;
  return NULL;
}

int main() {
  pthread_t threads[THREADS];
  for (int i = 0; i < SIZE; i++) {
    numeros[i] = i + 1; //cria o array de elementos
  }
  for (int i = 0; i < THREADS; i++) {
    pthread_create(&threads[i], NULL, soma_paralela, &i); //cria as threads para a soma paralela
  }
  for (int i = 0; i < THREADS; i++) {
    pthread_join(threads[i], NULL); //espera as threads terminarem a execução
  }
  int soma_total = 0;
  
  //faz a soma total 
  for (int i = 0; i < THREADS; i++) {
    soma_total += resultados[i]; 
  }
  printf("Soma total: %d\n", soma_total);
  return 0;
}
