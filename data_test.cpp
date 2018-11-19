/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 */

#include "data.h"
#include <string.h>
#include <stdio.h>

bool testValidation();
bool testRemoval();
bool testAddition();
void printServiceSuccess(bool);

int main()
{
	bool passed = true;

	printf("--- DATA TEST ---\n");
	if (!testAddition())
		passed = false;
	if (!testRemoval())
		passed = false;
	if (!testValidation())
		passed = false;

	if (passed)
		printf("\nAll tests PASSED\n");
	else
	 	printf("\nTest FAILED\n");

	return 0;
}

bool testRemoval()
{
	Data data;
	int id = 0;

	printf("\nREMOVAL TEST\n");
	
	ProviderMember member;
	strcpy(member.Name, "John");
	member.IDNumber = id++;
	if (!data.addMember(member)) {
		printf("Could not add member\n");
		return false;
	} else
		printf("Added member '%s' (%d)\n", member.Name,
			member.IDNumber);

	ProviderMember provider;
	strcpy(provider.Name, "Bob");
	provider.IDNumber = id++;
	if (!data.addProvider(provider)) {
		printf("Could not add provider\n");
		return false;
	} else
		printf("Added provider '%s' (%d)\n", provider.Name,
			provider.IDNumber);

	ServiceCode code;
	code.Code = 10;
	strcpy(code.ServiceName, "Random Service");
	if (!data.addServiceCode(code)) {
		printf("Could not add service code\n");
		return false;
	} else
		printf("Added service '%s' (%d)\n", code.ServiceName,
			code.Code);

	ServiceReport report;
	report.MemberNum = member.IDNumber;
	report.ProviderNum = provider.IDNumber;
	report.ServiceCode = code.Code;
	if (data.addService(report) < 0) {
		printf("Could not add service... TEST FAILED\n");	
		return false;
	}

	data.removeMember(member.IDNumber);
	data.removeProvider(provider.IDNumber);

	try {
		data.getMember(member.IDNumber);
	} catch (std::exception &e) {
		printf("Member removed before archiving... TEST FAILED\n");
		return false;
	}

	try {
		data.getProvider(provider.IDNumber);
	} catch (std::exception &e) {
		printf("Provider removed before archiving... TEST FAILED\n");
		return false;
	}
	
	data.archiveServices();

	try {
		data.getMember(member.IDNumber);
		printf("Member found after deletion... TEST FAILED\n");
		return false;
	} catch (std::exception &e) {
	
	}

	try {
		data.getProvider(provider.IDNumber);
		printf("Provider found after deletion... TEST FAILED\n");
		return false;
	} catch (std::exception &e) {

	}

	printf("Test PASSED\n");	
	return true;
}

bool testAddition()
{
	Data data;
	int id = 0;

	printf("\nADDITION TEST\n");

	ProviderMember member;
	strcpy(member.Name, "John");
	member.IDNumber = id++;
	if (!data.addMember(member)) {
		printf("Could not add member... TEST FAILED\n");
		return false;
	} else
		printf("Added member '%s' (%d)\n", member.Name,
			member.IDNumber);

	ProviderMember provider;
	strcpy(provider.Name, "Bob");
	provider.IDNumber = id++;
	if (!data.addProvider(provider)) {
		printf("Could not add provider... TEST FAILED\n");
		return false;
	} else
		printf("Added provider '%s' (%d)\n", provider.Name,
			provider.IDNumber);

	strcpy(member.Name, "Susan");
	strcpy(provider.Name, "Logan");

	if (!data.addMember(member)) {
		printf("Could not add member... TEST FAILED\n");
		return false;
	}
	if (!data.addProvider(provider)) {
		printf("Could not add provider... TEST FAILED\n");
		return false;
	}

	if (strcmp(data.getMember(member.IDNumber).Name, "Susan") != 0) {
		printf("Member not changed... TEST FAILED\n");
		return false;
	} else
		printf("Member changed\n");
	if (strcmp(data.getProvider(provider.IDNumber).Name, "Logan") != 0) {
		printf("Provider not changed... TEST FAILED\n");
		return false;
	} else
		printf("Provider changed\n");

	printf("Test PASSED\n");
	return true;
}

bool testValidation()
{
	Data data;
	int id = 0;
	bool v;

	printf("\nVALIDATION TEST\n");

	ProviderMember member;
	strcpy(member.Name, "John");
	member.IDNumber = id++;
	v = data.addMember(member);
	printf("Added member '%s' (%d)\n", member.Name, member.IDNumber);
	if (!v) {
		printf("Could not add member\n");
		return false;
	}

	ProviderMember provider;
	strcpy(provider.Name, "Bob");
	provider.IDNumber = id++;
	v = data.addProvider(provider);
	printf("Added provider '%s' (%d)\n", provider.Name, provider.IDNumber);
	if (!v) {
		printf("Could not add provider\n");
		return false;
	}

	ServiceCode code;
	code.Code = 10;
	strcpy(code.ServiceName, "Random Service");
	if (!data.addServiceCode(code)) {
		printf("Could not add service code\n");
		return false;
	} else {
		printf("Added service '%s' (%d)\n", code.ServiceName,
			code.Code);
	}

	ServiceReport report;
	report.MemberNum = member.IDNumber;
	report.ProviderNum = provider.IDNumber;
	report.ServiceCode = code.Code;
	v = data.addService(report) > 0;
	printServiceSuccess(v);
	if (!v)
		return false;

	printf("Setting invalid provider...\n");
	report.ProviderNum = -1;
	v = data.addService(report) > 0;
	printServiceSuccess(v);
	if (v)
		return false;

	printf("Setting invalid member...\n");
	report.ProviderNum = provider.IDNumber;
	report.MemberNum = -1;
	v = data.addService(report) > 0;
	printServiceSuccess(v);
	if (v)
		return false;

	printf("Setting invalid service code...\n");
	report.MemberNum = member.IDNumber;
	report.ServiceCode = -1;
	v = data.addService(report) > 0;
	printServiceSuccess(v);
	if (v)
		return false;

	return true;
}

void printServiceSuccess(bool v)
{
	if (v)
		printf("Service successfully added... Test PASSED\n");
	else
		printf("Could not add service... Test FAILED\n");
}
