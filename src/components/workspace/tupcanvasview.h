/***************************************************************************
 *   Project TUPITUBE DESK                                                *
 *   Project Contact: info@maefloresta.com                                 *
 *   Project Website: http://www.maefloresta.com                           *
 *   Project Leader: Gustav Gonzalez <info@maefloresta.com>                *
 *                                                                         *
 *   Developers:                                                           *
 *   2010:                                                                 *
 *    Gustavo Gonzalez                                                     *
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

#ifndef TUPCANVASVIEW_H
#define TUPCANVASVIEW_H

#include "tglobal.h"
#include "tupgraphicsscene.h"

#include <QGraphicsView>
#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QKeyEvent>

class TUPITUBE_EXPORT TupCanvasView : public QGraphicsView
{
    Q_OBJECT

    public:
        TupCanvasView(QWidget *parent=0, TupGraphicsScene *scene=0, const QSize &screenSize = QSize(0, 0), 
                      const QSize &projectSize = QSize(0, 0), const QColor &bg = QColor(Qt::white));
        ~TupCanvasView();

    protected:
        virtual void drawBackground(QPainter *painter, const QRectF &rect);
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void keyPressEvent(QKeyEvent *event);
        virtual void keyReleaseEvent(QKeyEvent *event);

    signals:
        void rightClick();
        void zoomIn();
        void zoomOut();
        void frameBackward();
        void frameForward();
        // void callForPlugin(int menu, int index);

    private:
        void updateCenter(const QPoint point);

        TupGraphicsScene *scene;
        QSize screenSize;
        QSize projectSize;
        QColor bg;
        bool spaceBar;
        QRectF drawingRect;

        QPoint initPoint;
        QPoint centerPoint;
};

#endif
