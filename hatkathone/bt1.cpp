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

// Kh?i t?o hàng d?i
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// Thêm ph?n t? vào hàng d?i (enqueue)
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

// L?y ph?n t? kh?i hàng d?i (dequeue)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Hàng d?i r?ng!\n");
        return -1;  // Tr? v? giá tr? không h?p l? khi hàng d?i r?ng
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;  // N?u hàng d?i tr? nên r?ng
    } else {
        q->front->prev = NULL;
    }

    free(temp);
    q->size--;
    return data;
}

// Ki?m tra ph?n t? d?u hàng d?i (peek)
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Hàng d?i r?ng!\n");
        return -1;
    }
    return q->front->data;
}

// Ki?m tra hàng d?i có r?ng không (isEmpty)
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// L?y kích thu?c hàng d?i (size)
int size(Queue* q) {
    return q->size;
}

// In toàn b? hàng d?i (display)
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Hàng d?i r?ng!\n");
        return;
    }

    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Xóa toàn b? hàng d?i (clear)
void clear(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
}

// Ki?m tra ph?n t? cu?i cùng (rear)
int rear(Queue* q) {
    if (q->rear == NULL) {
        printf("Hàng d?i r?ng!\n");
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
        printf("1. Thêm ph?n t? vào hàng d?i (enqueue)\n");
        printf("2. L?y ph?n t? kh?i hàng d?i (dequeue)\n");
        printf("3. Ki?m tra ph?n t? d?u hàng d?i (peek/front)\n");
        printf("4. Ki?m tra hàng d?i có r?ng không (isEmpty)\n");
        printf("5. L?y kích thu?c hàng d?i (size)\n");
        printf("6. In toàn b? hàng d?i (display)\n");
        printf("7. Xóa toàn b? hàng d?i (clear)\n");
        printf("8. Ki?m tra ph?n t? cu?i cùng (rear)\n");
        printf("9. Thoát\n");
        printf("Ch?n thao tác: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nh?p giá tr? ph?n t? mu?n thêm vào hàng d?i: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1) {
                    printf("Ph?n t? dã du?c l?y kh?i hàng d?i: %d\n", data);
                }
                break;
            case 3:
                data = peek(&q);
                if (data != -1) {
                    printf("Ph?n t? d?u hàng d?i: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(&q)) {
                    printf("Hàng d?i r?ng.\n");
                } else {
                    printf("Hàng d?i không r?ng.\n");
                }
                break;
            case 5:
                printf("Kích thu?c hàng d?i: %d\n", size(&q));
                break;
            case 6:
                printf("Hàng d?i hi?n t?i: ");
                display(&q);
                break;
            case 7:
                clear(&q);
                printf("Hàng d?i dã du?c xóa.\n");
                break;
            case 8:
                data = rear(&q);
                if (data != -1) {
                    printf("Ph?n t? cu?i cùng trong hàng d?i: %d\n", data);
                }
                break;
            case 9:
                printf("Thoát chuong trình.\n");
                exit(0);
            default:
                printf("L?a ch?n không h?p l?. Vui lòng th? l?i.\n");
        }
    }
    return 0;
}

