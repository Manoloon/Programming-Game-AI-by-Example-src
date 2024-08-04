#include "WindowUtils.h"
#include <windows.h>
#include "../2d/Vector2D.h"
#include "utils.h"
#include "Stream_Utility_Functions.h"



//---------------------- ChangeMenuState ---------------------------------
//
//  Changes the state of a menu item given the item identifier, the 
//  desired state and the HWND of the menu owner
//------------------------------------------------------------------------
void ChangeMenuState(HWND hwnd, UINT MenuItem, UINT state)
{
  MENUITEMINFO mi;

  mi.cbSize = sizeof(MENUITEMINFO);
  mi.fMask  = MIIM_STATE;
  mi.fState = state;

  SetMenuItemInfo(GetMenu(hwnd), MenuItem, false, &mi);
  DrawMenuBar(hwnd);
}

//-------------------- CheckMenuItemAppropriately ----------------------------
//
//  if b is true MenuItem is checked, otherwise it is unchecked
//-----------------------------------------------------------------------------
void CheckMenuItemAppropriately(HWND hwnd, UINT MenuItem, bool b)
{
  if (b)
  {
    ChangeMenuState(hwnd, MenuItem, MFS_CHECKED);
  }
  else
  {
    ChangeMenuState(hwnd, MenuItem, MFS_UNCHECKED);
  }
}


//--------------------- CheckBufferLength --------------------------------
//
//  this is a replacement for the StringCchLength function found in the 
//  platform SDK. See MSDN for details. Only ever used for checking toolbar
//  strings
//------------------------------------------------------------------------
bool CheckBufferLength(char* buff, int MaxLength, int& BufferLength)
{
  std::string s = ttos(buff);

  BufferLength = s.length();

  if (BufferLength > MaxLength)
  {
    BufferLength = 0; return false;
  }  

  return true;
}

void ErrorBox(const std::string& msg)
{
  // Convert std::string to std::wstring
  int size_needed = MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, NULL, 0);
  std::wstring wmsg(size_needed, 0);
  MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, &wmsg[0], size_needed);
  MessageBoxW(NULL, wmsg.c_str(), L"Error", MB_OK);
}

void ErrorBox(const char* msg)
{
  // Convert char* to std::wstring
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, msg, -1, NULL, 0);
    std::wstring wmsg(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, msg, -1, &wmsg[0], size_needed);

    // Display the message box
    MessageBoxW(NULL, wmsg.c_str(), L"Error", MB_OK);
}

//gets the coordinates of the cursor relative to an active window 
Vector2D GetClientCursorPosition()
{
  POINT MousePos;

  GetCursorPos(&MousePos);

  ScreenToClient(GetActiveWindow(), &MousePos);

  return POINTtoVector(MousePos);
}

 
Vector2D GetClientCursorPosition(HWND hwnd)
{
  POINT MousePos;

  GetCursorPos(&MousePos);

  ScreenToClient(hwnd, &MousePos);

  return POINTtoVector(MousePos);
}


//-----------------------------------------------------------------------------
//
//  The following 3 functions are taken from Petzold's book and enable the 
//  client to use the file dialog common control
//-----------------------------------------------------------------------------
void FileInitialize (HWND hwnd,
                     OPENFILENAMEW& ofn,
                     const std::string& defaultFileTypeDescription,
                     const std::string& defaultFileExtension)
{
  std::string filter = defaultFileTypeDescription + '\0' + "*." + defaultFileExtension + '\0' +
                       "All Files (*.*)" + '\0' + "*.*" + '\0' + '\0';
  
  // Convert the filter string to a wide string
  int filterSizeNeeded = MultiByteToWideChar(CP_UTF8, 0, filter.c_str(), -1, NULL, 0);
  std::wstring wFilter(filterSizeNeeded, 0);
  MultiByteToWideChar(CP_UTF8, 0, filter.c_str(), -1, &wFilter[0], filterSizeNeeded);

  // Remove the additional null terminator at the end added by MultiByteToWideChar
  wFilter.pop_back();

  //static TCHAR szFilter[255];

  //  for (unsigned int i=0; i<filter.size(); ++i)
  //  {
  //    szFilter[i] = filter.at(i);
  //  }

  wchar_t* szFile = new wchar_t[MAX_PATH];
  szFile[0] = '\0'; // Initialize with an empty string

    // Convert defaultFileExtension to a wide string
    int extSizeNeeded = MultiByteToWideChar(CP_UTF8, 0, defaultFileExtension.c_str(), -1, NULL, 0);
    std::wstring wDefaultFileExtension(extSizeNeeded, 0);
    MultiByteToWideChar(CP_UTF8, 0, defaultFileExtension.c_str(), -1, &wDefaultFileExtension[0], extSizeNeeded);
    //
     ofn.lStructSize       = sizeof (OPENFILENAMEW) ;
     ofn.hwndOwner         = hwnd ;
     ofn.hInstance         = NULL ;
     ofn.lpstrFilter       = wFilter.c_str();
     ofn.lpstrCustomFilter = NULL ;
     ofn.nMaxCustFilter    = 0 ;
     ofn.nFilterIndex      = 1 ;
     ofn.lpstrFile         = szFile ;          // Set in Open and Close functions
     ofn.nMaxFile          = MAX_PATH ;
     ofn.lpstrFileTitle    = NULL ;          // Set in Open and Close functions
     ofn.nMaxFileTitle     = MAX_PATH ;
     ofn.lpstrInitialDir   = NULL ;
     ofn.lpstrTitle        = NULL ;
     ofn.Flags             = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST ;             // Set in Open and Close functions
     ofn.nFileOffset       = 0 ;
     ofn.nFileExtension    = 0 ;
     ofn.lpstrDefExt       = wDefaultFileExtension.c_str();
     ofn.lCustData         = 0L ;
     ofn.lpfnHook          = NULL ;
     ofn.lpTemplateName    = NULL ;

}



BOOL FileOpenDlg (HWND               hwnd,
                  PWSTR              pstrFileName,
                  PWSTR              pstrTitleName,
                  const std::string& defaultFileTypeDescription,
                  const std::string& defaultFileExtension)
{
     OPENFILENAMEW ofn;

     FileInitialize(hwnd, ofn, defaultFileTypeDescription, defaultFileExtension);
  
     ofn.hwndOwner         = hwnd ;
     ofn.lpstrFile         = pstrFileName ;
     ofn.lpstrFileTitle    = pstrTitleName ;
     ofn.Flags             = OFN_HIDEREADONLY | OFN_CREATEPROMPT ;
     
     return GetOpenFileNameW (&ofn) ;
}

BOOL FileSaveDlg (HWND               hwnd,
                  PWSTR              pstrFileName,
                  PWSTR              pstrTitleName,
                  const std::string& defaultFileTypeDescription,
                  const std::string& defaultFileExtension)
{
     OPENFILENAMEW ofn; FileInitialize(hwnd, ofn, defaultFileTypeDescription, defaultFileExtension);

     ofn.hwndOwner         = hwnd ;
     ofn.lpstrFile         = pstrFileName ;
     ofn.lpstrFileTitle    = pstrTitleName ;
     ofn.Flags             = OFN_OVERWRITEPROMPT ;
     
     return GetSaveFileNameW (&ofn) ;
}

//-------------------------- ResizeWindow -------------------------------------
//
//  call this to resize the active window to the specified size
//-----------------------------------------------------------------------------
void ResizeWindow(HWND hwnd, int cx, int cy)
{
  //does this window have a menu. If so set a flag to true
  HMENU hwndMenu = GetMenu(hwnd);
  bool bMenu = false;
  if (hwndMenu) bMenu = true;

  //create a rect of the desired window size
  RECT DesiredSize;
  DesiredSize.left = 0;
  DesiredSize.top  = 0;
  DesiredSize.right = cx;
  DesiredSize.bottom = cy;

  //determine the size the window should be given the desired client area
  AdjustWindowRectEx(&DesiredSize,
                     WS_OVERLAPPED | WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
                     bMenu,
                     0);

  //resize the window to fit
  SetWindowPos(hwnd,
               NULL,
               GetSystemMetrics(SM_CXSCREEN)/2 - cx/2,
               GetSystemMetrics(SM_CYSCREEN)/2 - cy/2,
               DesiredSize.right,
               DesiredSize.bottom,
               SWP_NOZORDER);
}

//------------------------- GetWindowHeight -----------------------------------
//-----------------------------------------------------------------------------
int  GetWindowHeight(HWND hwnd)
{
  if (hwnd == 0) return 0;

  RECT windowRect;

  GetWindowRect(hwnd, &windowRect);

  return windowRect.bottom - windowRect.top;
}

//------------------------- GetWindowWidth  -----------------------------------
//-----------------------------------------------------------------------------
int  GetWindowWidth(HWND hwnd)
{
  if (hwnd == 0) return 0;

  RECT windowRect;

  GetWindowRect(hwnd, &windowRect);

  return windowRect.right - windowRect.left;
}