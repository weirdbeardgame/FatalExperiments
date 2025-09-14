#include <iostream>
#include "PineClient.h"
#include "FatalFrameData.h"

int main()
{
    PineClient pine;
    pine.Open("pcsx2", 28011);
    system("clear");

    FatalData::PLYR_WRK *plyr = new FatalData::PLYR_WRK();
    u_short hp;
    while (true)
    {
        /*plyr = pine.ReadStruct<FatalData::PLYR_WRK>(0x252a90, sizeof(FatalData::PLYR_WRK));

        if (plyr == nullptr)
        {
            printf("Read Failed");
            break;
        }

        plyr->Print();*/

        hp = pine.Read16(0x252aa4);

        printf("HP: %u\n", hp);

        fflush(stdout);
        printf("\033[0;0H");
        printf("\e[?25l");

        memset(&plyr, 0, sizeof(plyr));
    }
    return 0;
}