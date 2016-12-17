#include "data.h"

QString Data::file_data="../BAG/data.xml";
int Data::id_max_bag=1;
int Data::id_min_vi=-1;
bool Data::primo=true;

Data::Data():list(Lista<bagaglio*>()){}
// il costruttore di copia di list non e` ridefinito, in quanto cio` che voglio e` proprio
// la copia di puntatori e non di creare una nuova lista
Data::Data(Lista<bagaglio *> L):list(L){}

int Data::min(int a,int b) const{return a<b ? a:b;}
int Data:: max(int a,int b) const{return a<b ? b:a;}

bool  Data::start_search(QString& a,QString& b, int j, int size) const{
    int tot=1;
    for(int k=j;k<size;k++)
        if(a.at(tot).toLatin1() == b.at(k).toLatin1()) tot++;
    double p=(tot*100)/max(a.size(),b.size());
    return p>50 ? true:false;
}

bool Data::match(QString a, QString b) const{ // TRUE sse la percentuale di match è maggiore stretta di 50
    a=a.toLower();b=b.toLower(); // ricerca ignore case
    int size=min(a.size(),b.size());
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            if(a.at(i).toLatin1() == b.at(j).toLatin1())
                return start_search(a,b,j+1,size);
    }
    return false;
}

void Data::load(QString path){ // carica i dati dal data.xml alla lista all'avvio
    if(!primo) // se non è la prima lista che viene caricata, dealloco tutti i bagagli della lista precedente
        deallocateAllLug();
    else primo=false;
    QFile file(path);
    QString nome,cognome,domicilio,destinazione,type,descr,modo;
    bagaglio* tmp=0;
    int giorno_p,mese_p,anno_p,id_v,id_b,giorno_v,mese_v,anno_v,parte;
    double massa,altezza,larghezza,prof;
    if(!list.isEmpty()) list.drop();
    if(file.open(QFile::ReadOnly)){
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()){
            if(xmlStreamReader.isStartElement()){
                if(xmlStreamReader.name()=="id_max_bag") id_max_bag=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="id_min_vi") id_min_vi=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="dati" || xmlStreamReader.name()=="tupla") xmlStreamReader.readNext();
                if(xmlStreamReader.name()=="nome") nome=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="cognome") cognome=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="giorno_p") giorno_p=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="mese_p") mese_p=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="anno_p") anno_p=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="domicilio") domicilio=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="parte") parte=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="id_v") id_v=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="destinazione") destinazione=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="modo") modo=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="giorno") giorno_v=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="mese") mese_v=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="anno") anno_v=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="id") id_b=xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="weight") massa=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="type") type=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="height") altezza=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="width") larghezza=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="description") descr=xmlStreamReader.readElementText();
                if(xmlStreamReader.name()=="depth"){ // letto tutto, costruiamo il bagaglio
                    prof=xmlStreamReader.readElementText().toDouble();
                    if(tmp) delete tmp;
                    Viaggio vi(id_v,destinazione,QDate(anno_v,mese_v,giorno_v),modo);
                    Proprietario pro(nome,cognome,QDate(anno_p,mese_p,giorno_p),domicilio,parte);
                    if(type == "HAND") tmp=new bagaglio_a_mano(id_b,massa,altezza,larghezza,prof,pro,vi,descr);
                    else if(type == "SPECIAL") tmp=new bagaglio_speciale(id_b,massa,altezza,larghezza,prof,pro,vi,descr);
                    else if(type == "NORMAL") tmp=new bagaglio_normale(id_b,massa,altezza,larghezza,prof,pro,vi,descr);
                    else if(type == "PLANT") tmp=new bagaglio_pianta(id_b,massa,altezza,larghezza,prof,pro,vi,descr);
                    else if(type == "TAME ANIMAL") tmp=new bagaglio_animale_mansueto(id_b,massa,altezza,larghezza,prof,pro,vi,descr);
                    else if(type == "DANGEROUS ANIMAL") tmp=new bagaglio_animale_pericoloso(id_b,massa,altezza,larghezza,prof,pro,vi,descr);
                }
                if(tmp){
                    list.push_back(tmp);
                    tmp=0;
                }
            }
            xmlStreamReader.readNext();
        }
        file.close();
    }
}

void Data::save(QString path){ // salva i dati dal contenitore al data.xml
    // qDebug()<<path;
    int size=path.size();
    if(size<4 || path.at(size-1)!='l' || path.at(size-2)!='m' || path.at(size-3)!='x' || path.at(size-4)!='.') path+=".xml";
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlStreamWriter(&file);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("dati");
    xmlStreamWriter.writeTextElement("id_max_bag",QString::number(id_max_bag));
    xmlStreamWriter.writeTextElement("id_min_vi",QString::number(id_min_vi));
    for(Lista<bagaglio*>::iteratore it=list.begin();it!=list.end() && !list.isEmpty();++it){
        xmlStreamWriter.writeStartElement("tupla");
        xmlStreamWriter.writeTextElement("nome",(list[it].b->getProprietario().getNome()));
        xmlStreamWriter.writeTextElement("cognome",(list[it].b->getProprietario().getCognome()));
        xmlStreamWriter.writeTextElement("giorno_p",QString::number(list[it].b->getProprietario().getQDateNascita().day()));
        xmlStreamWriter.writeTextElement("mese_p",QString::number(list[it].b->getProprietario().getQDateNascita().month()));
        xmlStreamWriter.writeTextElement("anno_p",QString::number(list[it].b->getProprietario().getQDateNascita().year()));
        xmlStreamWriter.writeTextElement("domicilio",list[it].b->getProprietario().getResidenza());
        xmlStreamWriter.writeTextElement("parte",QString::number(list[it].b->getProprietario().getParte()));
        xmlStreamWriter.writeTextElement("id_v",QString::number(list[it].b->getViaggio().getID()));
        xmlStreamWriter.writeTextElement("destinazione",(list[it].b->getViaggio().getDest()));
        xmlStreamWriter.writeTextElement("modo",(list[it].b->getViaggio().getModo()));
        xmlStreamWriter.writeTextElement("giorno",QString::number(list[it].b->getViaggio().getQDate().day()));
        xmlStreamWriter.writeTextElement("mese",QString::number(list[it].b->getViaggio().getQDate().month()));
        xmlStreamWriter.writeTextElement("anno",QString::number(list[it].b->getViaggio().getQDate().year()));
        xmlStreamWriter.writeTextElement("id",QString::number(list[it].b->getCode()));
        xmlStreamWriter.writeTextElement("type",list[it].b->getType());
        xmlStreamWriter.writeTextElement("weight",QString::number(list[it].b->getMassa()));
        xmlStreamWriter.writeTextElement("height",QString::number(list[it].b->getAltezza()));
        xmlStreamWriter.writeTextElement("width",QString::number(list[it].b->getLarghezza()));
        xmlStreamWriter.writeTextElement("description",(list[it].b->getDescription()));
        xmlStreamWriter.writeTextElement("depth",QString::number(list[it].b->getProf()));
        xmlStreamWriter.writeEndElement();
    }
    xmlStreamWriter.writeEndDocument();
    file.close();
}

bagaglio* Data::search_id(int id) const{
    for(Lista<bagaglio*>::iteratore it=list.begin();!(list.isEmpty()) && it!=list.end();++it)
        if((list[it].b->getCode()) == id) return list[it].b;
    return 0;
}

void Data::delete_by_id(int id){
    bool find=false;
    for(Lista<bagaglio*>::iteratore it=list.begin();it!=list.end() && !find;++it){
        if((list[it].b->getCode()==id)){
            list.delete_node(it.getPunt());
            find=true;
        }
    }
}

Lista<bagaglio *> &Data::getList(){return list;}

std::vector<bagaglio*> Data::search_own(QString owner, int& i) const{
    std::vector<bagaglio*> tmp;
    for(Lista<bagaglio*>::iteratore it=list.begin();!(list.isEmpty()) && it!=list.end();++it){
        if(match(owner,list[it].b->getProprietario().getFullName())){
            tmp.push_back(list[it].b);
            i++;
        }
    }
    return tmp;
}

std::vector<bagaglio*> Data::search_dest(QString dest) const{
    std::vector<bagaglio*> tmp;
    for(Lista<bagaglio*>::iteratore it=list.begin();!(list.isEmpty()) && it!=list.end();++it){
        if(match(dest,list[it].b->getViaggio().getDest()))
            tmp.push_back(list[it].b);
    }
    return tmp;
}

int Data::getIdMax() const{return id_max_bag;}
void Data::setIdMax(int i){ id_max_bag+=i; }
int Data::getIdMin() const{return id_min_vi;}
void Data::setIdMin(int i){id_min_vi-=i;}
void Data::setFileData(QString path){file_data=path;}
QString Data::getFileData() const{return file_data;}

/* Il contenitore contiene ptr a bagagli e non bagagli. Dato che il contenitore è templetizzato,
 * allora il distruttore di Nodo non deve essere ridefinito. Sarà compito di questo distruttore
 * deallocare i bagagli di ogni nodo. Il contenitore deallocherà solo sè stesso, cioè la struttura dati ospitante i ptr ai bagagli
*/

void Data::deallocateAllLug() const{
    for(Lista<bagaglio*>::iteratore it=list.begin();!(list.isEmpty()) && it!=list.end();++it)
        delete (list[it].b);
}

Data::~Data(){
    deallocateAllLug(); // rimuove tutti gli oggetti bagaglio
    // non serve deallocare gli oggetti puntati dalle celle del vector tmp in quanti puntano
    // ai medesimi bagagli ai quali puntano i nodi della lista.
}
