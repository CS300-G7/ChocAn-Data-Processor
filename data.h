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
#include <set>

class Data {
	/* Pretend this is the database or something. */
	std::map<int, ProviderMember> members;
	std::map<int, ProviderMember> providers;
	std::map<int, ServiceCode> serviceCodes;
	std::vector<ServiceReport> services;

	/* List of members/providers to be deleted. */	
	std::vector<int> removedMembers;
	std::vector<int> removedProviders;

public:
	Data();

	bool addMember(ProviderMember);
	ProviderMember getMember(int);
	bool addProvider(ProviderMember);
	ProviderMember getProvider(int);
	bool removeMember(int);
	bool removeProvider(int);

	bool addServiceCode(ServiceCode);
	std::map<int, ServiceCode> getServiceCodes();
	bool addService(ServiceReport);
	std::vector<ServiceReport> getServices();
	
	/** Needed so that only weekly services are included in the report. */
	void archiveServices();
};

#endif /* DATA_H */

