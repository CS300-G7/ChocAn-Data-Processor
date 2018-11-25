/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 * Stores and fetches information.
 */

#include "data.h"
#include <fstream>

using std::endl;


Data::Data()
{
	serviceid = 1;
	services.push_front(std::map<int, ServiceReport>());
}

bool Data::validateMember(ProviderMember &mem)
{
	/* Member ID cannot be greater than nine digits. */
	if (mem.IDNumber > 999999999)
		return false;
	else
		return true;
}

bool Data::addMember(ProviderMember mem)
{
	/* Member ID cannot be greater than nine digits. */
	if (mem.IDNumber > 999999999)
		return false;
	members[mem.IDNumber] = mem;
	return true;
}

ProviderMember Data::getMember(int id)
{
	return members.at(id);
}

bool Data::validateProvider(ProviderMember &mem)
{
	/* Provider ID cannot be greater than nine digits. */
	if (mem.IDNumber > 999999999)
		return false;
	else
		return true;
}

bool Data::addProvider(ProviderMember mem)
{
	/* Provider ID cannot be greater than nine digits. */
	if (mem.IDNumber > 999999999)
		return false;
	providers[mem.IDNumber] = mem;
	return true;
}

ProviderMember Data::getProvider(int id)
{
	return providers.at(id);
}

bool Data::removeMember(int id)
{
	if (members.find(id) != members.end()) {
		removedMembers.push_back(id);
		return true;
	} else
		return false;
}

bool Data::removeProvider(int id)
{
	if (providers.find(id) != providers.end()) {
		removedProviders.push_back(id);
		return true;
	} else
		return false;
}

bool Data::addServiceCode(ServiceCode code)
{
	/* Service code cannot be greater than six digits. */
	if (code.Code > 999999)
		return false;
	return serviceCodes.emplace(code.Code, code).second;
}

std::map<int, ServiceCode> Data::getServiceCodes()
{
	return serviceCodes;
}

bool Data::validateService(ServiceReport &service)
{
	if (serviceCodes.find(service.ServiceCode) == serviceCodes.end())
		return false;
	if (members.find(service.MemberNum) == members.end())
		return false;
	if (providers.find(service.ProviderNum) == providers.end())
		return false; 
	return true;
}

int Data::addService(ServiceReport service)
{
	if (serviceCodes.find(service.ServiceCode) == serviceCodes.end())
		return -1;
	if (members.find(service.MemberNum) == members.end())
		return -1;
	if (providers.find(service.ProviderNum) == providers.end())
		return -1; 
	services[0].emplace(serviceid, service);
	return serviceid++;
}

std::map<int, ServiceReport> Data::getServices(int period)
{
	return services[period];
}

bool Data::removeService(int id)
{
	for (auto &period : services) {
		auto it = period.find(id);
		if (it != period.end()) {
			period.erase(it);
			return true;
		}		
	}
	return false;
}

void Data::archiveServices()
{
	services.push_front(std::map<int, ServiceReport>());

	/* Remove everything staged for removal. */
	while (!removedMembers.empty()) {
		int id = removedMembers.back();
		members.erase(id);
		removedMembers.pop_back();
	}
	while(!removedProviders.empty()) {
		int id = removedProviders.back();
		providers.erase(id);
		removedProviders.pop_back();
	}
}


bool Data::requestDirectory(int pid)
{
	try {
		ProviderMember mem = getProvider(pid);
		std::ofstream file("directory.txt");
		file << "provider #" << mem.IDNumber << endl;
		file << endl;

		for (auto code : serviceCodes) {
			file << "Code : " << code.second.Code << endl;
			file << "Name : " << code.second.ServiceName << endl;
			file << "Fee  : " << code.second.Fee << endl;
			file << endl;
		}	
	} catch(std::exception &e) {
		return false;
	}
	return true;
}

