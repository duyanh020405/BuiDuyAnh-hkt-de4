#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Kh?i t?o h�ng d?i
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// Th�m ph?n t? v�o h�ng d?i (enqueue)
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = q->rear;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// L?y ph?n t? kh?i h�ng d?i (dequeue)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("H�ng d?i r?ng!\n");
        return -1;  // Tr? v? gi� tr? kh�ng h?p l? khi h�ng d?i r?ng
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;  // N?u h�ng d?i tr? n�n r?ng
    } else {
        q->front->prev = NULL;
    }

    free(temp);
    q->size--;
    return data;
}

// Ki?m tra ph?n t? d?u h�ng d?i (peek)
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("H�ng d?i r?ng!\n");
        return -1;
    }
    return q->front->data;
}

// Ki?m tra h�ng d?i c� r?ng kh�ng (isEmpty)
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// L?y k�ch thu?c h�ng d?i (size)
int size(Queue* q) {
    return q->size;
}

// In to�n b? h�ng d?i (display)
void display(Queue* q) {
    if (q->front == NULL) {
        printf("H�ng d?i r?ng!\n");
        return;
    }

    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// X�a to�n b? h�ng d?i (clear)
void clear(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
}

// Ki?m tra ph?n t? cu?i c�ng (rear)
int rear(Queue* q) {
    if (q->rear == NULL) {
        printf("H�ng d?i r?ng!\n");
        return -1;
    }
    return q->rear->data;
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, data;

    while (1) {
        printf("==================MENU=================\n");
        printf("1. Th�m ph?n t? v�o h�ng d?i (enqueue)\n");
        printf("2. L?y ph?n t? kh?i h�ng d?i (dequeue)\n");
        printf("3. Ki?m tra ph?n t? d?u h�ng d?i (peek/front)\n");
        printf("4. Ki?m tra h�ng d?i c� r?ng kh�ng (isEmpty)\n");
        printf("5. L?y k�ch thu?c h�ng d?i (size)\n");
        printf("6. In to�n b? h�ng d?i (display)\n");
        printf("7. X�a to�n b? h�ng d?i (clear)\n");
        printf("8. Ki?m tra ph?n t? cu?i c�ng (rear)\n");
        printf("9. Tho�t\n");
        printf("Ch?n thao t�c: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nh?p gi� tr? ph?n t? mu?n th�m v�o h�ng d?i: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1) {
                    printf("Ph?n t? d� du?c l?y kh?i h�ng d?i: %d\n", data);
                }
                break;
            case 3:
                data = peek(&q);
                if (data != -1) {
                    printf("Ph?n t? d?u h�ng d?i: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("H�ng d?i r?ng.\n");
                } else {
                    printf("H�ng d?i kh�ng r?ng.\n");
                }
                break;
            case 5:
                printf("K�ch thu?c h�ng d?i: %d\n", size(&q));
                break;
            case 6:
                printf("H�ng d?i hi?n t?i: ");
                display(&q);
                break;
            case 7:
                clear(&q);
                printf("H�ng d?i d� du?c x�a.\n");
                break;
            case 8:
                data = rear(&q);
                if (data != -1) {
                    printf("Ph?n t? cu?i c�ng trong h�ng d?i: %d\n", data);
                }
                break;
            case 9:
                printf("Tho�t chuong tr�nh.\n");
                exit(0);
            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
        }
    }
    return 0;
}

