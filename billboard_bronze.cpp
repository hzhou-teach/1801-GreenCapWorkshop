// Brian Lu
// 20 mins ***x******
// Don't know why the 4th case keeps failing.

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <limits>

int main()
{
    int x1,y1,x2,y2,// Lawnmower
        x3,y3,x4,y4;// Cow Feed
    
    FILE *input = fopen("billboard.in", "r");
    fscanf(input, "%d %d %d %d", &x1, &y1, &x2, &y2);
    fscanf(input, "%d %d %d %d", &x3, &y3, &x4, &y4);
    fclose(input);

    int diffx = std::max(0,std::min(x4,x2)-std::max(x3,x1));
    int diffy = std::max(0,std::min(y4,y2)-std::max(y3,y1));

    int mowerwidth  = x2-x1;
    int mowerheight = y2-y1;

    int tarpwidth = mowerwidth;
    int tarpheight = mowerheight;

    if (diffx >= mowerwidth && (x4>x2||x3<x1)) {
        tarpheight -= diffy;
    }
    if (diffy >= mowerheight && (y4>y2||y3<y1)) {
        tarpwidth -= diffx;
    }

    FILE *output = fopen("billboard.out", "w");
    fprintf(output, "%d\n", tarpwidth*tarpheight);
    fclose(output);

    return 0;
}