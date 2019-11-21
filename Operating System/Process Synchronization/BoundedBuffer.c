#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define TRUE 1
typedef int buffer_item;
#define BUFFER_SIZE 5
buffer_item START_NUMBER;
buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t empty;
sem_t full;
int insertPointer = 0, removePointer = 0;
int insert_item(buffer_item item);
int remove_item(buffer_item *item);
void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item)
{
	buffer[insertPointer] = item;
	insertPointer = (insertPointer + 1) % BUFFER_SIZE;
	return 0;
}

int remove_item(buffer_item *item)
{
	*item = buffer[removePointer];
    buffer[removePointer]=0;
	removePointer = (removePointer + 1) % BUFFER_SIZE;
	return 0;
}

void *producer(void *param)
{
	buffer_item item;
	while(TRUE) {
		sleep(2);
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		item = START_NUMBER++;
		insert_item(item);
		printf("Producer %u produced %d \n", (unsigned int)pthread_self(), item);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

void *consumer(void *param)
{
	buffer_item item;
	while(TRUE){
		sleep(2);
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		remove_item(&item);
		printf("Consumer %u consumed %d \n", (unsigned int)pthread_self(), item);
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

int main(int argc, char *argv[])
{
    //TODO:用户指定sleepTime,生产者消费者线程个数,运行时输入即可
	int sleepTime, producerThreads, consumerThreads;
	int i, j;
	if(argc != 5)
	{
		fprintf(stderr, "Useage: <sleep time> <producer threads> <consumer threads> <start number>\n");
		return -1;
	}
    //字符串自动转整数
	sleepTime = atoi(argv[1]);
	producerThreads = atoi(argv[2]);
	consumerThreads = atoi(argv[3]);
	START_NUMBER = atoi(argv[4]);
    //创建互斥信号量,调用pthread API
	pthread_mutex_init(&mutex, NULL);
    //创建full和empty信号量,并且赋予初值
    //这里第一个参数是指信号量的指针,0表示仅有该进程下线程可以访问该信号量,第三个表示初始化数值
	sem_init(&full, 0, BUFFER_SIZE);
	sem_init(&empty, 0, 0);
	pthread_t pid, cid;
	for(i = 0; i < producerThreads; i++){
        //创建producer线程,个数由用户指定,去运行producer过程
		pthread_create(&pid,NULL,&producer,NULL);
	}
	for(j = 0; j < consumerThreads; j++){
        //同理
		pthread_create(&cid,NULL,&consumer,NULL);
	}
    //sleep for a while
	// sleep(sleepTime);
	return 0;
}
