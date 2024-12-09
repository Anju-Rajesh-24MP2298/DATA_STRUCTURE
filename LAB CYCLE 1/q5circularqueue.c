#include <stdio.h>
#include <stdlib.h>

int *queue,MAX_SIZE,i;
int front = -1, rear = -1;

int isFull()
{
	return (rear + 1) % MAX_SIZE == front;
}

int isEmpty()
{
	return front == -1;
}

void enqueue(int data)
{
	if (isFull())
	{
        	printf("Queue is Full!!\n");
	        return;
	}
	if (front == -1)
	{
	        front = 0;
	}
	rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
        printf("Element %d inserted\n", data);
}

int dequeue()
{
        if (isEmpty())
	{
	        printf("Queue is Empty\n");
	        return -1;
        }
        int data = queue[front];
        if (front == rear)
	{
	        front = rear = -1;
        }
        else
	{
	        front = (front + 1) % MAX_SIZE;
        }
        return data;
}

void display()
{
        if (isEmpty())
	{
        	printf("Queue is empty\n");
	        return;
        }
        printf("Queue elements: \n");
        int i = front;
        while (i != rear)
	{
        	printf("%d ", queue[i]);
	        i = (i + 1) % MAX_SIZE;
        }
	        printf("%d\n", queue[rear]);
}
void search()
{
	if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        int searchItem, found = 0;
        printf("Enter Element to Search: ");
        scanf("%d", &searchItem);
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            if (queue[i] == searchItem)
            {
                found = 1;
                break;
            }
        }
        if (queue[i] == searchItem)
        {
            found = 1;
        }
        if (found)
        {
            printf("Element %d found in the queue\n", searchItem);
        }
        else
        {
            printf("Element %d not found in the queue\n", searchItem);
        }
    }
}

int main()
{
        int data,ch;
	printf("\nEnter the size of the queue:");
	scanf("%d",&MAX_SIZE);
	queue=(int *)malloc(MAX_SIZE * sizeof(int));
        while(1)
	{
                printf("\nCIRCULAR QUEUE \n 1.Insertion \n 2.Deletion \n 3.Display \n 4.Search \n 5.Exit");
		printf("\nEnter your choice:");
                scanf("%d",&ch);
                switch(ch)
		{
	                case 1:
				printf("\nEnter element to be insertedto the queue:");
                        	scanf("%d",&data);
	                        enqueue(data);
        	                display();
                	        break;
	                case 2:
				printf("Dequeued element is  %d\n", dequeue());
                        	display();
	                        break;
        	        case 3:
				display();
	                        break;
        	        case 4:
				search();
	                        break;
        	        case 5:
                        	exit(0);
	                        break;
        	        default:
				printf("\nInvalid choice\n");
				break;
                }
        }
        return 0;
}
