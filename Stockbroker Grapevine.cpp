#include <iostream>
#define INF 99999999
using namespace std;
int Dis[101][101];
int main()
{
    int P;
    int unused __attribute__((unused));
    while (scanf("%d", &P) && P) {
        for (int q = 1; q <= P; ++q) {
            for (int r = 1; r <= P; ++r)
                Dis[q][r] = INF;
            Dis[q][q] = 0;
        }

        for (int q = 1; q <= P; ++q) {
            int t, x, w;
            unused = scanf("%d", &t);
            for (int r = 0; r < t; ++r) {
                unused = scanf("%d %d", &x, &w);
                Dis[q][x] = w;
            }
        }

        for (int k = 1; k <= P; ++k)
            for (int q = 1; q <= P; ++q)
                for (int r = 1; r <= P; ++r)
                    if (Dis[q][k] + Dis[k][r] < Dis[q][r])
                        Dis[q][r] = Dis[q][k] + Dis[k][r];

        int Min = INF;
        int Min_pos;
        bool Disjoint = true;
        for (int q = 1; q <= P; ++q) {
            int Max_length = 0;
            bool Reachable = true;
            for (int r = 1; r <= P; ++r) {
                if (Dis[q][r] == INF) {
                    Reachable = false;
                    break;
                }
                else if (Dis[q][r] > Max_length)
                    Max_length = Dis[q][r];
            }
            if (Reachable == true) {
                Disjoint = false;
                if (Max_length < Min) {
                    Min = Max_length;
                    Min_pos = q;
                }
            }
        }
        if (Disjoint) puts("disjoint");
        else printf("%d %d\n", Min_pos, Min);
    }
}
