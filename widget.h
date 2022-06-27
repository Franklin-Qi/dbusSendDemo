#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 通过 session dbus 方式打开有线网络设置
    void setWiredSwitchEnable(bool enabled);

    // 通过命令方式打开设置的有线网络设置
    void openUkccNetwork();


private slots:
    void on_radioButton_clicked(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
