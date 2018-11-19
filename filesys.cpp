#include "pd:rp.h"

FObj :: FObj() {}


FObj :: ~FObj() {}


FObjService :: FObjService() {
    date_ = NULL;
    time_ = NULL;
    provider_num_ = NULL;
    member_num_ = NULL;
    service_code_ = NULL;
    comment_ = NULL;
}


FObjService :: FObjService(char* date, char* time, char* p_num, char* m_num, char* sc, char* comm) {
    if(date) {
        date_ = new char[strlen(date) + 1];
        strcpy(date_, date);
    } else {
        date_ = NULL;
    }
    
    if(time) {
        time_ = new char[strlen(time) + 1];
        strcpy(time_, time);
    } else {
        time_ = NULL;
    }
    
    if(p_num) {
        provider_num_ = new char[strlen(p_num) + 1];
        strcpy(provider_num_, p_num);
    } else {
        provider_num_ = NULL;
    }

    if(m_num) {
        member_num_ = new char[strlen(m_num) + 1];
        strcpy(member_num_, m_num);
    } else {
        member_num_ = NULL;
    }
    
    if(sc) {
        service_code_ = new char[strlen(sc) + 1];
        strcpy(service_code_, sc);
    } else {
        service_code_ = NULL;
    }
    
    if(comm) {
        comment_ = new char[strlen(comm) + 1];
        strcpy(comment_, comm);
    } else {
        comment_ = NULL;
    }
}


FObjService :: FObjService(const FObjService& service) {
    if(service.date_) {
        date_ = new char[strlen(service.date_) + 1];
        strcpy(date_, service.date_);
    } else {
        date_ = NULL;
    }
    
    if(service.time_) {
        time_ = new char[strlen(service.time_) + 1];
        strcpy(time_, service.time_);
    } else {
        time_ = NULL;
    }
    
    if(service.provider_num_) {
        provider_num_ = new char[strlen(service.provider_num_) + 1];
        strcpy(provider_num_, service.provider_num_);
    } else {
        provider_num_ = NULL;
    }

    if(service.member_num_) {
        member_num_ = new char[strlen(service.member_num_) + 1];
        strcpy(member_num_, service.member_num_);
    } else {
        member_num_ = NULL;
    }
    
    if(service.service_code_) {
        service_code_ = new char[strlen(service.service_code_) + 1];
        strcpy(service_code_, service.service_code_);
    } else {
        service_code_ = NULL;
    }
    
    if(service.comment_) {
        comment_ = new char[strlen(service.comment_) + 1];
        strcpy(comment_, service.comment_);
    } else {
        comment_ = NULL;
    }
}


FObjService :: ~FObjService() {
    Erase();
}


FObjService& FObjService :: operator=(const FObjService& service) {
    if(this == &service)
        return *this;
    
    Erase();

    if(service.time_) {
        time_ = new char[strlen(service.time_) + 1];
        strcpy(time_, service.time_);
    } else {
        time_ = NULL;
    }
    
    if(service.provider_num_) {
        provider_num_ = new char[strlen(service.provider_num_) + 1];
        strcpy(provider_num_, service.provider_num_);
    } else {
        provider_num_ = NULL;
    }

    if(service.member_num_) {
        member_num_ = new char[strlen(service.member_num_) + 1];
        strcpy(member_num_, service.member_num_);
    } else {
        member_num_ = NULL;
    }
    
    if(service.service_code_) {
        service_code_ = new char[strlen(service.service_code_) + 1];
        strcpy(service_code_, service.service_code_);
    } else {
        service_code_ = NULL;
    }
    
    if(service.comment_) {
        comment_ = new char[strlen(service.comment_) + 1];
        strcpy(comment_, service.comment_);
    } else {
        comment_ = NULL;
    } 

    return *this;
}


void FObjService :: Erase() {
    if(date_) {
        delete [] date_;
        date_ = NULL;
    }
        
    if(time_) {
        delete [] time_;
        time_ = NULL;
    }
        
    if(provider_num_) {
        delete [] provider_num_;
        provider_num_ = NULL;
    }
        
    if(member_num_) {
        delete [] member_num_;
        member_num_ = NULL;
    }
        
    if(service_code_) {
        delete []  service_code_;
        service_code_ = NULL;
    }
        
    if(comment_) {
        delete [] comment_;
        comment_ = NULL;
    }
}


bool FObjService :: Read(ifstream& in) {
    char dt[len2sz(LEN_DATE)];
    char tm[len2sz(LEN_TIME)];
    char p_num[len2sz(LEN_PROVIDER_NUM)];
    char m_num[len2sz(LEN_MEMBER_NUM)];
    char sc[len2sz(LEN_SERVICE_CODE)];
    char comm[len2sz(LEN_COMMENT)];
    
    if(!in)
        return false;
    
    Erase();

    if(in.peek() != EOF) {
        in.get(tm, len2sz(LEN_TIME), '\n');
        in.ignore(1000, '\n');
        time_ = new char[len2sz(LEN_TIME)];
        strcpy(time_, tm);
    } 

    if(in.peek() != EOF) {
        in.get(dt, len2sz(LEN_DATE), '\n');
        in.ignore(1000, '\n');
        date_ = new char[len2sz(LEN_DATE)];
        strcpy(date_, dt);
    }

    if(in.peek() != EOF) {
        in.get(p_num, len2sz(LEN_PROVIDER_NUM), '\n');
        in.ignore(1000, '\n');
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, p_num);
    }
    
    if(in.peek() != EOF) {
        in.get(m_num, len2sz(LEN_MEMBER_NUM), '\n');
        in.ignore(1000, '\n');
        member_num_ = new char[len2sz(LEN_MEMBER_NUM)];
        strcpy(member_num_, m_num);
    }

    if(in.peek() != EOF) {
        in.get(sc, len2sz(LEN_SERVICE_CODE), '\n');
        in.ignore(1000, '\n');
        service_code_ = new char[len2sz(LEN_SERVICE_CODE)];
        strcpy(service_code_, sc);
    }

    if(in.peek() != EOF) {
        in.get(comm, len2sz(LEN_COMMENT), '#');
        in.ignore(1000, '#');
        comment_ = new char[len2sz(LEN_COMMENT)];
        strcpy(comment_, comm);
    }

    return true;
}


bool FObjService :: Write(ofstream& out) const {
    if(!out)
        return false;

    out << time_ << endl;
    out << date_ << endl;
    out << provider_num_ << endl;
    out << member_num_ << endl;
    out << service_code_ << endl;
    out << comment_ << "#";
    
    return true;
}


void FObjService :: Display() const {
    cout << endl << "Service record:" << endl;
    cout << time_ << endl;
    cout << date_ << endl;
    cout << provider_num_ << endl;
    cout << member_num_ << endl;
    cout << service_code_ << endl;
    cout << comment_ << endl;
}


int FObjService :: CompareDate(const FObjService& service) const {
    return Date :: dtcmp(date_, service.date_);
}


int FObjService :: CompareTime(const FObjService& service) const {
    return Time :: tmcmp(time_, service.time_);
}


bool FObjService :: GenerateFileName(char* receiver) const {
    if(!time_ || !provider_num_) 
        return false;
    
    char tmp[len2sz(LEN_TIME + LEN_PROVIDER_NAME + 5)];
    strcpy(tmp, time_);
    strcat(tmp, "_");
    strcat(tmp, provider_num_);
    strcat(tmp, ".txt");
    strcpy(receiver, tmp);
    return true;
}

bool FObjService :: get_date(char* receiver) const {
    if(!date_)
        return false;
    strcpy(receiver, date_);
    return true;
}


bool FObjService :: GetComputerReceivedDate(char* receiver) const {
    if(!time_)
        return false;
    strncpy(receiver, time_, 10);
    return true;
}


FObjMemberService :: FObjMemberService() {
    provider_name_ = NULL;
    service_name_ = NULL;
    next_ = NULL;
}


FObjMemberService :: FObjMemberService(const FObjService& service)
    : FObjService(service), next_(NULL), provider_name_(NULL), service_name_(NULL)
{
}


FObjMemberService :: FObjMemberService(const FObjMemberService& member_service) 
    : FObjService(member_service), next_(NULL)
{
    if(member_service.provider_name_) {
        provider_name_ = new char[strlen(member_service.provider_name_) + 1];
        strcpy(provider_name_, member_service.provider_name_);
    } else {
        provider_name_ = NULL;
    }

    if(member_service.service_name_) {
        service_name_ = new char[strlen(member_service.service_name_) + 1];
        strcpy(service_name_, member_service.service_name_);
    } else {
        service_name_ = NULL;
    }
}


FObjMemberService :: ~FObjMemberService() {
    Erase();
}


void FObjMemberService :: Erase() {
    if(provider_name_) {
        delete [] provider_name_;
        provider_name_ = NULL;
    }

    if(service_name_) {
        delete [] service_name_;
        service_name_ = NULL;
    }
}


FObjMemberService& FObjMemberService :: operator=(const FObjMemberService& member_service) {
    if(this == &member_service) 
        return *this;

    this -> FObjService :: operator=(member_service);
    
    Erase();

    if(member_service.provider_name_) {
        provider_name_ = new char[strlen(member_service.provider_name_) + 1];
        strcpy(provider_name_, member_service.provider_name_);
    }

    if(member_service.service_name_) {
        service_name_ = new char[strlen(member_service.service_name_) + 1];
        strcpy(service_name_, member_service.service_name_);
    }

    return *this;
}


bool FObjMemberService :: Read(ifstream& in) {
    char p_name[len2sz(LEN_PROVIDER_NAME)];
    char s_name[len2sz(LEN_SERVICE_NAME)];
    char dt[len2sz(LEN_DATE)];
    
    if(!in) 
        return false;

    FObjService :: Erase();
    Erase();

    if(in.peek() != EOF) {
        in.get(dt, len2sz(LEN_DATE), '\n');
        in.ignore(1000, '\n');
        date_ = new char[len2sz(LEN_DATE)];
        strcpy(date_, dt);
    }

    if(in.peek() != EOF) {
        in.get(p_name, len2sz(LEN_PROVIDER_NAME), '\n');
        in.ignore(1000, '\n');
        provider_name_ = new char[len2sz(LEN_PROVIDER_NAME)];
        strcpy(provider_name_, p_name);
    }

    if(in.peek() != EOF) {
        in.get(s_name, len2sz(LEN_SERVICE_NAME), '\n');
        in.ignore(1000, '\n');
        service_name_ = new char[len2sz(LEN_SERVICE_NAME)];
        strcpy(service_name_, s_name);
    }

    next_ = NULL;

    return true;
}


bool FObjMemberService :: Write(ofstream& out) const {
    if(!out)
        return false;

    out << date_ << endl;
    out << provider_name_ << endl;
    out << service_name_ << endl;

    return true;
}


void FObjMemberService :: Display() const {
    cout << endl << date_ << endl;
    cout << provider_name_ << endl;
    cout << service_name_ << endl;
}


void FObjMemberService :: set_next(FObjMemberService* np) {
    next_ = np;
}


FObjMemberService* FObjMemberService :: get_next() const {
    return next_;
}


bool FObjMemberService :: get_info(DataCenter* dc, ProviderDirectoryLogging* pd) {
    char s_name[len2sz(LEN_SERVICE_NAME)];

    // not implemented yet
    // temp. assign data for testing
    char temp_pn[] = "temp. provider name";

    if(!pd) {
        cerr << "Cannot find provider directory information.\nMember service record exception. " << endl;
        return false;
    }

    if(!pd -> SearchServiceName(time_, service_code_, s_name))
        strcpy(s_name, "Unknown");

    // temporary value for provider name
    // char p_name[len2sz(LEN_PROVIDER_NAME)];
    // dc -> get_provider_name(provider_num_, p_name);
    // ------------------------- temp. value ------------------------------
    provider_name_  = new char[len2sz(strlen(temp_pn))];
    strcpy(provider_name_, temp_pn);
    // --------------------------------------------------------------------

    service_name_ = new char[len2sz(strlen(s_name))];
    strcpy(service_name_, s_name);

    return true;
}


char* FObjMemberService :: get_num() const {
    return member_num_;
}


FObjProviderService :: FObjProviderService() {
    member_name_ = NULL;
    fee_ = 0.0;
    next_ = NULL;
}


FObjProviderService :: FObjProviderService(const FObjService& service)
    : FObjService(service), member_name_(NULL), fee_(0.0), next_(NULL)
{
}


FObjProviderService :: FObjProviderService(const FObjProviderService& provider_service) 
    : FObjService(provider_service), next_(NULL) {
        if(provider_service.member_name_) {
            member_name_ = new char[len2sz(strlen(provider_service.member_name_))];
            strcpy(member_name_, provider_service.member_name_);
        } else {
            member_name_ = NULL;
        }

        fee_ = provider_service.fee_;
}


FObjProviderService :: ~FObjProviderService() {
    Erase();
}


void FObjProviderService :: Erase() {
    if(member_name_) {
        delete [] member_name_;
        member_name_ = NULL;
    }
}


FObjProviderService& FObjProviderService :: operator=(const FObjProviderService& provider_service) {
    if(this == &provider_service)
        return *this;

    this -> FObjService :: operator=(provider_service);

    Erase();

    if(provider_service.member_name_) {
        member_name_ = new char[len2sz(strlen(provider_service.member_name_))];
        strcpy(member_name_, provider_service.member_name_);
    }

    fee_ = provider_service.fee_;
    next_ = NULL;

    return *this;
}


bool FObjProviderService :: Read(ifstream& in) {
    char dt[len2sz(LEN_DATE)]; 
    char tm[len2sz(LEN_TIME)];
    char m_name[len2sz(LEN_MEMBER_NAME)];
    char m_num[len2sz(LEN_MEMBER_NUM)];
    char sc[len2sz(LEN_SERVICE_CODE)];
    float f = 0.0;

    if(!in) 
        return false;

    FObjService :: Erase();
    Erase();

    if(in.peek() != EOF) {
        in.get(dt, len2sz(LEN_DATE), '\n');
        in.ignore(1000, '\n');
        date_ = new char[len2sz(strlen(dt))];
        strcpy(date_, dt);
    }

    if(in.peek() != EOF) {
        in.get(tm, len2sz(LEN_TIME), '\n');
        in.ignore(1000, '\n');
        time_ = new char[len2sz(strlen(tm))];
        strcpy(time_, tm);
    }

    if(in.peek() != EOF) {
        in.get(m_name, len2sz(LEN_MEMBER_NAME), '\n');
        in.ignore(1000, '\n');
        member_name_ = new char[len2sz(strlen(m_name))];
        strcpy(member_name_, m_name);
    }

    if(in.peek() != EOF) {
        in.get(m_num, len2sz(LEN_MEMBER_NUM), '\n');
        in.ignore(1000, '\n');
        member_num_ = new char[len2sz(strlen(m_num))];
        strcpy(member_num_, m_num);
    }

    if(in.peek() != EOF) {
        in.get(sc, len2sz(LEN_SERVICE_CODE), '\n');
        in.ignore(1000, '\n');
        service_code_ = new char[len2sz(strlen(sc))];
        strcpy(service_code_, sc);
    }

    if(in.peek() != EOF) {
        in >> f;
        in.ignore(1000, '\n');
        fee_ = f;
    }
    
    next_  = NULL;
    return true;
}


bool FObjProviderService :: Write(ofstream& out) const {
    if(!out) 
        return false;

    out << date_ << endl;
    out << time_ << endl;
    out << member_name_ << endl;
    out << member_num_ << endl;
    out << service_code_ << endl;
    out << fee_ << endl;

    return true;
}


void FObjProviderService :: Display() const {
    cout << endl << date_ << endl;
    cout << time_ << endl;
    cout << member_name_ << endl;
    cout << member_num_ << endl;
    cout << service_code_ << endl;
    cout << fee_ << endl;
}


bool FObjProviderService :: get_info(DataCenter* dc, ProviderDirectoryLogging* pd) {
    //not implemented yet
    //temp. val used to test
    char temp_mn[] = "temp. member name";

    if(!pd) {
        cerr << "Cannot find provider directory information.\nMember service record exception. " << endl;
        return false;
    }

    fee_ = pd -> SerachFee(time_, service_code_);
    
    // temporary value for member name
    // char m_name[len2sz(LEN_PROVIDER_NAME)];
    // dc -> get_member_name(member_num_, m_name);
    // --------------------------- temp. value ---------------------------
    member_name_ = new char[len2sz(strlen(temp_mn))];
    strcpy(member_name_, temp_mn);
    // -------------------------------------------------------------------

    return true;
}


void FObjProviderService :: set_next(FObjProviderService* np) {
    next_ = np;
}


FObjProviderService* FObjProviderService :: get_next() const {
    return next_;
}


float FObjProviderService :: get_fee() const {
    return fee_;
}


char* FObjProviderService :: get_num() const {
    return provider_num_;
}


FObjMemberReport :: FObjMemberReport() {
    member_ = NULL;
    list_entry_ = NULL;
    report_date_ = NULL;
}


FObjMemberReport :: FObjMemberReport(Member* member, char* dt) {
    member_ = new Member(*member);
    list_entry_ = NULL;
    
    report_date_ = new char[len2sz(strlen(dt))];
    strcpy(report_date_, dt);
}


FObjMemberReport :: FObjMemberReport(const FObjMemberReport& report) {
    if(report.member_)
        member_ = new Member(*report.member_);
    else 
        member_ = NULL;

    list_entry_ = CopyServiceList(list_entry_, report.list_entry_);

    if(report.report_date_) {
        report_date_ = new char[len2sz(strlen(report.report_date_))];
        strcpy(report_date_, report.report_date_);
    } else {
        report_date_ = NULL;
    }
}


FObjMemberService* FObjMemberReport :: CopyServiceList(FObjMemberService* dst, 
                                                       FObjMemberService* scr) {
    if(!scr)
        return NULL;
    
    dst = new FObjMemberService(*scr);
    FObjMemberService* after_head_ptr = CopyServiceList(NULL, scr -> get_next());
    dst -> set_next(after_head_ptr);
    return dst;
}


FObjMemberReport :: ~FObjMemberReport() {
    if(member_) {
        delete member_;
        member_ = NULL;
    }

    if(report_date_) {
        delete report_date_;
        report_date_ = NULL;
    }

    list_entry_ = ClearServiceList(list_entry_);
}


FObjMemberService* FObjMemberReport :: ClearServiceList(FObjMemberService* phead) {
    if(!phead)
        return NULL;
    
    FObjMemberService* after_head_ptr = ClearServiceList(phead -> get_next());
    phead -> set_next(after_head_ptr);
    delete phead;
    phead = NULL;
    return NULL;
}


FObjMemberReport& FObjMemberReport :: operator=(const FObjMemberReport& report) {
    if(this == &report) 
        return *this;

    if(member_) 
        delete [] member_;
    if(report_date_)
        delete [] report_date_;
    list_entry_ = ClearServiceList(list_entry_);

    if(report.member_) 
        member_ = new Member(*report.member_);
    else    
        member_ = NULL;

    list_entry_ = CopyServiceList(list_entry_, report.list_entry_);

    if(report.report_date_) {
        report_date_ = new char[len2sz(strlen(report.report_date_))];
        strcpy(report_date_, report.report_date_);
    } else {
        report_date_ = NULL;
    }

    return *this;
}


bool FObjMemberReport :: Read(ifstream& in) {
    if(!in)
        return false;

    if(member_) 
        delete member_;
    list_entry_ = ClearServiceList(list_entry_);   

    member_ = new Member();
    if(!member_ -> Provider :: Read(in)) 
        return false;

    list_entry_ = ReadService(list_entry_, in);
    return true;
}


FObjMemberService* FObjMemberReport :: ReadService(FObjMemberService* phead, ifstream& in) {
    if(!in || in.peek() == EOF)
        return NULL;
    
    phead = new FObjMemberService();
    phead -> Read(in);
    FObjMemberService* after_head_ptr = ReadService(NULL, in);
    phead -> set_next(after_head_ptr);
    return phead;
}


bool FObjMemberReport :: Write(ofstream& out) const {
    if(!out)
        return false;

    if(!member_ -> Provider :: Write(out))
        return false;
    return WriteService(list_entry_, out);
}


bool FObjMemberReport :: WriteService(const FObjMemberService* phead, ofstream& out) const {
    if(!phead || !out)
        return false;

    if(!phead -> get_next())
        return phead -> Write(out);
    
    phead -> Write(out);
    return WriteService(phead -> get_next(), out);
}


void FObjMemberReport :: Display() const {
    member_ -> Provider :: Display();
    DisplayServiceList(list_entry_);
}


void FObjMemberReport :: DisplayServiceList(FObjMemberService* phead) const {
    if(!phead)
        return ;
    
    phead -> Display();
    DisplayServiceList(phead -> get_next());
}


void FObjMemberReport :: InsertMemberService(FObjMemberService& service) {
    FObjMemberService* pnode = new FObjMemberService(service);
    list_entry_ = InsertMemberService(list_entry_, pnode);
}


FObjMemberService* FObjMemberReport :: InsertMemberService(FObjMemberService* phead, 
                                                           FObjMemberService* pnode) {
    if(!phead)
        return pnode;

    if(phead -> CompareDate(*pnode) > 0) {
        pnode -> set_next(phead);
        return pnode;
    } else {
        FObjMemberService* after_head_ptr = InsertMemberService(phead -> get_next(), pnode);
        phead -> set_next(after_head_ptr);
        return phead;
    }
}


bool FObjMemberReport :: GetMemberNumber(char* receiver) const {
    if(!member_)
        return false;
    if(!member_ -> get_number())
        return false;
    
    strcpy(receiver, member_ -> get_number());
    return true;
}
        
        
bool FObjMemberReport :: GenerateFileName(char* receiver) const {
    if(!member_ || !report_date_) 
        return false;
    if(!member_ -> get_number() || !member_ -> get_name())
        return false;

    strcpy(receiver, member_ -> get_name());
    strcat(receiver, "_");
    strcat(receiver, report_date_);
    strcat(receiver, ".txt");
    return true;
}


FObjProviderReportSummary :: FObjProviderReportSummary() {
    provider_ = NULL;
    consultation_num_ = new char[4];
    consultation_num_[0] = '0';
    consultation_num_[1] = '0';
    consultation_num_[2] = '0';
    consultation_num_[3] = '\0';
    fee_ = 0.0;
    report_date_ = NULL;
}


FObjProviderReportSummary :: FObjProviderReportSummary(Provider* provider, char* dt) {
    provider_ = new Provider(*provider);
    consultation_num_ = new char[4];
    consultation_num_[0] = '0';
    consultation_num_[1] = '0';
    consultation_num_[2] = '0';
    consultation_num_[3] = '\0';
    fee_ = 0.0;

    if(dt) {
        report_date_ = new char[len2sz(strlen(dt))];
        strcpy(report_date_, dt);
    } else {
        report_date_ = NULL;
    }
}


FObjProviderReportSummary :: FObjProviderReportSummary(const FObjProviderReportSummary& summary) {
    if(summary.provider_) {
        provider_ = new Provider(*summary.provider_);
    } else {
        provider_ = NULL;
    }

    if(summary.consultation_num_) {
        consultation_num_ = new char[len2sz(strlen(summary.consultation_num_))];
        strcpy(consultation_num_, summary.consultation_num_);
    } else {
        consultation_num_ = NULL;
    }

    if(summary.report_date_) {
        report_date_ = new char[len2sz(strlen(summary.report_date_))];
        strcpy(report_date_, summary.report_date_);
    } else {
        report_date_ = NULL;
    }

    fee_ = summary.fee_;
}


FObjProviderReportSummary :: ~FObjProviderReportSummary() {
    Erase();
}


void FObjProviderReportSummary :: Erase() {
    if(provider_) {
        delete provider_;
        provider_ = NULL;
    }

    if(consultation_num_) {
        delete [] consultation_num_;
        consultation_num_ = NULL;
    }

    if(report_date_) {
        delete [] report_date_;
        report_date_ = NULL;
    }
}


FObjProviderReportSummary& FObjProviderReportSummary :: operator=(const FObjProviderReportSummary& summary) {
    if(this == &summary)    
        return *this;

    Erase();
    
    if(summary.provider_) {
        provider_ = new Provider(*summary.provider_);
    }

    if(summary.consultation_num_) {
        consultation_num_ = new char[len2sz(strlen(summary.consultation_num_))];
        strcpy(consultation_num_, summary.consultation_num_); 
    } else {
        consultation_num_ = NULL;
    }

    if(summary.report_date_) {
        report_date_ = new char[len2sz(strlen(summary.report_date_))];
        strcpy(report_date_, summary.report_date_);
    } else{
        report_date_ = NULL;
    }
    
    fee_ = summary.fee_;

    return *this;
}


bool FObjProviderReportSummary :: Read(ifstream& in) {
    char c_num[len2sz(LEN_CONSULTATION_NUM)];
    float fee;

    if(!in)
        return false;
        

    Erase();

    provider_ = new Provider();
    if(!provider_ -> Read(in))
        return false;

    if(in.peek() != EOF) {
        in.get(c_num, len2sz(LEN_CONSULTATION_NUM), '\n');
        in.ignore(1000, '\n');
        consultation_num_ = new char[len2sz(LEN_CONSULTATION_NUM)];
        strcpy(consultation_num_, c_num);
    }

    if(in.peek() != EOF) {
        in >> fee;
        in.ignore(1000, '\n');
        fee_ = fee;
    }

    return true;
}


bool FObjProviderReportSummary :: Write(ofstream& out) const {
    if(!out)
        return false;
    
    if(!provider_ -> Write(out))
        return false;
    
    out << consultation_num_ << endl;
    out << fee_ << endl;
    return true;
}


void FObjProviderReportSummary :: Display() const {
    if(provider_)
        provider_ -> Display();
    cout << consultation_num_ << endl;
    cout << fee_ << endl;
}


int FObjProviderReportSummary :: get_consultation_num() const {
    int n1, n2, n3;
    n1 = ch2int(consultation_num_[0]);
    n2 = ch2int(consultation_num_[1]);
    n3 = ch2int(consultation_num_[2]);
    return n1 * 100 + n2 * 10 + n3;
}

float FObjProviderReportSummary :: get_fee() const {
    return fee_;
}


FObjProviderReport :: FObjProviderReport() {
    list_entry_ = NULL;
}


FObjProviderReport :: FObjProviderReport(Provider* provider, char* dt)
    : FObjProviderReportSummary(provider, dt), list_entry_(NULL)
{
}


FObjProviderReport :: FObjProviderReport(const FObjProviderReport& report)
    : FObjProviderReportSummary(report) {
    list_entry_ = CopyServiceList(list_entry_, report.list_entry_);
}


FObjProviderService* FObjProviderReport :: CopyServiceList(FObjProviderService* dst, 
                                                           FObjProviderService* scr) {
    if(!scr)
        return NULL;
    
    dst = new FObjProviderService(*scr);
    FObjProviderService* after_head_ptr = CopyServiceList(NULL, scr -> get_next());
    dst -> set_next(after_head_ptr);
    return dst;
}


FObjProviderReport :: ~FObjProviderReport() {
    list_entry_ = ClearServiceList(list_entry_);
}


FObjProviderService* FObjProviderReport :: ClearServiceList(FObjProviderService* phead) {
    if(!phead)
        return NULL;

    FObjProviderService* after_head_ptr = ClearServiceList(phead -> get_next());
    phead -> set_next(after_head_ptr);
    delete phead;
    phead = NULL;
    return NULL;
}


FObjProviderReport& FObjProviderReport :: operator=(const FObjProviderReport& report) {
    if(this == &report)
        return *this;

    this -> FObjProviderReportSummary :: operator=(report);

    list_entry_ = ClearServiceList(list_entry_);
    list_entry_ = CopyServiceList(list_entry_, report.list_entry_);

    return *this;
}


bool FObjProviderReport :: Read(ifstream& in) {
    if(!in)
        return false;
    
    if(!FObjProviderReportSummary :: Read(in))
        return false;

    list_entry_ = ClearServiceList(list_entry_);    
    list_entry_ = ReadService(list_entry_, in);
    
    return true;
}


FObjProviderService* FObjProviderReport :: ReadService(FObjProviderService* phead, ifstream& in) {
    if(!in)
        return NULL;
    
    if(in.peek() == EOF)
        return NULL;
    
    phead = new FObjProviderService();
    phead -> Read(in);
    FObjProviderService* after_head_ptr = ReadService(NULL, in);
    phead -> set_next(after_head_ptr);
    return phead;
}


bool FObjProviderReport :: Write(ofstream& out) const {
    if(!out)
        return false;
    
    if(!FObjProviderReportSummary :: Write(out))
        return false;
    
    return WriteService(list_entry_, out);
}


bool FObjProviderReport :: WriteService(FObjProviderService* phead, ofstream& out) const {
    if(!out)
        return false;
    
    if(!phead)
        return true;
    
    phead -> Write(out);
    return WriteService(phead -> get_next(), out);
}


void FObjProviderReport :: Display() const {
    if(provider_)
        provider_ -> Display();
    
    DisplayServiceList(list_entry_);
    cout << consultation_num_ << endl;
    cout << fee_ << endl;
}


void FObjProviderReport :: DisplayServiceList(FObjProviderService* phead) const {
    if(!phead)
        return ;
    
    phead -> Display();
    DisplayServiceList(phead -> get_next());
}


void FObjProviderReport :: InsertProviderService(FObjProviderService& service) {
    FObjProviderService* pnode = new FObjProviderService(service);
    incre3dig(consultation_num_); 
    fee_ += service.get_fee();
    list_entry_ = InsertProviderService(list_entry_, pnode);
}


FObjProviderService* FObjProviderReport :: InsertProviderService(FObjProviderService* phead, 
                                                                 FObjProviderService* pnode) {
    if(!phead)
        return pnode;
    
    if(phead -> CompareTime(*pnode) > 0) {
        pnode -> set_next(phead);
        return pnode;
    } else {
        FObjProviderService* after_head_ptr = InsertProviderService(phead -> get_next(), pnode);
        phead -> set_next(after_head_ptr);
        return phead;
    }
}


bool FObjProviderReport :: GetProviderNumber(char* receiver) const {
    if(!provider_)
        return false;
    if(!provider_ -> get_number())
        return false;

    strcpy(receiver, provider_ -> get_number());
    return true;
}
        
        
bool FObjProviderReport :: GenerateFileName(char* receiver) const {
    if(!provider_ || !report_date_)
        return false;
    if(!provider_ -> get_name())
        return false;

    strcpy(receiver, provider_ -> get_name());
    strcat(receiver, "_");
    strcat(receiver, report_date_);
    strcat(receiver, ".txt");

    return true;
}


                                
FObjManagerReport :: FObjManagerReport() {
    provider_report_ = NULL;
    provider_num_ = 0;
    sum_consultation_ = 0;
    fee_ = 0.0;
    report_date_ = NULL;
}                       


FObjManagerReport :: FObjManagerReport(FObjProviderReportSummary* arr, int sz, char* dt) {
    sum_consultation_ = 0;
    provider_num_ = 0;
    
    if(arr) {
       provider_report_ = new FObjProviderReportSummary[sz];
        for(int i = 0; i < sz; ++i) {
                *(provider_report_ + i) = *(arr + i);
                sum_consultation_ += (provider_report_ + i) -> get_consultation_num();
                fee_ += (provider_report_ + i) -> get_fee();
                ++provider_num_;
        } 
    } else {
        provider_report_ = NULL;
        provider_num_ = 0;
        sum_consultation_ = 0;
        fee_ = 0.0;
    }

    if(dt) {
        report_date_ = new char[len2sz(strlen(dt))];
        strcpy(report_date_, dt);
    } else {
        report_date_ = NULL;
    }
}


FObjManagerReport :: FObjManagerReport(const FObjManagerReport& report) {
    if(!report.provider_report_) {
        provider_report_ = NULL;
        provider_num_ = 0;
        sum_consultation_ = 0;
        fee_ = 0.0;
    } else {
        provider_report_ = new FObjProviderReportSummary[report.provider_num_];
        for(int i = 0; i < report.provider_num_; ++i) {
            *(provider_report_ + i) = *(report.provider_report_ + i);
            sum_consultation_ += (report.provider_report_ + i) -> get_consultation_num();
            fee_ += (report.provider_report_ + i) -> get_fee();
            ++provider_num_;
        } 
    }

    if(report.report_date_) {
        report_date_ = new char[len2sz(strlen(report.report_date_))];
        strcpy(report_date_, report.report_date_);
    } else {
        report_date_ = NULL;
    }
}


FObjManagerReport :: ~FObjManagerReport() {
    Erase();
}


void FObjManagerReport :: Erase() {
    if(provider_report_) {
        delete [] provider_report_;
        provider_report_ = NULL;
    }

    if(report_date_) {
        delete [] report_date_;
        report_date_ = NULL;
    }

    provider_num_ = 0;
    sum_consultation_ = 0;
    fee_ = 0.0;
}

FObjManagerReport& FObjManagerReport :: operator=(const FObjManagerReport& report) {
    if(this == &report)
        return *this;
    
    Erase();

    if(!report.provider_report_) {
        provider_report_ = NULL;
        provider_num_ = 0;
        sum_consultation_ = 0;
        fee_ = 0.0;
    } else {
        provider_report_ = new FObjProviderReportSummary[report.provider_num_];
        for(int i = 0; i < report.provider_num_; ++i) {
            *(provider_report_ + i) = *(report.provider_report_ + i);
            sum_consultation_ += (report.provider_report_ + i) -> get_consultation_num();
            fee_ += (report.provider_report_ + i) -> get_fee();
            ++provider_num_;
        } 
    }

    if(report.report_date_) {
        report_date_ = new char[len2sz(strlen(report.report_date_))];
        strcpy(report_date_, report.report_date_);
    } else {
        report_date_ = NULL;
    }

    return *this;       
}


bool FObjManagerReport :: Read(ifstream& in) {
    int count = 0;

    if(!in)
        return false;

    Erase();

    if(in.peek() != EOF) {
        in >> provider_num_;
        in.ignore(1000, '\n');   
        in >> sum_consultation_; 
        in.ignore(1000, '\n');
        in >> fee_;
        in.ignore(1000, '\n');
    }
    
    if(provider_num_) {
        provider_report_ = new FObjProviderReportSummary[provider_num_];
        while(count < provider_num_ && in.peek() != EOF) {
            FObjProviderReportSummary report_summary;
            report_summary.Read(in);
            *(provider_report_ + count) = report_summary;
            ++count;
        }
    }
    
    return true;
}


bool FObjManagerReport :: Write(ofstream& out) const {
    if(!out)
        return false;
    
    out << provider_num_ << endl;
    out << sum_consultation_ << endl;
    out << fee_ << endl;
    for(int i = 0; i < provider_num_; ++i) 
        (provider_report_ + i) -> Write(out);

    return true;
}


void FObjManagerReport :: Display() const {
    if(provider_report_) {
        for(int i = 0; i < provider_num_; ++i) 
            (provider_report_ + i) -> Display();
    }
    cout << provider_num_ << endl;
    cout << sum_consultation_ << endl;
    cout << fee_ << endl;
}


bool FObjManagerReport :: GenerateFileName(char* receiver) const {
    if(!report_date_)
        return false;

    strcpy(receiver, report_date_);
    strcat(receiver, ".txt");
    return true;    
}


FObjEFT :: FObjEFT() {
    provider_num_ = NULL;
    provider_name_ = NULL;
}


FObjEFT :: FObjEFT(FObjProviderReportSummary& summary) 
    : FObjProviderReportSummary(summary) {
    if(provider_ -> get_number()) {
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, provider_ -> get_number());
    } else {
        provider_num_ = NULL;
    }
    
    if(provider_ -> get_name()) {
        provider_name_ = new char[len2sz(LEN_PROVIDER_NAME)];
        strcpy(provider_name_, provider_ -> get_name());
    } else {
        provider_name_ = NULL;
    }
}


FObjEFT :: FObjEFT(const FObjEFT& eft) : FObjProviderReportSummary(eft) {
    if((eft.provider_) -> get_number()) {
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, (eft.provider_) -> get_number());
    } else {
        provider_num_ = NULL;
    }
    
    if((eft.provider_) -> get_name()) {
        provider_name_ = new char[len2sz(LEN_PROVIDER_NAME)];
        strcpy(provider_name_, (eft.provider_) -> get_name());
    } else {
        provider_name_ = NULL;
    }
}


FObjEFT :: ~FObjEFT() {
    Erase();
}


void FObjEFT :: Erase() {
    if(provider_name_) {
        delete [] provider_name_;
        provider_name_ = NULL;
    }

    if(provider_num_) {
        delete [] provider_num_;
        provider_num_ = NULL;
    }
}


FObjEFT& FObjEFT :: operator=(const FObjEFT& eft) {
    if(this == &eft)
        return *this;

    this -> FObjProviderReportSummary :: operator=(eft);

    Erase();

    if((eft.provider_) -> get_number()) {
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, (eft.provider_) -> get_number());
    } else {
        provider_num_ = NULL;
    }
    
    if((eft.provider_) -> get_name()) {
        provider_name_ = new char[len2sz(LEN_PROVIDER_NAME)];
        strcpy(provider_name_, (eft.provider_) -> get_name());
    } else {
        provider_name_ = NULL;
    }

    return *this;
}


bool FObjEFT :: Read(ifstream& in) {
    char p_name[len2sz(LEN_PROVIDER_NAME)];
    char p_num[len2sz(LEN_PROVIDER_NUM)];
    
    if(!in)
        return false;

    FObjProviderReportSummary :: Erase();
    Erase();

    if(in.peek() != EOF) {
        in.get(p_name, len2sz(LEN_PROVIDER_NAME), '\n');
        in.ignore(1000, '\n');
        provider_name_ = new char[len2sz(LEN_PROVIDER_NAME)];
        strcpy(provider_name_, p_name);
    }
    
    if(in.peek() != EOF) {
        in.get(p_num, len2sz(LEN_PROVIDER_NUM), '\n');
        in.ignore(1000, '\n');
        provider_num_ = new char[len2sz(LEN_PROVIDER_NUM)];
        strcpy(provider_num_, p_num);
    }

    return true;
}


bool FObjEFT :: Write(ofstream& out) const {
    if(!out)
        return false;
    
    out << provider_name_ << endl;
    out << provider_num_ << endl;
    out << fee_ << endl;

    return true;
}


void FObjEFT :: Display() const {
    cout << endl << provider_name_ << endl;
    cout << provider_num_ << endl;
    cout << fee_ << endl;
}


bool FObjEFT :: GenerateFileName(char* receiver) const {
    if(!report_date_ || !provider_num_) 
        return false;
    
    strcpy(receiver, report_date_);
    strcat(receiver, "_");
    strcat(receiver, provider_num_);
    strcat(receiver, "_EFT.txt");
    return true;
}


CdcMemberEntries :: CdcMemberEntries() {
    size_ = 0;
    entry_array_ = NULL;
}


CdcMemberEntries:: CdcMemberEntries(Member* array, int sz) {
    if(array && sz > 0) {
        entry_array_ = new Member[sz];
        for(int i = 0; i < sz; ++i) {
            entry_array_[i] = array[i];
        }
        size_ = sz; 
    } else {
        size_ = 0;
        entry_array_ = NULL;
    }
}


CdcMemberEntries :: CdcMemberEntries(const CdcMemberEntries& item) {
    if(item.entry_array_ && item.size_ > 0) {
        entry_array_ = new Member[item.size_];
        for(int i = 0; i < item.size_; ++i) {
            entry_array_[i] = item.entry_array_[i];
        }
        size_ = item.size_;
    } else {
        size_ = 0;
        entry_array_ = NULL;
    }
}


CdcMemberEntries:: ~CdcMemberEntries() {
    if(entry_array_) {
        delete [] entry_array_;
        entry_array_ = NULL;
    }
}


CdcMemberEntries& CdcMemberEntries :: operator=(const CdcMemberEntries& item) {
    if(this == &item)
        return *this;

    if(entry_array_) {
        delete [] entry_array_;
        entry_array_ = NULL;
    }

    if(item.entry_array_ && item.size_ > 0) {
        entry_array_ = new Member[item.size_];
        for(int i = 0; i < item.size_; ++i) {
            entry_array_[i] = item.entry_array_[i];
        }
        size_ = item.size_;
    } else {
        size_ = 0;
        entry_array_ = NULL;
    }

    return *this;
}


bool CdcMemberEntries :: Read(ifstream& in) {
    if(!in)
        return false;
    
    size_ = 0;
    if(entry_array_) {
        delete [] entry_array_;
        entry_array_ = NULL;
    } 

    entry_array_ = new Member[MAX_CDC_ENTRIES];
    while(in.peek() != EOF) {
        entry_array_[size_++].Read(in);
    }
    
    return true;
}


 
bool CdcMemberEntries :: Write(ofstream& out) const {
    if(!out)
        return false;

    for(int i = 0; i < size_; ++i) 
        entry_array_[i].Write(out);

    return true;
}



void CdcMemberEntries:: Display() const {
    for(int i = 0; i < size_; ++i) 
        entry_array_[i].Display();
}



int CdcMemberEntries :: get_entries(Member* receiver) const {
    if(size_ > 0 && entry_array_) {
        for(int i = 0; i < size_; ++i) 
            receiver[i] = entry_array_[i];
        return size_;
    } else {
        return 0;
    }
}


CdcProviderEntries :: CdcProviderEntries() {
    size_ = 0;
    entry_array_ = NULL;
}


CdcProviderEntries:: CdcProviderEntries(Provider* array, int sz) {
    if(array && sz > 0) {
        entry_array_ = new Provider[sz];
        for(int i = 0; i < sz; ++i) {
            entry_array_[i] = array[i];
        }
        size_ = sz; 
    } else {
        size_ = 0;
        entry_array_ = NULL;
    }
}


CdcProviderEntries :: CdcProviderEntries(const CdcProviderEntries& item) {
    if(item.entry_array_ && item.size_ > 0) {
        entry_array_ = new Provider[item.size_];
        for(int i = 0; i < item.size_; ++i) {
            entry_array_[i] = item.entry_array_[i];
        }
        size_ = item.size_;
    } else {
        size_ = 0;
        entry_array_ = NULL;
    }
}


CdcProviderEntries:: ~CdcProviderEntries() {
    if(entry_array_) {
        delete [] entry_array_;
        entry_array_ = NULL;
    }
}


CdcProviderEntries& CdcProviderEntries :: operator=(const CdcProviderEntries& item) {
    if(this == &item)
        return *this;

    if(entry_array_) {
        delete [] entry_array_;
        entry_array_ = NULL;
    }

    if(item.entry_array_ && item.size_ > 0) {
        entry_array_ = new Provider[item.size_];
        for(int i = 0; i < item.size_; ++i) {
            entry_array_[i] = item.entry_array_[i];
        }
        size_ = item.size_;
    } else {
        size_ = 0;
        entry_array_ = NULL;
    }

    return *this;
}


bool CdcProviderEntries :: Read(ifstream& in) {
    if(!in)
        return false;
    
    size_ = 0;
    if(entry_array_) {
        delete [] entry_array_;
        entry_array_ = NULL;
    } 

    entry_array_ = new Provider[MAX_CDC_ENTRIES];
    while(in.peek() != EOF) {
        entry_array_[size_++].Read(in);
    }
    
    return true;
}


 
bool CdcProviderEntries :: Write(ofstream& out) const {
    if(!out)
        return false;

    for(int i = 0; i < size_; ++i) 
        entry_array_[i].Write(out);

    return true;
}



void CdcProviderEntries:: Display() const {
    for(int i = 0; i < size_; ++i) 
        entry_array_[i].Display();
}



int CdcProviderEntries :: get_entries(Provider* receiver) const {
    if(size_ > 0 && entry_array_) {
        for(int i = 0; i < size_; ++i) 
            receiver[i] = entry_array_[i];
        return size_;
    } else {
        return 0;
    }
}


File :: File() {
    path_ = NULL;
    name_ = NULL;
    date_ = NULL;
}


File :: File(char* path, char* name, char* date) {
    if(path) {
        path_ = new char[len2sz(strlen(path))];
        strcpy(path_, path);
    } else {
        path_ = NULL;
    }

    if(name) {
        name_ = new char[len2sz(strlen(name))];
        strcpy(name_, name);
    } else {
        name_ = NULL;
    }

    if(date) {
        date_ = new char[len2sz(strlen(date))];
        strcpy(date_, date);
    } else {
        date_ = NULL;
    }
}


File :: File(const File& f) {
    if(f.path_) {
        path_ = new char[len2sz(strlen(f.path_))];
        strcpy(path_, f.path_);
    } else {
        path_ = NULL;
    }

    if(f.name_) {
        name_ = new char[len2sz(strlen(f.name_))];
        strcpy(name_, f.name_);
    } else {
        name_ = NULL;
    }

    if(f.date_) {
        date_ = new char[len2sz(strlen(f.date_))];
        strcpy(date_, f.date_);
    } else {
        date_ = NULL;
    }
}


File :: ~File() {
    Erase();
}


void File :: Erase() {
    if(path_) {
        delete [] path_;
        path_ = NULL;
    }

    if(name_) {
        delete [] name_;
        name_ = NULL;
    }

    if(date_) {
        delete [] date_;
        date_ = NULL;
    }
}


File& File :: operator=(const File& f) {
    if(this == &f)
        return *this;

    Erase();

    if(f.path_) {
        path_ = new char[len2sz(strlen(f.path_))];
        strcpy(path_, f.path_);
    } else {
        path_ = NULL;
    }

    if(f.name_) {
        name_ = new char[len2sz(strlen(f.name_))];
        strcpy(name_, f.name_);
    } else {
        name_ = NULL;
    }

    if(f.date_) {
        date_ = new char[len2sz(strlen(f.date_))];
        strcpy(date_, f.date_);
    } else {
        date_ = NULL;
    }

    return *this;
}


bool File :: Read(FObj** item) {
    bool ret;
    
    in.open(path_);
    if(!in)
        return false;
    ret = (*item) -> Read(in);
    in.close();
    return ret;
}


bool File :: Write(FObj* item) {
    bool ret;

    out.open(path_);
    if(!out)
        return false;
    ret = item -> Write(out);
    out.close();
    return ret;
}


bool File :: WriteAppend(FObj* item) {
    bool ret;

    out.open(path_, ios::app);
    if(!out)
        return false;
    ret = item -> Write(out);
    out.close();
    return ret;
}


Directory :: Directory() {
    link_1_ = NULL;
    link_2_ = NULL;
    path_ = NULL;
    name_ = NULL;
}


Directory :: Directory(char* path, char* name) {
    if(path) {
        path_ = new char[len2sz(strlen(path))];
        strcpy(path_, path);
    } else {
        path_ = NULL;
    }

    if(name) {
        name_ = new char[len2sz(strlen(name))];
        strcpy(name_, name);
    } else {
        path_ = NULL;
    }

    link_1_ = NULL;
    link_2_ = NULL;
}


Directory :: Directory(const Directory& dir) {
    if(dir.path_) {
        path_ = new char[len2sz(strlen(dir.path_))];
        strcpy(path_, dir.path_);
    } else {
        path_ = NULL;
    }

    if(dir.name_) {
        name_ = new char[len2sz(strlen(dir.name_))];
        strcpy(name_, dir.name_);
    }

    link_1_ = NULL;
    link_2_ = NULL;
}


Directory :: ~Directory() {
    Erase();
}


void Directory :: Erase() {
    if(path_) {
        delete [] path_;
        path_ = NULL;
    }

    if(name_) {
        delete [] name_;
        name_ = NULL;
    }
}


Directory& Directory :: operator=(const Directory& dir) {
    if(this == &dir) 
        return *this;

    Erase();

    if(dir.path_) {
        path_ = new char[len2sz(strlen(dir.path_))];
        strcpy(path_, dir.path_);
    } else {
        path_ = NULL;
    }

    if(dir.name_) {
        name_ = new char[len2sz(strlen(dir.name_))];
        strcpy(name_, dir.name_);
    }

    link_1_ = NULL;
    link_2_ = NULL;  

    return *this;
}


void Directory :: set_link1(Directory* lk1) {
    link_1_ = lk1;
}


Directory* Directory :: get_link1() const {
    return link_1_;
}

        
void Directory :: set_link2(Directory* lk2) {
    link_2_ = lk2;
}
        
        
Directory* Directory :: get_link2() const {
    return link_2_;
}

       
char* Directory :: get_name() const {
    if(name_)
        return name_;
    return NULL;
}
        
      
char* Directory :: get_path() const {
    if(path_)
        return path_;
    return NULL;
}


//testing purpose function
void Directory :: Display() {
    cout << endl << path_ << endl;
    cout << name_ << endl;
}


FileManager :: FileManager() {
    member_report_ = NULL;
    provider_report_ = NULL;
    service_record_head_ = NULL;
    service_record_tail_ = NULL;
    current_working_directory_ = new char[len2sz(LEN_PATH_MAX)];
    current_working_directory_ = getcwd(current_working_directory_, LEN_PATH_MAX);
}


FileManager :: FileManager(const FileManager& f) {
    if(f.member_report_) {
        member_report_ = CopyReportDirectoryTree(member_report_, f.member_report_);
    } else {
        member_report_ = NULL;
    }

    if(f.provider_report_) {
        provider_report_ = CopyReportDirectoryTree(provider_report_, f.provider_report_);
    } else {
        provider_report_ = NULL;
    }

    if(f.service_record_head_ && f.service_record_tail_) {
        service_record_head_ = CopyServiceRecordList(service_record_head_, f.service_record_head_);
    } else {
        service_record_head_ = NULL;
        service_record_tail_ = NULL;
    }

    if(current_working_directory_) {
        current_working_directory_ = new char[len2sz(strlen(f.current_working_directory_))];
        strcpy(current_working_directory_, f.current_working_directory_);
    } else {
        current_working_directory_ = NULL;
    }
}


Directory* FileManager :: CopyServiceRecordList(Directory* dst, Directory* scr) {
    if(!scr) {
        dst = NULL;
        service_record_tail_ = NULL;
    } 

    Directory* after_curr_ptr;
    Directory* curr = new Directory(*scr);
    curr -> set_link2(dst);
    if(scr -> get_link1()) {
        after_curr_ptr = CopyServiceRecordList(curr, scr -> get_link1());
    } else {
        after_curr_ptr = NULL;
        service_record_tail_ = curr;
    }
    curr -> set_link1(after_curr_ptr);
    return curr;
}


Directory* FileManager :: CopyReportDirectoryTree(Directory* dst, Directory* scr) {
    if(!scr)
        return NULL;
    
    dst = new Directory(*scr);
    Directory* left_child_ptr = CopyReportDirectoryTree(NULL, scr -> get_link1());
    Directory* right_child_ptr = CopyReportDirectoryTree(NULL, scr -> get_link2());
    dst -> set_link1(left_child_ptr);
    dst -> set_link2(right_child_ptr);
    return dst;
}


FileManager :: ~FileManager() {
    Erase();
}


void FileManager :: Erase() {
    service_record_head_ = ClearServiceRecordList(service_record_head_);
    member_report_ = ClearReportDirectoryTree(member_report_);
    provider_report_ = ClearReportDirectoryTree(provider_report_);
    if(current_working_directory_) {
        delete [] current_working_directory_;
        current_working_directory_ = NULL;
    }    
}


Directory* FileManager :: ClearServiceRecordList(Directory* phead) {
    if(!phead) {
        service_record_tail_ = NULL;
        return NULL;
    }
        
    phead -> set_link2(NULL);
    Directory* after_head_ptr = ClearServiceRecordList(phead -> get_link1());
    phead -> set_link1(after_head_ptr);
    delete phead;
    phead = NULL;
    return NULL;
}


Directory* FileManager :: ClearReportDirectoryTree(Directory* proot) {
    if(!proot) 
        return NULL;
    
    Directory* left_child_ptr = ClearReportDirectoryTree(proot -> get_link1());
    Directory* right_child_ptr = ClearReportDirectoryTree(proot -> get_link2());
    proot -> set_link1(left_child_ptr);
    proot -> set_link2(right_child_ptr);
    delete proot;
    proot = NULL;
    return NULL;
}


FileManager& FileManager :: operator=(const FileManager& f) {
    if(this == &f)
        return *this;

    Erase();

    if(f.member_report_) {
        member_report_ = CopyReportDirectoryTree(member_report_, f.member_report_);
    } else {
        member_report_ = NULL;
    }

    if(f.provider_report_) {
        provider_report_ = CopyReportDirectoryTree(provider_report_, f.provider_report_);
    } else {
        provider_report_ = NULL;
    }

    if(f.service_record_head_ && f.service_record_tail_) {
        service_record_head_ = CopyServiceRecordList(service_record_head_, f.service_record_head_);
    } else {
        service_record_head_ = NULL;
        service_record_tail_ = NULL;
    }

    if(current_working_directory_) {
        current_working_directory_ = new char[len2sz(strlen(f.current_working_directory_))];
        strcpy(current_working_directory_, f.current_working_directory_);
    } else {
        current_working_directory_ = NULL;
    }

    return *this;
}


void FileManager :: InsertServiceDirectory(Directory& dir) {
    Directory* pnode = new Directory(dir);
    service_record_head_ = InsertServiceDirectory(service_record_head_, pnode);
}   


Directory* FileManager :: InsertServiceDirectory(Directory* phead, Directory* item) {
    if(!phead) {
        service_record_tail_ = item;
        return item;
    }

    if(Date :: dtcmp(phead -> get_name(), item -> get_name()) < 0) {
        item -> set_link1(phead);
        phead -> set_link2(item);
        return item;
    } else {
        if(phead == service_record_tail_) {
            phead -> set_link1(item);
            item -> set_link2(phead);
            service_record_tail_ = item;
            return phead;
        }
        Directory* after_head_ptr = InsertServiceDirectory(phead -> get_link1(), item);
        after_head_ptr -> set_link2(phead);
        phead -> set_link1(after_head_ptr);
        return phead;
    }
}


void FileManager :: InsertMemberReportDirectory(Directory& dir) {
    Directory* pnode = new Directory(dir);
    member_report_ = InsertReportDirectory(member_report_, pnode);
}


void FileManager :: InsertProviderReportDirectory(Directory& dir) {
    Directory* pnode = new Directory(dir);
    provider_report_ = InsertReportDirectory(provider_report_, pnode);
}


Directory* FileManager :: InsertReportDirectory(Directory* proot, Directory* item) {
    if(!proot)
        return item;
    
    if(strcmp(item -> get_name(), proot -> get_name()) < 0) {
        Directory* left_child_ptr = InsertReportDirectory(proot -> get_link1(), item);
        proot -> set_link1(left_child_ptr);
        return proot;
    } else {
        Directory* right_child_ptr = InsertReportDirectory(proot -> get_link2(), item);
        proot -> set_link2(right_child_ptr);
        return proot;
    }
}


//testing purpose function
void FileManager :: DisplayServiceDirectory() {
    DisplayServiceDirectory(service_record_head_);
}


//testing purpose function
void FileManager :: DisplayServiceDirectoryRev() {
    DisplayServiceDirectoryRev(service_record_tail_);
}


//testing purpose function
void FileManager :: DisplayServiceDirectory(Directory* phead) {
    if(!phead)
        return ;
    
    phead -> Display();
    DisplayServiceDirectory(phead -> get_link1());
}


//testing purpose function
void FileManager :: DisplayServiceDirectoryRev(Directory* ptail) {
    if(!ptail)
        return ;
    
    ptail -> Display();
    DisplayServiceDirectoryRev(ptail -> get_link2());
}


//testing purpose function
void FileManager :: DisplayMemberReportDirectory() {
    DisplayReportDirectory(member_report_);
}


//testing purpose function
void FileManager :: DisplayProviderReportDirectory() {
    DisplayReportDirectory(provider_report_);
}


//testing purpose function
void FileManager :: DisplayReportDirectory(Directory* proot) {
    if(!proot)
        return ;
    
    DisplayReportDirectory(proot -> get_link1());
    proot -> Display();
    DisplayReportDirectory(proot -> get_link2());
}


bool FileManager :: Initialize() {
    char* dir_service = new char[LEN_PATH_MAX];
    char* dir_member_report = new char[LEN_PATH_MAX];
    char* dir_provider_report = new char[LEN_PATH_MAX];

    if(!CheckDirectory()) {
        cerr << "Cannot initialize file system. Program halt." << endl;
        exit(1);
    }

    dir_service = getcwd(dir_service, 300);
    dir_member_report = getcwd(dir_member_report, 300);
    dir_provider_report = getcwd(dir_provider_report, 300);

    strcat(dir_service, "/service_record");
    strcat(dir_member_report, "/report/member");
    strcat(dir_provider_report, "/report/provider");

    int count = TraverseDirectory(dir_service, TRAVERSE_SERVICE);
    int count1 = TraverseDirectory(dir_member_report, TRAVERSE_MEMBER_REPORT);
    int count2 = TraverseDirectory(dir_provider_report, TRAVERSE_PROVIDER_REPORT);

    //testing purpose 
    cout << "the num. of service directories:  " << count << endl;
    cout << "the num. of member report directories:  " << count1 << endl;
    cout << "the num. of provider report directories:  " << count2 << endl;

    delete [] dir_service;
    delete [] dir_member_report;
    delete [] dir_provider_report;

    return true;
}


int FileManager :: TraverseDirectory(const char* pathname, int mode) {
    struct stat statbuf;
    dirent* dir;
    DIR* d;
    int ret;
    int arglen;
    char* subdir;

    if(!pathname || lstat(pathname, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0)
        return -1;

    if((d = opendir(pathname)) == NULL) 
        return -1; 

    ret = 0;
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
            strcmp(dir -> d_name, ".DS_Store") == 0)
            continue;
        if(dir -> d_type == DT_DIR) {
            subdir = new char[LEN_PATH_MAX];
            strcpy(subdir, pathname);
            strcat(subdir, "/");
            strcat(subdir, dir -> d_name);
            Directory sd(subdir, dir -> d_name);

            if(mode == TRAVERSE_SERVICE)
                InsertServiceDirectory(sd);
            else if(mode == TRAVERSE_MEMBER_REPORT)
                InsertMemberReportDirectory(sd);
            else if(mode == TRAVERSE_PROVIDER_REPORT)
                InsertProviderReportDirectory(sd);
            
            delete [] subdir;
            ++ret;
        } 
    }
    closedir(d);

    return ret;
}


int FileManager :: Write(const FObj* file) {
    if(!file)
        return -1;
    
    const FObjService* f_service = dynamic_cast<const FObjService*>(file);
    if(f_service) {
        if(WriteService(f_service) == 0)
            return 0;
    } else {
        const FObjMemberReport* m_report = dynamic_cast<const FObjMemberReport*>(file);
        if(m_report) {
            if(WriteMemberReport(m_report) == 0)
                return 0;
        } else {
            const FObjProviderReport* p_report = dynamic_cast<const FObjProviderReport*>(file);
            if(p_report) {
                if(WriteProviderReport(p_report) == 0)
                    return 0;
            } else {
                const FObjManagerReport* m_report = dynamic_cast<const FObjManagerReport*>(file);
                if(m_report) {
                    if(WriteManagerReport(m_report) == 0)
                        return 0;
                } else {
                    const CdcMemberEntries* m_entries = dynamic_cast<const CdcMemberEntries*>(file);
                    if(m_entries) {
                        if(WriteCdcMemberEntries(m_entries) == 0)
                            return 0;
                    } else {
                        const CdcProviderEntries* p_entries = dynamic_cast<const CdcProviderEntries*>(file);
                        if(p_entries) {
                            if(WriteCdcProviderEntries(p_entries) == 0)
                                return 0;
                        } else {
                            const HashNode* pd_entries = dynamic_cast<const HashNode*>(file);
                            if(pd_entries) {
                                if(WriteProviderDirectoryEntries(pd_entries) == 0)
                                    return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 1;
}


int FileManager :: WriteService(const FObjService* service) {
    char dt[len2sz(LEN_DATE)];
    char path[LEN_PATH_MAX]; 
    
    if(!service)
        return 0;

    if(!service -> GetComputerReceivedDate(dt))
        return 0;

    strcpy(path, current_working_directory_);
    strcat(path, "/service_record");
    strcat(path, "/");
    strcat(path, dt);

    Directory* d = new Directory(path, dt);
    service_record_head_ = WriteService(service_record_head_, d, service);
    delete d;

    return 1;
}
    

Directory* FileManager :: WriteService(Directory* phead, Directory* item, const FObjService* service) {
    char filepath[LEN_PATH_MAX];
    char filename[len2sz(LEN_SERVICE_FILE)];
    ofstream out;

    if(!item || !service) {
        return phead;
    }

    if(!phead) {
        if(mkdir(item -> get_path(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
            return phead;
        if(!service -> GenerateFileName(filename))
            return phead;
        
        strcpy(filepath, item -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);
        
        out.open(filepath);
        service -> Write(out);
        out.close();

        service_record_tail_ = item;
        return item;
    }

    if(Date :: dtcmp(item -> get_name(), phead -> get_name()) > 0) {
        if(mkdir(item -> get_path(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
            return phead;
        if(!service -> GenerateFileName(filename))
            return phead;
        
        strcpy(filepath, item -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);
        
        out.open(filepath);
        service -> Write(out);
        out.close(); 
        
        item -> set_link1(phead);
        phead -> set_link2(item);
        return item;
    } else if(Date :: dtcmp(item -> get_name(), phead -> get_name()) == 0) {
        if(!service -> GenerateFileName(filename))
            return phead;
       
        strcpy(filepath, phead -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);
        
        out.open(filepath);
        service -> Write(out);
        out.close();
        return phead;
    } else {
        Directory* after_head_ptr = WriteService(phead -> get_link1(), item, service);
        after_head_ptr -> set_link2(phead);
        phead -> set_link1(after_head_ptr);
        return phead;
    }
}


int FileManager :: WriteMemberReport(const FObjMemberReport* report) {
    char path[LEN_PATH_MAX];
    char num[len2sz(LEN_MEMBER_NUM)];

    if(!report)
        return 0;

    if(!report -> GetMemberNumber(num))
        return 0;

    strcpy(path, current_working_directory_);
    strcat(path, "/report/member");
    strcat(path, "/");
    strcat(path, num); 

    Directory d(path, num);
    member_report_ = WriteMemberReport(member_report_, &d, report);
    
    return 1;
}


Directory* FileManager :: WriteMemberReport(Directory* proot, Directory* item, const FObjMemberReport* report) {
    char filepath[LEN_PATH_MAX];
    char filename[len2sz(LEN_SERVICE_FILE)];
    ofstream out;

    if(!item || !report)
        return proot;

    if(!proot) {
        if(mkdir(item -> get_path(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
            return NULL;
        if(!report -> GenerateFileName(filename))
            return NULL;

        strcpy(filepath, item -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);

        Directory* pnode = new Directory(*item);

        cout << "Write Member report:  " << filepath << endl;

        out.open(filepath);
        report -> Write(out);
        out.close();

        return pnode;
    }

    if(strcmp(item -> get_name(), proot -> get_name()) < 0) {
        Directory* left_child_ptr = WriteMemberReport(proot -> get_link1(), item, report);
        proot -> set_link1(left_child_ptr);
        return proot;
    } else if(strcmp(item -> get_name(), proot -> get_name()) > 0) {
        Directory* right_child_ptr = WriteMemberReport(proot -> get_link2(), item, report);
        proot -> set_link2(right_child_ptr);
        return proot;
    } else {
        if(!report -> GenerateFileName(filename))
            return proot;

        strcpy(filepath, item -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);

        cout << "Member report has saved to:  " << filepath << endl;

        out.open(filepath);
        report -> Write(out);
        out.close();
        return proot;
    }
}


int FileManager :: WriteProviderReport(const FObjProviderReport* report) {
    char path[LEN_PATH_MAX];
    char num[len2sz(LEN_PROVIDER_NUM)];

    if(!report)
        return 0;

    if(!report -> GetProviderNumber(num))
        return 0;

    strcpy(path, current_working_directory_);
    strcat(path, "/report/provider");
    strcat(path, "/");
    strcat(path, num); 

    FObjProviderReportSummary tmp = *report;
    FObjEFT* eft = new FObjEFT(tmp);
    WriteEft(eft);

    Directory d(path, num);
    provider_report_ = WriteProviderReport(provider_report_, &d, report);
    
    delete eft;

    return 1;
}


Directory* FileManager :: WriteProviderReport(Directory* proot, Directory* item, const FObjProviderReport* report) {
    char filepath[LEN_PATH_MAX];
    char filename[200];    // temp. length
    ofstream out;

    if(!item || !report)
        return proot;

    if(!proot) {
        if(mkdir(item -> get_path(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
            return NULL;
        if(!report -> GenerateFileName(filename))
            return NULL;

        Directory* pnode = new Directory(*item);

        strcpy(filepath, item -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);

        out.open(filepath);
        report -> Write(out);
        out.close();

        cout << "Provider report has saved to:  " << filepath << endl;
        return pnode;
    }

    if(strcmp(item -> get_name(), proot -> get_name()) < 0) {
        Directory* left_child_ptr = WriteProviderReport(proot -> get_link1(), item, report);
        proot -> set_link1(left_child_ptr);
        return proot;
    } else if(strcmp(item -> get_name(), proot -> get_name()) > 0) {
        Directory* right_child_ptr = WriteProviderReport(proot -> get_link2(), item, report);
        proot -> set_link2(right_child_ptr);
        return proot;
    } else {
        if(!report -> GenerateFileName(filename))
            return proot;

        strcpy(filepath, item -> get_path());
        strcat(filepath, "/");
        strcat(filepath, filename);

        cout << "Provider report has saved to:  " << filepath << endl;

        out.open(filepath);
        report -> Write(out);
        out.close();
        return proot;
    }
}


int FileManager :: WriteEft(const FObjEFT* eft) {
    int ret;
    char filepath[LEN_PATH_MAX];
    char filename[len2sz(LEN_EFT_FILE)];
    ofstream out;

    if(!eft)
        return 0;
    if(!eft -> GenerateFileName(filename))
        return 0;

    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/eft_record/");
    strcat(filepath, filename);

    out.open(filepath);
    ret = eft -> Write(out);
    out.close();
    
    return ret;
}


int FileManager :: WriteManagerReport(const FObjManagerReport* report) {
    int ret;
    char filepath[LEN_PATH_MAX];
    char filename[len2sz(LEN_MANAGER_FILE)];
    ofstream out;

    if(!report)
        return 0;
    if(!report -> GenerateFileName(filename))
        return 0;

    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/report/manager/");
    strcat(filepath, filename);

    cout << "Manager report has saved to:  " << filepath << endl;

    out.open(filepath);
    ret = report -> Write(out);
    out.close();
    
    return ret;
}


int FileManager :: WriteCdcMemberEntries(const CdcMemberEntries* entries) {
    char filename[] = "member_entries.txt";
    char filepath[LEN_PATH_MAX];
    int ret;
    ofstream out;

    if(!entries)
        return 0;
    
    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/cdc_record/");
    strcat(filepath, filename);

    out.open(filepath);
    ret = entries -> Write(out);
    out.close();

    return ret;
}


int FileManager :: WriteCdcProviderEntries(const CdcProviderEntries* entries) {
    char filename[] = "provider_entires.txt";
    char filepath[LEN_PATH_MAX];
    int ret;
    ofstream out;

    if(!entries)
        return 0;
    
    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/cdc_record/");
    strcat(filepath, filename);

    out.open(filepath);
    ret = entries -> Write(out);
    out.close();

    return ret;
}


int FileManager :: WriteProviderDirectoryEntries(const HashNode* pd_entries) {
    char filepath[LEN_PATH_MAX];
    ofstream out;
    int ret;

    if(!pd_entries -> get_time())
        return 0;

    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/provider_directory/");
    strcat(filepath, pd_entries -> get_time());
    strcat(filepath, "_provider_directory.txt");

    out.open(filepath);
    ret = pd_entries -> Write(out);
    out.close();

    cout << "Provider Directory entries have saved to:  " << filepath << endl; 

    return ret;
}


int FileManager :: Read(HashNode* receiver) {
    char dirpath[LEN_PATH_MAX];
    char most_recently[len2sz(LEN_TIME)];
    char tm[len2sz(LEN_TIME)];
    char filepath[LEN_PATH_MAX];
    dirent* dir;
    DIR* d;
    struct stat statbuf;
    ifstream in;
    int ret;
    bool found = false;

    if(!current_working_directory_)
        return false;
    
    strcpy(dirpath, current_working_directory_);
    strcat(dirpath, "/provider_directory");
    
    if(lstat(dirpath, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0)
        return 0;
    if((d = opendir(dirpath)) == NULL) 
        return 0; 

    strcpy(most_recently, "00_00_0000_00_00_00"); 
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
                    strcmp(dir -> d_name, ".DS_Store") == 0)
            continue;
        if(dir -> d_type == DT_REG) {
            if(!ParseProviderDirectoryTime(tm, dir -> d_name))
                return 0;
            if(Time :: tmcmp(tm, most_recently) > 0) {
                found = true;
                strcpy(most_recently, tm);
            }
        }
    }
    
    if(found) {
        strcpy(filepath, current_working_directory_);
        strcat(filepath, "/provider_directory/");
        strcat(filepath, most_recently);
        strcat(filepath, "_provider_directory.txt");
        in.open(filepath);
        receiver -> set_time(most_recently);
        ret = receiver -> Read(in);
        in.close();
    }

    closedir(d);

    return found;
}


int FileManager :: Read(HashNode* receiver, const char* curr_tm) {
    char dirpath[LEN_PATH_MAX];
    char most_recently[len2sz(LEN_TIME)];
    char filepath[LEN_PATH_MAX];
    char tm[len2sz(LEN_TIME)];
    dirent* dir;
    DIR* d;
    struct stat statbuf;
    bool found = false;
    ifstream in;
    int ret;

    if(!current_working_directory_)
        return false;
    
    strcpy(dirpath, current_working_directory_);
    strcat(dirpath, "/provider_directory");
    
    if(lstat(dirpath, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0)
        return 0;
    if((d = opendir(dirpath)) == NULL) 
        return 0; 

    strcpy(most_recently, "00_00_0000_00_00_00"); 
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
                    strcmp(dir -> d_name, ".DS_Store") == 0)
            continue;
        if(dir -> d_type == DT_REG) {
            if(!ParseProviderDirectoryTime(tm, dir -> d_name))
                return 0;
            if(Time :: tmcmp(tm, most_recently) > 0 && Time :: tmcmp(tm, curr_tm) <= 0) {
                strcpy(most_recently, tm);
                found = true;
            }
        }
    }
    if(found) {
        strcpy(filepath, current_working_directory_);
        strcat(filepath, "/provider_directory/");
        strcat(filepath, most_recently);
        strcat(filepath, "_provider_directory.txt");
        in.open(filepath);
        receiver -> set_time(most_recently);
        ret = receiver -> Read(in);
        in.close();
    }
    
    closedir(d);

    if(found)
        return ret;
    return found;
}


int FileManager :: Read(class HashNode* receiver, char* t_min, char* t_max) {
    char filepath[LEN_PATH_MAX];
    char dirpath[LEN_PATH_MAX];
    char leftmost[len2sz(LEN_TIME)];
    char tm[len2sz(LEN_TIME)];
    dirent* dir;
    DIR* d;
    struct stat statbuf;
    int count = 0;
    ifstream in;

    if(!current_working_directory_)
        return 0;
    
    strcpy(dirpath, current_working_directory_);
    strcat(dirpath, "/provider_directory");
    
    if(lstat(dirpath, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0) {
        cerr << "Cannot find the directory: " << dirpath << endl;
        return 0;
    }
    if((d = opendir(dirpath)) == NULL) 
        return 0; 
    
    strcpy(leftmost, "00_00_0000_00_00_00");
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
                    strcmp(dir -> d_name, ".DS_Store") == 0)
            continue;
        if(dir -> d_type == DT_REG) {
            if(!ParseProviderDirectoryTime(tm, dir -> d_name))
                return 0;
            if(Time :: tmcmp(tm, t_min) > 0 && Time :: tmcmp(tm, t_max) <= 0) {
                strcpy(filepath, dirpath);
                strcat(filepath, "/");
                strcat(filepath, dir -> d_name);
                in.open(filepath);
                receiver[count].set_time(tm);
                count += receiver[count].Read(in);
                in.close();
            } else {
                if(Time :: tmcmp(leftmost, tm) < 0 && Time :: tmcmp(tm, t_max) <= 0) {
                    strcpy(leftmost, tm);
                }
            }
        }
    }
    
    if(strcmp(leftmost, "00_00_0000_00_00_00") != 0) {
        strcpy(filepath, dirpath);
        strcat(filepath, "/");
        strcat(filepath, leftmost);
        strcat(filepath, "_provider_directory.txt");
        in.open(filepath);
        receiver[count].set_time(leftmost);
        count += receiver[count].Read(in);
        in.close(); 
    }

    closedir(d);
     
    return count;
}


int FileManager :: Read(CdcMemberEntries* receiver) {
    char filepath[LEN_PATH_MAX];
    ifstream in;
    int ret;
    
    if(!receiver)   
        return -1;

    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/cdc_record/member_entries.txt");

    in.open(filepath);
    ret = receiver -> Read(in);
    in.close();
    
    return ret;
}


int FileManager :: Read(CdcProviderEntries* receiver) {
    char filepath[LEN_PATH_MAX];
    ifstream in;
    int ret;

    if(!receiver)
        return -1;
    
    strcpy(filepath, current_working_directory_);
    strcat(filepath, "/cdc_record/provider_entries.txt");

    in.open(filepath);
    ret = receiver -> Read(in);
    in.close();

    return ret;
}


int FileManager :: Read(FObjService* receiver, char* d_min, char* d_max) {
    Directory* curr;
    dirent* dir;
    DIR* d;
    struct stat statbuf;
    char* pathname;
    char filepath[LEN_PATH_MAX];
    ifstream in;
    int ret;
    
    if(Date :: dtcmp(d_max, service_record_tail_ -> get_name()) < 0)
        return 0;
    if(Date :: dtcmp(d_min, service_record_head_ -> get_name()) > 0)
        return 0;

    ret = 0;
    curr = service_record_head_;
    while(curr) {
        pathname = curr -> get_path();
        if(Date :: dtcmp(curr -> get_name(), d_max) <= 0 && 
            Date :: dtcmp(curr -> get_name(), d_min) >= 0) {
            if(!pathname || lstat(pathname, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0)
                return 0;
            if((d = opendir(pathname)) == NULL) 
                return 0; 
            while((dir = readdir(d)) != NULL) {
                if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
                    strcmp(dir -> d_name, ".DS_Store") == 0)
                    continue;
                if(dir -> d_type == DT_REG) {
                    strcpy(filepath, pathname);
                    strcat(filepath, "/");
                    strcat(filepath, dir -> d_name);
                    in.open(filepath);
                    ret += receiver[ret].Read(in);
                    in.close();
                }
            }
            curr = curr -> get_link1(); 
        } else {
            curr = NULL;
        }
    }
    return ret;
}

 
int FileManager :: Read(FObjProviderReportSummary* receiver, char* d_min, char* d_max) {
    int ret = 0;
    int count;

    if(!provider_report_)
        return 0;
    Read(provider_report_, receiver, ret, d_min, d_max);
    return ret;
}


void FileManager :: Read(Directory* proot, FObjProviderReportSummary* receiver, int& index, char* d_min, char* d_max) {
    char filepath[LEN_PATH_MAX];
    char dt[len2sz(LEN_DATE)];
    char* pathname;
    dirent* dir;
    DIR* d;
    struct stat statbuf; 
    ifstream in;

    if(!proot)
        return ;
    
    pathname = proot -> get_path();
    if(!pathname || lstat(pathname, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0)
        return ;
    if((d = opendir(pathname)) == NULL) 
        return ; 
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
            strcmp(dir -> d_name, ".DS_Store") == 0)
                continue;
        if(dir -> d_type == DT_REG) {
            if(!ParseProviderReportDate(dt, dir -> d_name))
                return ;
            if(Date :: dtcmp(dt, d_max) <= 0 && Date :: dtcmp(dt, d_min) >= 0) {
                strcpy(filepath, pathname);
                strcat(filepath, "/");
                strcat(filepath, dir -> d_name);
                in.open(filepath);
                index += receiver[index].Read(in);
                in.close();
            }
        }
    }    

    Read(proot -> get_link1(), receiver, index, d_min, d_max);
    Read(proot -> get_link2(), receiver, index, d_min, d_max);
}


bool FileManager :: ParseProviderReportDate(char* receiver, const char* filename) {
    int len;
    int count = 9;
    char tmp[len2sz(LEN_DATE)];

    if(!filename)
        return false;

    if((len = strlen(filename)) < 15)
        return false;
    for(int i = len - 5; i > len - 15; --i) {
        tmp[count--] = filename[i];
    }
    if(count == -1) {
        tmp[LEN_DATE] = '\0';
        strcpy(receiver, tmp);
        return true;
    }
    return false;
}


int FileManager :: Read(FObjEFT* receiver, char* d_min, char* d_max) {
    char filepath[LEN_PATH_MAX];
    char dt[len2sz(LEN_DATE)];
    char pathname[LEN_PATH_MAX];
    dirent* dir;
    DIR* d;
    struct stat statbuf; 
    ifstream in;
    int ret = 0;

    strcpy(pathname, current_working_directory_);
    strcat(pathname, "/eft_record");
    if(lstat(pathname, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0)
        return 0;
    if((d = opendir(pathname)) == NULL) 
        return 0;
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
            strcmp(dir -> d_name, ".DS_Store") == 0)
                continue;
        if(dir -> d_type == DT_REG) {
            if(!ParseEftDate(dt, dir -> d_name))
                return 0;
            if(Date :: dtcmp(dt, d_min) >= 0 && Date :: dtcmp(dt, d_max) <= 0) {
                strcpy(filepath, pathname);
                strcat(filepath, "/");
                strcat(filepath, dir -> d_name);
                in.open(filepath);
                ret += receiver[ret].Read(in);
                in.close();
            }
        }
    }    
    return ret;
}


bool FileManager :: ParseEftDate(char* receiver, const char* filename) {
    char dt[len2sz(LEN_DATE)];
    
    if(!filename || strlen(filename) != LEN_EFT_FILE)
        return false;

    strncpy(dt, filename, LEN_DATE);
    strcpy(receiver, dt);
    return true;
}


bool FileManager :: ParseProviderDirectoryTime(char* receiver, const char* filename) const {
    char tm[len2sz(LEN_TIME)];

    if(!filename || strlen(filename) != LEN_PD_FILE)    
        return false;
    
    for(int i = 0; i < LEN_TIME; ++i)
        receiver[i] = filename[i];
    receiver[LEN_TIME] = '\0';
    return true;
}


bool FileManager :: CheckDirectory() {
    const char* file_classes[] = {
    "service_record",
    "report",
    "cdc_record",
    "eft_record",
    "provider_directory"
    };

    const char* report_classes[] = {
    "member",
    "provider",
    "manager",     
    };

    bool folder_good[5] = {
        false,
        false,
        false,
        false,
        false
    };

    bool report_folder_good[3] = {
        false,
        false,
        false
    };

    dirent* dir;
    DIR* d;
    struct stat statbuf;
    int index = 0;
    char reportpath[LEN_PATH_MAX];
    bool folder_ok = true;

    cout << "Directories Detection" << endl;
    cout << "------------------------------------------------------------" << endl;

    if(!current_working_directory_ || lstat(current_working_directory_, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0) {
        cerr << current_working_directory_ << " is invalid." << endl;
        exit(0);
    }
    if((d = opendir(current_working_directory_)) == NULL) {
        cerr << "Cannot open " << current_working_directory_ << endl;
        exit(0);
    }
    while((dir = readdir(d)) != NULL) {
        if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
                    strcmp(dir -> d_name, ".DS_Store") == 0)
            continue;
        if(dir -> d_type == DT_DIR) {
            if(strcmp(dir -> d_name, file_classes[0]) == 0) {
                cout << current_working_directory_ << "/" << dir -> d_name << "   OK" << endl;
                folder_good[0] = true;
            }
            if(strcmp(dir -> d_name, file_classes[1]) == 0) {
                cout << current_working_directory_ << "/" << dir -> d_name << "   OK" << endl;
                folder_good[1] = true;
            }
            if(strcmp(dir -> d_name, file_classes[2]) == 0) {
                cout << current_working_directory_ << "/" << dir -> d_name << "   OK" << endl;
                folder_good[2] = true;
            }
            if(strcmp(dir -> d_name, file_classes[3]) == 0) {
                cout << current_working_directory_ << "/" << dir -> d_name << "   OK" << endl;
                folder_good[3] = true;
            }
            if(strcmp(dir -> d_name, file_classes[4]) == 0) {
                cout << current_working_directory_ << "/" << dir -> d_name << "   OK" << endl;
                folder_good[4] = true;
            }
        }
    }

    closedir(d);

    for(int i = 0; i < 5; ++i)
        if(!folder_good[i]) {
            cout << "Cannot find the path: " << current_working_directory_ << "/" << file_classes[i] << endl;
            folder_ok = false;
        }
            
    
    if(folder_good[1]) {
        strcpy(reportpath, current_working_directory_);
        strcat(reportpath, "/report/");
        if(lstat(reportpath, &statbuf) < 0 || S_ISDIR(statbuf.st_mode) == 0) {
            return false;
        }
        if((d = opendir(reportpath)) == NULL) {
            return false;
        } 
        while((dir = readdir(d)) != NULL) {
            if(strcmp(dir -> d_name, ".") == 0 || strcmp(dir -> d_name, "..") == 0 || 
                        strcmp(dir -> d_name, ".DS_Store") == 0)
                continue;
            if(dir -> d_type == DT_DIR) {
                if(strcmp(dir -> d_name, report_classes[0]) == 0) {
                    cout << reportpath << dir -> d_name << "   OK" << endl;
                    report_folder_good[0] = true;
                }
                if(strcmp(dir -> d_name, report_classes[1]) == 0) {
                    cout << reportpath << dir -> d_name << "   OK" << endl; 
                    report_folder_good[1] = true;
                }
                if(strcmp(dir -> d_name, report_classes[2]) == 0) {
                    cout << reportpath << dir -> d_name << "   OK" << endl;
                    report_folder_good[2] = true;
                }
            }
        }

        closedir(d);

        for(int i = 0; i < 3; ++i)
            if(!report_folder_good[i]) {
                cout << "Cannot find the path: " << reportpath << file_classes[i] << endl;
                folder_ok = false; 
            }
    }

    if(folder_ok) {
        cout << "------------------------------------------------------------" << endl;
        cout << "Result: directories are normal. " << endl; 
    } else {
        cout << "------------------------------------------------------------" << endl;
        cout << "Result: directories need to be initialized" << endl;
        InitProcess(folder_good, report_folder_good);
    }

    return true;
}



void FileManager :: InitProcess(bool folder[], bool report_folder[]) {
    const char* file_classes[] = {
    "/service_record",
    "/report",
    "/cdc_record",
    "/eft_record",
    "/provider_directory"
    };

    const char* report_classes[] = {
    "/member",
    "/provider",
    "/manager",     
    };

    char* path;
    char* new_dir;
    char* new_rpt_dir;
    size_t sz = 256;
    struct stat s;
    DIR* dir;
    dirent* ret;
    int d_ret;


    cout << "System Initialization process..." << endl << endl;

    path = new char[sz];

    path = getcwd(path, sz);

    lstat(path, &s);
    if(!S_ISDIR(s.st_mode)) {
        cout << "invalid" << endl;
        exit(1);
    } 

    for(int i = DIR_service; i <= DIR_pd; ++i) {
        if(!folder[i]) {
            new_dir = new char[strlen(path) + strlen(file_classes[i]) + 2];
            strcpy(new_dir, path);
            strcat(new_dir, file_classes[i]);
            cout << "Create Directory:  " << new_dir << endl;
            d_ret = mkdir(new_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            if(d_ret == -1) {
                cerr << "Make directory error!" << endl;
                exit(1); 
            }
            delete [] new_dir;
        }
    }

    for(int j = DIR_member_rpt; j <= DIR_manager_rpt; ++j) {
        if(!report_folder[j]) {
            new_rpt_dir = new char[strlen(path) + strlen(file_classes[DIR_report]) + strlen(report_classes[j]) + 1];
            strcpy(new_rpt_dir, path);
            strcat(new_rpt_dir, file_classes[DIR_report]);
            strcat(new_rpt_dir, report_classes[j]);
            cout << "Create Directory:  " << new_rpt_dir << endl;
            d_ret = mkdir(new_rpt_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            if(d_ret == -1) {
                cerr << "Make directory error!" << endl;
                exit(1); 
            }        
            delete [] new_rpt_dir;
        }
    }

    cout << endl << "System initializaion done..." << endl;

    delete [] path;
}