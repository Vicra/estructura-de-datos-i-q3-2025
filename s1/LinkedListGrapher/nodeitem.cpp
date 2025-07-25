#include "nodeitem.h"

NodeItem::NodeItem(const QString& val, bool isLast, QGraphicsItem* parent)
    : QGraphicsItem(parent), value(val), isLast(isLast) {}

QRectF NodeItem::boundingRect() const {
    return QRectF(0, 0, 120, 60); // Enough space for circle + arrow
}

void NodeItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    // Draw the circle (node)
    painter->setBrush(Qt::white);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawEllipse(0, 0, 40, 40);

    // Draw the value in center
    painter->setPen(Qt::black);
    painter->drawText(QRectF(0, 0, 40, 40), Qt::AlignCenter, value);

    // Draw arrow
    QLineF line(40, 20, 100, 20);
    painter->drawLine(line);

    // Draw arrowhead
    QPointF arrowP1 = line.p2() - QPointF(10, 5);
    QPointF arrowP2 = line.p2() - QPointF(10, -5);
    QPolygonF arrowHead;
    arrowHead << line.p2() << arrowP1 << arrowP2;
    painter->setBrush(Qt::black);
    painter->drawPolygon(arrowHead);

    // Draw "null"
    if(isLast)
        painter->drawText(QPointF(100, 15), "null");
}

void NodeItem::setIsLast(bool last) {
    isLast = last;
    update();
}

