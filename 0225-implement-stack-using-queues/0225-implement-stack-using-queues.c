#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *Q1; // Mảng Q1 (luôn chứa các phần tử theo thứ tự stack)
    int front1, rear1;

    int *Q2; // Mảng Q2 (dùng làm bộ nhớ tạm khi push)
    int front2, rear2;

    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->capacity = 100; 
    
    // Cấp phát mảng bên trong
    obj->Q1 = (int*)malloc(obj->capacity * sizeof(int));
    obj->Q2 = (int*)malloc(obj->capacity * sizeof(int));

    // Khởi tạo chỉ số
    obj->front1 = 0; obj->rear1 = -1;
    obj->front2 = 0; obj->rear2 = -1;
    
    return obj; 
}

void myStackPush(MyStack* obj, int x) {
    // Bước 1: Đưa x vào Q2 (đang trống)
    obj->Q2[++(obj->rear2)] = x;

    // Bước 2: Lấy toàn bộ từ Q1 bỏ sang Q2 (đứng sau x)
    while (obj->front1 <= obj->rear1) {
        obj->Q2[++(obj->rear2)] = obj->Q1[obj->front1++];
    }

    // Bước 3: Hoán đổi Q1 và Q2 để Q1 lại là queue chính
    // Hoán đổi con trỏ mảng
    int *tempQ = obj->Q1;
    obj->Q1 = obj->Q2;
    obj->Q2 = tempQ;

    // Hoán đổi các chỉ số quản lý
    int tempFront = obj->front1; obj->front1 = obj->front2; obj->front2 = tempFront;
    int tempRear = obj->rear1; obj->rear1 = obj->rear2; obj->rear2 = tempRear;

    // Reset lại Q2 về trạng thái trống để dùng cho lần push sau
    obj->front2 = 0;
    obj->rear2 = -1;
}

int myStackPop(MyStack* obj) {
    // Vì Q1 đã được sắp xếp, chỉ cần lấy phần tử đầu tiên (front)
    return obj->Q1[obj->front1++];
}

int myStackTop(MyStack* obj) {
    // Xem phần tử đầu tiên của Q1
    return obj->Q1[obj->front1];
}

bool myStackEmpty(MyStack* obj) {
    // Nếu front vượt quá rear của Q1 nghĩa là stack rỗng
    return obj->front1 > obj->rear1;
}

void myStackFree(MyStack* obj) {
    free(obj->Q1);
    free(obj->Q2);
    free(obj);
}