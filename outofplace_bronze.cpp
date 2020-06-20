// Brian Lu
// 23 mins so far...
// Passes sample on my end, not on USACO.org?? might be uninitialized vars idk, will check tommorrow
// I think I might have interpreted the question incorrectly.... :/

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <limits>

int main()
{
    int N;
    
    FILE *input = fopen("outofplace.in", "r");
    fscanf(input, "%d", &N);
    int cows[N+2];
    cows[0] = -1;
    cows[N+1] = 1000001;

    for (int i = 1; i <= N; i++) {
        fscanf(input, "%d", &cows[i]);
    }
    fclose(input);

    int oopindex, outofplace, direction;
    for (int i = 1; i <= N; i++) {
        if (cows[i] < cows[i+1] && cows[i-1] < cows[i]) {} else {
            oopindex = i;
            outofplace = cows[i];
            if (cows[i-1] < cows[i]) {
                direction = 1;
            } else {
                direction = -1;
            }
            break;
        }
    }


    int previous = outofplace;
    int jumps = 0;
    for (int i = oopindex; i != direction == 1 ? N+1 : 0; i+=direction) {
        if (cows[i] != previous) {
            previous = cows[i];
            jumps++;
        }
        if (cows[i] < cows[i+1] && cows[i-1] < cows[i]) {
            break;
        }
    }

    FILE *output = fopen("outofplace.out", "w");
    fprintf(output, "%d\n", jumps);
    fclose(output);

    return 0;
}