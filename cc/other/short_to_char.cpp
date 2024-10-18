#include "../common/cc.h"

int main()
{

    unsigned char uc[] = {0xe8, 0xe8, 0xe8, 0xe8};
    short &nShort = *(short *)(uc);
    nShort = 1;

    typedef struct  _Info
    {
        int nParam1;
        short nParam2;
        char chParam3;
        char chParam4[256];
        float fParam5;
        double fParam6;
    } Info, *PInfo;

    Info info;
    info.chParam3 = 23;
   
    int nSzie = sizeof(info);
    char *pBuffer = new char[nSzie];
    memcpy_s(pBuffer, nSzie, &info, nSzie);

    Info &info2 = *(Info *)pBuffer;
    delete[] pBuffer;
    return 0;
}