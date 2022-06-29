#pragma once

#include <QtWidgets/QMainWindow>

namespace Ui
{
    class Notepad;
} // namespace Ui

class Notepad : public QMainWindow
{
    Q_OBJECT

  public:
    explicit Notepad( QWidget * parent = 0 );
    ~Notepad();

  private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

  private:
    Ui::Notepad * ui;
    QString currentFile;
};
