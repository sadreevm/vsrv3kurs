#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void alarm_handler(int signum);

int main() {
  char buffer[100];
  void (*sigHandlerReturn)(int);

  sigHandlerReturn = signal(SIGALRM, alarm_handler);
  if (sigHandlerReturn == SIG_ERR) {
    perror("Signal Error");
    return 1;
  }

  printf("Waiting (10 sec)\n");
  fflush(stdout);

  alarm(10);

  char *result = fgets(buffer, sizeof(buffer), stdin);

  alarm(0);

  printf("Спасибо\n");

  return 0;
}

void alarm_handler(int signum) {
  if (signum == SIGALRM) {
    write(1, "Нет ввода\n", 18);
    exit(0);
  }
}
