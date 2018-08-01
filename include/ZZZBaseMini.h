																			 /*
-------- ZZZBaseMini.h -------------------------------------------------------

		Copyright © 2018 ZZZ Ltd. - Bulgaria. All rights reserved.

		Please read license at end of this file.
-------------------------------------------------------------------------------
																			 */
#pragma once

#include "IZZZBaseMini.h"


namespace ZzzBase
{

class ZZZ_BASE_MINI_API ZZZBaseMini : public IZZZBaseMini
{
public:
																			 /*
	-------- constructors ---------------------------------------------------*/
	ZZZBaseMini(unsigned long int openType = ZZZ_BASE_MINI_OPEN_IN_FILE);
	ZZZBaseMini(std::string const& baseFileName1, std::string const& baseFileName2,
		unsigned long int openType = ZZZ_BASE_MINI_OPEN_IN_FILE,
		std::string const& user="", std::string const& password="");
																			 /*
	-------- destructor -----------------------------------------------------*/
	virtual ~ZZZBaseMini();

	bool Open(std::string const& baseFileName1, std::string const& baseFileName2,
		unsigned long int openType = ZZZ_BASE_MINI_OPEN_IN_FILE,
		std::string const& user="", std::string const& password="");
	void Close();
	bool IsOpened();

	void CheckState(bool test = true);
    void BreakWriteProcess();

    long long int BeginWriteProcess(std::string const& user, std::string const& password);
    long long int BeginReadProcess(std::string const& user, std::string const& password);
    void EndProcess(long long int id);
																			 /*
	-------- data management ------------------------------------------------*/
    bool AddElement(long long int id, std::string const& element);
	bool ChangeElement(long long int id, std::string const& element);
	bool RemoveElement(long long int id);
	std::string GetElement(long long int id) const;
	bool MoveToElement(long long int id, std::string const& element);
	long long int GetElementLength(long long int id);
	bool MoveToSubSet(long long int id);
	bool MoveToSuperSet(long long int id);
	bool MoveToFirstElement(long long int id);
	bool MoveToLastElement(long long int id);
	bool MoveToNextElement(long long int id);
	bool MoveToPreviousElement(long long int id);
	int MoveToClosestElement(long long int id, std::string const& element);
	bool MoveToBeginElement(long long int id, std::string const& element);
	bool MoveToEndElement(long long int id, std::string const& element);
	std::string MakePathToElement(long long int id, bool savePos);
	bool MoveToElementByPath(long long int id, std::string const& path, bool global);
	bool AddElementByPath(long long int id, std::string const& path, bool global);
	bool MoveToPreviousSymbol(long long int id);
	bool MoveToNextSymbol(long long int id);
	bool MoveToUpSymbol(long long int id);
	bool MoveToDownSymbol(long long int id);
	std::string DividerPathToPath(std::string const& divPath, std::string const& div);
	std::string PathToDividerPath(std::string const& div, std::string const& path);
	std::string GetElementByPath(long long int id, std::string const& path, bool global);
	bool TestForElement(long long int id, std::string const& element);
	bool TestForPath(long long int id, std::string const& path, bool global);
	void LockWrite(long long int id);
	void UnlockWrite(long long int id);
	void LockRead(long long int id);
	void UnlockRead(long long int id);

	bool MoveTo(long long int id, std::string const& fromPath, std::string const& toPath);

	void RemoveFromIndex(long long int id);
	void AddToIndex(long long int id, std::string const& element, std::string const& indexPath = "");
	std::string SearchInIndex(long long int id, std::string const& query, std::string const& indexPath = "", long long int maxCount=ZZZ_BASE_MINI_POINTER_TYPE_MAX);

	bool AddUser(long long int id, std::string const& user, std::string const& password, std::string const& mode);
	bool ChangeUserPassword(long long int id, std::string const& sourceUser, std::string const& sourcePassword, std::string const& newUser, std::string const& newPassword);
	bool RemoveUser(long long int id, std::string const& user, std::string const& password);

	long long int GetSetElementsCount(long long int id);
	long long int GetBaseElementsCount(long long int id);
	bool MoveToSystemSet(long long int id);

																			 /*
	-------- buffers management ---------------------------------------------*/
	bool Remove(std::string const& baseFileName);
	void SetBufferMaxItems(unsigned long long int maxItems);
	void SetBufferMaxItemsDivider(float maxItemsDivider);
	void SetBufferMaxItemSize(long long int maxItemSize);
	void SetBuffersMaxItems(unsigned long long int maxItems);
	void SetBuffersMaxItemsDivider(float maxItemsDivider);

																			 /*
	-------- version --------------------------------------------------------*/
	std::string Version();
	std::string VersionOperatingSystem();
	std::string VersionApplicationType();
	int VersionMajor();
	int VersionMinor();
	int VersionRelease();
	int VersionBuild();
	void Release();
private:
	void* zzzCursorProtected;
};

} // namespace ZZZBaseMini

																			 /*
-------- License --------------------------------------------------------------
-------------------------------------------------------------------------------
																			 */
