/*
 *  Mouser - a silly mouse pointer duplicator
 *  Copyright (C) 2018 Johan Thelin <e8johan@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include <QRandomGenerator>
#include "mouser.h"

const int randomAreaSizeX = 4000;
const int randomAreaSizeY = 2000;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    
    uint cursors = 1;
    if (argc == 2)
    {
        bool ok;
        uint t = app.arguments().last().toUInt(&ok);
        if (ok)
            cursors = t;
    }
    
    while(cursors-- > 0)
    {
        Mouser *m = new Mouser(QRandomGenerator::global()->bounded(0, randomAreaSizeX)-randomAreaSizeX/2, 
                               QRandomGenerator::global()->bounded(0, randomAreaSizeY)-randomAreaSizeY/2);
        m->show();
    }
    
    return app.exec();
}
