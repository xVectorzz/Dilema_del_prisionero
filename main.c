#include <stdio.h>
#include <stdlib.h>

int payoffs[4][2] = {
    {-3,-3},
    {0,-10},
    {-10,0},
    {-5,-5}
};

char *actions[] = {
    "Cooperar",
    "Traicionar"
  };

int eleccionPrisionero(int* choise, char prisionero){
    int decision = 0;
    printf("Eres el prisionero %c, toma una decision:",prisionero);
    scanf("%d", &decision);

    *choise = decision;
    if(prisionero == 'B') return -1;

    return 0;
}

int *pago(int choiseA, int choiseB){

    if(choiseA == 1 && choiseB == 1)
        return payoffs[0];
    else if (choiseA == 2 && choiseB == 1)
        return payoffs[1];
    else if (choiseA == 1 && choiseB == 2)
        return payoffs[2];
    else if (choiseA == 2 && choiseB == 2)
        return payoffs[3];

    printf("Decision no identificada!");
    exit(1);
}

void mostrarDecision(int decision, char prisionero){
    printf("Prisionero %c elige: [%s]\n", prisionero, actions[decision-1]);
}

int main(int argc, char *argv[]) {

    int *outcome;

    int choiseA = 0;
    int choiseB = 0;

    int close = 0;

    while(close != -1){
        close = eleccionPrisionero(&choiseA, 'A');
        close = eleccionPrisionero(&choiseB, 'B');

        printf("\n");
        mostrarDecision(choiseA,'A');
        mostrarDecision(choiseB,'B');
        outcome = pago(choiseA, choiseB);

        printf("Resultado (Años de carcel para A, Años de carcel para B): [%d, %d]\n",outcome[0],outcome[1]);
    }
    printf("Juego terminado.\n");

    return 0;
}

