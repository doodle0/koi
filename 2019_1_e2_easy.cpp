// 2019년 1차대회 초등부 2번 - 쉬운 풀이

#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char str[1000001];
        scanf("%s", str);

        int l = 0, r = strlen(str) - 1;
        int ll, rr;

        int isPal = 1;
        while (l < r) { // 회문인지 아닌지 검사
            if (str[l] != str[r]) {
                isPal = 0;
                break;
            }
            l++; r--;
        }

        // 왼쪽 지우고 검사
        ll = l + 1; rr = r;
        int isPsuLeft = 1; // 왼쪽 지웠을 때 회문인지
        while (ll < rr) {
            if (str[ll] != str[rr]) {
                isPsuLeft = 0;
                break;
            }
            ll++; rr--;
        }

        // 오른쪽 지우고 검사
        ll = l; rr = r - 1;
        int isPsuRight = 1; // 오른쪽 지웠을 떄 회문인지
        while (ll < rr) {
            if (str[ll] != str[rr]) {
                isPsuRight = 0;
                break;
            }
            ll++; rr--;
        }

        if (isPal == 1) printf("0\n");
        else if (isPsuLeft == 1 || isPsuRight == 1) printf("1\n");
        else printf("2\n");
    }
}
