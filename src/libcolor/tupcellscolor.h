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

#ifndef TUPCELLSCOLOR_H
#define TUPCELLSCOLOR_H

#include "tglobal.h"
#include "tcellview.h"
#include "tuppalettedocument.h"

#include <QFile>
#include <QDragEnterEvent>
#include <QMouseEvent>
#include <QDrag>
#include <QApplication>
#include <QPainter>
#include <QMimeData>
#include <QTextStream>

class TUPITUBE_EXPORT TupCellsColor : public TCellView
{
    Q_OBJECT

    public:
        enum Type{Color = 0, Gradient};
        TupCellsColor(QWidget *parent = nullptr, Type getType = Color);
        virtual ~TupCellsColor();

        void setReadOnly(bool enable);
        void setType(Type getType);
        bool isReadOnly();
        int getType();
        QString getName() const;
        void setName(const QString &getName);
        void save(const QString &path);

    protected:
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void dragEnterEvent(QDragEnterEvent *e);
        void dropEvent(QDropEvent *e);

    private:
        TupCellsColor::Type type;
        QString name;
        bool readOnly;
        QPoint startDragPosition;
};

#endif
