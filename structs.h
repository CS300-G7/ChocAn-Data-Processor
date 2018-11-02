struct ServiceReport
{
	char CDT[19];	//Current Date and Time
	char DoS[10];	//Date of service
	int ProviderNum;
	int MemberNum;
	int ServiceCode;
	char Comments[100];
	ServiceReport * next;
};

struct ProviderMember
{
	char Name[25];
	int IDNumber;
	char StreetAddess[25];
	char City[14];
	char State[2];
	int ZipCode;
	int Status;	//member status, 0 for suspended, 1 for valid
};

struct ServiceCode
{
	int Code;
	char ServiceName[20];
	float Fee;
};

struct Mhash
{
	ProviderMember Member;
	Mhash * next;
};

struct Phash
{
	ProviderMember Provider;
	Phash * next;
};

struct Dhash
{
	ServiceCode Service;
	Dhash * next;
};

struct MConsults
{
	char DoS[10];
	char ProviderName[25];
	char ServiceName[20];
	MConsults * next;
};

struct MReport
{
	ProviderMember Report;
	MConsults * Consults;
};

struct MRepHash
{
	MReport Member;
	MRepHash * next;
};

struct PConsults
{
	char DoS[10];
	char CDT[19];
	char MemberName[25];
	int MemberNum;
	int ServiceCode;
	float Fee;
	PConsults * next;
};

struct PReport
{
	ProviderMember Report;
	PConsults * Consults;
	int TotalConsults;
	float TotalFee;
};

struct PRepHash
{
	PReport Provider;
	PRepHash * next;
};

