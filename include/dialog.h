#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "simplelistener.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    // Initilize done
    void initializedSlot();

    // Connect done
    void connectedSlot();
    void disconnectedSlot();

    void exitedSlot();

    void serviceConnectedSlot();
    void serviceDisconnectedSlot();

    void releySlot(bool state);

private:
    Ui::Dialog *ui;

    // Create a sample listener and controller
    SampleListener  listener;
};

#endif // DIALOG_H
