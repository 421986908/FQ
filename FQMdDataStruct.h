#ifndef FQ_DATA_STRUCT_H__
#define FQ_DATA_STRUCT_H__

#define FQ_EXCHANGE_SH         "1"		///上交所
#define FQ_EXCHANGE_SZ         "2"		///深交所
#define FQ_EXCHANGE_SHFE       "3"		///上期所
#define FQ_EXCHANGE_ZCE        "4"		///郑商所
#define FQ_EXCHANGE_CFFEX      "7"		///中金所
#define FQ_EXCHANGE_DCE        "9"		///大商所
#define FQ_EXCHANGE_SGE        "10"		///上海黄金交易所

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
	char	TradingDay[9];					///交易日
	char	InstrumentID[31];				///合约代码
	char	ExchangeID[9];					///交易所代码
	char	ExchangeInstID[31];				///合约在交易所的代码
	double	LastPrice;						///最新价
	double	PreSettlementPrice;				///上次结算价
	double	PreClosePrice;					///昨收盘
	double	PreOpenInterest;				///昨持仓量
	double	OpenPrice;						///今开盘
	double	HighestPrice;					///最高价
	double	LowestPrice;					///最低价
	int	Volume;								///数量
	double	Turnover;						///成交金额
	double	OpenInterest; 					///持仓量
	double	ClosePrice;						///今收盘
	double	SettlementPrice;				///本次结算价
	double	UpperLimitPrice;				///涨停板价
	double	LowerLimitPrice;				///跌停板价
	double	PreDelta;						///昨虚实度
	double	CurrDelta;						///今虚实度
	char	UpdateTime[9];					///最后修改时间
	int	UpdateMillisec;						///最后修改毫秒
	double	BidPrice1;						///申买价一
	int	BidVolume1;							///申买量一
	double	AskPrice1;						///申卖价一
	int	AskVolume1;							///申卖量一
	double	BidPrice2;						///申买价二
	int	BidVolume2;							///申买量二
	double	AskPrice2;						///申卖价二
	int	AskVolume2;							///申卖量二
	double	BidPrice3;						///申买价三
	int	BidVolume3;							///申买量三
	double	AskPrice3;						///申卖价三
	int	AskVolume3;							///申卖量三
	double	BidPrice4;						///申买价四
	int	BidVolume4;							///申买量四
	double	AskPrice4;						///申卖价四
	int	AskVolume4;							///申卖量四
	double	BidPrice5;						///申买价五
	int	BidVolume5;							///申买量五
	double	AskPrice5;						///申卖价五
	int	AskVolume5;							///申卖量五
	double	AveragePrice;					///当日均价
};


/**
*	股票行情
*/ 
struct FQStockDepthMarketData
{
	char		ExchangeID[8];				// 交易所代码
	char		InstrumentID[20];			// 证券代码
	char		TimeStamp[20];				// 时间戳 YYYYMMDDHHMMSSsss（毫秒）， YYYY = 0000-9999, MM = 01-12, DD = 01-31, HH = 00-23, MM = 00-59, SS = 00-60 (秒)，sss=000-999 (毫秒)
	double		LastPx;						// 最新价
	double		PrevClosePx;				// 昨收价
	double		HighPx;						// 最高价
	double		OpenPx;						// 开盘价
	double		LowPx;						// 最低价
	double		ClosePx;					// 收盘价
	double		UpperLimitPrice ;			// 涨停板价
	double		LowerLimitPrice;			// 跌停板价
	double		TradeVolume;				// 成交数量
	double		TotalValueTraded;			// 成交金额
	double		IOPV;						// 基金净值
	double		BidPrice1;					// 申买价一
	int			BidVolume1;					// 申买量一
	double		AskPrice1;					// 申卖价一
	int			AskVolume1;					// 申卖量一
	double		BidPrice2;					// 申买价二
	int			BidVolume2;					// 申买量二
	double		AskPrice2;					// 申卖价二
	int			AskVolume2;					// 申卖量二
	double		BidPrice3;					// 申买价三
	int			BidVolume3;					// 申买量三
	double		AskPrice3;					// 申卖价三
	int			AskVolume3;					// 申卖量三
	double		BidPrice4;					// 申买价四
	int			BidVolume4;					// 申买量四
	double		AskPrice4;					// 申卖价四
	int			AskVolume4;					// 申卖量四
	double		BidPrice5;					// 申买价五
	int			BidVolume5;					// 申买量五
	double		AskPrice5;					// 申卖价五
	int			AskVolume5;					// 申卖量五
	double		BidPrice6;					// 申买价六
	int			BidVolume6;					// 申买量六
	double		AskPrice6;					// 申卖价六
	int			AskVolume6;					// 申卖量六
	double		BidPrice7;					// 申买价七
	int			BidVolume7;					// 申买量七
	double		AskPrice7;					// 申卖价七
	int			AskVolume7;					// 申卖量七
	double		BidPrice8;					// 申买价八
	int			BidVolume8;					// 申买量八
	double		AskPrice8;					// 申卖价八
	int			AskVolume8;					// 申卖量八
	double		BidPrice9;					// 申买价九
	int			BidVolume9;					// 申买量九
	double		AskPrice9;					// 申卖价九
	int			AskVolume9;					// 申卖量九
	double		BidPriceA;					// 申买价十
	int			BidVolumeA;					// 申买量十
	double		AskPriceA;					// 申卖价十
	int			AskVolumeA;					// 申卖量十
};

/**
*	指数行情
*/
struct FQIndexDepthMarketData
{
	char		ExchangeID[4];				// 交易所代码
	char		InstrumentID[20];			// 指数代码
	char		TimeStamp[20];				// 时间戳
	double		LastPx ;					// 最新指数
	double		PrevClosePx ;				// 昨日收盘指数
	double		HighPx ;					// 最高指数
	double		OpenPx ;					// 今开盘指数
	double		LowPx ;						// 最低指数
	double		ClosePx ;					// 收盘指数
	double		TradeVolume ;				// 成交数量
	double		TotalValueTraded ;			// 成交金额
};

/**
*	逐笔委托
*/
struct FQOrderTick
{
	char		ExchangeID[4];				// 交易所代码
	char		InstrumentID[20];			// 合约代码
	char		OrderTime[20];				// 时间戳
	double		Price;						// 委托价格
	double		Volume;						// 委托数量
	char		OrdType ;					// 订单类别 1 = 市价 2 = 限价 U = 本方最优
	char		Side;						// 买卖方向 1 = 买 2 = 卖 G = 借入 F = 出借
};

/**
*	逐笔成交
*/
struct FQTradeTick
{
	char		ExchangeID[4];				// 交易所代码
	char		InstrumentID[20];			// 合约代码
	char		TradeTime[20];				// 时间戳
	double		Price;						// 成交价格
	double		Volume;						// 成交数量
	char		ExecType ;					// 成交类别 4撤销 F成交
};


/*
*	adds 201706
*	期权行情
*/
struct FQOptionDepthMarketData
{
	char ExchangeID[8];								// 交易所代码
	char SecurityID[16];							// 合约编码
	char Timestamp[20];								// 时间戳
	double TotalLongPosition;						// 总持仓量
	double TradeVolume;								// 当日累计成交数量
	double TotalValueTraded;						// 当日累计成交金额
	double PreSettlPrice;							// 昨日结算价
	double SettlPrice;								// 今日结算价
	double OpenPrice;								// 今日开盘价
	double HighPrice;								// 当日最高成交价
	double LowPrice;								// 当日最低成交价
	double ClosePrice;								// 当日收盘价
	double TradePrice;								// 最新成交价格
	double AuctionPrice;							// 动态参考价格
	double AuctionQty;								// 虚拟匹配数量
	double BuyPrice1;								// 申买价一
	double BuyVolume1;								// 申买量一
	double SellPrice1;								// 申卖价一
	double SellVolume1;								// 申卖量一
	double BuyPrice2;								// 申买价二
	double BuyVolume2;								// 申买量二
	double SellPrice2;								// 申卖价二
	double SellVolume2;								// 申卖量二
	double BuyPrice3;								// 申买价三
	double BuyVolume3;								// 申买量三
	double SellPrice3;								// 申卖价三
	double SellVolume3;								// 申卖量三
	double BuyPrice4;								// 申买价四
	double BuyVolume4;								// 申买量四
	double SellPrice4;								// 申卖价四
	double SellVolume4;								// 申卖量四
	double BuyPrice5;								// 申买价五
	double BuyVolume5;								// 申买量五
	double SellPrice5;								// 申卖价五
	double SellVolume5;								// 申卖量五
};

/**
*	adds 201706
*	期权基础信息
*/
struct FQOptionBaseInfo
{
	char SecurityID[32];							// 2	SecurityID	合约编码	C8	期权合约的合约编码
	char ContractID[32];							// 3	ContractID	合约交易代码	C19
	char ContractSymbol[32]; 						// 4	ContractSymbol	期权合约简称	C20
	char UnderlyingSecurityID[32];					// 5	UnderlyingSecurityID	标的证券代码	C6
	char UnderlyingSymbol[32];						// 6	UnderlyingSymbol	基础证券证券名称	C8
	char UnderlyingType[32];						// 7	UnderlyingType	标的证券类型	C3	EBS – ETF， ASH – A股
	char OptionType;								// 8	OptionType	欧式美式	C1	若为欧式期权，则本字段为“E”；若为美式期权，则本字段为“A”
	char CallOrPut;									// 9	CallOrPut	认购认沽	C1	认购，则本字段为“C”；若为认沽，则本字段为“P”
	double ContractMultiplierUnit;					// 10	ContractMultiplierUnit	合约单位	N11	经过除权除息调整后的合约单位
	double ExercisePrice;							// 11	ExercisePrice	期权行权价	N11( 4 )	经过除权除息调整后的期权行权价，精确到0.0001元
	char StartDate[32];								// 12	StartDate	首个交易日	C8	期权首个交易日 , YYYYMMDD
	char EndDate[32];								// 13	EndDate	最后交易日	C8	期权最后交易日 / 行权日，YYYYMMDD
	char ExerciseDate[32];							// 14	ExerciseDate	期权行权日	C8	期权行权日，YYYYMMDD
	char DeliveryDate[32];							// 15	DeliveryDate	行权交割日	C8	行权交割日，默认为行权日的下一个交易日，YYYYMMDD
	char ExpireDate[32];							// 16	ExpireDate	期权到期日	C8	期权到期日，YYYYMMDD
	char UpdateVersion;								// 17	UpdateVersion	合约版本号	C1	期权合约的版本号
	double TotalLongPosition;						// 18	TotalLongPosition	当前合约未平仓数	N12	单位是 （张）
	double SecurityClosePx;							// 19	SecurityClosePx	合约前收盘价	N11( 4 )	昨日收盘价，右对齐，单位：元（精确到0.0001元）
	double SettlPrice;								// 20	SettlPrice	合约前结算价	N11( 4 )	昨日结算价，如遇除权除息则为调整后的结算价（合约上市首日填写参考价），右对齐，单位：元（精确到0.0001元）
	double UnderlyingClosePx;						// 21	UnderlyingClosePx	标的证券前收盘	N11( 4 )	期权标的证券除权除息调整后的前收盘价格，右对齐，单位：元（精确到0.0001元）
	char PriceLimitType;							// 22	PriceLimitType	涨跌幅限制类型	C1	‘N’有涨跌幅限制类型
	double DailyPriceUpLimit;						// 23	DailyPriceUpLimit	涨幅上限价格	N11( 4 )	当日期权涨停价格，单位：元（精确到0.0001元）
	double DailyPriceDownLimit;						// 24	DailyPriceDownLimit	跌幅下限价格	N11( 4 )	当日期权跌停价格，单位：元（精确到0.0001元）
	double MarginUnit;								// 25	MarginUnit	单位保证金	N16( 2 )	当日持有一张合约所需要的保证金数量，精确到分
	double MarginRatioParam1;						// 26	MarginRatioParam1	保证金计算比例参数一	N6( 2 )	保证金计算参数，单位： %
	double MarginRatioParam2;						// 27	MarginRatioParam2	保证金计算比例参数二	N6( 2 )	保证金计算参数，单位： %
	double RoundLot;								// 28	RoundLot	整手数	N12	一手对应的合约数
	double LmtOrdMinFloor;							// 29	LmtOrdMinFloor	单笔限价申报下限	N12	单笔限价申报的申报张数下限。
	double LmtOrdMaxFloor;							// 30	LmtOrdMaxFloor	单笔限价申报上限	N12	单笔限价申报的申报张数上限。
	double MktOrdMinFloor;							// 31	MktOrdMinFloor	单笔市价申报下限	N12	单笔市价申报的申报张数下限。
	double MktOrdMaxFloor;							// 32	MktOrdMaxFloor	单笔市价申报上限	N12	单笔市价申报的申报张数上限。
	double TickSize;								// 33	TickSize	最小报价单位	N11( 4 )	单位：元，精确到0.0001元
	char SecurityStatusFlag[32];					// 34	SecurityStatusFlag	期权合约状态信息标签	C8	该字段为8位字符串，左起每位表示特定的含义，无定义则填空格。
													// 第1位：‘0’表示可开仓，‘1’表示限制卖出开仓（不.包括备兑开仓）和买入开仓。
													// 第2位：‘0’表示未连续停牌，‘1’表示连续停牌。（预留，暂填0）
													// 第3位：‘0’表示未临近到期日，‘1’表示距离到期日不足5个交易日。
													// 第4位：‘0’表示近期未做调整，‘1’表示最近5个交易日内合约发生过调整。
													// 第5位：‘A’表示当日新挂牌的合约，‘E’表示存续的合约
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
	char SecurityID[32];					// 证券代码
	char Symbol[32];						// 证券简称
	char EnglishName[32];					// 英文简称
	char SecurityType[6];					// 证券代码类型
};

#pragma pack()

#endif