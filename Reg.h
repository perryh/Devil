
class Registry
{
public:
   //Konstruktoren
   inline Registry() {};
   //Destruktor
   inline ~Registry() {};

   bool OpenKey(HKEY key, LPCSTR SubKey);
   bool CloseKey();
   bool GetValue(LPCSTR ValueName, LPTSTR szValue);
   bool SetValue(LPCSTR ValueName, LPCSTR szValue);
   bool CreateKey(HKEY hKey, LPCTSTR SubKey);
   bool DeleteValue(LPCSTR ValueName);
   bool DeleteKey(LPCSTR KeyName);

protected:

   HKEY m_hkey;
};