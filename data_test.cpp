/* 
 * Author: Floris Creyf
 * Date: 12 Nov 2018
 */

#include "data.h"
#include <string.h>
#include <stdio.h>

void testValidation();

int main()
{
	printf("--- DATA TEST ---\n");
	testValidation();
	return 0;
}

void printServiceSuccess(bool v)
{
	if (v)
		printf("Service successfully added... Test PASSED\n");
	else
		printf("Could not add service... Test FAILED\n");
}

void testValidation()
{
	printf("VALIDATION TEST\n");

	Data data;
	bool v;
	int id = 0;
	bool passed = true;

	ProviderMember member;
	strcpy(member.Name, "John");
	member.IDNumber = id++;
	v = data.addMember(member);
	printf("Added member '%s' (%d)\n", member.Name, member.IDNumber);

	ProviderMember provider;
	strcpy(provider.Name, "Bob");
	provider.IDNumber = id++;
	v = data.addProvider(provider);
	printf("Added provider '%s' (%d)\n", provider.Name, provider.IDNumber);

	ServiceCode code;
	code.Code = 10;
	strcpy(code.ServiceName, "Eating");
	v = data.addServiceCode(code);
	printf("Added service '%s' (%d)\n", code.ServiceName, code.Code);

	ServiceReport report;
	report.MemberNum = member.IDNumber;
	report.ProviderNum = provider.IDNumber;
	report.ServiceCode = code.Code;
	v = data.addService(report);
	printServiceSuccess(v);
	if (!v)
		passed = false;

	printf("Setting invalid provider...\n");
	report.ProviderNum = -1;
	v = data.addService(report);
	printServiceSuccess(v);
	if (v)
		passed = false;

	printf("Setting invalid member...\n");
	report.ProviderNum = provider.IDNumber;
	report.MemberNum = -1;
	v = data.addService(report);
	printServiceSuccess(v);
	if (v)
		passed = false;

	printf("Setting invalid service code...\n");
	report.MemberNum = member.IDNumber;
	report.ServiceCode = -1;
	v = data.addService(report);
	printServiceSuccess(v);
	if (v)
		passed = false;

	if (passed)
		printf("All tests PASSED\n");
	else
	 	printf("Test FAILED\n");
}
