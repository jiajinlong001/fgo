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

//头像按钮点击状态数组
extern int connection[SERVANT_MAX+1];
//选择从者的数量及各从者的选择顺序
extern int selected[SERVANT_MAX+1];
//等级设置条各部件数组，包括一个头像label，3个技能label，8个等级spinbox，1个删除pushbutton，一个突破Checkbox
extern QLabel *heads[SERVANT_MAX+1];
extern QLabel *skills[SERVANT_MAX*3+1];
extern QSpinBox *levels[SERVANT_MAX*8+1];
extern QPushButton *deletes[SERVANT_MAX+1];
extern QCheckBox *breaks[SERVANT_MAX+1];

#define N2V(x)  servant_cal_##x

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
    //从者列表中头像按钮的槽函数，每个头像按钮对应一个
    void on_servant_cal_001_clicked();
    //选定从者后在下方显示从者的等级设置条
    void showdetails(int id);
    //选定从者后对应的按钮头像变暗
    void image_dark(int id,QLabel *label);
    //各从者对应的删除槽函数，名字中的序号与从者id是一致的，实现删除等级设置条并重新点亮图标
    void delete1();
    //删除等级设置条函数
    void remove(int id);
    //剩余从者重新排列函数
    void reset(int id);
    //其余从者头像按钮槽函数
    void on_servant_cal_002_clicked();
    void on_servant_cal_003_clicked();
//    void on_servant_cal_004_clicked();
//    void on_servant_cal_005_clicked();
//    void on_servant_cal_006_clicked();
//    void on_servant_cal_007_clicked();
    void on_servant_cal_008_clicked();
//    void on_servant_cal_009_clicked();
//    void on_servant_cal_010_clicked();
//    void on_servant_cal_011_clicked();
    //其余等级设置条删除按钮对应的槽函数
    void delete2();
    void delete3();
//    void delete4();
//    void delete5();
//    void delete6();
//    void delete7();
    void delete8();
    void delete_test(QPushButton *send,int id);
//    void delete9();
//    void delete10();
//    void delete11();


    void on_servant_cal_068_clicked();



    void on_servant_cal_076_clicked();

    void on_servant_cal_090_clicked();

    void on_servant_cal_091_clicked();

    void on_servant_cal_153_clicked();

    void on_servant_cal_160_clicked();

    void on_servant_cal_213_clicked();

    void on_servant_cal_004_clicked();

    void on_servant_cal_005_clicked();

    void on_servant_cal_006_clicked();

    void on_servant_cal_010_clicked();

    void on_servant_cal_101_clicked();

    void on_servant_cal_121_clicked();

    void on_servant_cal_123_clicked();

    void on_servant_cal_138_clicked();

    void on_servant_cal_176_clicked();

    void on_servant_cal_187_clicked();

    void on_servant_cal_221_clicked();

    void on_servant_cal_223_clicked();

    void on_servant_cal_227_clicked();

    void on_servant_cal_007_clicked();

    void on_servant_cal_009_clicked();

    void on_servant_cal_072_clicked();

    void on_servant_cal_126_clicked();

    void on_servant_cal_220_clicked();

    void on_servant_cal_166_clicked();

    void on_servant_cal_234_clicked();

    void on_servant_cal_165_clicked();

private:
    Ui::MainWindow *ui;
    void button_call(QPushButton *button,int id);

};

#endif // MAINWINDOW_H
