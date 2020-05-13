/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *rightLayout;
    QVBoxLayout *USD;
    QTextBrowser *HeaderUSD;
    QTextBrowser *bitcoinUSD;
    QTextBrowser *etheriumUSD;
    QTextBrowser *rippleUSD;
    QTextBrowser *litecoinUSD;
    QTextBrowser *moneroUSD;
    QTextBrowser *zcashUSD;
    QVBoxLayout *EUR;
    QTextBrowser *HeaderEUR;
    QTextBrowser *bitcoinEUR;
    QTextBrowser *etheriumEUR;
    QTextBrowser *rippleEUR;
    QTextBrowser *litecoinEUR;
    QTextBrowser *moneroEUR;
    QTextBrowser *zcashEUR;
    QVBoxLayout *GBP;
    QTextBrowser *HeaderGBP;
    QTextBrowser *bitcoinGBP;
    QTextBrowser *etheriumGBP;
    QTextBrowser *rippleGBP;
    QTextBrowser *litecoinGBP;
    QTextBrowser *moneroGBP;
    QTextBrowser *zcashGBP;
    QWidget *layoutWidget1;
    QVBoxLayout *leftLayout;
    QTextBrowser *tabTime;
    QTextBrowser *tabBitcoin;
    QTextBrowser *tabEtherium;
    QTextBrowser *tabRipple;
    QTextBrowser *tabLitecoin;
    QTextBrowser *tabMonero;
    QTextBrowser *tabZcash;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 280);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 10, 291, 261));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(11);
        layoutWidget->setFont(font);
        rightLayout = new QHBoxLayout(layoutWidget);
        rightLayout->setSpacing(0);
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        rightLayout->setContentsMargins(0, 0, 0, 0);
        USD = new QVBoxLayout();
        USD->setSpacing(0);
        USD->setObjectName(QString::fromUtf8("USD"));
        HeaderUSD = new QTextBrowser(layoutWidget);
        HeaderUSD->setObjectName(QString::fromUtf8("HeaderUSD"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HeaderUSD->sizePolicy().hasHeightForWidth());
        HeaderUSD->setSizePolicy(sizePolicy);
        HeaderUSD->setFont(font);

        USD->addWidget(HeaderUSD);

        bitcoinUSD = new QTextBrowser(layoutWidget);
        bitcoinUSD->setObjectName(QString::fromUtf8("bitcoinUSD"));
        sizePolicy.setHeightForWidth(bitcoinUSD->sizePolicy().hasHeightForWidth());
        bitcoinUSD->setSizePolicy(sizePolicy);
        bitcoinUSD->setFont(font);
        bitcoinUSD->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        USD->addWidget(bitcoinUSD);

        etheriumUSD = new QTextBrowser(layoutWidget);
        etheriumUSD->setObjectName(QString::fromUtf8("etheriumUSD"));
        sizePolicy.setHeightForWidth(etheriumUSD->sizePolicy().hasHeightForWidth());
        etheriumUSD->setSizePolicy(sizePolicy);
        etheriumUSD->setFont(font);
        etheriumUSD->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        USD->addWidget(etheriumUSD);

        rippleUSD = new QTextBrowser(layoutWidget);
        rippleUSD->setObjectName(QString::fromUtf8("rippleUSD"));
        sizePolicy.setHeightForWidth(rippleUSD->sizePolicy().hasHeightForWidth());
        rippleUSD->setSizePolicy(sizePolicy);
        rippleUSD->setFont(font);
        rippleUSD->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        USD->addWidget(rippleUSD);

        litecoinUSD = new QTextBrowser(layoutWidget);
        litecoinUSD->setObjectName(QString::fromUtf8("litecoinUSD"));
        sizePolicy.setHeightForWidth(litecoinUSD->sizePolicy().hasHeightForWidth());
        litecoinUSD->setSizePolicy(sizePolicy);
        litecoinUSD->setFont(font);
        litecoinUSD->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        USD->addWidget(litecoinUSD);

        moneroUSD = new QTextBrowser(layoutWidget);
        moneroUSD->setObjectName(QString::fromUtf8("moneroUSD"));
        sizePolicy.setHeightForWidth(moneroUSD->sizePolicy().hasHeightForWidth());
        moneroUSD->setSizePolicy(sizePolicy);
        moneroUSD->setFont(font);
        moneroUSD->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        USD->addWidget(moneroUSD);

        zcashUSD = new QTextBrowser(layoutWidget);
        zcashUSD->setObjectName(QString::fromUtf8("zcashUSD"));
        sizePolicy.setHeightForWidth(zcashUSD->sizePolicy().hasHeightForWidth());
        zcashUSD->setSizePolicy(sizePolicy);
        zcashUSD->setFont(font);
        zcashUSD->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        USD->addWidget(zcashUSD);


        rightLayout->addLayout(USD);

        EUR = new QVBoxLayout();
        EUR->setSpacing(0);
        EUR->setObjectName(QString::fromUtf8("EUR"));
        HeaderEUR = new QTextBrowser(layoutWidget);
        HeaderEUR->setObjectName(QString::fromUtf8("HeaderEUR"));
        sizePolicy.setHeightForWidth(HeaderEUR->sizePolicy().hasHeightForWidth());
        HeaderEUR->setSizePolicy(sizePolicy);
        HeaderEUR->setFont(font);

        EUR->addWidget(HeaderEUR);

        bitcoinEUR = new QTextBrowser(layoutWidget);
        bitcoinEUR->setObjectName(QString::fromUtf8("bitcoinEUR"));
        sizePolicy.setHeightForWidth(bitcoinEUR->sizePolicy().hasHeightForWidth());
        bitcoinEUR->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(11);
        font1.setStrikeOut(false);
        bitcoinEUR->setFont(font1);
        bitcoinEUR->setFocusPolicy(Qt::StrongFocus);
        bitcoinEUR->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        EUR->addWidget(bitcoinEUR);

        etheriumEUR = new QTextBrowser(layoutWidget);
        etheriumEUR->setObjectName(QString::fromUtf8("etheriumEUR"));
        sizePolicy.setHeightForWidth(etheriumEUR->sizePolicy().hasHeightForWidth());
        etheriumEUR->setSizePolicy(sizePolicy);
        etheriumEUR->setFont(font);
        etheriumEUR->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        EUR->addWidget(etheriumEUR);

        rippleEUR = new QTextBrowser(layoutWidget);
        rippleEUR->setObjectName(QString::fromUtf8("rippleEUR"));
        sizePolicy.setHeightForWidth(rippleEUR->sizePolicy().hasHeightForWidth());
        rippleEUR->setSizePolicy(sizePolicy);
        rippleEUR->setFont(font);
        rippleEUR->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        EUR->addWidget(rippleEUR);

        litecoinEUR = new QTextBrowser(layoutWidget);
        litecoinEUR->setObjectName(QString::fromUtf8("litecoinEUR"));
        sizePolicy.setHeightForWidth(litecoinEUR->sizePolicy().hasHeightForWidth());
        litecoinEUR->setSizePolicy(sizePolicy);
        litecoinEUR->setFont(font);
        litecoinEUR->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        EUR->addWidget(litecoinEUR);

        moneroEUR = new QTextBrowser(layoutWidget);
        moneroEUR->setObjectName(QString::fromUtf8("moneroEUR"));
        sizePolicy.setHeightForWidth(moneroEUR->sizePolicy().hasHeightForWidth());
        moneroEUR->setSizePolicy(sizePolicy);
        moneroEUR->setFont(font);
        moneroEUR->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        EUR->addWidget(moneroEUR);

        zcashEUR = new QTextBrowser(layoutWidget);
        zcashEUR->setObjectName(QString::fromUtf8("zcashEUR"));
        sizePolicy.setHeightForWidth(zcashEUR->sizePolicy().hasHeightForWidth());
        zcashEUR->setSizePolicy(sizePolicy);
        zcashEUR->setFont(font);
        zcashEUR->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        EUR->addWidget(zcashEUR);


        rightLayout->addLayout(EUR);

        GBP = new QVBoxLayout();
        GBP->setSpacing(0);
        GBP->setObjectName(QString::fromUtf8("GBP"));
        HeaderGBP = new QTextBrowser(layoutWidget);
        HeaderGBP->setObjectName(QString::fromUtf8("HeaderGBP"));
        sizePolicy.setHeightForWidth(HeaderGBP->sizePolicy().hasHeightForWidth());
        HeaderGBP->setSizePolicy(sizePolicy);
        HeaderGBP->setFont(font);

        GBP->addWidget(HeaderGBP);

        bitcoinGBP = new QTextBrowser(layoutWidget);
        bitcoinGBP->setObjectName(QString::fromUtf8("bitcoinGBP"));
        sizePolicy.setHeightForWidth(bitcoinGBP->sizePolicy().hasHeightForWidth());
        bitcoinGBP->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(11);
        font2.setStyleStrategy(QFont::PreferDefault);
        bitcoinGBP->setFont(font2);
        bitcoinGBP->setLayoutDirection(Qt::LeftToRight);
        bitcoinGBP->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bitcoinGBP->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bitcoinGBP->setLineWrapMode(QTextEdit::NoWrap);
        bitcoinGBP->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        GBP->addWidget(bitcoinGBP);

        etheriumGBP = new QTextBrowser(layoutWidget);
        etheriumGBP->setObjectName(QString::fromUtf8("etheriumGBP"));
        sizePolicy.setHeightForWidth(etheriumGBP->sizePolicy().hasHeightForWidth());
        etheriumGBP->setSizePolicy(sizePolicy);
        etheriumGBP->setFont(font);
        etheriumGBP->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        GBP->addWidget(etheriumGBP);

        rippleGBP = new QTextBrowser(layoutWidget);
        rippleGBP->setObjectName(QString::fromUtf8("rippleGBP"));
        sizePolicy.setHeightForWidth(rippleGBP->sizePolicy().hasHeightForWidth());
        rippleGBP->setSizePolicy(sizePolicy);
        rippleGBP->setFont(font);
        rippleGBP->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        GBP->addWidget(rippleGBP);

        litecoinGBP = new QTextBrowser(layoutWidget);
        litecoinGBP->setObjectName(QString::fromUtf8("litecoinGBP"));
        sizePolicy.setHeightForWidth(litecoinGBP->sizePolicy().hasHeightForWidth());
        litecoinGBP->setSizePolicy(sizePolicy);
        litecoinGBP->setFont(font);
        litecoinGBP->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        GBP->addWidget(litecoinGBP);

        moneroGBP = new QTextBrowser(layoutWidget);
        moneroGBP->setObjectName(QString::fromUtf8("moneroGBP"));
        sizePolicy.setHeightForWidth(moneroGBP->sizePolicy().hasHeightForWidth());
        moneroGBP->setSizePolicy(sizePolicy);
        moneroGBP->setFont(font);
        moneroGBP->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        GBP->addWidget(moneroGBP);

        zcashGBP = new QTextBrowser(layoutWidget);
        zcashGBP->setObjectName(QString::fromUtf8("zcashGBP"));
        sizePolicy.setHeightForWidth(zcashGBP->sizePolicy().hasHeightForWidth());
        zcashGBP->setSizePolicy(sizePolicy);
        zcashGBP->setFont(font);
        zcashGBP->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        GBP->addWidget(zcashGBP);


        rightLayout->addLayout(GBP);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 171, 261));
        QFont font3;
        font3.setPointSize(11);
        layoutWidget1->setFont(font3);
        leftLayout = new QVBoxLayout(layoutWidget1);
        leftLayout->setSpacing(0);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        leftLayout->setContentsMargins(0, 0, 1, 0);
        tabTime = new QTextBrowser(layoutWidget1);
        tabTime->setObjectName(QString::fromUtf8("tabTime"));
        sizePolicy.setHeightForWidth(tabTime->sizePolicy().hasHeightForWidth());
        tabTime->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(11);
        font4.setKerning(false);
        tabTime->setFont(font4);
        tabTime->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabTime);

        tabBitcoin = new QTextBrowser(layoutWidget1);
        tabBitcoin->setObjectName(QString::fromUtf8("tabBitcoin"));
        sizePolicy.setHeightForWidth(tabBitcoin->sizePolicy().hasHeightForWidth());
        tabBitcoin->setSizePolicy(sizePolicy);
        tabBitcoin->setFont(font3);
        tabBitcoin->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabBitcoin);

        tabEtherium = new QTextBrowser(layoutWidget1);
        tabEtherium->setObjectName(QString::fromUtf8("tabEtherium"));
        sizePolicy.setHeightForWidth(tabEtherium->sizePolicy().hasHeightForWidth());
        tabEtherium->setSizePolicy(sizePolicy);
        tabEtherium->setFont(font3);
        tabEtherium->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabEtherium);

        tabRipple = new QTextBrowser(layoutWidget1);
        tabRipple->setObjectName(QString::fromUtf8("tabRipple"));
        sizePolicy.setHeightForWidth(tabRipple->sizePolicy().hasHeightForWidth());
        tabRipple->setSizePolicy(sizePolicy);
        tabRipple->setFont(font3);
        tabRipple->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabRipple);

        tabLitecoin = new QTextBrowser(layoutWidget1);
        tabLitecoin->setObjectName(QString::fromUtf8("tabLitecoin"));
        sizePolicy.setHeightForWidth(tabLitecoin->sizePolicy().hasHeightForWidth());
        tabLitecoin->setSizePolicy(sizePolicy);
        tabLitecoin->setFont(font3);
        tabLitecoin->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabLitecoin);

        tabMonero = new QTextBrowser(layoutWidget1);
        tabMonero->setObjectName(QString::fromUtf8("tabMonero"));
        sizePolicy.setHeightForWidth(tabMonero->sizePolicy().hasHeightForWidth());
        tabMonero->setSizePolicy(sizePolicy);
        tabMonero->setFont(font3);
        tabMonero->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabMonero);

        tabZcash = new QTextBrowser(layoutWidget1);
        tabZcash->setObjectName(QString::fromUtf8("tabZcash"));
        sizePolicy.setHeightForWidth(tabZcash->sizePolicy().hasHeightForWidth());
        tabZcash->setSizePolicy(sizePolicy);
        tabZcash->setFont(font3);
        tabZcash->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        leftLayout->addWidget(tabZcash);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OCB Currency", nullptr));
        HeaderUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">USD</span></p></body></html>", nullptr));
        bitcoinUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        etheriumUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        rippleUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        litecoinUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        moneroUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        zcashUSD->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        HeaderEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">EUR</span></p></body></html>", nullptr));
        bitcoinEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        etheriumEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        rippleEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        litecoinEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        moneroEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        zcashEUR->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        HeaderGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">GBP</span></p></body></html>", nullptr));
        bitcoinGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        etheriumGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        rippleGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        litecoinGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        moneroGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        zcashGBP->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Comic Sans MS'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Loading</span></p></body></html>", nullptr));
        tabTime->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; color:#000000;\"> Time:  -</span></p></body></html>", nullptr));
        tabBitcoin->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">  </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Bitcoin:</span></p></body></html>", nullptr));
        tabEtherium->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">  Etherium:</span></p></body></html>", nullptr));
        tabRipple->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">  Ripple:</span></p></body></html>", nullptr));
        tabLitecoin->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">  Litecoin:</span></p></body></html>", nullptr));
        tabMonero->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">  Monero:</span></p></body></html>", nullptr));
        tabZcash->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">  Zcash:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
