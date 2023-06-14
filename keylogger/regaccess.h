/* ---------------------------------------------
   nama file: regaccess.h

   --------------------------------------------- */

#ifndef _REGACCESS_
#define _REGACCESS_

enum PreKeys
{
    HKLM, HKCU, HKCC,
    HKDD, HKCR, HKU,
    HKPD,
};
HKEY GetPredefinedKey (PreKeys PreKey);
DWORD ReadDWORDValue (PreKeys PreKey, char *Subkey,
                      char *Value);

/* ---------------------------------------------
ini aslinya jadi salah                      
char* ReadString Vlaue (PreKeys PreKey, char *SubKey,
                        char *Value, DWORD Data);
                        
                        SubKey ini harusnya Subkey
                        semuanya
   --------------------------------------------- */
char* ReadStringValue (PreKeys PreKey, char *Subkey,
                        char *Value, DWORD Data);
                        
bool SetDWORDValue (PreKeys PreKey, char *Subkey,
                    char *Value, DWORD Data);
                    
bool DeleteKey (PreKeys PreKey, char *Subkey);

bool SetStringValue (PreKeys PreKey,char *Subkey,
                     char *Value, char* Data);
                     
bool CreateKey (PreKeys PreKey, char *Subkey);

#endif // _REGACCESS_



