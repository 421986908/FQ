#include "FQMdSpi.h"

#include <string.h>
#include <fstream>

#include "boost/thread/thread.hpp"
#include "boost/lexical_cast.hpp"

CFQMdSpiImp::CFQMdSpiImp()
:preMin("")
{
	char line[200];
	string strLine;
	ifstream file("F:\\FQ\\FQ\\Debug\\20180916.txt");
    if(!file.is_open())
    {
        return;
    }
	while (!file.eof())//1900-12-12 12:21:02.111
	{
		file.getline(line, 200);
		strLine = line;
		string time = strLine.substr(0, 26);
        int year = boost::lexical_cast<int>(time.substr(0,4));
        int month = boost::lexical_cast<int>(time.substr(5,2));
        int day = boost::lexical_cast<int>(time.substr(8,2));
        int hour = boost::lexical_cast<int>(time.substr(11,2));
        int minute = boost::lexical_cast<int>(time.substr(14,2));
        stringstream stream;
        stream << year << month << day << hour << minute;
        time.clear();
        time = stream.str();
		string id = strLine.substr(35, 6);
		string price = strLine.substr(42, 7);
		size_t pos = strLine.find(".", 54);
		string volume = strLine.substr(54, pos - 54);

		if (!id.compare("000001"))
		{
			yestoday_volume01[time] = boost::lexical_cast<double>(volume);
		}
		else
		{
			yestoday_volume16[time] = boost::lexical_cast<double>(volume);
		}
	}
}

void CFQMdSpiImp::OnRspError(FQRspInfo* pRspInfo)
{
    cout << pRspInfo->errorMsg << endl;
}

void CFQMdSpiImp::OnFrontConnected()
{
    cout << "connected!" << endl;
    const char* tmp[10];
    tmp[0] = "000016";
    tmp[1] = "000001";
    fq_api->SubscribeMarketData((char **)tmp, 2);
}

void CFQMdSpiImp::OnFrontDisconnected()
{
    cout << "disconnected" << endl;
}

void CFQMdSpiImp::OnRtnIndexDepthMarketData(FQIndexDepthMarketData* pIndexData)
{
    string time;
    pIndexData->TimeStamp[12] = 0;//199012211025
    time = pIndexData->TimeStamp;
    if(time != curMin)
    {
        preMin = curMin;
        if(curMin.empty())
            preMin = time;
        curMin = time;
    }
    if(!strcmp(pIndexData->InstrumentID,"000001"))
    {
        data[0][0] = pIndexData->LastPx;
        data[0][1] = pIndexData->PrevClosePx;

		today_volume01[curMin] = pIndexData->TradeVolume;
    }
    else
    {
        data[1][0] = pIndexData->LastPx;
        data[1][1] = pIndexData->PrevClosePx;

        today_volume16[curMin] = pIndexData->TradeVolume;
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
    cout << "  " << today_volume01[preMin] / yestoday_volume01[preMin];
    cout << "  ";
    cout << data[1][0] << "  " << (data[1][0] - data[1][1]) / data[1][1] * 100;
    cout << "  " << today_volume16[preMin] / yestoday_volume16[preMin];
    cout << endl;
}