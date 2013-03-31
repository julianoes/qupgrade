#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}
class QTimer;
class QextSerialPort;
class QextSerialEnumerator;
class QGCFirmwareUpgradeWorker;
class QNetworkRequest;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void filenameSet(QString filename);

protected:
    void changeEvent(QEvent *e);

public slots:
    void onPortAddedOrRemoved();
    void onLoadFinished(bool success);
    void onDownloadProgress(qint64 curr, qint64 total);

private slots:
    void onPortNameChanged(const QString &name);
    void onUploadButtonClicked();
    void onDownloadFinished();
    void onDownloadRequested(const QNetworkRequest &request);
    void onHomeRequested();
    void onLinkClicked(const QUrl&);

private:
    bool loading;
    Ui::Dialog *ui;
    QTimer *timer;
    QextSerialPort *port;
    QextSerialEnumerator *enumerator;
    QGCFirmwareUpgradeWorker *worker;

    QString lastFilename;
};

#endif // DIALOG_H
