// Brian Lu
// 15 mins **********
// Of course not super efficient, ran into some dumb problems with input early on.

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
    
    FILE *input = fopen("lifeguards.in", "r");
    fscanf(input, "%d", &N);
    int start[N], end[N];
    for (int i = 0; i < N; i++) {
        fscanf(input, "%d %d", &start[i], &end[i]);
    }
    fclose(input);

    int lifeguards, time;
    int maxtime = 0;

    for (int i = 0; i < N; i++) {
        lifeguards = 0;
        time = 0;
        for (int j = 1; j < 1001; j++) {
            for (int k = 0; k < N; k++) {
                if (k != i && j == start[k]) {
                    lifeguards++;
                }
                if (k != i && j == end[k]) {
                    lifeguards--;
                }
            }
            if (lifeguards > 0) {
                time++;
            }
        }
        maxtime = std::max(time, maxtime);
    }

    FILE *output = fopen("lifeguards.out", "w");
    fprintf(output, "%d\n", maxtime);
    fclose(output);

    return 0;
}