#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool DBConnection(QSqlDatabase db) {

       db.setHostName("localhost");
       db.setDatabaseName("Marks");
       db.setUserName("root");
       db.setPassword("1");
       return db.open();
}

void MainWindow::on_pushButton_clicked() {
    QString name = ui->lineEdit->text();
    QString date = ui->dateEdit->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "mydb");
    QSqlQuery query(db);

    if (!DBConnection(db)) {
        ui->label_3->setText(db.lastError().text());
    } else {
        if (!query.exec("SELECT TIMESTAMPDIFF(MINUTE, (SELECT MIN(time) FROM card JOIN (archive) ON (card.card_id = archive.id) WHERE DATE(card.time) = '" + date + "' AND archive.info = '" + name + "'), (SELECT MAX(time) FROM card JOIN (archive) ON (card.card_id = archive.id) WHERE DATE(card.time) = '" + date + "' AND archive.info = '" + name + "'));")) {
            ui->label_3->setText(db.lastError().text());
        } else {
            while (query.next()) {
                 ui->label_3->setText("Отработал: " + query.value(0).toString() + " минут");
               }
        }
        db.close();
    }

    QSqlDatabase::removeDatabase("mydb");
}
