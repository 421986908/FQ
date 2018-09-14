#include "FQMdSpi.h"

#include <string.h>

#include "boost/thread/thread.hpp"
#include "boost/filesystem.hpp"

using namespace boost::filesystem;

CFQMdSpiImp::CFQMdSpiImp()
{
    path fpath("test");
    boost::filesystem::ifstream filestream(fpath);
    cout << filestream << endl;

    filestream.close();
}

void CFQMdSpiImp::OnRspError(FQRspInfo* pRspInfo)
{
    cout << pRspInfo->errorMsg << endl;
}

void CFQMdSpiImp::OnFrontConnected()
{
    cout << "connected!" << endl;
    char* tmp[10];
    tmp[0] = "000016";
    tmp[1] = "000001";
    fq_api->SubscribeMarketData(tmp, 2);
}

void CFQMdSpiImp::OnFrontDisconnected()
{
    cout << "disconnected" << endl;
}

void CFQMdSpiImp::OnRtnIndexDepthMarketData(FQIndexDepthMarketData* pIndexData)
{
    if(!strcmp(pIndexData->InstrumentID,"000001"))
    {
        data[0][0] = pIndexData->LastPx;
        data[0][1] = pIndexData->PrevClosePx;
    }
    else
    {
        data[1][0] = pIndexData->LastPx;
        data[1][1] = pIndexData->PrevClosePx;
    }

    Show();
}

void CFQMdSpiImp::OnRtnStockDepthMarketData(FQStockDepthMarketData* pMarketData)
{
    if(pMarketData->ExchangeID[0] == '2')
        return;
    cout << pMarketData->LastPx << "  ";
    cout << (pMarketData->LastPx - pMarketData->PrevClosePx) / pMarketData->PrevClosePx * 100;
    cout << endl;
}

void CFQMdSpiImp::Show()
{
    cout << data[0][0] << "  " << (data[0][0] - data[0][1]) / data[0][1] * 100;
    cout << "  ";
    cout << data[1][0] << "  " << (data[1][0] - data[1][1]) / data[1][1] * 100;
    cout << endl;
}