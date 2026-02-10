#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaforo;
int recurso_compartilhado = 0;

void* acessar_recurso(void* arg) {
  int id = *((int*) arg);
  for (int i = 0; i < 10; i++) {
    sem_wait(&semaforo); //coloca o semaforo em vermelho (0)
    printf("Thread %d acessando recurso compartilhado: %d\n", id, recurso_compartilhado);
    recurso_compartilhado++; //acessa o recurso compartilhado
    printf("Thread %d liberando recurso compartilhado: %d\n", id, recurso_compartilhado);
    sem_post(&semaforo); //coloca o semaforo em verde (1)
  }
  return NULL;
}

int main() {
  pthread_t threads[5];
  sem_init(&semaforo, 0, 1); //inicia o semaforo com desligado (0) e ligado (1)
  for (int i = 0; i < 5; i++) {
    pthread_create(&threads[i], NULL, acessar_recurso, &i); //cria as threads e passa as informações para elas
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL); //espera as threads terminarem suas execuções
  }
  sem_destroy(&semaforo); //destroi o semaforo
  return 0;
}
