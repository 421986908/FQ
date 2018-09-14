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

	/* ���Ӳ��� */
	// ���ͻ����뽻�׺�̨������ͨ������ʱ���÷��������á�
	virtual void OnFrontConnected() {};	

	// ���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á�
	virtual void OnFrontDisconnected() {};

	// ����Ӧ��
	virtual void OnRspError(FQRspInfo* pRspInfo) {};

	/* ��½���� */
	// ��½����Ӧ��
	virtual void OnRspUserLogin(FQLoginInfo* pLoginInfo, FQRspInfo* pRspInfo) {};

	// �ǳ�����Ӧ��
	virtual void OnRspUserLogout(FQLogoutInfo* pLogoutInfo, FQRspInfo* pRspInfo) {};
 
	/* ��Ʊ����Ӧ�� */
	// ָ����������
	virtual void OnRtnIndexDepthMarketData(FQIndexDepthMarketData* pIndexData) {};

	// ��Ʊ�����������
	virtual void OnRtnStockDepthMarketData(FQStockDepthMarketData* pMarketData) {};

	// ���ί������
	virtual void OnRtnOrderTickData(FQOrderTick* pOrderTick) {};

	// ��ʳɽ�����
	virtual void OnRtnTradeTickData(FQTradeTick* pTradeTick) {};

	/* �ڻ�����Ӧ�� */
	// �ڻ������������
	virtual void OnRtnFtdcDepthMarketData(FQFtdcDepthMarketData * pMarketData) {};

	/* ��Ȩ����Ӧ�� */
	// ��Ȩ�����������
	virtual void OnRtnOptionDepthMarketData(FQOptionDepthMarketData* pMarketData) {};

	// ��Ȩ������������
	virtual void OnRtnOptionBaseInfo(FQOptionBaseInfo* pBaseInfo) {};

	/* ����Ӧ�� */
	// ���Ĵ���Ӧ��
	virtual void OnRspSubscribeMarketData(FQRspInfo* pRspInfo) {};

	// ȡ�����Ĵ���Ӧ��
	virtual void OnRspUnsubscribeMarketData(FQRspInfo* pRspInfo) {};

	/* ��ȡ�����б�Ӧ�� */
	// ��ȡ�г��б�
	virtual void OnRspGetMarketList(FQMarketInfo pMarketInfo[], int nCount) {};

	// ��ȡ�����б�
	virtual void OnRspGetCodeList(FQCodeInfo pCodeList[], int nCount) {};
};

class FQ_MD_API_EXPORT CFQMdApi {
public:

	static CFQMdApi* CreateNxMdApi();

	// �ͷ�
	virtual void Release() = 0;

	// ��ʼ��
	virtual void Init() = 0;

	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;

	// ע��ǰ�û������ַ
	virtual bool RegisterFront(const char* pFrontAddress) = 0;

	// ע��ص��ӿ�
	virtual bool RegisterSpi(CFQMdSpi* pSpi) = 0;

	/* ���� */
	// ��������
	virtual bool SubscribeMarketData(char* pInstruments[], int nCount) = 0;

	// ȡ����������
	virtual bool UnsubscribeMarketData(char* pInstruments[], int nCount) = 0;

	/* ��½ */
	// ��½
	virtual bool ReqUserLogin(FQLoginInfo* pLoginInfo) = 0;

	// �ǳ�
	virtual bool ReqUserLogout(FQLogoutInfo* pLogoutInfo) = 0;

	/* ��ȡ�����б� */
	virtual bool ReqMarketList() = 0;

	virtual bool ReqCodeList(const char* market) = 0;

protected:
	virtual ~CFQMdApi();
};

#endif