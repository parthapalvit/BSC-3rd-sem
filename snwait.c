
//Simulate and implement stop and wait protocol for noisy channel.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int msg;
    int nframes = 10;
    int frameNo = 1;
    srand(time(NULL)); // Initialize random seed

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    printf("\nTotal no of frame to be sent %d\n", nframes);
    while (nframes > 0)
    {
        printf("\n\n->Sending frame- %d", frameNo);
        msg = rand() % 10;
        printf("\n Value of frame= %d", msg);
        if (msg % 5 == 0)
        {
            sleep(2);
            printf("\n No acknowledgement received frame- %d", frameNo);
            printf("\n\n->Resending frame - %d", frameNo);
            msg = rand() % 10;
            printf("\n Value of frame= %d\n", msg);
        }
        printf("\n Acknowledgement for frame %d", frameNo);
        nframes--;
        frameNo++;
    }
    return 0;
}

// #include<time.h> in the code to utilize the time(NULL) function, which is commonly used to seed the random number generator (srand). Seeding the random number generator with the current time ensures that the sequence of random numbers generated is different each time the program runs.
//If our program doesn't depend on having different sequences of random numbers across executions, we can omit the #include<time.h> and the associated srand line.
