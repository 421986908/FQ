#ifndef FQ_MD_API
#define FQ_MD_API

#if defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define FQ_MD_API_EXPORT __declspec(dllexport)
#else
#define FQ_MD_API_EXPORT __declspec(dllimport)
#endif 
#else
#define FQ_MD_API_EXPORT 
#endif

#include "FQMdDataStruct.h"

class CFQMdSpi {
public:
	virtual ~CFQMdSpi() {}

	/* 连接部分 */
	// 当客户端与交易后台建立起通信连接时，该方法被调用。
	virtual void OnFrontConnected() {};	

	// 当客户端与交易后台通信连接断开时，该方法被调用。
	virtual void OnFrontDisconnected() {};

	// 错误应答
	virtual void OnRspError(FQRspInfo* pRspInfo) {};

	/* 登陆部分 */
	// 登陆请求应答
	virtual void OnRspUserLogin(FQLoginInfo* pLoginInfo, FQRspInfo* pRspInfo) {};

	// 登出请求应答
	virtual void OnRspUserLogout(FQLogoutInfo* pLogoutInfo, FQRspInfo* pRspInfo) {};
 
	/* 股票数据应答 */
	// 指数行情推送
	virtual void OnRtnIndexDepthMarketData(FQIndexDepthMarketData* pIndexData) {};

	// 股票深度行情推送
	virtual void OnRtnStockDepthMarketData(FQStockDepthMarketData* pMarketData) {};

	// 逐笔委托推送
	virtual void OnRtnOrderTickData(FQOrderTick* pOrderTick) {};

	// 逐笔成交推送
	virtual void OnRtnTradeTickData(FQTradeTick* pTradeTick) {};

	/* 期货数据应答 */
	// 期货深度行情推送
	virtual void OnRtnFtdcDepthMarketData(FQFtdcDepthMarketData * pMarketData) {};

	/* 期权数据应答 */
	// 期权深度行情推送
	virtual void OnRtnOptionDepthMarketData(FQOptionDepthMarketData* pMarketData) {};

	// 期权基础数据推送
	virtual void OnRtnOptionBaseInfo(FQOptionBaseInfo* pBaseInfo) {};

	/* 订阅应答 */
	// 订阅代码应答
	virtual void OnRspSubscribeMarketData(FQRspInfo* pRspInfo) {};

	// 取消订阅代码应答
	virtual void OnRspUnsubscribeMarketData(FQRspInfo* pRspInfo) {};

	/* 获取代码列表应答 */
	// 获取市场列表
	virtual void OnRspGetMarketList(FQMarketInfo pMarketInfo[], int nCount) {};

	// 获取代码列表
	virtual void OnRspGetCodeList(FQCodeInfo pCodeList[], int nCount) {};
};

class FQ_MD_API_EXPORT CFQMdApi {
public:

	static CFQMdApi* CreateNxMdApi();

	// 释放
	virtual void Release() = 0;

	// 初始化
	virtual void Init() = 0;

	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;

	// 注册前置机网络地址
	virtual bool RegisterFront(const char* pFrontAddress) = 0;

	// 注册回调接口
	virtual bool RegisterSpi(CFQMdSpi* pSpi) = 0;

	/* 订阅 */
	// 订阅行情
	virtual bool SubscribeMarketData(char* pInstruments[], int nCount) = 0;

	// 取消订阅行情
	virtual bool UnsubscribeMarketData(char* pInstruments[], int nCount) = 0;

	/* 登陆 */
	// 登陆
	virtual bool ReqUserLogin(FQLoginInfo* pLoginInfo) = 0;

	// 登出
	virtual bool ReqUserLogout(FQLogoutInfo* pLogoutInfo) = 0;

	/* 获取代码列表 */
	virtual bool ReqMarketList() = 0;

	virtual bool ReqCodeList(const char* market) = 0;

protected:
	virtual ~CFQMdApi();
};

#endif