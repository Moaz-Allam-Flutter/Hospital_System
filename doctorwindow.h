#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class DoctorWindow;
}

class DoctorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorWindow(QWidget *parent = nullptr);
    ~DoctorWindow();

private slots:
    void on_addSlotButton_clicked();
    void on_editSlotButton_clicked();
    void on_deleteSlotButton_clicked();
    void on_searchMedicalRecords_textChanged(const QString &text); // New slot for search

private:
    Ui::DoctorWindow *ui;

    // Initialize the tables
    void initializeAppointmentsTable();
    void initializeMedicalRecordsTable();
    void initializeSlotsTable();

    // Generate a random slot ID
    int generateRandomSlotId();

    // Save and load slots data from a file
    void saveSlotsToFile(const QString& filename);
    void loadSlotsFromFile(const QString& filename);

    // Save and load medical records data from a file
    void saveMedicalRecordsToFile(const QString& filename);
    void loadMedicalRecordsFromFile(const QString& filename);

    // Filter the medical records table based on search text
    void filterMedicalRecordsTable(const QString &searchText);
};

#endif // DOCTORWINDOW_H
