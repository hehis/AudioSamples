#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QXYSeries>
#include <QtCore/QIODevice>

QT_BEGIN_NAMESPACE
class QQuickView;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class DataSource : public QIODevice
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = 0);
    Q_INVOKABLE void setSeries(QAbstractSeries *series);

protected:
    qint64 readData(char * data, qint64 maxSize);
    qint64 writeData(const char * data, qint64 maxSize);

private:
    QXYSeries *m_series;
};


#endif // DATASOURCE_H
