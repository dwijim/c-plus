/* ---------------------------------------------
   nama file: regacces.cpp

   --------------------------------------------- */

#include <iostream>
#include <windows.h>
#include "regaccess.h"

using namespace std;

HKEY GetPredefineKey (PreKeys PreKey)
{
    if(PreKey == HKCR)
        return HKEY_CLASSES_ROOT;
    else if (PreKey == HKCU)
        return HKEY_CURRENT_USER;
    else if(PreKey == HKLM)
        return HKEY_LOCAL_MACHINE;
    else if(PreKey == HKU)
        return HKEY_USERS;
    else if(PreKey == HKPD)
        return HKEY_PERFORMANCE_DATA;
    else if(PreKey == HKCC)
        return HKEY_CURRENT_CONFIG;
    else if(PreKey ==HKDD)
        return HKEY_DYN_DATA;
    else
        return 0;
}

DWORD ReadDWORDValue(PreKeys PreKey, cahr *SubKey,
                     char* Value)
{
    HKEY hPkey, hKey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);
    BYTE buffer[1024] = {'\0'};
    DWORD *pData, Data;
    unsigned long size = sizeof(buffer)-1;

    lResult = RegOpenKeyEx(hPkey,SubKey,0,KEY_READ,&hKey);

    if  (lResult == ERROR_SUCCESS)
    {
        lResult = RegQueryValueEx(hKey,Value,0,0,buffer,&size);
        pData = (LPDWORD) buffer;
        Data = *pData;
        return Data;
    }
    else
    {
        return 0;
    }
    RegCloseKey(hKey);
}

bool DeleteKey(PreKeys PreKey, char *SubKey)
{
    HKEY hPkey, hKey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);

    lResult = RegDeleteKey(hPkey, SubKey);
    if (lResult == ERROR_SUCCESS)
        return true;
    else
        return false;

    RegCloseKey(hKey);
}

char* ReadStringValue(PreKeys PreKey, char *SubKey,
                      char *Vlaue)
{
    HKEY hPkey, hKey;
    LONG lResult;
    BYTE Buffer[1024] = {'\0'};
    hPkey = GetPredefineKey(PreKey);
    char *pszData;
    char *Data = new char[1024];
    unsigned long size = sizeof(buffer)-1;

    lResult = RegOpenKeyEx(hPkey,SubKey,0,KEY_READ,&hKey);

    if (lResult == ERROR_SUCCESS)
    {
        lResult = RegQueryValueEx(hKey,Value,0,0,buffer,&size);

        if (lResult == ERROR_SUCCESS)]
        {
            pszData = (char*) buffer;
            strncpy(Data, pszData, sizeof(Data)-1);
            delete pszData;
            return Data;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

    RegCloseKey(hKey);
}

bool SetDWORDValue(PreKeys PreKey, char *SubKey,
                   char* Value, DWORD Data)
{
    HKEY hPkey, hKey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);

    lResult = RegOpenKeyEx(hPkey, SubKey, 0,
                           KEY_ALL_ACCESS, &hKey);
    if (lResult == ERROR_SUCCESS)
    {
        lResult = RegSetValueEx(hKey, Value, 0, REG_DWORD,
                                (CONST BYTE*)&Data, sizeof(Data));
        if (lResult == ERROR_SUCCESS)\
            return true;
        else
            return false;
    }
    else
        return false;

    RegCloseKey(hKey);
}

bool SetStringValue(PreKeys PreKey, char *SubKey,
                    char *Value, char* Data)
{
    HKEY hPkey, hKey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);
    lResult = RegOpenKeyEx(hPkey, SubKey, 0,
                           KEY_ALL_ACCESS, &hKey);

    if (lResult == ERROR_SUCCESS)
    {
        lResult = RegSetValueEx(hKey, Value, 0, REG_SZ,
                                (LPBYTE) Data, strlen(Data));

        if (lResult == ERROR_SUCCESS)
            return true;
        else
            return false;
    }

    else
        return false;

    RegCloseKey(hKey);
}

bool CreatKey(PreKeys PreKey, char *SubKey)
{
    HKEY hKey, hPkey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);
    lResult = RegCreateKeyEx(hPkey, SubKey, 0, NULL,
                             REG_OPTION_NON_VOLATILE,
                             KEY_ALL_ACCESS, NULL,
                             &hKey, NULL);

    if (lResult == ERROR_SUCCESS)
        return true;
    else
        return false;

    RegCloseKey(hKey);
}


HKEY GetPredefineKey(PreKeys Prekey)
{
    if(Prekey == HKCR)
        return HKEY_CLASSES_ROOT;
    else if(Prekey ==HKCU)
        return HKEY_CURRENT_USER;
    else if(Prekey == HKLM)
        return HKEY_LOCAL_MACHINE;
    else if(Prekey == HKU)
        return HKEY_USERS;
    else if(Prekey == HKPD)
        return HKEY_PERFORMANCE_DATA;
    else if(Prekey == HKCC)
        return HKEY_CURRENT_CONFIG;
    else if(Prekey == HKDD)
        return HKEY_DYN_DATA;
    else
        return 0;
}


bool DeleteKey(PreKeys PreKey, char *SubKey)
{
    HKEY hPKey, hKey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);

    lResult = RegDeleteKey(hPkey, SubKey);
    if (lResult == ERROR_SUCCESS)
        return true;
    else
        return false;

    RegCloseKey(hKey);
}


bool CreateKey(PreKeys PreKey, char *SubKey)
{
    HKEY hKey, hPkey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);
    lResult = RegCreateKeyEx(hPkey, SubKey, 0, NULL,
                             REG_OPTION_NON_VOLATILE,
                             KEY_ALL_ACCESS, NULL,
                             &hKey, NULL);

    if (lResult == ERROR_SUCCESS)
        return true;
    else
        return false;

    RegCloseKey(hKey);
}


bool SetDWORDValue(PreKeys PreKey, char *Subkey,
                   char* Value, DWORD Data)
{
    HKEY hPkey, hKey;
    LONG lResult;
    hPkey = GetPredefineKey(PreKey);

    lResult = RegOpenKeyEx(hPkey, Subkey, 0,
                           KEY_ALL_ACCESS, &hKey);

    if (lResult == ERROR_SUCCESS)
    {
        lResult = RegSetValueEx(hKey, Value, 0, REG_DWORD,
                                (CONST BYTE*)&Data, sizeof(Data));

        if (lResult == ERROR_SUCCESS)
            return true;
        else
            return false;
    }
    else
        return false;

    RegCloseKey(hKey);
}


char* ReadStringValue(PreKeys PreKey, char *SubKey,
                      char *Value)
{
    HKEY hPkey, hKey;
    LONG lResult;
    BYTE buffer[1024] = {'\0'};
    hPkey = GetPredefineKey(PreKey);
    char *pszData;
    char *Data = new char[1024];
    unsigned long size = sizeof(buffer)-1;

    lResult = RegOpenKeyEx(hPkey,SubKey,0,KEY_READ,&hKey);

    if (lResult == ERROR_SUCCESS)
    {
        lResult = RegQueryValueEx(hKey,Value,0,0,buffer,*size);

        if (lResult == ERROR_SUCCESS)
        {
            pszData = (char*) buffer;
            strncpy(Data, pszData, sizeof(Data)-1);
            delete pszData;
            return Data;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

    RegCloseKey(hKey);
}

