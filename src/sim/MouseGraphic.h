#pragma once

#include <QPair>
#include <QVector>

#include "Mouse.h"
#include "TriangleGraphic.h"
#include "units/Angle.h"
#include "units/Coordinate.h"

namespace mms {

class MouseGraphic {

public:

    MouseGraphic(const Mouse* mouse);

    Coordinate getInitialMouseTranslation() const;
    QPair<Coordinate, Angle> getCurrentMousePosition() const;

    QVector<TriangleGraphic> draw(
        const Coordinate& currentTranslation,
        const Angle& currentRotation) const;

private:

    const Mouse* m_mouse;

};

} 
