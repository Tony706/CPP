#include<iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
class Interval
	{
	public:
	    int r, t;
	
	    bool operator < (const Interval& x) const {
	        if (t != x.t)
	            return t < x.t;
	        return r < x.r;
	    }
	} *intervals;
int main() 
{
    int N, i, last_finished;
    scanf("%d", &N);
    intervals = new Interval[N];
    for (i = 0; i < N; i++)
        scanf("%d %d", &intervals[i].r, &intervals[i].t);
    sort(intervals, intervals + N);
    queue <int> opt; 
    for (i = 0, last_finished = 0; i < N; i++)
        if (intervals[i].r >= last_finished)   
			{
            opt.push(i);
            last_finished = intervals[i].t;
        	}
        	
    printf("%d\n", opt.size());
    return 0;
}
