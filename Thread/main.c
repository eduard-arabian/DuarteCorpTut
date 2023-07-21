#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ProcessSeparate(void *data);

int main() {
  pthread_t process1;
  pthread_t process2;

  pthread_create(&process1, NULL, &ProcessSeparate, "Hi");
  pthread_create(&process2, NULL, &ProcessSeparate, "Bye");
  pthread_join(process1, NULL);
  pthread_join(process2, NULL);

  return 0;
}

void *ProcessSeparate(void *data) {
  char *text = (char *)data;
  struct timespec tiempo = {1, 0};

  while (1) {
      printf("%s\n", text);
      pthread_delay_np(&tiempo);
  }
}
