#pragma once
class WinApiException
{
private:
	int errorCode;
public:
	WinApiException(int aErrorCode): errorCode(aErrorCode) {}
	

	int GetErrorCode(void)
	{
		return errorCode;
	}
};

