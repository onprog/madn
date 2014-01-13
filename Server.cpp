
#include "Server.h"
#include "QDataStream"
#include "QString"
#include <iostream>

Server::Server(QObject *parent) {
    server = new QTcpServer(parent);
    server->listen();
    connect(server, SIGNAL(newConnection()), this, SLOT(neueVerbindung()));
    for (int i = 0; i < CLIENTS_MAX; ++i) {
        clients[i] = 0;
    }
    anzahlClients = 0;
}

void Server::neueVerbindung() {
    QTcpSocket *neuerClient = server->nextPendingConnection();
    if (anzahlClients >= CLIENTS_MAX) {
        neuerClient->disconnectFromHost();
    }
    clients[anzahlClients++] = neuerClient;
    connect(neuerClient, SIGNAL(readyRead()), this, SLOT(nachrichtEmpfangen()));
//    sendeBegruessung(neuerClient);
}

void Server::nachrichtEmpfangen() {
    QTcpSocket *client = dynamic_cast<QTcpSocket *>(sender());
    if (client == 0) {
        std::cerr << "Server::nachrichtEmpfangen : sender() ist nicht QTcpSocket";
    }
    while (client->canReadLine()) {
        QByteArray nachricht = client->readLine();

    }
}
