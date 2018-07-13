#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define FALSE 0


struct queue{
	int items[MAXSIZE];
	int front, rear;
};

int empty(struct queue *pq){
	return (pq -> front == pq -> rear) ? TRUE : FALSE;
} 

void intialize(struct queue *pq){
	(pq -> front) = (pq -> rear) = MAXSIZE - 1;
}


/*
	Insert :- 
	
	1.Intially we have set the index of front and rear to be the same which is equal to the maxmimum limit of the array. 
	
	2. We always want to keep the index of the front label ahead of the rear

	3. Since we intialised the front to MAXSIZE - 1 then the next index which is 0. 

	4. If that is not the case then we just normally increment it. 

	5. We also check for the oveflow condition which occurs when the rear and front labels are equal. Which doesn't get triggered with the intialisation defaults since we would have already set to 0 (the starting index). 

	6. So in default case after the initial increment rear lags the front by one. 

	7. Then we "return the value after incrementing " the front label. 

*/

void insert(struct queue *pq, int x){
	if(pq -> rear == MAXSIZE - 1)
		pq -> rear = 0;
	else (pq -> rear)++;
	
	if(pq -> rear == pq -> front){
		printf("\nOverflow !! Exiting \n");
		exit(1);
	}
	pq -> items[pq->rear] = x;
	return;
}

int remove_ele(struct queue *pq){
	if(empty(pq)){
		printf("Underflow!!");
		exit(1);
	}
	if(pq -> front == MAXSIZE - 1)
		pq -> front = 0;
	else 
		(pq -> front) ++;
	return (pq -> items [pq -> front ]);

}

int main(){
	struct queue pq;
	intialize(&pq);
	int op, temp, val;
	printf("\n1.Insert to the queue \n2.Delete from queue \n3.Show all the queue contents\n");
	scanf("%d", &op);
	
	while(1){	
	switch(op){
	case 1: printf("\nHow many numbers ?");
		scanf("%d", &temp);
		for(int i = 0; i < temp; i++){
		scanf("%d", &val);
		insert(&pq, val);
		}
		break;

	case 2: printf("%d was deleted from the queue", remove_ele(&pq));
		break;

	default : printf("Wrong choice entered exiting! Bye !");
		  exit(0);
		  break;
		}
	}
return 0;
} 
