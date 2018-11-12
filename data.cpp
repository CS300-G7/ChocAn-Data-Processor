/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 * Stores and fetches information.
 */

#include "data.h"

Data::Data()
{
	serviceid = 0;
}

bool Data::addMember(ProviderMember mem)
{
	members.emplace(mem.IDNumber, mem);
	return true;
}

ProviderMember Data::getMember(int id)
{
	return members.at(id);
}

bool Data::addProvider(ProviderMember mem)
{
	providers.emplace(mem.IDNumber, mem);
	return true;
}

ProviderMember Data::getProvider(int id)
{
	return providers.at(id);
}

bool Data::addServiceCode(ServiceCode code)
{
	serviceCodes.emplace(code.Code, code);
	return true;
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
	services.emplace(serviceid++, service);
	return true;
}

std::map<int, ServiceReport> Data::getServices()
{
	return services;	
}

void Data::archiveServices()
{
	services.clear();
}

