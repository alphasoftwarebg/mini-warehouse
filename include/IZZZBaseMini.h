																			 /*
-------- IZZZBaseMini.h ------------------------------------------------------

		Copyright © 2018 ZZZ Ltd. - Bulgaria. All rights reserved.

		Please read license at end of this file.
-------------------------------------------------------------------------------
																			 */
#pragma once

#include <string>
#ifdef _WIN32
	#include <windows.h>
#endif


const long long int ZZZ_BASE_MINI_POINTER_TYPE_MAX = 0x7fffffffffffffffLL;

const unsigned long int ZZZ_BASE_MINI_OPEN_READ_ONLY			= 0x00000001;
const unsigned long int ZZZ_BASE_MINI_OPEN_IN_MEMORY			= 0x00000002;
const unsigned long int ZZZ_BASE_MINI_OPEN_IN_FILE				= 0x00000004;


struct IZZZBaseMini
{
	virtual bool Open(std::string const& baseFileName1, std::string const& baseFileName2,
		unsigned long int openType = ZZZ_BASE_MINI_OPEN_IN_FILE,
		std::string const& user="", std::string const& password="") = 0;
	virtual void Close() = 0;
	virtual bool IsOpened() = 0;

	virtual void CheckState(bool test = true) = 0;
    virtual void BreakWriteProcess() = 0;

	virtual long long int BeginWriteProcess(std::string const& user, std::string const& password) = 0;
    virtual long long int BeginReadProcess(std::string const& user, std::string const& password) = 0;
    virtual void EndProcess(long long int id) = 0;
																			 /*
	-------- data management ------------------------------------------------*/
    virtual bool AddElement(long long int id, std::string const& element) = 0;
	virtual bool ChangeElement(long long int id, std::string const& element) = 0;
	virtual bool RemoveElement(long long int id) = 0;
	virtual std::string GetElement(long long int id) const = 0;
	virtual bool MoveToElement(long long int id, std::string const& element) = 0;
	virtual long long int GetElementLength(long long int id) = 0;
	virtual bool MoveToSubSet(long long int id) = 0;
	virtual bool MoveToSuperSet(long long int id) = 0;
	virtual bool MoveToFirstElement(long long int id) = 0;
	virtual bool MoveToLastElement(long long int id) = 0;
	virtual bool MoveToNextElement(long long int id) = 0;
	virtual bool MoveToPreviousElement(long long int id) = 0;
	virtual int MoveToClosestElement(long long int id, std::string const& element) = 0;
	virtual bool MoveToBeginElement(long long int id, std::string const& element) = 0;
	virtual bool MoveToEndElement(long long int id, std::string const& element) = 0;
	virtual std::string MakePathToElement(long long int id, bool savePos) = 0;
	virtual bool MoveToElementByPath(long long int id, std::string const& path, bool global) = 0;
	virtual bool AddElementByPath(long long int id, std::string const& path, bool global) = 0;
	virtual bool MoveToPreviousSymbol(long long int id) = 0;
	virtual bool MoveToNextSymbol(long long int id) = 0;
	virtual bool MoveToUpSymbol(long long int id) = 0;
	virtual bool MoveToDownSymbol(long long int id) = 0;
	virtual std::string DividerPathToPath(std::string const& divPath, std::string const& div) = 0;
	virtual std::string PathToDividerPath(std::string const& div, std::string const& path) = 0;
	virtual std::string GetElementByPath(long long int id, std::string const& path, bool global) = 0;
	virtual bool TestForElement(long long int id, std::string const& element) = 0;
	virtual bool TestForPath(long long int id, std::string const& path, bool global) = 0;
	virtual void LockWrite(long long int id) = 0;
	virtual void UnlockWrite(long long int id) = 0;
	virtual void LockRead(long long int id) = 0;
	virtual void UnlockRead(long long int id) = 0;

	virtual bool MoveTo(long long int id, std::string const& fromPath, std::string const& toPath) = 0;

	virtual void RemoveFromIndex(long long int id) = 0;
	virtual void AddToIndex(long long int id, std::string const& element, std::string const& indexPath = "") = 0;
	virtual std::string SearchInIndex(long long int id, std::string const& query, std::string const& indexPath = "", long long int maxCount=ZZZ_BASE_MINI_POINTER_TYPE_MAX) = 0;

	virtual bool AddUser(long long int id, std::string const& user, std::string const& password, std::string const& mode) = 0;
	virtual bool ChangeUserPassword(long long int id, std::string const& sourceUser, std::string const& sourcePassword, std::string const& newUser, std::string const& newPassword) = 0;
	virtual bool RemoveUser(long long int id, std::string const& user, std::string const& password) = 0;

	virtual long long int GetSetElementsCount(long long int id) = 0;
	virtual long long int GetBaseElementsCount(long long int id) = 0;
	virtual bool MoveToSystemSet(long long int id) = 0;

																			 /*
	-------- buffers management ---------------------------------------------*/
	virtual bool Remove(std::string const& baseFileName) = 0;
	virtual void SetBufferMaxItems(unsigned long long int maxItems) = 0;
	virtual void SetBufferMaxItemsDivider(float maxItemsDivider) = 0;
	virtual void SetBufferMaxItemSize(long long int maxItemSize) = 0;
	virtual void SetBuffersMaxItems(unsigned long long int maxItems) = 0;
	virtual void SetBuffersMaxItemsDivider(float maxItemsDivider) = 0;

																			 /*
	-------- version --------------------------------------------------------*/
	virtual std::string Version() = 0;
	virtual std::string VersionOperatingSystem() = 0;
	virtual std::string VersionApplicationType() = 0;
	virtual int VersionMajor() = 0;
	virtual int VersionMinor() = 0;
	virtual int VersionRelease() = 0;
	virtual int VersionBuild() = 0;

	virtual void Release() = 0;
};

#ifdef ZZZ_BASE_MINI_DLL
	#if defined(_LIB)
		#define ZZZ_BASE_MINI_API
	#elif defined (__GNUC__) && defined(__unix__)
		#define ZZZ_BASE_MINI_API __attribute__ ((__visibility__("default")))
	#elif defined(_WIN32)
		#ifdef ZZZ_BASE_MINI_EXPORTS
			#define ZZZ_BASE_MINI_API __declspec(dllexport)
		#else
			#define ZZZ_BASE_MINI_API __declspec(dllimport)
		#endif
	#endif
#else
	#define ZZZ_BASE_MINI_API
#endif

#ifdef __cplusplus
	typedef IZZZBaseMini* ZZZBaseMiniHANDLE;
	#define EXTERN_C     extern "C"
#else // C
	typedef struct tagZZZBaseMiniHANDLE {} * ZZZBaseMiniHANDLE;
	#define EXTERN_C
#endif // __cplusplus

#ifdef _WIN32
	#define std_call WINAPI
#else
	#define std_call
#endif

																			 /*
-------- constructor --------------------------------------------------------*/
EXTERN_C ZZZ_BASE_MINI_API
ZZZBaseMiniHANDLE std_call Get();
																			 /*
-------- destructor ---------------------------------------------------------*/
EXTERN_C ZZZ_BASE_MINI_API
void std_call Release(ZZZBaseMiniHANDLE handle);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call Open(ZZZBaseMiniHANDLE handle,
	char const* baseFileName1,
	char const* baseFileName2,
	unsigned long int openType,
	char const* user,
	char const* password);

EXTERN_C ZZZ_BASE_MINI_API
void std_call Close(ZZZBaseMiniHANDLE handle);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call IsOpened(ZZZBaseMiniHANDLE handle);


EXTERN_C ZZZ_BASE_MINI_API
void std_call CheckState(ZZZBaseMiniHANDLE handle,
	bool test = true);

EXTERN_C ZZZ_BASE_MINI_API
void std_call BreakWriteProcess(ZZZBaseMiniHANDLE handle);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call BeginWriteProcess(ZZZBaseMiniHANDLE handle,
	char const* user,
	char const* password);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call BeginReadProcess(ZZZBaseMiniHANDLE handle,
	char const* user,
	char const* password);

EXTERN_C ZZZ_BASE_MINI_API
void std_call EndProcess(ZZZBaseMiniHANDLE handle,
	long long int id);
																			 /*
-------- data management ----------------------------------------------------*/
EXTERN_C ZZZ_BASE_MINI_API
bool std_call AddElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call ChangeElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call RemoveElement(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call GetElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char* result);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call GetElementLength(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToSubSet(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToSuperSet(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToFirstElement(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToLastElement(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToNextElement(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToPreviousElement(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
int std_call MoveToClosestElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToBeginElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToEndElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call MakePathToElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char* result,
	bool savePos);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToElementByPath(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* path,
	long long int pathLength,
	bool global);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call AddElementByPath(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* path,
	long long int pathLength,
	bool global);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToPreviousSymbol(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToNextSymbol(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToUpSymbol(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToDownSymbol(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call DividerPathToPath(ZZZBaseMiniHANDLE handle,
	char* result,
	char const* divPath,
	char const* div);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call PathToDividerPath(ZZZBaseMiniHANDLE handle,
	char* result,
	char const* div,
	char const* path,
	long long int pathLength);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call GetElementByPath(ZZZBaseMiniHANDLE handle,
	long long int id,
	char* result,
	char const* path,
	long long int pathLength,
	bool global);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call TestForElement(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call TestForPath(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* path,
	long long int pathLength,
	bool global);

EXTERN_C ZZZ_BASE_MINI_API
void std_call LockWrite(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
void std_call UnlockWrite(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
void std_call LockRead(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
void std_call UnlockRead(ZZZBaseMiniHANDLE handle,
	long long int id);


EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveTo(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* fromPath,
	long long int fromPathLength,
	char const* toPath,
	long long int toPathLength);


EXTERN_C ZZZ_BASE_MINI_API
void std_call RemoveFromIndex(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
void std_call AddToIndex(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* element,
	long long int elementLength,
	char const* indexPath,
	long long int indexPathLength);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call SearchInIndex(ZZZBaseMiniHANDLE handle,
	long long int id,
	char* result,
	char const* query,
	char const* indexPath,
	long long int indexPathLength,
	long long int maxCount);


EXTERN_C ZZZ_BASE_MINI_API
bool std_call AddUser(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* user,
	char const* password,
	char const* mode);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call ChangeUserPassword(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* sourceUser,
	char const* sourcePassword,
	char const* newUser,
	char const* newPassword);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call RemoveUser(ZZZBaseMiniHANDLE handle,
	long long int id,
	char const* user,
	char const* password);


EXTERN_C ZZZ_BASE_MINI_API
long long int std_call GetSetElementsCount(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
long long int std_call GetBaseElementsCount(ZZZBaseMiniHANDLE handle,
	long long int id);

EXTERN_C ZZZ_BASE_MINI_API
bool std_call MoveToSystemSet(ZZZBaseMiniHANDLE handle,
	long long int id);

																			 /*
-------- buffers management -------------------------------------------------*/
EXTERN_C ZZZ_BASE_MINI_API
bool std_call Remove(ZZZBaseMiniHANDLE handle,
	char const* baseFileName);

EXTERN_C ZZZ_BASE_MINI_API
void std_call SetBufferMaxItems(ZZZBaseMiniHANDLE handle,
	unsigned long long int maxItems);

EXTERN_C ZZZ_BASE_MINI_API
void std_call SetBufferMaxItemsDivider(ZZZBaseMiniHANDLE handle,
	float maxItemsDivider);

EXTERN_C ZZZ_BASE_MINI_API
void std_call SetBufferMaxItemSize(ZZZBaseMiniHANDLE handle,
	long long int maxItemSize);

EXTERN_C ZZZ_BASE_MINI_API
void std_call SetBuffersMaxItems(ZZZBaseMiniHANDLE handle,
	unsigned long long int maxItems);

EXTERN_C ZZZ_BASE_MINI_API
void std_call SetBuffersMaxItemsDivider(ZZZBaseMiniHANDLE handle,
	float maxItemsDivider);

																			 /*
-------- version ------------------------------------------------------------*/
EXTERN_C ZZZ_BASE_MINI_API
short int std_call Version(ZZZBaseMiniHANDLE handle,
	char* result);

EXTERN_C ZZZ_BASE_MINI_API
short int std_call VersionOperatingSystem(ZZZBaseMiniHANDLE handle,
	char* result);

EXTERN_C ZZZ_BASE_MINI_API
short int std_call VersionApplicationType(ZZZBaseMiniHANDLE handle,
	char* result);

EXTERN_C ZZZ_BASE_MINI_API
int std_call VersionMajor(ZZZBaseMiniHANDLE handle);

EXTERN_C ZZZ_BASE_MINI_API
int std_call VersionMinor(ZZZBaseMiniHANDLE handle);

EXTERN_C ZZZ_BASE_MINI_API
int std_call VersionRelease(ZZZBaseMiniHANDLE handle);

EXTERN_C ZZZ_BASE_MINI_API
int std_call VersionBuild(ZZZBaseMiniHANDLE handle);

																			 /*
-------- License --------------------------------------------------------------
-------------------------------------------------------------------------------
																			 */
