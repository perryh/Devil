#include <windows.h>
#include "Reg.h"

bool Registry::OpenKey(HKEY key,LPCSTR SubKey)
{
   if (RegOpenKeyEx(key,
               (LPCTSTR) SubKey,
               NULL,
               KEY_ALL_ACCESS,
               &m_hkey) == ERROR_SUCCESS) //Alles ok!

      return true;
   else
      return false;
}

bool Registry::CloseKey()
{
   if (RegCloseKey(m_hkey) == ERROR_SUCCESS)
      return true;
   else
      return false;
}

bool Registry::GetValue(LPCSTR ValueName, LPTSTR szValue)
{
   DWORD dwType;
   DWORD dwSize = MAX_PATH;

   if(RegQueryValueEx(   m_hkey,
                  ValueName,
                  0,
                  &dwType,
                  (BYTE*)szValue,
                  &dwSize) == ERROR_SUCCESS)
      return true;
   else
      return false;

}

bool Registry::SetValue(LPCTSTR ValueName, LPCSTR szValue)
{
   if (RegSetValueEx(   m_hkey,
               ValueName,
               0,
               REG_SZ,
               (BYTE *) szValue,
               strlen(szValue)) == ERROR_SUCCESS)
      return true;
   else
      return false;
}
               
bool Registry::DeleteValue(LPCTSTR ValueName)
{
   if (RegDeleteValue(m_hkey, ValueName) == ERROR_SUCCESS)
      return true;
   else
      return false;
}

bool Registry::DeleteKey(LPCTSTR KeyName)
{
   if (RegDeleteKey(m_hkey, KeyName) == ERROR_SUCCESS)
      return true;
   else
      return false;
}

bool Registry::CreateKey(HKEY hKey, LPCTSTR SubKey)
{
   if (RegCreateKeyEx((HKEY)hKey,
               SubKey,
               0,
               NULL,
               REG_OPTION_NON_VOLATILE,
               KEY_ALL_ACCESS,
               NULL,
               &m_hkey,
               NULL) == ERROR_SUCCESS)
      return true;
   else
      return false;
}

