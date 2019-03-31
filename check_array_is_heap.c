#include <stdio.h>
#include <stdlib.h>
int check_if_heap(int size, int *arr) {
    int child_id = 1; /* used to identify children of a node */
    int i;
    int bin_max_heap = 0;
    if (size == 1) {
        printf("1\n");
        return 1;
    }
    for(i = 0; i < size; i++) {
        if (arr[i] > arr[child_id]) {
            bin_max_heap = 1;
            if((child_id + 1) < size) {
                if (arr[i] < arr[child_id + 1]) {
                    bin_max_heap = 0;
                    break;
                }
            }
        }
        else {
            bin_max_heap = 0;
            break;
        }
        child_id += 2;
    }
    return bin_max_heap;
}

int main() {
    int tc; /* Number of testcases */
    int size; /* size of array */
    int i, j;
    int *arr = (int*)malloc(sizeof(int)*1000);
    scanf("%d", &tc);
    int bmh[tc];
    for(i = 0; i < tc; i++) {
        scanf("%d", &size);
        for(j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }
        bmh[i] = check_if_heap(size, arr);
    }
    for(i = 0; i < tc; i++)
        printf("%d\n", bmh[i]);
    return 0;
}
