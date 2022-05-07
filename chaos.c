#include <stdlib.h>
#include <unistd.h>
#include "toolbox.h"

int main()
{
    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

    // arrays
    int originalPoints[3][2] = { {0,functional_height}, {120,0}, {functional_width,functional_height} };
    int lastPoint[2] = {6, functional_height - 4};

    // create the original triangle
    m3_plot( originalPoints[0][0], originalPoints[0][1], CLR_RED );
    m3_plot( originalPoints[1][0], originalPoints[1][1], CLR_LIME );
    m3_plot( originalPoints[2][0], originalPoints[2][1], CLR_BLUE );

    // plot first point
    m3_plot( lastPoint[0], lastPoint[1], CLR_WHITE );  

    while(1) {

        // get a random point from originalPoints
        int r = rand() % 3;

        // find rise and run between that point and last point
        int run = (originalPoints[r][0] > lastPoint[0]) ? originalPoints[r][0] - lastPoint[0] : lastPoint[0] - originalPoints[r][0];
        int rise = (originalPoints[r][1] > lastPoint[1]) ? originalPoints[r][1] - lastPoint[1] : lastPoint[1] - originalPoints[r][1];

        // calc the new last point
        lastPoint[0] = (originalPoints[r][0] > lastPoint[0]) ? lastPoint[0] + (run / 2) : lastPoint[0] - (run / 2);
        lastPoint[1] = (originalPoints[r][1] > lastPoint[1]) ? lastPoint[1] + (rise / 2) : lastPoint[1] - (rise / 2);

        // plot this point
        m3_plot( lastPoint[0], lastPoint[1], CLR_WHITE );
        
        // slow things down so you can see it work
        int n = 1200;
        while(n--);

    }

    return 0;
}