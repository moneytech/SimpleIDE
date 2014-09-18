/*
 * This file is part of the Parallax Propeller SimpleIDE development environment.
 *
 * Copyright (C) 2014 Parallax Incorporated
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QPORTCOMBOBOX_H
#define QPORTCOMBOBOX_H

/*
 * This class is used to overload QComboBox so we can click on the combo-box for enumerating ports.
 */
#include <QComboBox>

class QPortComboBox : public QComboBox
{
Q_OBJECT
public:

    QPortComboBox(QWidget *w)
        : QComboBox(w)
    {
    }
    virtual ~QPortComboBox()
    {
    }

    void mousePressEvent(QMouseEvent * event) {
        // emit before handling rest of event otherwise bad things can happen!
        emit clicked();
        QComboBox::mousePressEvent(event);
    }

signals:
    void clicked();

};

#endif // QPORTCOMBOBOX_H
