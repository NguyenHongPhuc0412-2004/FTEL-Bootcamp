/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;

    int *answer = (int*)calloc(temperaturesSize, sizeof(int)); // auto = 0
    int *stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prev = stack[top--];       // pop
            answer[prev] = i - prev;       // số ngày chờ
        }
        stack[++top] = i; // push index
    }

    free(stack);
    return answer;
}