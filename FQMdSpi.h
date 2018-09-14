#include <iostream>

#include "FQMdApi.h"
#include "FQMdDataStruct.h"

using namespace std;

class CFQMdSpiImp : CFQMdSpi{
public:
    CFQMdApi* fq_api;
    double data[20][2];

    CFQMdSpiImp();

    void OnFrontConnected();
    void OnFrontDisconnected();
    void OnRspError(FQRspInfo* pRspInfo);
    void OnRtnIndexDepthMarketData(FQIndexDepthMarketData* pIndexData);
    void OnRtnStockDepthMarketData(FQStockDepthMarketData* pMarketData);

    void Show();
};