#include <fstream>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include "notimplement.h"

using namespace std;

class FObj {
    public:
        FObj();

        virtual ~FObj(); 
    
        virtual bool Read(ifstream&) = 0;
        virtual bool Write(ofstream&) const = 0;
        virtual void Display() const = 0;
};



class FObjService : public FObj {
    public:
        FObjService();
        FObjService(char*, char*, char*, char*, char*, char*);
        FObjService(const FObjService&);

        ~FObjService();

        FObjService& operator=(const FObjService&);
        
        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        int CompareDate(const FObjService&) const;
        int CompareTime(const FObjService&) const;

        bool GenerateFileName(char*) const;
        bool get_date(char*) const;
        bool GetComputerReceivedDate(char*) const;


    protected:
        void Erase();

        char* date_;
        char* time_;
        char* provider_num_;
        char* member_num_;
        char* service_code_;
        
    private:
        char* comment_;
};


class FObjMemberService : public FObjService {
    public:
        FObjMemberService();
        FObjMemberService(const FObjService&);
        FObjMemberService(const FObjMemberService&);

        ~FObjMemberService();

        FObjMemberService& operator=(const FObjMemberService&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        bool get_info(DataCenter*, class ProviderDirectoryLogging*);
        char* get_num() const; 
        void set_next(FObjMemberService*);
        FObjMemberService* get_next() const;

    protected:
        void Erase();
        
        FObjMemberService* next_;
        char* provider_name_;
        char* service_name_;
};


class FObjProviderService : public FObjService {
    public:
        FObjProviderService();
        FObjProviderService(const FObjService&);
        FObjProviderService(const FObjProviderService&);

        ~FObjProviderService();

        FObjProviderService& operator=(const FObjProviderService&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        bool get_info(DataCenter*, ProviderDirectoryLogging*);
        char* get_num() const;
        void set_next(FObjProviderService*);
        FObjProviderService* get_next() const;
        float get_fee() const;

    protected: 
        void Erase();

        FObjProviderService* next_;
        char* member_name_;
        float fee_;
};


class Provider : public FObj {
    public: 
        Provider();
        Provider(char*, char*, char*, char*, char*, char*);
        Provider(const Provider&);

        ~Provider();

        Provider& operator=(const Provider&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        bool operator<(const Provider&) const; 
        bool operator>(const Provider&) const;
        bool operator==(const Provider&) const;

        friend bool operator<(const Provider&, const Provider&);
        friend bool operator>(const Provider&, const Provider&);
        friend bool operator==(const Provider&, const Provider&);
    
        char* get_number() const;
        char* get_name() const;

    protected:
        void Erase();

        char* name_;
        char* number_;
        char* address_;
        char* city_;
        char* state_;
        char* zip_code_;
};


class Member : public Provider {
    public: 
        Member();
        Member(char*, char*, char*, char*, char*, char*, char*);
        Member(const Member&);

        ~Member();

        Member& operator=(const Member&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        friend bool operator<(const Member&, const Member&);
        friend bool operator>(const Member&, const Member&);
        friend bool operator==(const Member&, const Member&);

    private:
        void Erase();

        char* status_;
};


class FObjMemberReport : public FObj {
    public: 
        FObjMemberReport();
        FObjMemberReport(Member*, char*);
        FObjMemberReport(const FObjMemberReport&);

        ~FObjMemberReport();        

        FObjMemberReport& operator=(const FObjMemberReport&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        void InsertMemberService(FObjMemberService&);
        
        bool GetMemberNumber(char*) const;
        bool GenerateFileName(char*) const;

    protected:
        FObjMemberService* list_entry_;
        Member* member_;
        char* report_date_;

    private:
        FObjMemberService* CopyServiceList(FObjMemberService* dst, FObjMemberService* scr);
        FObjMemberService* ClearServiceList(FObjMemberService* phead);
        FObjMemberService* ReadService(FObjMemberService* phead, ifstream& in);
        bool WriteService(const FObjMemberService* phead, ofstream& out) const;
        void DisplayServiceList(FObjMemberService* phead) const;
        FObjMemberService* InsertMemberService(FObjMemberService* phead, FObjMemberService* pnode);
};


class FObjProviderReportSummary : public FObj {
    public:  
        FObjProviderReportSummary();
        FObjProviderReportSummary(Provider*, char*);
        FObjProviderReportSummary(const FObjProviderReportSummary&);

        ~FObjProviderReportSummary();

        FObjProviderReportSummary& operator=(const FObjProviderReportSummary&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        int get_consultation_num() const;
        float get_fee() const;

    protected:
        void Erase();

        char* report_date_;
        Provider* provider_;
        char* consultation_num_;
        float fee_;
};


class FObjProviderReport : public FObjProviderReportSummary {
    public: 
        FObjProviderReport();
        FObjProviderReport(Provider*, char*);
        FObjProviderReport(const FObjProviderReport&);

        ~FObjProviderReport();

        FObjProviderReport& operator=(const FObjProviderReport&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        void InsertProviderService(FObjProviderService&);

        bool GetProviderNumber(char*) const;
        bool GenerateFileName(char*) const;

    private:
        FObjProviderService* CopyServiceList(FObjProviderService* dst, FObjProviderService* scr);
        FObjProviderService* ClearServiceList(FObjProviderService* phead);
        FObjProviderService* ReadService(FObjProviderService* phead, ifstream& in);
        bool WriteService(FObjProviderService* phead, ofstream& out) const;
        void DisplayServiceList(FObjProviderService* phead) const;
        FObjProviderService* InsertProviderService(FObjProviderService* phead, FObjProviderService* pnode);

        FObjProviderService* list_entry_;
};


//need testing
class FObjManagerReport : public FObj {
    public: 
        FObjManagerReport();
        FObjManagerReport(FObjProviderReportSummary*, int, char*);
        FObjManagerReport(const FObjManagerReport&);

        ~FObjManagerReport();

        FObjManagerReport& operator=(const FObjManagerReport&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        bool GenerateFileName(char*) const;

    private:
        void Erase();

        char* report_date_;
        FObjProviderReportSummary* provider_report_;
        int provider_num_;
        int sum_consultation_;
        float fee_;
};


//need testing
class FObjEFT : public FObjProviderReportSummary {
    public: 
        FObjEFT();
        FObjEFT(FObjProviderReportSummary&);
        FObjEFT(const FObjEFT&);

        ~FObjEFT();

        FObjEFT& operator=(const FObjEFT&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        bool GenerateFileName(char*) const;

    private: 
        void Erase();

        char* provider_num_;
        char* provider_name_;
};


class CdcMemberEntries : public FObj {
    public: 
        CdcMemberEntries();
        CdcMemberEntries(Member*, int);
        CdcMemberEntries(const CdcMemberEntries&);

        ~CdcMemberEntries();

        CdcMemberEntries& operator=(const CdcMemberEntries&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        int get_entries(Member*) const;

    private:
        int size_;
        Member* entry_array_;
};


class CdcProviderEntries : public FObj {
    public: 
        CdcProviderEntries();
        CdcProviderEntries(Provider*, int);
        CdcProviderEntries(const CdcProviderEntries&);

        ~CdcProviderEntries();

        CdcProviderEntries& operator=(const CdcProviderEntries&);

        bool Read(ifstream&);
        bool Write(ofstream&) const;
        void Display() const;

        int get_entries(Provider*) const;

    private:
        int size_;
        Provider* entry_array_;
};


class File {
    public:  
        File();
        File(char*, char*, char*);
        File(const File&);

        ~File();

        File& operator=(const File&);

        bool Read(FObj**);
        bool Write(FObj*);
        bool WriteAppend(FObj*);
    
    private: 
        void Erase();

        char* path_;
        char* name_;
        char* date_;
        ifstream in;
        ofstream out;
};


class Directory {
    public: 
        Directory();
        Directory(char*, char*);
        Directory(const Directory&);

        ~Directory();

        Directory& operator=(const Directory&);

        void set_link1(Directory*);
        Directory* get_link1() const;

        void set_link2(Directory*);
        Directory* get_link2() const;

        char* get_name() const;
        char* get_path() const;

        //testing purpose function
        void Display();

    private:  
        void Erase();

        Directory* link_1_;
        Directory* link_2_;
        char* path_;
        char* name_;
};


class FileManager {
    public: 
        FileManager();
        FileManager(const FileManager&);

        ~FileManager();

        FileManager& operator=(const FileManager&);

        int Read(CdcMemberEntries*);
        int Read(CdcProviderEntries*);
        int Read(FObjService*, char*, char*);
        int Read(FObjProviderReportSummary*, char*, char*);
        int Read(class HashNode*, char*, char*);
        int Read(FObjEFT*, char*, char*);
        int Read(HashNode*);
        int Read(HashNode*, const char*);
        int Write(const FObj*);

        //testing purpose function
        void DisplayServiceDirectory();
        void DisplayServiceDirectoryRev();
        void DisplayMemberReportDirectory();
        void DisplayProviderReportDirectory();

        bool Initialize();

    private:
        bool CheckDirectory();
        void InitProcess(bool[], bool[]);
        void InsertServiceDirectory(Directory&);
        void InsertMemberReportDirectory(Directory&);
        void InsertProviderReportDirectory(Directory&);

        void Erase(); 
        Directory* CopyServiceRecordList(Directory* dst, Directory* scr);
        Directory* CopyReportDirectoryTree(Directory* dst, Directory* scr);
        Directory* ClearServiceRecordList(Directory* phead);
        Directory* ClearReportDirectoryTree(Directory* proot);
        Directory* InsertServiceDirectory(Directory* phead, Directory* item);
        Directory* InsertReportDirectory(Directory* proot, Directory* item);

        int TraverseDirectory(const char* pathname, int mode);
        int WriteService(const FObjService* service);
        Directory* WriteService(Directory* phead, Directory* item, const FObjService* service);
        int WriteMemberReport(const FObjMemberReport* report);
        Directory* WriteMemberReport(Directory* proot, Directory* item, const FObjMemberReport* report);
        int WriteProviderReport(const FObjProviderReport* report);
        Directory* WriteProviderReport(Directory* proot, Directory* item, const FObjProviderReport* report);
        int WriteEft(const FObjEFT* eft);
        int WriteManagerReport(const FObjManagerReport* report);
        int WriteCdcMemberEntries(const CdcMemberEntries* entries);
        int WriteCdcProviderEntries(const CdcProviderEntries* entries);
        int WriteProviderDirectoryEntries(const HashNode* pd_entries);
       
        void Read(Directory* proot, FObjProviderReportSummary* receiver, int& index, char* d_min, char* d_max);

        bool ParseProviderReportDate(char*, const char*);
        bool ParseEftDate(char*, const char*);
        bool ParseProviderDirectoryTime(char*, const char*) const;

        //testing purpose function
        void DisplayServiceDirectory(Directory* phead);
        void DisplayServiceDirectoryRev(Directory* ptail);
        void DisplayReportDirectory(Directory* proot);

        Directory* member_report_;
        Directory* provider_report_;
        Directory manager_report_;
        Directory cdc_record_;
        Directory eft_record_;
        Directory provider_directory_;
        Directory* service_record_head_;
        Directory* service_record_tail_;
        char* current_working_directory_;
};
