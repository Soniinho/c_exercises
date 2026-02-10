#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int recurso_compartilhado = 0;

void* acessar_recurso(void* arg) {
  int id = *((int*) arg);
  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&mutex); //trava o mutex para garantir acesso ao recurso compartilhado
    printf("Thread %d acessando recurso compartilhado: %d\n", id, recurso_compartilhado);
    recurso_compartilhado++;
    printf("Thread %d liberando recurso compartilhado: %d\n", id, recurso_compartilhado);
    pthread_mutex_unlock(&mutex); //libera o mutex para que outras threads possam acessar o recurso compartilhado
  }
  return NULL;
}

int main() {
  pthread_t threads[5];
  pthread_mutex_init(&mutex, NULL); //inicializa o mutex
  for (int i = 0; i < 5; i++) {
    pthread_create(&threads[i], NULL, acessar_recurso, &i); //cria as threads e passa as informações
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL); //espera as threads terminarem 
  }
  pthread_mutex_destroy(&mutex); //destroi o mutex
  return 0;
}
