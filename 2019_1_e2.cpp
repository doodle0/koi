// 2019년 1차대회 초등부 2번

#include <stdio.h>
#include <string.h>
 
#define MAX_LEN 100000
 
int main() {
    int t;
 
    scanf("%d", &t);
    while (t--) {
        char str[MAX_LEN + 1];
        scanf("%s", str);
 
        int l = 0, r = strlen(str) - 1;
        int ll, rr;
         
        bool isPal = true;
        while (l < r) { // 회문인지 아닌지 검사
            if (str[l] != str[r]) {
                isPal = false;
                break;
            }
            l++; r--;
        }
 
        // 왼쪽 지우고 검사
        ll = l + 1; rr = r;
        bool isPsuLeft = true; // 왼쪽 지웠을 때 회문인지
        while (ll < rr) {
            if (str[ll] != str[rr]) {
                isPsuLeft = false;
                break;
            }
            ll++; rr--;
        }
 
        // 오른쪽 지우고 검사
        ll = l; rr = r - 1;
        bool isPsuRight = true; // 오른쪽 지웠을 떄 회문인지
        while (ll < rr) {
            if (str[ll] != str[rr]) {
                isPsuRight = false;
                break;
            }
            ll++; rr--;
        }
 
        if (isPal) printf("0\n");
        else if (isPsuLeft || isPsuRight) printf("1\n");
        else printf("2\n");
    }
}
