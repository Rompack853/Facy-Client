#ifndef FRMOPTIONS_H
#define FRMOPTIONS_H

#include <QWidget>

namespace Ui {
class FrmOptions;
}

class FrmOptions : public QWidget
{
    Q_OBJECT

public:
    explicit FrmOptions(QWidget *parent = nullptr);
    ~FrmOptions();

private slots:
    void changeOptionPage(int page);

    void on_btnGeneral_clicked();

    void on_btnNetwork_clicked();

private:
    Ui::FrmOptions *ui;
};

#endif // FRMOPTIONS_H
