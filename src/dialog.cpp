#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Keep this process running until Enter is pressed
    // std::cout << "Press Enter to quit..." << std::endl;
    // std::cin.get();

    ui->label_Init          ->setText   ( "Not Initialized..."      );
    ui->label_Connect       ->setText   ( "Not Connected"           );
    ui->label_serviceConnect->setText   ( "Service Disconnected.."  );

    ui->label_Relay->setText( "OFF" );

    // Signal connecting
    QObject::connect(  &listener,   SIGNAL  ( initializedSignal ()  ),
                        this,       SLOT    ( initializedSlot   ()  )   );

    QObject::connect(  &listener,   SIGNAL  ( connectedSignal ()    ),
                        this,       SLOT    ( connectedSlot   ()    )   );

    QObject::connect(  &listener,   SIGNAL  ( disconnectedSignal    () ),
                        this,       SLOT    ( disconnectedSlot      () ) );

    QObject::connect(  &listener,   SIGNAL  ( exitedSignal    () ),
                        this,       SLOT    ( exitedSlot      () ) );

    QObject::connect(  &listener,   SIGNAL  ( serviceConnectedSignal    () ),
                        this,       SLOT    ( serviceConnectedSlot      () ) );

    QObject::connect(  &listener,   SIGNAL  ( serviceDisconnectedSignal    () ),
                        this,       SLOT    ( serviceDisconnectedSlot      () ) );


    QObject::connect(  &listener,   SIGNAL  ( releySignal    (bool) ),
                        this,       SLOT    ( releySlot      (bool) ) );

    // Start Leap Thread
    this->listener.start();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initializedSlot()
{
    ui->label_Init->setText("Initilized !!!");
}

void Dialog::connectedSlot()
{
    ui->label_Connect->setText("Connected !!!");
}

void Dialog::disconnectedSlot()
{
    ui->label_Connect->setText("Not Connected");
}

void Dialog::exitedSlot()
{

}

void Dialog::serviceConnectedSlot()
{
    ui->label_serviceConnect->setText( "Service Connected !!!" );
}

void Dialog::serviceDisconnectedSlot( )
{
    ui->label_serviceConnect->setText( "Service Disconnected.." );
}

void Dialog::releySlot(bool state)
{
    if(state)
    {
        ui->label_Relay->setText( "ON" );
    }
    else
    {
        ui->label_Relay->setText( "OFF" );
    }
}
