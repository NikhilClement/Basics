#include <stdio.h>
void shift(short int num) {
    int i = 0, t1, t2, t3, r = 0; //temp1, temp2, result
    int bit_pattern = 0xc0;
    while (bit_pattern > 0) {
        t1 = num & bit_pattern;
        t1 = (t1 >> 1) & bit_pattern;
        t2 = num & bit_pattern;
        t2 = (t2 << 1) & bit_pattern;
        bit_pattern >>= 2;
        r |= (t1 | t2);
    }
    printf("%d\n", r);
}
int main() {
    //code
    int testcase;
    scanf("%d", &testcase);
    int num[testcase];
    int t1, t2, r, length = 0, i;
    for(i = 0; i < testcase; i++)
        scanf("%d", &num[i]);
    for(i = 0; i < testcase; i++) {
        shift(num[i]);
    }
    return 0;
}

