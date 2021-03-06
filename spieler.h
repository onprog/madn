#ifndef SPIELER_H
#define SPIELER_H
#include "zustand.h"
#include <QString>
#include <QObject>

class Spieler : public QObject
{
    Q_OBJECT
private:
    int anzStartfeld;
    int anzZielfeld;
    int anzGewurfelt;
    int augen;
    QString benutzerName;
    QString ip;
    bool awayFromKeyboard;
    bool darfKlicken;
    bool startpositionBelegt;
    bool zuendeGespielt;
public:
    Zustand spielerFarbe;
    explicit Spieler(QObject *parent = 0);
    void wurfelPhase(); //wird von spiele() aufgerufen
    void initSpieler(int i);
    bool getStartpositionBelegt() {return startpositionBelegt;}
    void setStartpositionBelegt(bool n) {startpositionBelegt=n;}
    bool getDarfKlicken() {return darfKlicken;}
    void setDarfKlicken(bool n) {darfKlicken=n;}
    void anzStartfeldVerringern() {anzStartfeld--;}
    void anzStartfeldErhoehen() {anzStartfeld++;}
public slots:
    void spiele(Zustand);  //wird von der Netzwerkverbindung aufgerufen
    void zugPhase(int);  //wird vom Hauptwürfel aufgerufen
    void checkPhase(); //wird vom Feld aufgerufen
    void setzeAugen(int);
signals:
    void spielerFertig();
    void darfWurfeln();
    void wurfelFarbe(Zustand);
};

#endif // SPIELER_H
