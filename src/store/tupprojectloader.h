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

#ifndef TUPPROJECTLOADER_H
#define TUPPROJECTLOADER_H

#include "tglobal.h"
#include "tuplibraryobject.h"

class TupProject;

class TUPITUBE_EXPORT TupProjectLoader
{
    public:
    	TupProjectLoader();
    	~TupProjectLoader();
    	
    	static void createItem(int sceneIndex, int layerIndex, int frameIndex, int itemPosition, QPointF point, 
                               TupLibraryObject::Type type, const QString &xml, TupProject *project);

    	static void createFrame(int sceneIndex, int layerIndex, int frameIndex, const QString &name, TupProject *project);
    	static void createLayer(int sceneIndex, int layerIndex, const QString &name, TupProject *project);

    	static void createSoundLayer(int sceneIndex, int layerIndex, const QString &name, TupProject *project);
    	
    	static void createScene(const QString &name, int sceneIndex, TupProject *project);
    	
    	static void createSymbol(TupLibraryObject::Type type, const QString &name, const QString &parent, const QByteArray &data, TupProject *project);
};

#endif
