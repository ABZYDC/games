/* mastermind.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmind();

int main()
{
    time_t t;
    srand((unsigned) time(&t));

    int code[4];
    int repeatCheck[4];
    int guess[4];

    for(int i=0; i<4; i++)
    {
        do {
            scanf("%d", &code[i]);
        } while (code[i]>6 || code[i]<1);
        //printf("%d ", code[i]);
    }

    for (int i=1; i<=1000; i++) {
        printf("CHEATER!!! ");
    }
    for (int i=0; i<200; i++) {
        printf("\n");
    }

    printf("\n");

    int wPeg, rPeg;

    for (;;)
    {

        wPeg=0, rPeg=0;

        for(int i=0; i<4; i++)
        {
            repeatCheck[i] = 0;
        }
        
        printf("Enter guess: ");
        for(int i=0; i<4; i++)
        {
            do
            {
                scanf("%d", &guess[i]);
            } while (guess[i]>6 || guess[i]<1);
        }

        //printf("RED PEGS: ");

        for(int i=0; i<4; i++)
        {
            if (code[i] == guess[i])
            {
                //printf("[code[%d]=%d], ", i+1, code[i]);
                rPeg++;
                repeatCheck[i] = 1;
            }
        }

        //printf("| WHITE PEGS: ");

        for(int i=0; i<4; i++)
        if (code[i] != guess[i])
        {{
            for(int j=0; j<4; j++)
            {
                if (code[j] == guess[i] && !repeatCheck[j])
                {
                    //printf("[guess[%d]=code[%d]=%d], ", i+1, j+1, guess[i]);
                    wPeg++;
                    repeatCheck[j] = 1;
                    break;
                }
            }
        }}
        
        //printf("| ");
        printf("%d red, %d white\n", rPeg, wPeg);
        if (rPeg == 4)
        {
            printf("You win\n");
            break;
        }
    }
}
