#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int BlockSize = 4;

int PlayerStep();

int main()
{   
    int N;
    int player, AI;

    srand(time(NULL));
    int M = rand()%3+2;

    int K = rand()%(BlockSize-1) + 1;  // 1 2 3

    N = BlockSize*M+1+K;

    //printf("M = %i\n", M);
    //printf("K = %i\n", K);
    printf("Total number = %i\n", N);

    while ( N > 1)
    {
        //AI = rand()%3+1;
        AI = (N-1)%BlockSize;

        printf("AI turn: %i\n", AI);
        N -= AI;
        printf("N = %i\n", N);

        if (N <= 1)
        {
            printf("AI win\n");
            break;
        }

        printf("Your turn\n");
        player = PlayerStep();
        N -= player;
        printf("N = %i\n", N);

        if (N<=1)
        {
            printf("Player win");
            break;
        }
    }

    return 0;
}

int PlayerStep()
{
    do
    {
        int res;
        scanf("%i", &res);
        if (res > BlockSize-1 || res < 1)
            printf("Wrong number. Repeat please.");
        else
            return res;

    } while (1);
}




