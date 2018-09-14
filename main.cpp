#include <iostream>

#include "FQMdSpi.h"

#include<iomanip>

using namespace std;

int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    CFQMdApi* fq_api = CFQMdApi::CreateNxMdApi();
    CFQMdSpiImp *fq_spi = new CFQMdSpiImp();
    fq_spi->fq_api = fq_api;
    fq_api->RegisterFront("tcp://140.207.227.177:17410");
    fq_api->RegisterSpi((CFQMdSpi*)fq_spi);
    fq_api->Init();
    fq_api->Join();
    return 0;
}
