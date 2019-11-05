#ifndef HISTORYFORM_H
#define HISTORYFORM_H

#include <QWidget>
#include <QTimer>
#include <QSqlQueryModel>
#include <QSqlTableModel>

namespace Ui {
class HistoryForm;
}

class HistoryForm : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryForm(QWidget *parent = nullptr);
    ~HistoryForm();

private:
    Ui::HistoryForm *ui;
    QSqlQueryModel *m_model;

private slots:
    void onUpdateModel();
};

#endif // HISTORYFORM_H
