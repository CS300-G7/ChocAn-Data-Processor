#include <iostream>
#include <fstream>
#include <cstring>

#define DEFAULT_PD_MAX        50
#define REMOVE_BY_CODE        1
#define REMOVE_BY_NAME        2
#define RETRIEVE_CODE         1
#define RETRIEVE_NAME         2
#define LEN_PATH_MAX          512
#define LEN_SERVICE_CODE      6
#define LEN_SERVICE_NAME      20
#define len2sz(x) ((int)(x) + 1)
#define ch2int(x) ((char)(x) - 48)
#define int2askii(x) ((int)(x) + 48)
#define twobit2int(x1, x2) ((int)(x1) * 10 + (int)(x2))
#define fourbit2int(x1, x2, x3, x4) ((int)(x1) * 1000 + (int)(x2) * 100 + (int)(x3) * 10 + (int)(x4))

int GetPrime(int num);


class ProviderDirectoryEntry {
    public:     
        ProviderDirectoryEntry();
        ProviderDirectoryEntry(char*, char*, float);
        ProviderDirectoryEntry(const ProviderDirectoryEntry&);

        ~ProviderDirectoryEntry();

        ProviderDirectoryEntry& operator=(const ProviderDirectoryEntry&);

        int CompareServiceName(ProviderDirectoryEntry&) const;
        int CompareServiceName(const char*) const;

        char* get_service_code() const;
        char* get_service_name() const;
        float get_fee() const;

    private:
        void Erase();

        char* service_name_;
        char* service_code_;
        float service_fee_;
};


class PdEntry : public ProviderDirectoryEntry {
    public: 
        PdEntry();
        PdEntry(char*, char*, float);
        PdEntry(const PdEntry&);
 
        PdEntry* get_next() const;
        void set_next(PdEntry*);

    private: 
        PdEntry* next_;
};


class PdBinaryEntry {
    public: 
        PdBinaryEntry();
        PdBinaryEntry(PdEntry*);

        int CompareServiceName(const char*) const;
        int CompareServiceName(const PdBinaryEntry*) const;

        void set_entry(PdEntry*);
        PdEntry* get_entry() const;

        void set_left(PdBinaryEntry*);
        PdBinaryEntry* get_left() const;

        void set_right(PdBinaryEntry*);
        PdBinaryEntry* get_right() const;

    private:
        PdEntry* entry_ptr_;
        PdBinaryEntry* left_;
        PdBinaryEntry* right_;
};


class HashNode {
    public: 
        HashNode();
        HashNode(char*);
        HashNode(int, char*);
        HashNode(const HashNode&);

        ~HashNode();

        void set_next(HashNode*);
        HashNode* get_next() const;

        float SearchFee(const char*) const;
        bool SearchServiceName(const char*, char*) const;

        int Hashing(const char*) const;

    protected:
        PdEntry* CopyList(PdEntry* dst, PdEntry* scr);
        PdEntry* ClearList(PdEntry* phead);

        PdEntry** table_;
        int size_;
        char* time_;
    
    private:
        HashNode* next_;
};



class ProviderDirectoryHandler : public HashNode {
    public: 
        ProviderDirectoryHandler();
        ProviderDirectoryHandler(const ProviderDirectoryHandler&);

        ~ProviderDirectoryHandler();
        
        bool Insert(PdEntry*); 
        bool RemoveAtPos(int pos);

    private:
        PdBinaryEntry* TreeInsertion(PdBinaryEntry* item, PdBinaryEntry* proot);
        PdBinaryEntry* TreeRemoveAll(PdBinaryEntry* proot);
        PdBinaryEntry* TreeRemove(PdEntry* pos, PdBinaryEntry* proot);
        PdBinaryEntry* ReplaceIOS(PdBinaryEntry* lchild, PdEntry** pdptr);
        void TreeDisplay(PdBinaryEntry* proot) const;
               
        
        PdEntry* GetEntryAtPos(int pos);

        PdBinaryEntry* root_;
};