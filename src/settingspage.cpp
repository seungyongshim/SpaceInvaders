#include "settingspage.hpp"
#include "ui_settingspage.h"

#include "json/assertions.h"
#include "json/value.h"
#include "json/writer.h"
#include "json/json.h"
#include "json/config.h"

#include <QDebug>

#include "util.hpp"
#include "constants.hpp"

SettingsPage::SettingsPage(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SettingsPage)
{
  ui->setupUi(this);

  ui->comboBoxDifficulty->addItem("Easy", 1);
  ui->comboBoxDifficulty->addItem("Normal", 2);
  ui->comboBoxDifficulty->addItem("Hard", 3);

  ui->comboBoxSpeed->addItem("Speed 1", 1);
  ui->comboBoxSpeed->addItem("Speed 2", 2);
  ui->comboBoxSpeed->addItem("Speed 3", 3);

  connect(this, SIGNAL(moveToMenuPage()),
          parent, SLOT(moveToMenuPage()));

  ///
  /// It reads setting data from a file.
  ///
  /// If file doesn't exits or
  /// in case it contains wrong data it won't crash the app.
  ///
  try
  {
    Json::Value settings;

    settings = Util::ReadJson(Globals::SettingsFileName);

    int currentDifficulty = settings["Difficulty"].asInt();
    int currentSpeed = settings["Speed"].asInt();

    // Because it starts from 0.
    currentDifficulty--;
    currentSpeed--;

    // Set settings from the file if data is available.
    ui->comboBoxDifficulty->setCurrentIndex(currentDifficulty);
    ui->comboBoxSpeed->setCurrentIndex(currentSpeed);
  }
  catch(std::exception ex) {
    qDebug() << "Can't read settings from a file!";
  }
}

SettingsPage::~SettingsPage()
{
  delete ui;
}

void SettingsPage::on_menuButton_clicked()
{
  emit moveToMenuPage();
}

void SettingsPage::on_saveButton_clicked()
{
  int currentDifficulty = ui->comboBoxDifficulty->currentIndex();
  int currentSpeed = ui->comboBoxSpeed->currentIndex();

  // Because it starts from 0.
  currentDifficulty++;
  currentSpeed++;

  Json::Value settings = Util::ReadJson(Globals::SettingsFileName);

  settings["Difficulty"] = currentDifficulty;
  settings["Speed"] = currentSpeed;

  Util::WriteJson(Globals::SettingsFileName, settings);

  emit moveToMenuPage();
}
