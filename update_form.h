#ifndef UPDATE_FORM_H
#define UPDATE_FORM_H

#include <QDialog>
#include <string>

namespace Ui {
class UpdateForm;
}

class UpdateForm : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateForm(QWidget *parent = nullptr);
    ~UpdateForm();
    void setFilename(std::string filename);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::UpdateForm *ui;
    std::string filename;
};

#endif // UPDATE_FORM_H
