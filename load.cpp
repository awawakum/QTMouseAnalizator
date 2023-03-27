#include "load.h"

LoadDialog::LoadDialog( QWidget* parent ) : QFileDialog( parent )
{

}

void LoadDialog::set_FPath(){
    FPath = QFileDialog::getOpenFileName(0, "Выберите файл для чтения", "", "*.txt");
    QFile file(FPath);

    QVector <qp> loaded_vector;

    if (file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              if(line.contains('x')){
                loaded_vector.append(extractCords(line));
              }
           }
           file.close();
    }

    emit load_vector(loaded_vector);
}

qp LoadDialog::extractCords(const QString &s)
{
    qp Point;
    bool flag = false;
    QString num_x, num_y;
    int count = 0;
    int x = -1;
    int y = -1;
    foreach(QChar c, s) {

        if (c.isDigit()) {
            if (count == 0){
                flag = true;
                num_x.append(c);
            }
            if (count == 1){
                flag = true;
                num_y.append(c);
            }
        } else {
            flag = false;
        }

        if (flag == false && !num_x.isEmpty() && x==-1){
            count++;
            x = num_x.toInt();
        }

        if (flag == false && !num_y.isEmpty() && y==-1){
            count++;
            y = num_y.toInt();
        }

    }


    Point.pos = QPoint(num_x.toInt(),num_y.toInt());

    return Point;


}
