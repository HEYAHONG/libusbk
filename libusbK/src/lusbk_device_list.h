/*! \file lusbk_device_list.h
*/

#ifndef __LUSBK_DEVICE_LIST_H
#define __LUSBK_DEVICE_LIST_H

#include <windows.h>
#include <objbase.h>
#include "lusbk_common.h"

#include <PSHPACK1.H>
typedef struct _KUSB_DEV_LIST_SEARCH
{
	BOOL EnableRawDeviceInterfaceGuid;
	BOOL EnableCompositeDeviceMode;
}* PKUSB_DEV_LIST_SEARCH, KUSB_DEV_LIST_SEARCH;

typedef struct _KUSB_DEV_LIST
{
	KUSB_USER_CONTEXT UserContext;

	LONG DrvId;
	CHAR DeviceInterfaceGUID[MAX_PATH];
	CHAR DeviceInstance[MAX_PATH];
	CHAR ClassGUID[MAX_PATH];
	CHAR Mfg[MAX_PATH];
	CHAR DeviceDesc[MAX_PATH];
	CHAR Service[MAX_PATH];
	CHAR SymbolicLink[MAX_PATH];
	CHAR DevicePath[MAX_PATH];
	DWORD ReferenceCount;
	DWORD Linked;
	DWORD LUsb0SymbolicLinkIndex;

	struct _KUSB_DEV_LIST* CompositeList;
	struct _KUSB_DEV_LIST* next;
	struct _KUSB_DEV_LIST* prev;

	volatile LONG refCount;
	DWORD cbSize;
}* PKUSB_DEV_LIST, KUSB_DEV_LIST;
#include <POPPACK.H>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

//! Get a usb device list.
/*!
  \ingroup devlist
  \param DeviceList Pointer reference that will receive a a populated device list.
  \param SearchParameters search/filtering options.
*/
KUSB_EXP LONG KUSB_API LstK_GetDeviceList(
    __deref_inout PKUSB_DEV_LIST* DeviceList,
    __in PKUSB_DEV_LIST_SEARCH SearchParameters);

//! Free a usb device list.
/*!
  \ingroup devlist
  \param DeviceList The list to free.
*/
KUSB_EXP VOID KUSB_API LstK_FreeDeviceList(
    __deref_inout PKUSB_DEV_LIST* DeviceList);

#endif