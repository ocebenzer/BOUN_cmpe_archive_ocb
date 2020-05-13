#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QtNetwork/QNetworkAccessManager>
#include <chrono>
#include <QJsonDocument>
#include <QVariant>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateTime();


    APITimer = new QTimer(this);
    connect(APITimer,SIGNAL(timeout()),this,SLOT(pingAPI()));
    //2k, change to 20k later
    APITimer->start(2000);

    pingAPI();





    clockTimer = new QTimer(this);
    connect(clockTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
    clockTimer->start(1000);



}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateTime(){
    QString timestring = QTime::currentTime().toString();
    timestring.push_front(" Time:  ");
    ui->tabTime->setText(timestring);

}
void MainWindow::pingAPI(){
    //pings the geckoAPI
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::updateAPI);
    QNetworkRequest myRequest(geckoAPILink);
    myRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    manager->get(myRequest);
    //debug
    //ui->tabTime->setText("ping");
}
void MainWindow::updateAPI(QNetworkReply *reply){
    //updates the GUI elements
    json = QJsonDocument::fromJson(reply->readAll()).object();

    //debug
    qDebug() << QJsonDocument(json).toJson();
    json_map = json.toVariantMap();

    //USD part
    ui->bitcoinUSD->setText(insertJson("bitcoin", "usd"));
    ui->etheriumUSD->setText(insertJson("ethereum", "usd"));
    ui->rippleUSD->setText(insertJson("ripple", "usd"));
    ui->litecoinUSD->setText(insertJson("litecoin", "usd"));
    ui->moneroUSD->setText(insertJson("monero", "usd"));
    ui->zcashUSD->setText(insertJson("zcash", "usd"));

    //EUR part
    ui->bitcoinEUR->setText(insertJson("bitcoin", "eur"));
    ui->etheriumEUR->setText(insertJson("ethereum", "eur"));
    ui->rippleEUR->setText(insertJson("ripple", "eur"));
    ui->litecoinEUR->setText(insertJson("litecoin", "eur"));
    ui->moneroEUR->setText(insertJson("monero", "eur"));
    ui->zcashEUR->setText(insertJson("zcash", "eur"));

    //GBP part
    ui->bitcoinGBP->setText(insertJson("bitcoin", "gbp"));
    ui->etheriumGBP->setText(insertJson("ethereum", "gbp"));
    ui->rippleGBP->setText(insertJson("ripple", "gbp"));
    ui->litecoinGBP->setText(insertJson("litecoin", "gbp"));
    ui->moneroGBP->setText(insertJson("monero", "gbp"));
    ui->zcashGBP->setText(insertJson("zcash", "gbp"));


}
QString MainWindow::insertJson(std::string first, std::string second){
    QVariantMap row = json_map[QString::fromStdString(first)].toMap();
    qDebug() <<  row[QString::fromStdString(second)].toString() ;
    return row[QString::fromStdString(second)].toString();

}






















