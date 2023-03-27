#include "history.h"
#include "string.h"


HistoryLabel::HistoryLabel(QWidget* parent)
{
    this->setText("История перемещений курсора: ");
}


void HistoryLabel::set_text(QVector<qp> history)
{
    std::string label_text = "История перемещений курсора: ";

    for (auto i : history) {
        label_text += "\nx: ";
        label_text += std::to_string(i.pos.x());
        label_text += " y: ";
        label_text += std::to_string(i.pos.y());
        label_text += "\n ";
    }
    const QString s = QString::fromStdString(label_text);
    this->setText(s);
    emit vector_changed(s);
}


QString HistoryLabel::get_vector(){
    return this->text();
}


void HistoryLabel::clear_field(){
    this -> setText("История перемещений курсора: ");
}
