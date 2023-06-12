#ifndef _REGACCESS_
#define _REGACCESS_

enum PreKeys
{
    HKLM, HKCU, HKCC,
    HKDD, HKCR, HKU,
    HKPD,
};
HKEY GetPredefineKey (PreKeys PreKey);
DWORD ReadDWORDValue (PreKeys PreKey, char *SubKey,
                      char *Value);
char* ReadString Vlaue (PreKeys PreKey, char *SubKey,
                        char *Value, DWORD Data);
bool SetDWORDValue (PreKeys PreKey, char *SubKey,
                    char *Value, DWORD Data);
bool DeleteKey (PreKeys PreKey, char *SubKey);
bool SetStringValue (PreKeys PreKey,char *SubKey,
                     char *Value, char* Data);
bool CerateKey (PreKeys PreKey, char *SubKey);

#endif // _REGACCESS_



