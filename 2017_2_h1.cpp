#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define MAX_N 100000

enum { A0, B0, AF, BF };
struct state {
	int cnt;
	int code;
	int other;
};

bool visit[4][MAX_N + 1] = { 0 };

int main() {
	int a, b, c, d;

	scanf("%d%d%d%d", &a, &b, &c, &d);

	if (c != a && c != 0 && d != b && d != 0) {
		printf("-1");
		return 0;
	}

	// 상태 코드, 나머지 통 남은 양
	queue<state> qu;
	qu.push({ 0, A0, 0 });

	while (!qu.empty()) {
		auto now = qu.front();
		qu.pop();
		if (visit[now.code][now.other]) continue;
		visit[now.code][now.other] = true;

		switch (now.code) {
		case A0:
			if (c == 0 && d == now.other) {
				printf("%d", now.cnt);
				return 0;
			}
			qu.push({ now.cnt + 1, AF, now.other }); // A를 채움
			qu.push({ now.cnt + 1, A0, b }); // B를 채움
			if (now.other <= a) qu.push({ now.cnt + 1, B0, now.other }); // B -> A 이후 B가 0
			else qu.push({ now.cnt + 1, AF, now.other - a }); // B->A 이후 A가 만땅
			break;

		case B0:
			if (d == 0 && c == now.other) {
				printf("%d", now.cnt);
				return 0;
			}
			qu.push({ now.cnt + 1, BF, now.other }); // B를 채움
			qu.push({ now.cnt + 1, B0, a }); // A를 채움
			if (now.other <= b) qu.push({ now.cnt + 1, A0, now.other }); // A->B 이후 A가 0
			else qu.push({ now.cnt + 1, BF, now.other - b }); // A->B 이후 B가 만땅
			break;

		case AF:
			if (c == a && d == now.other) {
				printf("%d", now.cnt);
				return 0;
			}
			qu.push({ now.cnt + 1, A0, now.other }); // A를 비움
			qu.push({ now.cnt + 1, AF, b }); // B를 채움
			if (now.other + a <= b) qu.push({ now.cnt + 1, A0, now.other + a }); // A->B 이후 A가 0
			else qu.push({ now.cnt + 1, BF, now.other + a - b }); // A->B 이후 B가 만땅
			break;

		case BF:
			if (d == b && c == now.other) {
				printf("%d", now.cnt);
				return 0;
			}
			qu.push({ now.cnt + 1, B0, now.other }); // B를 비움
			qu.push({ now.cnt + 1, AF, b }); // A를 채움
			if (now.other + b <= a) qu.push({ now.cnt + 1, B0, now.other + b }); // B->A 이후 B가 0
			else qu.push({ now.cnt + 1, AF, now.other + b - a }); // B->A 이후 A가 만땅
			break;
		}
	}

	printf("-1");
}
