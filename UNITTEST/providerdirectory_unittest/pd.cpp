#include "pd.h"

ProviderDirectoryEntry :: ProviderDirectoryEntry() {
    service_code_ = NULL;
    service_name_ = NULL;
    service_fee_ = 0.0;
}


ProviderDirectoryEntry :: ProviderDirectoryEntry(char* s_code, char* s_name, float fee) {
    if(s_code) {
        service_code_ = new char[len2sz(strlen(s_code))];
        strcpy(service_code_, s_code);
    } else {
        service_code_ = NULL;
    }

    if(s_name) {
        service_name_ = new char[len2sz(strlen(s_name))];
        strcpy(service_name_, s_name);
    } else {
        service_name_ = NULL;
    }

    service_fee_ = fee;
}


ProviderDirectoryEntry :: ProviderDirectoryEntry(const ProviderDirectoryEntry& entry) {
    if(entry.service_code_) {
        service_code_ = new char[len2sz(strlen(entry.service_code_))];
        strcpy(service_code_, entry.service_code_);
    } else {
        service_code_ = NULL;
    }

    if(entry.service_name_) {
        service_name_ = new char[len2sz(strlen(entry.service_name_))];
        strcpy(service_name_, entry.service_name_);
    } else {
        service_name_ = NULL;
    }

    service_fee_ = entry.service_fee_;
}


ProviderDirectoryEntry :: ~ProviderDirectoryEntry() {
    Erase();
}


void ProviderDirectoryEntry :: Erase() {
    if(service_code_) {
        delete [] service_code_;
        service_code_ = NULL;
    } 
    
    if(service_name_) {
        delete [] service_name_;
        service_name_ = NULL;
    }
}


ProviderDirectoryEntry& ProviderDirectoryEntry :: operator=(const ProviderDirectoryEntry& entry) {
    if(this == &entry)
        return *this;

    Erase();

    if(entry.service_code_) {
        service_code_ = new char[len2sz(strlen(entry.service_code_))];
        strcpy(service_code_, entry.service_code_);
    } else {
        service_code_ = NULL;
    }

    if(entry.service_name_) {
        service_name_ = new char[len2sz(strlen(entry.service_name_))];
        strcpy(service_name_, entry.service_name_);
    } else {
        service_name_ = NULL;
    }

    service_fee_ = entry.service_fee_;

    return *this; 
}


int ProviderDirectoryEntry :: CompareServiceName(ProviderDirectoryEntry& entry) const {
    return strcmp(service_name_, entry.service_name_);
}


int ProviderDirectoryEntry :: CompareServiceName(const char* string) const {
    return strcmp(string, service_name_);
}


char* ProviderDirectoryEntry :: get_service_code() const {
    return service_code_;
}


char* ProviderDirectoryEntry :: get_service_name() const {
    return service_name_;
}


float ProviderDirectoryEntry :: get_fee() const {
    return service_fee_;
}


PdEntry :: PdEntry() {
    next_ = NULL;
}
        

PdEntry :: PdEntry(char* s_code, char* s_name, float s_fee) 
    : ProviderDirectoryEntry(s_code, s_name, s_fee) {
    next_ = NULL;
}


PdEntry :: PdEntry(const PdEntry& entry) 
    : ProviderDirectoryEntry(entry), next_(NULL) 
{
}

        
PdEntry* PdEntry :: get_next() const {
    return next_;
}
        
      
void PdEntry :: set_next(PdEntry* next) {
    next_ = next;
}




HashNode :: HashNode() {
    size_ = DEFAULT_PD_MAX;
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        table_[i] = NULL;
    time_ = NULL;
    next_ = NULL;
}
        
        
HashNode :: HashNode(char* tm) {
    if(tm) {
        time_ = new char[len2sz(strlen(tm))];
        strcpy(time_, tm);
    } else {
        time_ = NULL;
    }
    
    size_ = DEFAULT_PD_MAX;
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        table_[i] = NULL; 

    next_ = NULL;
}
        
        
HashNode :: HashNode(int sz, char* tm) {
    if(tm) {
        time_ = new char[len2sz(strlen(tm))];
        strcpy(time_, tm);
    } else {
        time_ = NULL;
    }

    size_ = GetPrime(sz);
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        table_[i] = NULL; 

    next_ = NULL;
}
        
        
HashNode :: HashNode(const HashNode& node) {
    if(node.time_) {
        time_ = new char[len2sz(strlen(node.time_))];
        strcpy(time_, node.time_);
    } else {
        time_ = NULL;
    }

    size_ = node.size_;
    table_ = new PdEntry*[size_];
    for(int i = 0; i < size_; ++i)
        if(node.table_[i])
            table_[i] = CopyList(table_[i], node.table_[i]);
        else 
            table_[i] = NULL;
    
    next_ = NULL;
}


PdEntry* HashNode :: CopyList(PdEntry* dst, PdEntry* scr) {
    if(!scr)
        return NULL;
    
    dst = new PdEntry(*scr);
    PdEntry* after_head_ptr = CopyList(NULL, scr -> get_next());
    dst -> set_next(after_head_ptr);
    return dst;
}


HashNode :: ~HashNode() {
    if(time_) {
        delete [] time_;
        time_ = NULL;
    }

    if(table_ && size_) {
        for(int i = 0; i < size_; ++i) 
            table_[i] = ClearList(table_[i]);
        delete [] table_;
    }
}


PdEntry* HashNode :: ClearList(PdEntry* phead) {
    if(!phead)
        return NULL;
    
    PdEntry* after_head_ptr = ClearList(phead -> get_next());
    phead -> set_next(after_head_ptr);
    delete phead;
    phead = NULL;
    return NULL;
}


void HashNode :: set_next(HashNode* next) {
    next_ = next;
}
        
        
HashNode* HashNode :: get_next() const {
    return next_;
}


float HashNode :: SearchFee(const char* code) const {
    int index = -1;
    PdEntry* curr = NULL;
    bool found = false;
    float ret = -1;

    if(!code) 
        return -1;
    
        
    index = Hashing(code);
    if(index >= 0 && index < size_) {
        curr = table_[index];
        while(curr && !found) {
            if(strcmp(code, curr -> get_service_code()) == 0) {
                found = true;
                ret = curr -> get_fee();
            } else {
                curr = curr -> get_next();
            }
        }
    }

    return ret;
}
        
        
bool HashNode :: SearchServiceName(const char* code, char* receiver) const {
    int index = -1;
    PdEntry* curr = NULL;
    bool found = false;

    if(!code)
        return false;
    
    index = Hashing(code);
    if(index >= 0 && index < size_) {
        curr = table_[index];
        while(curr && !found) {
            if(strcmp(code, curr -> get_service_code()) == 0) {
                found = true;
                strcpy(receiver, curr -> get_service_name());
            } else {
                curr = curr -> get_next();
            }
        }
    }

    return found;
}
 
        
int HashNode :: Hashing(const char* code) const {
    if(!code || strlen(code) != LEN_SERVICE_CODE || size_ == 0) {
        return -1;
    }
        
    int n1 = ch2int(code[0]);
    int n2 = ch2int(code[1]);
    int n3 = ch2int(code[2]);
    int n4 = ch2int(code[3]);
    int n5 = ch2int(code[4]);
    int n6 = ch2int(code[5]);

    int val = n1 * 100000 + n2 * 10000 + n3 * 1000 + n4 * 100 + n5 * 10 + n6;
    return val % size_;  
}


PdBinaryEntry :: PdBinaryEntry() {
    entry_ptr_ = NULL;
    left_ = NULL;
    right_ = NULL;
}


PdBinaryEntry :: PdBinaryEntry(PdEntry* entry) {
    entry_ptr_ = entry;
    left_ = NULL;
    right_ = NULL;
}



int PdBinaryEntry :: CompareServiceName(const char* name) const {
    return strcmp(name, entry_ptr_ -> get_service_name());
}
      

int PdBinaryEntry :: CompareServiceName(const PdBinaryEntry* node) const {
    return strcmp(node -> entry_ptr_ -> get_service_name(), entry_ptr_ -> get_service_name());
}


void PdBinaryEntry :: set_entry(PdEntry* entry) {
    entry_ptr_ = entry;
}


PdEntry* PdBinaryEntry :: get_entry() const {
    return entry_ptr_;
}


void PdBinaryEntry :: set_left(PdBinaryEntry* left) {
    left_ = left;
}
     

PdBinaryEntry* PdBinaryEntry :: get_left() const {
    return left_;
}

        
void PdBinaryEntry :: set_right(PdBinaryEntry* right) {
    right_ = right;
}
       
 
PdBinaryEntry* PdBinaryEntry :: get_right() const {
    return right_;
}


ProviderDirectoryHandler :: ProviderDirectoryHandler() {
    root_ = NULL;
}


ProviderDirectoryHandler :: ProviderDirectoryHandler(const ProviderDirectoryHandler& handler) 
    : HashNode(handler) {
    root_ = NULL;

    PdEntry* curr = NULL;
    if(table_ && size_) {
        for(int i = 0; i < size_; ++i) {
            if(table_[i]) {
                curr = table_[i];
                while(curr) {
                    PdBinaryEntry* item = new PdBinaryEntry(curr);
                    root_ = TreeInsertion(item, root_);
                    curr = curr -> get_next();
                }
            }
        }
    }
}


PdBinaryEntry* ProviderDirectoryHandler :: TreeInsertion(PdBinaryEntry* item, PdBinaryEntry* proot) {
    if(!item)
        return proot;
    
    if(!proot)
        return item;
    
    if(proot -> CompareServiceName(item) < 0) {
        PdBinaryEntry* left_child_ptr = TreeInsertion(item, proot -> get_left());
        proot -> set_left(left_child_ptr);
        return proot;
    } else {
        PdBinaryEntry* right_child_ptr = TreeInsertion(item, proot -> get_right());
        proot -> set_right(right_child_ptr);
        return proot;
    }
}


ProviderDirectoryHandler :: ~ProviderDirectoryHandler() {
    root_ = TreeRemoveAll(root_);
}


PdBinaryEntry* ProviderDirectoryHandler :: TreeRemoveAll(PdBinaryEntry* proot) {
    if(!proot)
        return NULL;
    
    PdBinaryEntry* left_child_ptr = TreeRemoveAll(proot -> get_left());
    PdBinaryEntry* right_child_ptr = TreeRemoveAll(proot -> get_right());
    proot -> set_left(left_child_ptr);
    proot -> set_right(right_child_ptr);
    delete proot;
    proot = NULL;
    return NULL;
}

bool ProviderDirectoryHandler :: Insert(PdEntry* item) {
    int index;
    char existence_check[len2sz(LEN_SERVICE_NAME)];

    if(SearchServiceName(item -> get_service_code(), existence_check)) {
        return false;
    }
        
    if(!item) {
        std :: cerr << "Entry creation exception. Insertion failed!" << std :: endl;
        return false;
    }

    index = Hashing(item -> get_service_code());
    if(index < 0 || index >= size_ || !table_) {
        std :: cerr << "Hashing error. Insertion failed!" << std :: endl;
        return false;
    } 
    if(!table_[index])
        table_[index] = item;
    else {
        item -> set_next(table_[index]);
        table_[index] = item;
    }

    PdBinaryEntry* node = new PdBinaryEntry(item);
    root_ = TreeInsertion(node, root_);
    return true;
}


bool ProviderDirectoryHandler :: RemoveAtPos(int pos) {
    int number = 0;
    bool found = false;
    PdEntry* curr = NULL;
    PdEntry* prev = NULL;

    if(pos <= 0 || !table_ || !size_)
        return false;
    
    for(int i = 0; i < size_; ++i) {
        if(table_[i] && !found) {
            curr = table_[i];
            prev = NULL;
            while(curr) {
                ++number;
                if(number == pos) {
                    found = true;
                    if(!prev) {
                        table_[i] = curr -> get_next();
                        curr -> set_next(NULL);
                    } else {
                        prev -> set_next(curr -> get_next());
                        curr -> set_next(NULL);
                    }
                    root_ = TreeRemove(curr, root_);
                } else {
                    prev = curr;
                    curr = curr -> get_next();
                }
            }
        }
    }

    return found;
}


PdBinaryEntry* ProviderDirectoryHandler :: TreeRemove(PdEntry* pos, PdBinaryEntry* proot) {
    PdEntry* ios = NULL;

    if(!proot)
        return NULL;
    if(proot -> CompareServiceName(pos -> get_service_name()) < 0) {
        PdBinaryEntry* left_child_ptr = TreeRemove(pos, proot -> get_left());
        proot -> set_left(left_child_ptr);
        return proot;
    } else if(proot -> CompareServiceName(pos -> get_service_name()) > 0) {
        PdBinaryEntry* right_child_ptr = TreeRemove(pos, proot -> get_right());
        proot -> set_right(right_child_ptr);
        return proot;
    } else {
        if(!proot -> get_left() && !proot -> get_right()) {
            delete proot;
            proot = NULL;
            return NULL;
        } else if(!proot -> get_left()) {
            PdBinaryEntry* ret = proot -> get_right();
            proot -> set_right(NULL);
            delete proot;
            proot = NULL;
            return ret;
        } else if(!proot -> get_right()) {
            PdBinaryEntry* ret = proot -> get_left();
            proot -> set_left(NULL);
            delete proot;
            proot = NULL;
            return ret;
        } else {
            PdBinaryEntry* left_subroot;
            left_subroot = ReplaceIOS(proot -> get_left(), &ios);
            proot -> set_left(left_subroot);
            proot -> set_entry(ios);
            return proot;
        }
    }
}


PdBinaryEntry* ProviderDirectoryHandler :: ReplaceIOS(PdBinaryEntry* lchild, PdEntry** pdptr) {
    if(!lchild -> get_right()) {
        *pdptr = lchild -> get_entry();
        if(!lchild -> get_left()) {
            delete lchild;
            lchild = NULL;
            return NULL;
        } else {
            PdBinaryEntry* ret = lchild -> get_left();
            lchild -> set_left(NULL);
            delete lchild;
            lchild = NULL;
            return ret;
        }
    } 
    PdBinaryEntry* right_child_ptr = ReplaceIOS(lchild -> get_right(), pdptr);
    lchild -> set_right(right_child_ptr);
    return lchild;
}


static const int prime_set[11] = 
{
    53, 97, 193, 389, 769,
    1543, 3079, 6151, 
    12289, 24593,49157
};


int GetPrime(int num) {
    const int* first = prime_set;
    const int* last = prime_set + 10;
    const int* position = std :: lower_bound(first, last, num);
    int pos = position - prime_set;
    return prime_set[pos];   
}