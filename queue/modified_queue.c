#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10 
#define TRUE 1 
#define FALSE 0

struct queue{
	int front, rear;
	int item[MAXSIZE];
};

void intialise(struct queue *pq){
	pq -> front = 0;
	pq -> rear = -1;
}

int empty(struct queue *pq){
	return ((pq -> front == 0 && pq -> rear == -1) ? TRUE : FALSE);
}

void insert(struct queue *pq, int x){
	if (pq -> rear == MAXSIZE - 1)
	{
		for (int i = (pq -> front); i < (pq -> rear) ; ++i)
			pq -> item[i - (pq -> front)] = pq -> item[i];
		pq -> rear = pq -> front;
		pq -> front = 0;
	}

	pq -> item[++(pq -> front)] = x;
}

int remove_ele(struct queue *pq){
	if (empty(pq))
	{
		printf("\nUnderflow !! Exiting\n");
		exit(1);
	}

	return (pq->item[(pq -> front)++]);
}

void print_all(struct queue *pq){
	for (int i = (pq->front); i < (pq->rear) ; ++i)
			printf("\t%d\t\n",pq->item[i]);
}

int main(int argc, char const *argv[])
{
	struct queue pq;
	intialise(&pq);
	for (int i = 0; i < MAXSIZE; ++i)
		insert(&pq, i);
	print_all(&pq);

	return 0;
}
