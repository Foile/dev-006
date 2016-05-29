#include <windows.h>

#define MAX_STRING_LENGTH 260
/**
	@brief Инфраструктурный класс для инкапсуляции Win32API (диалог открытия файла)
*/
class OpenFileDialog
{
private:
	///структура, определяемая Win32API
	OPENFILENAME _filename;
	///Внутренний буфер
	char _bufferForFileEditControl[MAX_STRING_LENGTH];
	///Буфер, содержащий имя файла
	char _bufferForFileName[MAX_STRING_LENGTH];
	///буфер, содержащий фильтры имени файла
	char _filter[MAX_STRING_LENGTH];

public:
	///конструктор
	/// @param owner - дескриптор окна владельца
	OpenFileDialog(HWND owner);	
	///получить введенное пользователем имя файла и полный путь к нему
	char* getFileName();
	///получить введенное пользователем имя файла без пути
	char* getOnlyFileName();	
	///установить фильтр типов файлов
	/// @param filter - указатель на текстовую строку, содержащую необходимые фильтры
	void setFilter(char* filter);	
	///отображение диалога
	///@return true - если диалог закрыт по кнопке ОК, false, если диалог закрыт по кнопке ОТМЕНА
	bool show();
	
};