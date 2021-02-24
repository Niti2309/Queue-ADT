#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *Q;
};
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("queue is full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("queue is empty");
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue *q)
{
    if(q->front==q->rear)
        return 0;
    else
        return 1;
}

int isFull(struct Queue *q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

int first(struct Queue *q)
{
    return q->Q[q->front];
}
int last(struct Queue *q)
{
    return q->Q[q->rear];
}
void Display(struct Queue q)
{
    int i;
    for(i=q.front+1; i<=q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
}

void create(struct Queue *q,int size)
{
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->rear=-1;
    q->front=-1;
}


int main()
{
    struct Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,10);
    enqueue(&q,10);
    Display(q);
    printf("\n");

    printf("%d ",dequeue(&q));
    printf("\n");

    printf("%d ",isEmpty(&q));
    printf("\n");

    printf("%d ",isFull(&q));
    printf("\n");

    printf("%d ",first(&q));
    printf("\n");


    printf("%d ",last(&q));
    printf("\n");


    return 0;
}
