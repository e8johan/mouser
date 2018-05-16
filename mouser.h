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

#ifndef MOUSER_H
#define MOUSER_H

#include <QWidget>

class Mouser : public QWidget
{
    Q_OBJECT
    
public:
    Mouser(int xoffset, int yoffset);
    
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;
    
private slots:
    void onPollMouse();
    
private:
    int m_xoffset, m_yoffset;
    QPixmap m_pointer;
};

#endif // MOUSER_H
