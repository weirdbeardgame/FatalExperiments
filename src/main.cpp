#include <iostream>
#include "PineClient.h"
#include "FatalFrameData.h"

int main()
{
    PineClient pine;
    pine.Open("pcsx2", 28011);
    system("clear");

    FatalData::PLYR_WRK plyr;
    while (true)
    {
        plyr = pine.ReadStruct<FatalData::PLYR_WRK>(0x00252a90, sizeof(FatalData::PLYR_WRK));
        plyr.Print();
        fflush(stdout);
        printf("\033[0;0H");
        printf("\e[?25l");

        memset(&plyr, 0, sizeof(plyr));
    }
    return 0;
}