#include <stdio.h>
#include <pthread.h>

#define THREADS 4

pthread_barrier_t barreira;

void* imprimir_numeros(void* arg) {
  int id = *((int*) arg);
  printf("Thread %d iniciando execução\n", id);
  for (int i = 1; i <= 10; i++) {
    printf("Thread %d: %d\n", id, i);
  }
  printf("Thread %d esperando outras threads na barreira\n", id);
  //as threads executam eesperam outras threads na barreira
  pthread_barrier_wait(&barreira);
  //quando todas chegarem as barreira elas são liberadas
  printf("Thread %d continuando execução após barreira\n", id);
  return NULL;
}

int main() {
  pthread_t threads[THREADS];
  pthread_barrier_init(&barreira, NULL, THREADS); //inicia a barreira
  for (int i = 0; i < THREADS; i++) {
    pthread_create(&threads[i], NULL, imprimir_numeros, &i); //cria as threads e passa as informações para elas
  }
  for (int i = 0; i < THREADS; i++) {
    pthread_join(threads[i], NULL); //espera as threads terminarem suas execuções
  }
  pthread_barrier_destroy(&barreira); //destroi a barreira
  return 0;
}
