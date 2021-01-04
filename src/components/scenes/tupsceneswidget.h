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

#ifndef TUPSCENESWIDGET_H
#define TUPSCENESWIDGET_H

#include "tglobal.h"
#include "tupmodulewidgetbase.h"
#include "tupsceneslist.h"
#include "treewidgetsearchline.h"
#include "tupprojectrequest.h"
#include "tupprojectactionbar.h"
#include "tuprequestbuilder.h"
#include "timagebutton.h"
#include "toptionaldialog.h"
#include "tconfig.h"

#include <QGroupBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QPixmap>
#include <QList>
#include <QTreeWidgetItem>
#include <QToolTip>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QToolButton>

class TupSceneResponse;

class TUPITUBE_EXPORT TupScenesWidget : public TupModuleWidgetBase
{
    Q_OBJECT

    public:
        TupScenesWidget(QWidget *parent = nullptr);
        ~TupScenesWidget();

    public slots:
        void closeAllScenes();

    private:
        void setupButtons();
        void setupTableScenes();

    private slots:
        void emitRequestInsertScene();
        void emitRequestRemoveScene();
        void renameObject(QTreeWidgetItem* item);
        void refreshItem(QTreeWidgetItem *item);

    protected:
        virtual void sceneResponse(TupSceneResponse *e);

    public slots:
        void sendEvent(int action);
        void selectScene(int index);

    private:
        QButtonGroup *buttonGroup;
        TupScenesList *scenesTable;

        bool renaming;
        QString oldId;
};

#endif
