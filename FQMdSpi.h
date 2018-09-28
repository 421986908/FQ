#include <iostream>
#include <map>

#include "FQMdApi.h"
#include "FQMdDataStruct.h"

using namespace std;

class CFQMdSpiImp : CFQMdSpi{
public:
    CFQMdApi* fq_api;
    double data[20][2];
	map<string, double> yestoday_volume01;
	map<string, double> yestoday_volume16;
    map<string, double> today_volume01;
	map<string, double> today_volume16;

    string preMin;
    string curMin;

    ofstream* file01;
    ofstream* file16;

    CFQMdSpiImp();

    void OnFrontConnected();
    void OnFrontDisconnected();
    void OnRspError(FQRspInfo* pRspInfo);
    void OnRtnIndexDepthMarketData(FQIndexDepthMarketData* pIndexData);
    void OnRtnStockDepthMarketData(FQStockDepthMarketData* pMarketData);

    void Show();
};