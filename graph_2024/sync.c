#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int tube[2];
void gestionnaire_signal(int signum) {
    close(tube[0]);
    close(tube[1]);
    exit(0);
}
int main() {
    signal(SIGUSR1, gestionnaire_signal);
    int entiers[2];
    int somme;
    if(pipe(tube) == -1) {
        perror("Erreur lors de la création du tube");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();
    if(pid == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(EXIT_FAILURE);
    }
    if(pid > 0) { // Processus père
        while(1) {
            printf("Entrez deux entiers (0 pour terminer) : ");
            scanf("%d %d", &entiers[0], &entiers[1]);
            write(tube[1], entiers, sizeof(entiers));
            if(entiers[0] == 0 && entiers[1] == 0) {
                printf("Envoi du signal de fin au fils...\n");
                kill(pid, SIGUSR1);
                break;
            }
            read(tube[0], &somme, sizeof(somme));
            printf("Somme calculée par le fils : %d\n", somme);
        }
    } else { // Processus fils
        while(1) {
            read(tube[0], entiers, sizeof(entiers));
            if(entiers[0] == 0 && entiers[1] == 0) {
                printf("Reçu le signal de fin du père. Terminaison...\n");
                kill(getppid(), SIGUSR1);
                break;
            }
            somme = entiers[0] + entiers[1];
            write(tube[1], &somme, sizeof(somme));
        }
    }
    return 0;
}
