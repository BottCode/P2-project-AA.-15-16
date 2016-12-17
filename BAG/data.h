#ifndef DATA_H
#define DATA_H
#include <model_contenitore.h>
#include <QString>
#include <memory>
class Data
{
public:
    Data();
    Data(Lista<bagaglio*>);
    int min(int,int) const;
    int max(int,int) const;
    bool start_search(QString&,QString&,int,int) const;
    bool match(QString, QString) const;
    void load(QString);
    void save(QString);
    int getIdMax() const;
    void setIdMax(int);
    int getIdMin() const;
    void setIdMin(int);
    void setFileData(QString);
    QString getFileData() const;
    bagaglio* search_id(int) const;
    std::vector<bagaglio*> search_own(QString,int&) const;
    std::vector<bagaglio*> search_dest(QString dest) const;
    void delete_by_id(int);
    Lista<bagaglio *>& getList();
    void deallocateAllLug() const;
    ~Data();
private:
    Lista<bagaglio*> list;
    static QString file_data; // path del file in uso
    static int id_max_bag, id_min_vi;
    static bool primo;
};

#endif // DATA_H
