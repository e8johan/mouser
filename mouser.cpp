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

#include <QPaintEvent>
#include <QCursor>
#include <QTimer>
#include <QPainter>

#include "mouser.h"

Mouser::Mouser(int xoffset, int yoffset)
    : QWidget(nullptr, Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput)
    , m_xoffset(xoffset)
    , m_yoffset(yoffset)
{
    m_pointer = QPixmap(":/pointer.png");
    
    setAttribute(Qt::WA_TranslucentBackground);
    
    QTimer *t = new QTimer();
    connect(t, &QTimer::timeout, this, &Mouser::onPollMouse);
    t->setInterval(10);
    t->start();
}

QSize Mouser::sizeHint() const
{
    return m_pointer.size();
}

void Mouser::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    
    QPainter p(this);
    p.drawPixmap(0, 0, m_pointer);
}

void Mouser::onPollMouse()
{
    QPoint pos = QCursor::pos();
    move(pos.x()+m_xoffset, pos.y()+m_yoffset);
}
