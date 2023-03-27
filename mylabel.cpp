#include "mylabel.h"
#include "string.h"


MyLabel::MyLabel(QWidget* parent)
{
    this->setText("Координаты курсора: \nx: 0\ny:0");
}

void MyLabel::set_text(const QPoint pos)
{
    std::string label_text = "Координаты курсора: \nx:";
    label_text += std::to_string(pos.x());
    label_text += " \ny:";
    label_text += std::to_string(pos.y());
    label_text += " \n";

    const QString s = QString::fromStdString(label_text);

    this->setText(s);
}
