#include <stdio.h>
#include <queue>
#include <map>

using namespace std;

int aMax, bMax;

struct State {
    int a, b;
    bool operator<(const State &rhs) const {
        if (a == rhs.a) return b < rhs.b;
        return a < rhs.a;
    }
    State fillA() const {
        return {aMax, b};
    }
    State fillB() const {
        return {a, bMax};
    }
    State emptyA() const {
        return {0, b};
    }
    State emptyB() const {
        return {a, 0};
    }
    State mAB() const {
        if (a + b > bMax) return {a - bMax + b, bMax};
        return {0, a + b};
    }
    State mBA() const {
        if (a + b > aMax) return {aMax, b - aMax + a};
        return {a + b, 0};
    }
};

int main() {
    State goal;

    scanf("%d%d%d%d", &aMax, &bMax, &goal.a, &goal.b);

    queue<State> qu;
    map<State, int> time;
    qu.push(State{ 0, 0 });
    time[State{0, 0}] = 0;

    while (!qu.empty()) {
        auto now = qu.front();
        qu.pop();

        if (now.a == goal.a && now.b == goal.b) {
            printf("%d", time[now]);
            return 0;
        }

        vector<State> next = {now.fillA(), now.fillB(), now.emptyA(), now.emptyB(), now.mAB(), now.mBA()};
        for (auto nx : next) {
            if (time.find(nx) == time.end()) {
                qu.push(nx);
                time[nx] = time[now] + 1;
            }
        }
    }
    printf("-1");
}
