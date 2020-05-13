#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QVariantMap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString insertJson(std::string first, std::string second);

public slots:
    void updateTime();
    void pingAPI();
    void updateAPI(QNetworkReply* reply);

private:
    int counter =0;
    Ui::MainWindow *ui;
    QTimer *clockTimer;
    QTimer *APITimer;

    QUrl geckoAPILink = QUrl(
    "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin,ethereum,ripple,litecoin,monero,zcash&vs_currencies=usd,eur,gbp"
        );
    QJsonObject json;
    QVariantMap json_map;

};
#endif // MAINWINDOW_H
