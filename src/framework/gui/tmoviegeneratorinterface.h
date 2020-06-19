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

#ifndef TMOVIEGENERATORINTERFACE_H
#define TMOVIEGENERATORINTERFACE_H

class T_GUI_EXPORT TMovieGeneratorInterface
{
    public:
        enum Format
             {
               NONE = 0,
               WEBM = 1 << 0,
               OGV  = 1 << 1,
               MP4  = 1 << 2,
               MPEG = 1 << 3,
               AVI  = 1 << 4,
               MOV  = 1 << 5,
               GIF  = 1 << 6
               // SQA: Obsolete formats 
               // SWF  = 1 << 2,
               // ASF  = 1 << 6,
             };

        Q_DECLARE_FLAGS(Formats, Format);

        virtual ~TMovieGeneratorInterface() {};
        virtual void nextFrame() = 0;
        virtual void reset() = 0;
        virtual bool validMovieHeader() = 0;
        virtual QString getErrorMsg() const = 0;

        void saveMovie(const QString &filename);

    protected:
        virtual void copyMovieFile(const QString &filename) = 0;
        virtual bool beginVideoFile() = 0;
        virtual void endVideoFile() = 0;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(TMovieGeneratorInterface::Formats);

#endif
