#ifndef NODEITEM_H
#define NODEITEM_H

// NodeItem.h
#include <QGraphicsItem>
#include <QPainter>
#include <QString>

class NodeItem : public QGraphicsItem {
public:
    NodeItem(const QString& value, bool isLast, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void setIsLast(bool last);
private:
    QString value;
    bool isLast;
};

#endif // NODEITEM_H
