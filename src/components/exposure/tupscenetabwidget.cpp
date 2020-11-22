/***************************************************************************
 *   Project TUPITUBE DESK                                                *
 *   Project Contact: info@maefloresta.com                                 *
 *   Project Website: http://www.maefloresta.com                           *
 *   Project Leader: Gustav Gonzalez <info@maefloresta.com>                *
 *                                                                         *
 *   Developers:                                                           *
 *   2010:                                                                 *
 *    Gustavo Gonzalez / xtingray                                          *
 *                                                                         *
 *   KTooN's versions:                                                     * 
 *                                                                         *
 *   2006:                                                                 *
 *    David Cuadrado                                                       *
 *    Jorge Cuadrado                                                       *
 *   2003:                                                                 *
 *    Fernado Roldan                                                       *
 *    Simena Dinas                                                         *
 *                                                                         *
 *   Copyright (C) 2010 Gustav Gonzalez - http://www.maefloresta.com       *
 *   License:                                                              *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#include "tupscenetabwidget.h"
#include "timagebutton.h"

TupSceneTabWidget::TupSceneTabWidget(QWidget *parent) : QFrame(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(1);

    tabber = new QTabWidget;
    connect(tabber, SIGNAL(currentChanged(int)), this, SIGNAL(currentChanged(int)));
    layout->addWidget(tabber);

    setLayout(layout);
}

TupSceneTabWidget::~TupSceneTabWidget()
{
    tables.clear();
    undoTables.clear();
    // opacityControl.clear();
    // undoOpacities.clear();

    delete tabber;
}

void TupSceneTabWidget::removeAllTabs()
{
    int count = tabber->count();
    for (int i = 0; i < count; i++)
         delete tabber->currentWidget();

    tables.clear();
    // opacityControl.clear();
}

void TupSceneTabWidget::addScene(int index, const QString &name, TupExposureTable *table) 
{
    QFrame *frame = new QFrame;
    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->setMargin(1);

    QHBoxLayout *toolsLayout = new QHBoxLayout;
    toolsLayout->setAlignment(Qt::AlignHCenter);

    QLabel *header = new QLabel();
    QPixmap pix(THEME_DIR + "icons/layer_opacity.png");
    header->setToolTip(tr("Current Layer Opacity"));
    header->setPixmap(pix);

    QDoubleSpinBox *opacitySpinBox = new QDoubleSpinBox(this);
    opacitySpinBox->setRange(0.1, 1.0);
    opacitySpinBox->setSingleStep(0.1);
    opacitySpinBox->setValue(1.0);
    opacitySpinBox->setToolTip(tr("Current Layer Opacity"));
    connect(opacitySpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(layerOpacityChanged(double)));

    opacityControl << opacitySpinBox;

    toolsLayout->addWidget(header);
    toolsLayout->addWidget(opacitySpinBox);

    layout->addLayout(toolsLayout);
    layout->addWidget(table);
    frame->setLayout(layout);

    tables.insert(index, table);
    tabber->insertTab(index, frame, name);
}

void TupSceneTabWidget::restoreScene(int index, const QString &name)
{
    QFrame *frame = new QFrame;
    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->setMargin(1);

    QHBoxLayout *toolsLayout = new QHBoxLayout;
    toolsLayout->setAlignment(Qt::AlignHCenter);

    QLabel *header = new QLabel();
    QPixmap pix(THEME_DIR + "icons/layer_opacity.png");
    header->setToolTip(tr("Current Layer Opacity"));
    header->setPixmap(pix);

    TupExposureTable *table = undoTables.takeLast();
    QDoubleSpinBox *opacitySpinBox = undoOpacities.takeLast();
    opacityControl << opacitySpinBox;

    toolsLayout->addWidget(header);
    toolsLayout->addWidget(opacitySpinBox);

    layout->addLayout(toolsLayout);
    layout->addWidget(table);
    frame->setLayout(layout);

    tables.insert(index, table);
    tabber->insertTab(index, frame, name);
}

void TupSceneTabWidget::removeScene(int index, bool withBackup) 
{
    if (withBackup) {
        undoTables << tables.takeAt(index);
        undoOpacities << opacityControl.takeAt(index);
    } else {
        tables.takeAt(index);
    }

    blockSignals(true);
    tabber->removeTab(index);
    blockSignals(false);
}

/*
void TupSceneTabWidget::removeCleanScene(int index)
{
    tables.takeAt(index);
    blockSignals(true);
    tabber->removeTab(index);
    blockSignals(false);
}
*/

void TupSceneTabWidget::renameScene(int index, const QString &name)
{
    tabber->setTabText(index, name);
}

TupExposureTable* TupSceneTabWidget::getCurrentTable() 
{
    int index = currentIndex();
    return getTable(index);
}

TupExposureTable* TupSceneTabWidget::getTable(int index)
{
    if (isTableIndexValid(index)) {
        TupExposureTable *table = tables.at(index);

        if (table) {
            return table;
        } else {
            #ifdef TUP_DEBUG
                qDebug() << "[TupSceneTabWidget::getTable()] - Fatal Error: Table pointer is NULL!";
            #endif
        }
    }

    #ifdef TUP_DEBUG
        qDebug() << "[TupSceneTabWidget::getTable()] - Fatal Error: Invalid table index: " << index;
    #endif

    return 0;
}

void TupSceneTabWidget::setCurrentIndex(int index)
{
    tabber->setCurrentIndex(index);
}

int TupSceneTabWidget::currentIndex()
{
    int index = tabber->currentIndex();
    return index;
}

bool TupSceneTabWidget::isTableIndexValid(int index)
{
    if (index > -1 && index < tables.count())
        return true;

    return false;
}

int TupSceneTabWidget::count()
{
    return tables.count();
}

void TupSceneTabWidget::setLayerOpacity(int sceneIndex, double opacity)
{
    opacityControl.at(sceneIndex)->setValue(opacity);
}

void TupSceneTabWidget::setLayerVisibility(int sceneIndex, int layerIndex, bool visibility)
{
    if (isTableIndexValid(sceneIndex)) {
        TupExposureTable *table = tables.at(sceneIndex);
        table->setLayerVisibility(layerIndex, visibility);
    } else {
        #ifdef TUP_DEBUG
            qDebug() << "[TupSceneTabWidget::setLayerVisibility()] - Fatal Error: Invalid table index: " << sceneIndex;
        #endif
    }
}
