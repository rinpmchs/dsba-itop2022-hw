#ifndef CUISINES_H
#define CUISINES_H

#include <QDialog>

namespace Ui {
class Cuisines;
}

class Cuisines : public QDialog
{
    Q_OBJECT

public:
    explicit Cuisines(QWidget *parent = nullptr);
    ~Cuisines();

private slots:
    void on_pushButton_close_clicked();

private:
    Ui::Cuisines *ui;
};

#endif // CUISINES_H




//<widget class="QListWidget" name="listWidget">
// <item>
//  <property name="text">
//   <string>African</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Andhra</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Asian</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Bengali Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Chettinad</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Chinese</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Coactal Karnataka</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Continental</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Coorg</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>European</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>French</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Fusion</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Goan Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Himachal</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Hyderabadi</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Indo Chinese</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Italian Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Karnataka</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Kashmiri</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Kerala Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Konkan</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Maharashtrian Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Malvani</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Mangalorean</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Mediterranean</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Mexican</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Middle Eastern</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Mughlai</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>North Indian Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Punjai</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>South Indian Recipes</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Tamil Nadu</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Thai</string>
//  </property>
// </item>
// <item>
//  <property name="text">
//   <string>Udupi</string>
//  </property>
// </item>
//</widget>
