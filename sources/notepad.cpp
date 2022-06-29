#include "notepad.hpp"
// #include "ui_notepad.hpp"

#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QtCore/QString>
#include <QtCore/QTextStream>
#include <QtGui/QFont>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QFontDialog>
#include <QtWidgets/QMessageBox>

#if defined( QT_PRINTSUPPORT_LIB )
    #include <QtPrintSupport/qtprintsupportglobal.h>
    #if QT_CONFIG( printer )
        #if QT_CONFIG( printdialog )
            #include <QPrintDialog>
        #endif // QT_CONFIG(printdialog)
        #include <QPrinter>
    #endif // QT_CONFIG(printer)
#endif // QT_PRINTSUPPORT_LIB

Notepad::Notepad( QWidget * parent )
  : QMainWindow( parent ), ui( new Ui::Notepad() )
{
    ui->setupUi( this );
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionNew_triggered()
{
    currentFile = "";
    ui->textEdit->setText( QString() );
    QMessageBox::information( this, "title", "Hello" );
}

void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName( this, "Open the file" );
    QFile file( fileName );
    currentFile = fileName;
    if ( ! file.open( QIODevice::ReadOnly | QFile::Text ) )
    {
        QMessageBox::warning( this,
                              "Warning",
                              "Cannot open file: " + file.errorString() );
        return;
    }
    setWindowTitle( fileName );
    QTextStream in( &file );
    QString text = in.readAll();
    ui->textEdit->setText( text );
    file.close();
}

void Notepad::on_actionSave_triggered()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if ( currentFile.isEmpty() )
    {
        fileName    = QFileDialog::getSaveFileName( this, "Save" );
        currentFile = fileName;
    }
    else
    {
        fileName = currentFile;
    }
    QFile file( fileName );
    if ( ! file.open( QIODevice::WriteOnly | QFile::Text ) )
    {
        QMessageBox::warning( this,
                              "Warning",
                              "Cannot save file: " + file.errorString() );
        return;
    }
    setWindowTitle( fileName );
    QTextStream out( &file );
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void Notepad::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName( this, "Save as" );
    QFile file( fileName );

    if ( ! file.open( QFile::WriteOnly | QFile::Text ) )
    {
        QMessageBox::warning( this,
                              "Warning",
                              "Cannot save file: " + file.errorString() );
        return;
    }
    currentFile = fileName;
    setWindowTitle( fileName );
    QTextStream out( &file );
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void Notepad::on_actionPrint_triggered()
{
    // #if QT_CONFIG( printer )
    //     QPrinter printDev;
    //     #if QT_CONFIG( printdialog )
    //     QPrintDialog dialog( &printDev, this );
    //     if ( dialog.exec() == QDialog::Rejected )
    //         return;
    //     #endif // QT_CONFIG(printdialog)
    //     ui->textEdit->print( &printDev );
    // #endif // QT_CONFIG(printer)
}

void Notepad::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void Notepad::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont( &fontSelected, this );
    if ( fontSelected )
        ui->textEdit->setFont( font );
}
