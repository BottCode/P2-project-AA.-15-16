#ifndef MODEL_GABBIA_H
#define MODEL_GABBIA_H

class Gabbia{
private:
    double massa_animale; // in Kg
    double altezza; // in cm
    double larghezza; // in cm
    double prof; // in cm
    bool leggera; // true sse è per animali di piccola taglia
    // una gabbia leggera pesa 0.5 kg al metro cubo. 1.5 altrimenti
public:
    Gabbia();
    Gabbia(double,double,double,double,bool);
    Gabbia(const Gabbia&);
    double getAltezza() const;
    double getLarghezza() const;
    double getProf() const;
    double getLeggera() const;
    double getMassa() const; // della gabbia e l'animale
    double getVolume() const; // in metri cubi
};


#endif // MODEL_GABBIA_H
