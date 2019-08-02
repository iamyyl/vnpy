// vnctpmd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnctpmd.h"

///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void MdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
    processFrontConnected(&task);
}

void MdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
    processFrontDisconnected(&task);
}

void MdApi::OnHeartBeatWarning(int nTimeLapse)
{
	Task task = Task();
	task.task_name = ONHEARTBEATWARNING;
	task.task_id = nTimeLapse;
    processHeartBeatWarning(&task);
}

void MdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLogin)
	{
		CThostFtdcRspUserLoginField *task_data = new CThostFtdcRspUserLoginField();
		*task_data = *pRspUserLogin;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspUserLogin(&task);
}

void MdApi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;
	if (pUserLogout)
	{
		CThostFtdcUserLogoutField *task_data = new CThostFtdcUserLogoutField();
		*task_data = *pUserLogout;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspUserLogout(&task);
}

void MdApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspError(&task);
}

void MdApi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSUBMARKETDATA;
	if (pSpecificInstrument)
	{
		CThostFtdcSpecificInstrumentField *task_data = new CThostFtdcSpecificInstrumentField();
		*task_data = *pSpecificInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspSubMarketData(&task);
}

void MdApi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBMARKETDATA;
	if (pSpecificInstrument)
	{
		CThostFtdcSpecificInstrumentField *task_data = new CThostFtdcSpecificInstrumentField();
		*task_data = *pSpecificInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspUnSubMarketData(&task);
}

void MdApi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSUBFORQUOTERSP;
	if (pSpecificInstrument)
	{
		CThostFtdcSpecificInstrumentField *task_data = new CThostFtdcSpecificInstrumentField();
		*task_data = *pSpecificInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspSubForQuoteRsp(&task);
}

void MdApi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBFORQUOTERSP;
	if (pSpecificInstrument)
	{
		CThostFtdcSpecificInstrumentField *task_data = new CThostFtdcSpecificInstrumentField();
		*task_data = *pSpecificInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CThostFtdcRspInfoField *task_error = new CThostFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
    processRspUnSubForQuoteRsp(&task);
}

void MdApi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	Task task = Task();
	task.task_name = ONRTNDEPTHMARKETDATA;
	if (pDepthMarketData)
	{
		CThostFtdcDepthMarketDataField *task_data = new CThostFtdcDepthMarketDataField();
		*task_data = *pDepthMarketData;
		task.task_data = task_data;
	}
    processRtnDepthMarketData(&task);
}

void MdApi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	Task task = Task();
	task.task_name = ONRTNFORQUOTERSP;
	if (pForQuoteRsp)
	{
		CThostFtdcForQuoteRspField *task_data = new CThostFtdcForQuoteRspField();
		*task_data = *pForQuoteRsp;
		task.task_data = task_data;
	}
    processRtnForQuoteRsp(&task);
}

void MdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	onMdApi_->onFrontConnected();
}

void MdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	onMdApi_->onFrontDisconnected(task->task_id);
}

void MdApi::processHeartBeatWarning(Task *task)
{
	gil_scoped_acquire acquire;
	onMdApi_->onHeartBeatWarning(task->task_id);
}

void MdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcRspUserLoginField *task_data = (CThostFtdcRspUserLoginField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["LoginTime"] = toUtf(task_data->LoginTime);
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		data["SystemName"] = toUtf(task_data->SystemName);
		data["FrontID"] = task_data->FrontID;
		data["SessionID"] = task_data->SessionID;
		data["MaxOrderRef"] = toUtf(task_data->MaxOrderRef);
		data["SHFETime"] = toUtf(task_data->SHFETime);
		data["DCETime"] = toUtf(task_data->DCETime);
		data["CZCETime"] = toUtf(task_data->CZCETime);
		data["FFEXTime"] = toUtf(task_data->FFEXTime);
		data["INETime"] = toUtf(task_data->INETime);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspUserLogin(data, error, task->task_id, task->task_last);
}

void MdApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcUserLogoutField *task_data = (CThostFtdcUserLogoutField*)task->task_data;
		data["BrokerID"] = toUtf(task_data->BrokerID);
		data["UserID"] = toUtf(task_data->UserID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspUserLogout(data, error, task->task_id, task->task_last);
}

void MdApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspError(error, task->task_id, task->task_last);
}

void MdApi::processRspSubMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSpecificInstrumentField *task_data = (CThostFtdcSpecificInstrumentField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspSubMarketData(data, error, task->task_id, task->task_last);
}

void MdApi::processRspUnSubMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSpecificInstrumentField *task_data = (CThostFtdcSpecificInstrumentField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspUnSubMarketData(data, error, task->task_id, task->task_last);
}

void MdApi::processRspSubForQuoteRsp(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSpecificInstrumentField *task_data = (CThostFtdcSpecificInstrumentField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspSubForQuoteRsp(data, error, task->task_id, task->task_last);
}

void MdApi::processRspUnSubForQuoteRsp(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcSpecificInstrumentField *task_data = (CThostFtdcSpecificInstrumentField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CThostFtdcRspInfoField *task_error = (CThostFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	onMdApi_->onRspUnSubForQuoteRsp(data, error, task->task_id, task->task_last);
}

void MdApi::processRtnDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcDepthMarketDataField *task_data = (CThostFtdcDepthMarketDataField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["ExchangeInstID"] = toUtf(task_data->ExchangeInstID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["Volume"] = task_data->Volume;
		data["Turnover"] = task_data->Turnover;
		data["OpenInterest"] = task_data->OpenInterest;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PreDelta"] = task_data->PreDelta;
		data["CurrDelta"] = task_data->CurrDelta;
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["AveragePrice"] = task_data->AveragePrice;
		data["ActionDay"] = toUtf(task_data->ActionDay);
		delete task->task_data;
	}
	onMdApi_->onRtnDepthMarketData(data);
}

void MdApi::processRtnForQuoteRsp(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CThostFtdcForQuoteRspField *task_data = (CThostFtdcForQuoteRspField*)task->task_data;
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ForQuoteSysID"] = toUtf(task_data->ForQuoteSysID);
		data["ForQuoteTime"] = toUtf(task_data->ForQuoteTime);
		data["ActionDay"] = toUtf(task_data->ActionDay);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		delete task->task_data;
	}
	onMdApi_->onRtnForQuoteRsp(data);
}

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void MdApi::createFtdcMdApi(string pszFlowPath)
{
	this->api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
}

void MdApi::release()
{
	this->api->Release();
}

void MdApi::init()
{
	this->active = true;
	this->api->Init();
}

int MdApi::join()
{
	int i = this->api->Join();
	return i;
}

int MdApi::exit()
{
	this->active = false;
    this->onMdApi_->onExit();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
}

string MdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
}

void MdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
}

int MdApi::subscribeMarketData(string instrumentID)
{
	char* buffer = (char*) instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeMarketData(myreq, 1);
	return i;
}

int MdApi::unSubscribeMarketData(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeMarketData(myreq, 1);
	return i;
}

int MdApi::subscribeForQuoteRsp(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->SubscribeForQuoteRsp(myreq, 1);
	return i;
}

int MdApi::unSubscribeForQuoteRsp(string instrumentID)
{
	char* buffer = (char*)instrumentID.c_str();
	char* myreq[1] = { buffer };
	int i = this->api->UnSubscribeForQuoteRsp(myreq, 1);
	return i;
}

int MdApi::reqUserLogin(const dict &req, int reqid)
{
	CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "TradingDay", myreq.TradingDay);
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	getString(req, "UserProductInfo", myreq.UserProductInfo);
	getString(req, "InterfaceProductInfo", myreq.InterfaceProductInfo);
	getString(req, "ProtocolInfo", myreq.ProtocolInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "OneTimePassword", myreq.OneTimePassword);
	getString(req, "ClientIPAddress", myreq.ClientIPAddress);
	getString(req, "LoginRemark", myreq.LoginRemark);
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
}

int MdApi::reqUserLogout(const dict &req, int reqid)
{
	CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "BrokerID", myreq.BrokerID);
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, reqid);
	return i;
}


///-------------------------------------------------------------------------------------
///  OnMdApi
///-------------------------------------------------------------------------------------
void OnMdApi::onExit()
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onExit);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onFrontConnected()
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onFrontConnected);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onFrontDisconnected(int reqid)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onFrontDisconnected, reqid);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onHeartBeatWarning(int reqid)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onHeartBeatWarning, reqid);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspUserLogin(const dict &data, const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspUserLogin, data, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspUserLogout(const dict &data, const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspUserLogout, data, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspError(const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspError, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspSubMarketData(const dict &data, const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspSubMarketData, data, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspUnSubMarketData(const dict &data, const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspUnSubMarketData, data, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspSubForQuoteRsp, data, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRspUnSubForQuoteRsp(const dict &data, const dict &error, int reqid, bool last)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRspUnSubForQuoteRsp, data, error, reqid, last);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRtnDepthMarketData(const dict &data)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRtnDepthMarketData, data);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

void OnMdApi::onRtnForQuoteRsp(const dict &data)
{
    try
    {
        PYBIND11_OVERLOAD(void, OnMdApi, onRtnForQuoteRsp, data);
    }
    catch (const error_already_set &e)
    {
        cout << e.what() << endl;
    }
}

PYBIND11_MODULE(vnctpmd, m)
{
	class_<MdApi> mdapi(m, "MdApi", module_local());
	mdapi
		.def(init<>())
		.def("setOnMdApi", &MdApi::setOnMdApi)
		.def("createFtdcMdApi", &MdApi::createFtdcMdApi)
		.def("release", &MdApi::release)
		.def("init", &MdApi::init)
		.def("join", &MdApi::join)
		.def("exit", &MdApi::exit)
		.def("getTradingDay", &MdApi::getTradingDay)
		.def("registerFront", &MdApi::registerFront)
		.def("subscribeMarketData", &MdApi::subscribeMarketData)
		.def("unSubscribeMarketData", &MdApi::unSubscribeMarketData)
		.def("subscribeForQuoteRsp", &MdApi::subscribeForQuoteRsp)
		.def("unSubscribeForQuoteRsp", &MdApi::unSubscribeForQuoteRsp)
		.def("reqUserLogin", &MdApi::reqUserLogin)
		.def("reqUserLogout", &MdApi::reqUserLogout)
        ;

	class_<OnMdApi, std::shared_ptr<OnMdApi>> onmdapi(m, "OnMdApi", module_local());
    onmdapi
		.def("onFrontConnected", &OnMdApi::onFrontConnected)
		.def("onFrontDisconnected", &OnMdApi::onFrontDisconnected)
		.def("onHeartBeatWarning", &OnMdApi::onHeartBeatWarning)
		.def("onRspUserLogin", &OnMdApi::onRspUserLogin)
		.def("onRspUserLogout", &OnMdApi::onRspUserLogout)
		.def("onRspError", &OnMdApi::onRspError)
		.def("onRspSubMarketData", &OnMdApi::onRspSubMarketData)
		.def("onRspUnSubMarketData", &OnMdApi::onRspUnSubMarketData)
		.def("onRspSubForQuoteRsp", &OnMdApi::onRspSubForQuoteRsp)
		.def("onRspUnSubForQuoteRsp", &OnMdApi::onRspUnSubForQuoteRsp)
		.def("onRtnDepthMarketData", &OnMdApi::onRtnDepthMarketData)
		.def("onRtnForQuoteRsp", &OnMdApi::onRtnForQuoteRsp)
		;
}
