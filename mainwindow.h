#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QSpinBox>
#include <QString>
#include <QCheckBox>

#define SERVANT_MAX 256

extern int bright[SERVANT_MAX+1];
extern int selected[SERVANT_MAX+1];
extern QLabel *heads[SERVANT_MAX+1];
extern QLabel *skills[SERVANT_MAX*3+1];
extern QSpinBox *levels[SERVANT_MAX*8+1];
extern QPushButton *deletes[SERVANT_MAX+1];
extern QCheckBox *breaks[SERVANT_MAX+1];

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();  
private slots:
    void on_servant_cal_001_clicked();
    void showdetails(int id);
    void on_servant_cal_002_clicked();
    void image_dark(int id,QLabel *label);
    void on_servant_cal_008_clicked();
    void delete1();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
