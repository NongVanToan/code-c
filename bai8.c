#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size, capacity;
    int* array;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;  // Thực hiện công thức này để thay đổi chỉ số rear
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;  // Thực hiện công thức này để thay đổi chỉ số rear
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;  // Thực hiện công thức này để thay đổi chỉ số front
    queue->size = queue->size - 1;
    return item;
}
int main() {
    struct Queue* queue = createQueue(5);

    // Thêm phần tử vào Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("%d đã được lấy ra khỏi Queue\n", dequeue(queue));
    printf("%d đã được lấy ra khỏi Queue\n", dequeue(queue));

    // Thêm phần tử mới vào Queue
    enqueue(queue, 50);

    // In ra phần tử ở đầu và cuối Queue
    printf("Phần tử đầu tiên là %d\n", queue->array[queue->front]);
    printf("Phần tử cuối cùng là %d\n", queue->array[queue->rear]);

    return 0;
}
