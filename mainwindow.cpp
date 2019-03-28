#include "mainwindow.h"
#include "ui_mainwindow.h"

//记录删除按钮与删除槽信号的绑定状态，0为未绑定，1为已绑定
extern int connection[SERVANT_MAX+1]={0};
//选择从者的数量及各从者的选择顺序
extern int selected[SERVANT_MAX+1]={0};
//等级设置条各部件数组，包括一个头像label，3个技能label，8个等级spinbox，1个删除pushbutton，一个突破CheckBox
//这里面heads，deletes，breaks的角标与从者id是对应的，skills和levels的角标与从者id存在线性关系
QLabel *heads[SERVANT_MAX+1];
QLabel *skills[SERVANT_MAX*3+1];
QSpinBox *levels[SERVANT_MAX*8+1];
QPushButton *deletes[SERVANT_MAX+1];
QCheckBox *breaks[SERVANT_MAX+1];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i=1;i<SERVANT_MAX;i++)
    {
        //各部件组初始化
        heads[i]=new QLabel(ui->scrollAreaWidgetContents);
        skills[3*i-2]=new QLabel(ui->scrollAreaWidgetContents);
        skills[3*i-1]=new QLabel(ui->scrollAreaWidgetContents);
        skills[3*i]=new QLabel(ui->scrollAreaWidgetContents);
        levels[i*8-7]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-6]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-5]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-4]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-3]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-2]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8-1]=new QSpinBox(ui->scrollAreaWidgetContents);
        levels[i*8]=new QSpinBox(ui->scrollAreaWidgetContents);
        deletes[i]=new QPushButton(ui->scrollAreaWidgetContents);
        breaks[i]=new QCheckBox(ui->scrollAreaWidgetContents);
        //设置技能设置条初始状态为隐藏
        heads[i]->setVisible(false);
        skills[3*i-2]->setVisible(false);
        skills[3*i-1]->setVisible(false);
        skills[3*i]->setVisible(false);
        levels[i*8-7]->setVisible(false);
        levels[i*8-6]->setVisible(false);
        levels[i*8-5]->setVisible(false);
        levels[i*8-4]->setVisible(false);
        levels[i*8-3]->setVisible(false);
        levels[i*8-2]->setVisible(false);
        levels[i*8-1]->setVisible(false);
        levels[i*8]->setVisible(false);
        deletes[i]->setVisible(false);
        breaks[i]->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

    //点击按钮后头像变暗函数
void MainWindow::image_dark(int id,QLabel *label){
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QImage *head = new QImage(buf);
    QImage *newhead=new QImage(head->width(),head->height(),QImage::Format_ARGB32);
    QColor oldColor;
    int r,g,b;
    for (int x=0;x<head->width();x++)
    {
        for (int y=0;y<head->height();y++)
        {
            oldColor=QColor(head->pixel(x,y));
    //将亮度降低为60%，并写入到新的QImage对象newhead
            r=oldColor.red()*0.6;
            g=oldColor.green()*0.6;
            b=oldColor.blue()*0.6;

            newhead->setPixel(x,y,qRgb(r,g,b));
        }
    }
    //将QImage对象newhead转化为QPixmap对象icon并作为pushbutton8的图标，实现点击后变暗
    QPixmap icon=QPixmap::fromImage(newhead->scaled(head->size(),Qt::KeepAspectRatio));
    QPushButton * button = (QPushButton *)sender();
    button->setIcon(icon);
    QPixmap heads;
    heads.load(buf);

    label->setPixmap(heads);

}

    //等级设置条生成函数
void MainWindow::showdetails(int id)
{
    //选择从者数+1，并将值赋给变量i，赋值的目的主要是为了缩短代码长度
    selected[0]=selected[0]+1;
    int i=selected[0];

    //将从者id与选择顺序相对应，即第i个选择的从者编号为id
    selected[id]=selected[0];

    //设定各个部件的左上顶点位置和尺寸，认为每个设置条的高度为130
    heads[id]->setGeometry(230,495+130*(i-1),100,100);
    skills[3*id-2]->setGeometry(640,485+130*(i-1),30,30);
    skills[3*id-1]->setGeometry(640,525+130*(i-1),30,30);
    skills[3*id]->setGeometry(640,565+130*(i-1),30,30);
    levels[id*8-7]->setGeometry(400,525+130*(i-1),60,30);
    levels[id*8-6]->setGeometry(490,525+130*(i-1),60,30);
    levels[id*8-5]->setGeometry(690,485+130*(i-1),60,30);
    levels[id*8-4]->setGeometry(690,525+130*(i-1),60,30);
    levels[id*8-3]->setGeometry(690,565+130*(i-1),60,30);
    levels[id*8-2]->setGeometry(780,485+130*(i-1),60,30);
    levels[id*8-1]->setGeometry(780,525+130*(i-1),60,30);
    levels[id*8]->setGeometry(780,565+130*(i-1),60,30);
    deletes[id]->setGeometry(900,515+130*(i-1),130,50);
    breaks[id]->setGeometry(430,565+130*(i-1),60,20);

    //设定所有部件可见
    heads[id]->setVisible(true);
    skills[3*id-2]->setVisible(true);
    skills[3*id-1]->setVisible(true);
    skills[3*id]->setVisible(true);
    levels[id*8-7]->setVisible(true);
    levels[id*8-6]->setVisible(true);
    levels[id*8-5]->setVisible(true);
    levels[id*8-4]->setVisible(true);
    levels[id*8-3]->setVisible(true);
    levels[id*8-2]->setVisible(true);
    levels[id*8-1]->setVisible(true);
    levels[id*8]->setVisible(true);
    deletes[id]->setVisible(true);
    breaks[id]->setVisible(true);

    //为4个label赋予图片
    //暗化图像整合成一个参数id=从者序号，buf为QString
    image_dark(id,heads[id]);

    //读取该从者对应的技能图标，这里打算采用数据库实现
    //也可以从头像按钮槽函数向showdetails函数传递技能图标序号
    QPixmap skill1,skill2,skill3;
    skill1.load(":/resource/skill/18.png");
    skill2.load(":/resource/skill/50.png");
    skill3.load(":/resource/skill/01.png");

    //将各label的图片调整到与label大小一致
    heads[id]->setScaledContents(true);
    skills[3*id-2]->setScaledContents(true);
    skills[3*id-1]->setScaledContents(true);
    skills[3*id]->setScaledContents(true);

    //在技能图标label中显示技能图标
    skills[3*id-2]->setPixmap(skill1);
    skills[3*id-1]->setPixmap(skill2);
    skills[3*id]->setPixmap(skill3);

    //为pushbutton和CheckBox设置文字
    deletes[id]->setText("Delete");
    breaks[id]->setText("break");

    //为8个spinbox赋初值，其中默认从者等级上限需要从数据库获得
    //也可以从头像按钮槽函数向showdetails函数传递从者星级
    levels[id*8-7]->setValue(1);
    levels[id*8-6]->setValue(90);
    levels[id*8-5]->setValue(1);
    levels[id*8-4]->setValue(1);
    levels[id*8-3]->setValue(1);
    levels[id*8-2]->setValue(10);
    levels[id*8-1]->setValue(10);
    levels[id*8]->setValue(10);

    //为各框设定最大值
    levels[id*8-7]->setMaximum(100);
    levels[id*8-6]->setMaximum(100);
    levels[id*8-5]->setMaximum(10);
    levels[id*8-4]->setMaximum(10);
    levels[id*8-3]->setMaximum(10);
    levels[id*8-2]->setMaximum(10);
    levels[id*8-1]->setMaximum(10);
    levels[id*8]->setMaximum(10);
}

    //删除从者函数
void MainWindow::remove(int id)
{
    //隐藏掉该id对应的等级设置条
    heads[id]->setVisible(false);
    skills[3*id-2]->setVisible(false);
    skills[3*id-1]->setVisible(false);
    skills[3*id]->setVisible(false);
    levels[id*8-7]->setVisible(false);
    levels[id*8-6]->setVisible(false);
    levels[id*8-5]->setVisible(false);
    levels[id*8-4]->setVisible(false);
    levels[id*8-3]->setVisible(false);
    levels[id*8-2]->setVisible(false);
    levels[id*8-1]->setVisible(false);
    levels[id*8]->setVisible(false);
    deletes[id]->setVisible(false);
    breaks[id]->setVisible(false);
    //选择从者数-1
    selected[0]=selected[0]-1;
}

    //重排
void MainWindow::reset(int id)
{
    //找到删除的从者对应的选择顺序并赋给i
    int i=selected[id];
    //将该id对应的从者头像按钮恢复可响应状态
    selected[id]=0;
    //比如删除的是第5个选择的从者，那么第一次循环时i=5，找到第6个选择的从者，将该从者的等级设置条移动到第5个的位置，并更新第6个从者的选择数据至5，以此类推
    for (;i<selected[0]+1;i++)
    {
        for (int j=1;j<SERVANT_MAX+1;j++)
        {
            if (selected[j]==i+1)
            {
                heads[j]->setGeometry(230,495+130*(i-1),100,100);
                skills[3*j-2]->setGeometry(640,485+130*(i-1),30,30);
                skills[3*j-1]->setGeometry(640,525+130*(i-1),30,30);
                skills[3*j]->setGeometry(640,565+130*(i-1),30,30);
                levels[j*8-7]->setGeometry(400,525+130*(i-1),60,30);
                levels[j*8-6]->setGeometry(490,525+130*(i-1),60,30);
                levels[j*8-5]->setGeometry(690,485+130*(i-1),60,30);
                levels[j*8-4]->setGeometry(690,525+130*(i-1),60,30);
                levels[j*8-3]->setGeometry(690,565+130*(i-1),60,30);
                levels[j*8-2]->setGeometry(780,485+130*(i-1),60,30);
                levels[j*8-1]->setGeometry(780,525+130*(i-1),60,30);
                levels[j*8]->setGeometry(780,565+130*(i-1),60,30);
                deletes[j]->setGeometry(900,515+130*(i-1),130,50);
                breaks[j]->setGeometry(430,565+130*(i-1),60,20);
                selected[j]=i;
//                ui->label->setText(ui->label->text()+";"+QString::number(j,10)+";");
            }
        }
    }

}

    //点击学妹
void MainWindow::on_servant_cal_001_clicked()
{
button_call((QPushButton *)sender(),1);
}

    //删除学妹
void MainWindow::delete1()
{
    int id = 1;
    remove(id);
    reset(id);
    //从者头像点亮
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QPixmap head;
    head.load(buf);
    ui->servant_cal_001->setIcon(head);
}

    //点击saber
void MainWindow::on_servant_cal_002_clicked()
{
    button_call((QPushButton *)sender(),2);
}

    //删除saber
void MainWindow::delete2()
{
    int id = 2;
    remove(id);
    reset(id);
    //从者头像点亮
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QPixmap head;
    head.load(buf);
    ui->servant_cal_002->setIcon(head);
}

    //点击吾王alter，剑阶
void MainWindow::on_servant_cal_003_clicked()
{
button_call((QPushButton *)sender(),3);
}

    //删除吾王alter，剑阶
void MainWindow::delete3()
{
    int id = 3;
    remove(id);
    reset(id);
    //从者头像点亮
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QPixmap head;
    head.load(buf);
    ui->N2V(003)->setIcon(head);
}

    //点击阿蒂拉0
void MainWindow::button_call(QPushButton *button,int id)
{
    //QPushButton *tmp;
   // tmp = (QPushButton *)sender();
    if (selected[id]==0)
    {
        showdetails(id);

        //将删除按钮与对应的槽函数绑定
        if (connection[id]==0)
        {
            connection[id]=1;
            connect(deletes[id],&QPushButton::clicked,this,[=]{delete_test(button,id);});
        }
    }

}
void MainWindow::on_servant_cal_008_clicked()
{
    button_call((QPushButton *)sender(),8);
}

    //删除阿蒂拉
void MainWindow::delete8()
{
    int id = 8;
    remove(id);
    reset(id);
    //从者头像点亮
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QPixmap head;
    head.load(buf);
    //QPushButton * button = (QPushButton *)sender();
    //button->setIcon(head);
    //this->
    ui->N2V(008)->setIcon(head);
}

void MainWindow::delete_test(QPushButton *recv,int id)
{
    //int id = 8;
    remove(id);
    reset(id);
    //从者头像点亮
    QString buf;
    buf.sprintf(":/resource/head/%03d.jpg",id);
    QPixmap head;
    head.load(buf);
   // QPushButton * button = (QPushButton *)sender();
    // QPushButton * button =(QPushButton *) this;
    recv->setIcon(head);
    //ui->servant_cal_008->setIcon(head);

}


void MainWindow::on_servant_cal_068_clicked()
{
    button_call((QPushButton *)sender(),68);
}


void MainWindow::on_servant_cal_076_clicked()
{
    button_call((QPushButton *)sender(),76);
}

void MainWindow::on_servant_cal_090_clicked()
{
    button_call((QPushButton *)sender(),90);
}

void MainWindow::on_servant_cal_091_clicked()
{
    button_call((QPushButton *)sender(),91);
}

void MainWindow::on_servant_cal_153_clicked()
{
    button_call((QPushButton *)sender(),153);
}

void MainWindow::on_servant_cal_160_clicked()
{
    button_call((QPushButton *)sender(),160);
}

void MainWindow::on_servant_cal_213_clicked()
{
    button_call((QPushButton *)sender(),213);
}

void MainWindow::on_servant_cal_004_clicked()
{
    button_call((QPushButton *)sender(),4);
}

void MainWindow::on_servant_cal_005_clicked()
{
    button_call((QPushButton *)sender(),5);
}

void MainWindow::on_servant_cal_006_clicked()
{
    button_call((QPushButton *)sender(),6);
}

void MainWindow::on_servant_cal_010_clicked()
{
    button_call((QPushButton *)sender(),10);
}

void MainWindow::on_servant_cal_101_clicked()
{
    button_call((QPushButton *)sender(),101);
}

void MainWindow::on_servant_cal_121_clicked()
{
    button_call((QPushButton *)sender(),121);
}

void MainWindow::on_servant_cal_123_clicked()
{
    button_call((QPushButton *)sender(),123);
}

void MainWindow::on_servant_cal_138_clicked()
{
    button_call((QPushButton *)sender(),138);
}

void MainWindow::on_servant_cal_176_clicked()
{
    button_call((QPushButton *)sender(),176);
}

void MainWindow::on_servant_cal_187_clicked()
{
    button_call((QPushButton *)sender(),187);
}

void MainWindow::on_servant_cal_221_clicked()
{
    button_call((QPushButton *)sender(),221);
}

void MainWindow::on_servant_cal_223_clicked()
{
    button_call((QPushButton *)sender(),223);
}

void MainWindow::on_servant_cal_227_clicked()
{
    button_call((QPushButton *)sender(),227);
}

void MainWindow::on_servant_cal_007_clicked()
{
    button_call((QPushButton *)sender(),7);
}

void MainWindow::on_servant_cal_009_clicked()
{
    button_call((QPushButton *)sender(),9);
}

void MainWindow::on_servant_cal_072_clicked()
{
    button_call((QPushButton *)sender(),72);
}

void MainWindow::on_servant_cal_126_clicked()
{
    button_call((QPushButton *)sender(),126);
}

void MainWindow::on_servant_cal_220_clicked()
{
    button_call((QPushButton *)sender(),220);
}

void MainWindow::on_servant_cal_166_clicked()
{
    button_call((QPushButton *)sender(),166);
}

void MainWindow::on_servant_cal_234_clicked()
{
    button_call((QPushButton *)sender(),234);
}

void MainWindow::on_servant_cal_165_clicked()
{
    button_call((QPushButton *)sender(),165);
}
