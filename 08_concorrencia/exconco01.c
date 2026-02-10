#include <stdio.h>
#include <pthread.h>

//Essa função só imprime de 1 até 50
void* print_numbers(void* arg) {
  int start = *((int*) arg);
  for (int i = start; i <= start + 49; i++) {
    printf("%d ", i);
  }
  return NULL;
}

int main() {
  pthread_t t1, t2;
  int start1 = 1;
  int start2 = 51;
  //aqui cria as threads em endereos específicos, 
  //passando os valores de start e a função que iram executar
  pthread_create(&t1, NULL, print_numbers, &start1); 
  pthread_create(&t2, NULL, print_numbers, &start2);
  //aqui elas esperam as treads terminarem para sincronizar elas
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}