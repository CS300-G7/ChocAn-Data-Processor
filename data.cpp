/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 * Stores and fetches information.
 */

#include "data.h"

Data::Data()
{

}

bool Data::addMember(ProviderMember mem)
{
	return members.emplace(mem.IDNumber, mem).second;
}

ProviderMember Data::getMember(int id)
{
	return members.at(id);
}

bool Data::addProvider(ProviderMember mem)
{
	return providers.emplace(mem.IDNumber, mem).second;
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
	return serviceCodes.emplace(code.Code, code).second;
}

std::map<int, ServiceCode> Data::getServiceCodes()
{
	return serviceCodes;
}

bool Data::addService(ServiceReport service)
{
	if (serviceCodes.find(service.ServiceCode) == serviceCodes.end())
		return false;
	if (members.find(service.MemberNum) == members.end())
		return false;
	if (providers.find(service.ProviderNum) == providers.end())
		return false; 
	services.push_back(service);
	return true;
}

std::vector<ServiceReport> Data::getServices()
{
	return services;	
}

void Data::archiveServices()
{
	services.clear();
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

