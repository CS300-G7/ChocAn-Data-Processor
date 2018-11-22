/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 * Stores and fetches information.
 */

#ifndef DATA_H
#define DATA_H

#include "structs.h"
#include <vector>
#include <map>
#include <deque>

class Data {
	/* Pretend this is the database or something. */
	std::map<int, ProviderMember> members;
	std::map<int, ProviderMember> providers;
	std::map<int, ServiceCode> serviceCodes;
	std::deque<std::map<int, ServiceReport>> services;
	int serviceid;

	/* List of members/providers to be deleted. */	
	std::vector<int> removedMembers;
	std::vector<int> removedProviders;

public:
	Data();
	
	bool validateMember(ProviderMember &);
	bool addMember(ProviderMember);
	ProviderMember getMember(int);
	bool validateProvider(ProviderMember &);
	bool addProvider(ProviderMember);
	ProviderMember getProvider(int);
	bool removeMember(int);
	bool removeProvider(int);
	
	bool addServiceCode(ServiceCode);
	std::map<int, ServiceCode> getServiceCodes();
	bool validateService(ServiceReport &);
	int addService(ServiceReport);
	std::map<int, ServiceReport> getServices(int);
	bool removeService(int);	
	/** Creates a new time period for the next report. */
	void archiveServices();

	bool requestDirectory(int);
};

#endif /* DATA_H */

