// 2019년 1차대회 초등부 2번 - 함수를 이용한 풀이

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

int ls, rs;

bool isPal(char s[], int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            ls = l;
            rs = r;
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[MAX_LEN];
        scanf("%s", s);
        int l = 0, r = strlen(s) - 1;
        if (isPal(s, l, r)) {
            printf("0\n");
        } else {
            int ll = ls, rr = rs;
            printf("%d\n", isPal(s, ll, rr - 1) || isPal(s, ll + 1, rr) ? 1 : 2);
        }
    }
}
