# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# define BufferSize 10

void *Producer();
void *Consumer();

int BufferIndex=0;
char *BUFFER;

pthread_cond_t Buffer_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t ptid,ctid;

    BUFFER=(char *) malloc(sizeof(char) * BufferSize);

    pthread_create(&ptid,NULL,Producer,NULL);
    pthread_create(&ctid,NULL,Consumer,NULL);

    pthread_join(ptid,NULL);
    pthread_join(ctid,NULL);


    return 0;
}

void *Producer()
{
    for(;;)
    {
        pthread_mutex_lock(&mVar);
        if(BufferIndex==BufferSize)
        {
            pthread_cond_wait(&Buffer_Full,&mVar);
        }
        printf("Buffer Index = %d\n", BufferIndex);
        BUFFER[BufferIndex++]='@';
        pthread_mutex_unlock(&mVar);
        pthread_cond_signal(&Buffer_Empty);
        usleep(5000);
    }
}

void *Consumer()
{
    for(;;)
    {
        pthread_mutex_lock(&mVar);
        if(BufferIndex < 0)
        {
            pthread_cond_wait(&Buffer_Empty,&mVar);
        }
        printf("Consume : %d \n",BufferIndex--);
        pthread_mutex_unlock(&mVar);
        pthread_cond_signal(&Buffer_Full);
        usleep(5000);
    }
}
