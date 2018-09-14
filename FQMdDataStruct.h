#ifndef FQ_DATA_STRUCT_H__
#define FQ_DATA_STRUCT_H__

#define FQ_EXCHANGE_SH         "1"		///�Ͻ���
#define FQ_EXCHANGE_SZ         "2"		///���
#define FQ_EXCHANGE_SHFE       "3"		///������
#define FQ_EXCHANGE_ZCE        "4"		///֣����
#define FQ_EXCHANGE_CFFEX      "7"		///�н���
#define FQ_EXCHANGE_DCE        "9"		///������
#define FQ_EXCHANGE_SGE        "10"		///�Ϻ��ƽ�����

#pragma pack(1)

struct FQLoginInfo
{
	char brokerId[32];
	char userId[32];
	char password[32];
};

struct FQLogoutInfo
{
	char brokerId[32];
	char userId[32];
};

struct FQRspInfo
{
	int errorId;
	char errorMsg[128];
};

struct FQLoginRspInfo 
{
	FQLoginInfo loginInfo;
	FQRspInfo rspInfo;
};

struct FQLogoutRspInfo 
{
	FQLogoutInfo logoutInfo;
	FQRspInfo rspInfo;
};


struct FQFtdcDepthMarketData
{
	char	TradingDay[9];					///������
	char	InstrumentID[31];				///��Լ����
	char	ExchangeID[9];					///����������
	char	ExchangeInstID[31];				///��Լ�ڽ������Ĵ���
	double	LastPrice;						///���¼�
	double	PreSettlementPrice;				///�ϴν����
	double	PreClosePrice;					///������
	double	PreOpenInterest;				///��ֲ���
	double	OpenPrice;						///����
	double	HighestPrice;					///��߼�
	double	LowestPrice;					///��ͼ�
	int	Volume;								///����
	double	Turnover;						///�ɽ����
	double	OpenInterest; 					///�ֲ���
	double	ClosePrice;						///������
	double	SettlementPrice;				///���ν����
	double	UpperLimitPrice;				///��ͣ���
	double	LowerLimitPrice;				///��ͣ���
	double	PreDelta;						///����ʵ��
	double	CurrDelta;						///����ʵ��
	char	UpdateTime[9];					///����޸�ʱ��
	int	UpdateMillisec;						///����޸ĺ���
	double	BidPrice1;						///�����һ
	int	BidVolume1;							///������һ
	double	AskPrice1;						///������һ
	int	AskVolume1;							///������һ
	double	BidPrice2;						///����۶�
	int	BidVolume2;							///��������
	double	AskPrice2;						///�����۶�
	int	AskVolume2;							///��������
	double	BidPrice3;						///�������
	int	BidVolume3;							///��������
	double	AskPrice3;						///��������
	int	AskVolume3;							///��������
	double	BidPrice4;						///�������
	int	BidVolume4;							///��������
	double	AskPrice4;						///��������
	int	AskVolume4;							///��������
	double	BidPrice5;						///�������
	int	BidVolume5;							///��������
	double	AskPrice5;						///��������
	int	AskVolume5;							///��������
	double	AveragePrice;					///���վ���
};


/**
*	��Ʊ����
*/ 
struct FQStockDepthMarketData
{
	char		ExchangeID[8];				// ����������
	char		InstrumentID[20];			// ֤ȯ����
	char		TimeStamp[20];				// ʱ��� YYYYMMDDHHMMSSsss�����룩�� YYYY = 0000-9999, MM = 01-12, DD = 01-31, HH = 00-23, MM = 00-59, SS = 00-60 (��)��sss=000-999 (����)
	double		LastPx;						// ���¼�
	double		PrevClosePx;				// ���ռ�
	double		HighPx;						// ��߼�
	double		OpenPx;						// ���̼�
	double		LowPx;						// ��ͼ�
	double		ClosePx;					// ���̼�
	double		UpperLimitPrice ;			// ��ͣ���
	double		LowerLimitPrice;			// ��ͣ���
	double		TradeVolume;				// �ɽ�����
	double		TotalValueTraded;			// �ɽ����
	double		IOPV;						// ����ֵ
	double		BidPrice1;					// �����һ
	int			BidVolume1;					// ������һ
	double		AskPrice1;					// ������һ
	int			AskVolume1;					// ������һ
	double		BidPrice2;					// ����۶�
	int			BidVolume2;					// ��������
	double		AskPrice2;					// �����۶�
	int			AskVolume2;					// ��������
	double		BidPrice3;					// �������
	int			BidVolume3;					// ��������
	double		AskPrice3;					// ��������
	int			AskVolume3;					// ��������
	double		BidPrice4;					// �������
	int			BidVolume4;					// ��������
	double		AskPrice4;					// ��������
	int			AskVolume4;					// ��������
	double		BidPrice5;					// �������
	int			BidVolume5;					// ��������
	double		AskPrice5;					// ��������
	int			AskVolume5;					// ��������
	double		BidPrice6;					// �������
	int			BidVolume6;					// ��������
	double		AskPrice6;					// ��������
	int			AskVolume6;					// ��������
	double		BidPrice7;					// �������
	int			BidVolume7;					// ��������
	double		AskPrice7;					// ��������
	int			AskVolume7;					// ��������
	double		BidPrice8;					// ����۰�
	int			BidVolume8;					// ��������
	double		AskPrice8;					// �����۰�
	int			AskVolume8;					// ��������
	double		BidPrice9;					// ����۾�
	int			BidVolume9;					// ��������
	double		AskPrice9;					// �����۾�
	int			AskVolume9;					// ��������
	double		BidPriceA;					// �����ʮ
	int			BidVolumeA;					// ������ʮ
	double		AskPriceA;					// ������ʮ
	int			AskVolumeA;					// ������ʮ
};

/**
*	ָ������
*/
struct FQIndexDepthMarketData
{
	char		ExchangeID[4];				// ����������
	char		InstrumentID[20];			// ָ������
	char		TimeStamp[20];				// ʱ���
	double		LastPx ;					// ����ָ��
	double		PrevClosePx ;				// ��������ָ��
	double		HighPx ;					// ���ָ��
	double		OpenPx ;					// ����ָ��
	double		LowPx ;						// ���ָ��
	double		ClosePx ;					// ����ָ��
	double		TradeVolume ;				// �ɽ�����
	double		TotalValueTraded ;			// �ɽ����
};

/**
*	���ί��
*/
struct FQOrderTick
{
	char		ExchangeID[4];				// ����������
	char		InstrumentID[20];			// ��Լ����
	char		OrderTime[20];				// ʱ���
	double		Price;						// ί�м۸�
	double		Volume;						// ί������
	char		OrdType ;					// ������� 1 = �м� 2 = �޼� U = ��������
	char		Side;						// �������� 1 = �� 2 = �� G = ���� F = ����
};

/**
*	��ʳɽ�
*/
struct FQTradeTick
{
	char		ExchangeID[4];				// ����������
	char		InstrumentID[20];			// ��Լ����
	char		TradeTime[20];				// ʱ���
	double		Price;						// �ɽ��۸�
	double		Volume;						// �ɽ�����
	char		ExecType ;					// �ɽ���� 4���� F�ɽ�
};


/*
*	adds 201706
*	��Ȩ����
*/
struct FQOptionDepthMarketData
{
	char ExchangeID[8];								// ����������
	char SecurityID[16];							// ��Լ����
	char Timestamp[20];								// ʱ���
	double TotalLongPosition;						// �ֲܳ���
	double TradeVolume;								// �����ۼƳɽ�����
	double TotalValueTraded;						// �����ۼƳɽ����
	double PreSettlPrice;							// ���ս����
	double SettlPrice;								// ���ս����
	double OpenPrice;								// ���տ��̼�
	double HighPrice;								// ������߳ɽ���
	double LowPrice;								// ������ͳɽ���
	double ClosePrice;								// �������̼�
	double TradePrice;								// ���³ɽ��۸�
	double AuctionPrice;							// ��̬�ο��۸�
	double AuctionQty;								// ����ƥ������
	double BuyPrice1;								// �����һ
	double BuyVolume1;								// ������һ
	double SellPrice1;								// ������һ
	double SellVolume1;								// ������һ
	double BuyPrice2;								// ����۶�
	double BuyVolume2;								// ��������
	double SellPrice2;								// �����۶�
	double SellVolume2;								// ��������
	double BuyPrice3;								// �������
	double BuyVolume3;								// ��������
	double SellPrice3;								// ��������
	double SellVolume3;								// ��������
	double BuyPrice4;								// �������
	double BuyVolume4;								// ��������
	double SellPrice4;								// ��������
	double SellVolume4;								// ��������
	double BuyPrice5;								// �������
	double BuyVolume5;								// ��������
	double SellPrice5;								// ��������
	double SellVolume5;								// ��������
};

/**
*	adds 201706
*	��Ȩ������Ϣ
*/
struct FQOptionBaseInfo
{
	char SecurityID[32];							// 2	SecurityID	��Լ����	C8	��Ȩ��Լ�ĺ�Լ����
	char ContractID[32];							// 3	ContractID	��Լ���״���	C19
	char ContractSymbol[32]; 						// 4	ContractSymbol	��Ȩ��Լ���	C20
	char UnderlyingSecurityID[32];					// 5	UnderlyingSecurityID	���֤ȯ����	C6
	char UnderlyingSymbol[32];						// 6	UnderlyingSymbol	����֤ȯ֤ȯ����	C8
	char UnderlyingType[32];						// 7	UnderlyingType	���֤ȯ����	C3	EBS �C ETF�� ASH �C A��
	char OptionType;								// 8	OptionType	ŷʽ��ʽ	C1	��Ϊŷʽ��Ȩ�����ֶ�Ϊ��E������Ϊ��ʽ��Ȩ�����ֶ�Ϊ��A��
	char CallOrPut;									// 9	CallOrPut	�Ϲ��Ϲ�	C1	�Ϲ������ֶ�Ϊ��C������Ϊ�Ϲ������ֶ�Ϊ��P��
	double ContractMultiplierUnit;					// 10	ContractMultiplierUnit	��Լ��λ	N11	������Ȩ��Ϣ������ĺ�Լ��λ
	double ExercisePrice;							// 11	ExercisePrice	��Ȩ��Ȩ��	N11( 4 )	������Ȩ��Ϣ���������Ȩ��Ȩ�ۣ���ȷ��0.0001Ԫ
	char StartDate[32];								// 12	StartDate	�׸�������	C8	��Ȩ�׸������� , YYYYMMDD
	char EndDate[32];								// 13	EndDate	�������	C8	��Ȩ������� / ��Ȩ�գ�YYYYMMDD
	char ExerciseDate[32];							// 14	ExerciseDate	��Ȩ��Ȩ��	C8	��Ȩ��Ȩ�գ�YYYYMMDD
	char DeliveryDate[32];							// 15	DeliveryDate	��Ȩ������	C8	��Ȩ�����գ�Ĭ��Ϊ��Ȩ�յ���һ�������գ�YYYYMMDD
	char ExpireDate[32];							// 16	ExpireDate	��Ȩ������	C8	��Ȩ�����գ�YYYYMMDD
	char UpdateVersion;								// 17	UpdateVersion	��Լ�汾��	C1	��Ȩ��Լ�İ汾��
	double TotalLongPosition;						// 18	TotalLongPosition	��ǰ��Լδƽ����	N12	��λ�� ���ţ�
	double SecurityClosePx;							// 19	SecurityClosePx	��Լǰ���̼�	N11( 4 )	�������̼ۣ��Ҷ��룬��λ��Ԫ����ȷ��0.0001Ԫ��
	double SettlPrice;								// 20	SettlPrice	��Լǰ�����	N11( 4 )	���ս���ۣ�������Ȩ��Ϣ��Ϊ������Ľ���ۣ���Լ����������д�ο��ۣ����Ҷ��룬��λ��Ԫ����ȷ��0.0001Ԫ��
	double UnderlyingClosePx;						// 21	UnderlyingClosePx	���֤ȯǰ����	N11( 4 )	��Ȩ���֤ȯ��Ȩ��Ϣ�������ǰ���̼۸��Ҷ��룬��λ��Ԫ����ȷ��0.0001Ԫ��
	char PriceLimitType;							// 22	PriceLimitType	�ǵ�����������	C1	��N�����ǵ�����������
	double DailyPriceUpLimit;						// 23	DailyPriceUpLimit	�Ƿ����޼۸�	N11( 4 )	������Ȩ��ͣ�۸񣬵�λ��Ԫ����ȷ��0.0001Ԫ��
	double DailyPriceDownLimit;						// 24	DailyPriceDownLimit	�������޼۸�	N11( 4 )	������Ȩ��ͣ�۸񣬵�λ��Ԫ����ȷ��0.0001Ԫ��
	double MarginUnit;								// 25	MarginUnit	��λ��֤��	N16( 2 )	���ճ���һ�ź�Լ����Ҫ�ı�֤����������ȷ����
	double MarginRatioParam1;						// 26	MarginRatioParam1	��֤������������һ	N6( 2 )	��֤������������λ�� %
	double MarginRatioParam2;						// 27	MarginRatioParam2	��֤��������������	N6( 2 )	��֤������������λ�� %
	double RoundLot;								// 28	RoundLot	������	N12	һ�ֶ�Ӧ�ĺ�Լ��
	double LmtOrdMinFloor;							// 29	LmtOrdMinFloor	�����޼��걨����	N12	�����޼��걨���걨�������ޡ�
	double LmtOrdMaxFloor;							// 30	LmtOrdMaxFloor	�����޼��걨����	N12	�����޼��걨���걨�������ޡ�
	double MktOrdMinFloor;							// 31	MktOrdMinFloor	�����м��걨����	N12	�����м��걨���걨�������ޡ�
	double MktOrdMaxFloor;							// 32	MktOrdMaxFloor	�����м��걨����	N12	�����м��걨���걨�������ޡ�
	double TickSize;								// 33	TickSize	��С���۵�λ	N11( 4 )	��λ��Ԫ����ȷ��0.0001Ԫ
	char SecurityStatusFlag[32];					// 34	SecurityStatusFlag	��Ȩ��Լ״̬��Ϣ��ǩ	C8	���ֶ�Ϊ8λ�ַ���������ÿλ��ʾ�ض��ĺ��壬�޶�������ո�
													// ��1λ����0����ʾ�ɿ��֣���1����ʾ�����������֣���.�������ҿ��֣������뿪�֡�
													// ��2λ����0����ʾδ����ͣ�ƣ���1����ʾ����ͣ�ơ���Ԥ��������0��
													// ��3λ����0����ʾδ�ٽ������գ���1����ʾ���뵽���ղ���5�������ա�
													// ��4λ����0����ʾ����δ����������1����ʾ���5���������ں�Լ������������
													// ��5λ����A����ʾ�����¹��Ƶĺ�Լ����E����ʾ�����ĺ�Լ
};


// Outer
struct FQMarketInfo
{
	char ExchangeID[4];
	int CodeCount;
	int CodeDate;
};

struct FQCodeInfo 
{
	char ExchangeID[4];
	char SecurityID[32];					// ֤ȯ����
	char Symbol[32];						// ֤ȯ���
	char EnglishName[32];					// Ӣ�ļ��
	char SecurityType[6];					// ֤ȯ��������
};

#pragma pack()

#endif