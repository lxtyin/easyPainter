//
// 此代码来源开源社区 并非本人实现，不作为考核参考。
//

#include "ColorPicker.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>

ColorHueBar::ColorHueBar(QWidget *parent)
        : QWidget(parent)
{
    m_slider = new QSlider(this);
    m_slider->setMaximum(359);
    m_slider->setFixedWidth(16);
    m_slider->setStyleSheet("QSlider::groove:vertical {width: 12px; \
                                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \
                                    stop:0 hsv(0,255,255), \
                                    stop:0.17 hsv(59,255,255), \
                                    stop:0.33 hsv(119,255,255), \
                                    stop:0.5 hsv(179,255,255), \
                                    stop:0.67 hsv(239,255,255), \
                                    stop:0.83 hsv(299,255,255), \
                                    stop:1 hsv(359,255,255));} \
                            QSlider::handle:vertical { \
                                background: white; \
                                height: 4px; \
                                margin:0px -2px; \
                                border: 1px solid grey; \
                                border-radius: 2px;} \
                            QSlider::add-page:vertical {background: transparent;} \
                            QSlider::sub-page:vertical {background: transparent;}");
    setValue(0);
    connect(m_slider, &QSlider::valueChanged, this, [this]{
        emit sig_valueChanged(value());
    });

    auto mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(m_slider);
}

ColorHueBar::~ColorHueBar()
{

}

void ColorHueBar::setValue(int val)
{
    m_slider->setValue(qAbs(val - m_slider->maximum()));
}

int ColorHueBar::value()
{
    return qAbs(m_slider->value() - m_slider->maximum());
}

ColorSVCanvas::ColorSVCanvas(QWidget *parent)
        : QWidget(parent)
        , m_margin(5)
        , m_radius(m_margin - 1)
        , m_saturationMax(255)
        , m_valueMax(255)
        , m_hue(0)
        , m_pos(QPoint(-1, -1))
{
    installEventFilter(this);
}

ColorSVCanvas::~ColorSVCanvas()
{

}

bool ColorSVCanvas::setHue(int hue)
{
    if(hue < 0 || hue > 359)
        return false;

    m_hue = hue;

    update();
    emit sig_colorChanged(color());

    return true;
}

bool ColorSVCanvas::setSaturationValue(int saturation, int value)
{
    return setSaturationValue(QPoint(saturation, value));
}

bool ColorSVCanvas::setSaturationValue(QPoint saturationValue)
{
    if(!QRect(0,0,256,256).contains(saturationValue))
        return false;

    m_pos = posFromValue(saturationValue);

    update();
    emit sig_colorChanged(color());

    return true;
}

QColor ColorSVCanvas::color()
{
    QPoint tmpVal = valueFromPos(m_pos);
    QColor tmpColor;
    tmpColor.setHsv(m_hue, tmpVal.x(), tmpVal.y());
    return tmpColor;
}

QRect ColorSVCanvas::availabilityRect()
{
    QRect tmpRect(m_margin, m_margin, width() - m_margin * 2, height() - m_margin * 2);
    return tmpRect;
}

int ColorSVCanvas::margin()
{
    return m_margin;
}

void ColorSVCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect = availabilityRect();

    // 绘制从左到右RGB(255,255,255)到HSV(h,255,255)的渐变
    QLinearGradient linearGradientH(rect.topLeft(), rect.topRight());
    linearGradientH.setColorAt(0, Qt::white);
    QColor color;
    color.setHsv(m_hue, m_saturationMax, m_valueMax);
    linearGradientH.setColorAt(1, color);
    painter.fillRect(rect, linearGradientH);

    // 绘制顶部颜色值为RGBA(0,0,0,0)到最底部RGBA(0,0,0,255)的渐变
    QLinearGradient linearGradientV(rect.topLeft(), rect.bottomLeft());
    linearGradientV.setColorAt(0, QColor(0, 0, 0, 0));
    linearGradientV.setColorAt(1, QColor(0, 0, 0, 255));
    painter.fillRect(rect, linearGradientV);

    painter.setPen(QColor(Qt::darkGray));
    painter.drawEllipse(m_pos, m_radius, m_radius);
}

void ColorSVCanvas::resizeEvent(QResizeEvent *)
{
    if(m_pos == QPoint(-1, -1)){
        setSaturationValue(255, 255);
    }
}

bool ColorSVCanvas::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == this){
        if(ev->type() == QEvent::MouseMove || ev->type() == QEvent::MouseButtonPress){
            if(dynamic_cast<QMouseEvent*>(ev)->buttons() & Qt::LeftButton){
                if(availabilityRect().contains(mapFromGlobal(QCursor::pos()))){
                    m_pos = mapFromGlobal(QCursor::pos());
                    update();
                    emit sig_colorChanged(color());
                }
            }
        }
    }
    return QWidget::eventFilter(obj, ev);
}

QPoint ColorSVCanvas::valueFromPos(QPoint &pos)
{
    QRect tmpRect = availabilityRect();

    QPoint tmpPos = pos - tmpRect.topLeft();
    int saturation = tmpPos.x() * m_saturationMax / tmpRect.width();
    int value = qAbs(tmpPos.y() * m_valueMax / tmpRect.height() - m_valueMax);

    return QPoint(saturation, value);
}

QPoint ColorSVCanvas::posFromValue(QPoint &val)
{
    QRect tmpRect = availabilityRect();

    int tmpX = val.x() * tmpRect.width() / m_saturationMax;
    int tmpY = qAbs(val.y() - m_valueMax) * tmpRect.height() / m_valueMax;

    return QPoint(tmpX, tmpY) + tmpRect.topLeft();
}

ColorChecker::ColorChecker(QWidget *parent)
        : QWidget(parent)
        , m_checkerSize(6)
{

}

ColorChecker::~ColorChecker()
{

}

void ColorChecker::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int rowCount = ev->rect().height() / m_checkerSize + 1;
    int colCount = ev->rect().width() / m_checkerSize + 1;

    for(int i=0; i < rowCount; i++){
        for(int j=0; j < colCount; j++){
            QRect checkerRect(m_checkerSize * j, m_checkerSize * i, m_checkerSize, m_checkerSize);

            QColor checkerColor;
            if(((j + i % 2) % 2) == 0){
                checkerColor = Qt::darkGray;
            }else{
                checkerColor = Qt::white;
            }
            painter.fillRect(checkerRect, checkerColor);
        }
    }
}

ColorAlphaBar::ColorAlphaBar(QWidget *parent)
        : QWidget(parent)
        , m_grooveHeight(12)
{
    m_checker = new ColorChecker(this);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setMaximum(255);
    m_slider->setValue(m_slider->maximum());
    m_slider->setFixedHeight(16);
    setColor(Qt::red);

    connect(m_slider, &QSlider::valueChanged, this, [this]{
        emit sig_colorChanged(color());
    });

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(m_slider);
}

ColorAlphaBar::~ColorAlphaBar()
{

}

void ColorAlphaBar::setColor(QColor oriColor)
{
    m_color = oriColor;
    m_color.setAlpha(255);

    QColor tmpColor(oriColor);
    tmpColor.setAlpha(0);

    m_slider->setStyleSheet(QString("QSlider::groove:horizontal { \
                                        height: %3px; \
                                        background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \
                                        stop:0 %1, \
                                        stop:1 %2);} \
                                    QSlider::handle:horizontal { \
                                        background: white; \
                                        width: 4px; \
                                        margin: -2px 0; \
                                        border: 1px solid grey; \
                                        border-radius: 2px;} \
                                    QSlider::add-page:horizontal {background: transparent;} \
                                    QSlider::sub-page:horizontal {background: transparent;}")
                                    .arg(tmpColor.name(QColor::HexArgb))
                                    .arg(m_color.name())
                                    .arg(m_grooveHeight));

    emit sig_colorChanged(color());
}

QColor ColorAlphaBar::color()
{
    QColor tmpColor(m_color);
    tmpColor.setAlpha(m_slider->value());
    return tmpColor;
}

void ColorAlphaBar::setValue(int alpha)
{
    m_slider->setValue(alpha);
}

void ColorAlphaBar::resizeEvent(QResizeEvent *)
{
    m_checker->setGeometry(0, (height() - m_grooveHeight) / 2, width(), m_grooveHeight);
}

ColorPickDialog::ColorPickDialog(QWidget *parent)
        : QDialog(parent, Qt::Popup)
{
    setFixedSize(320, 250);
    setAttribute(Qt::WA_StyledBackground);
    setObjectName("workbench");
    setStyleSheet("#workbench{background-color:white; border:1px solid rgb(245,245,245); border-radius: 6px;}");

    m_canvas = new ColorSVCanvas(this);
    m_canvas->setFixedSize(280, 180);

    m_hsvBar = new ColorHueBar(this);
    m_hsvBar->setFixedHeight(m_canvas->availabilityRect().height());

    m_alphaSlider = new ColorAlphaBar(this);
    m_alphaSlider->setFixedWidth(m_canvas->availabilityRect().width());

    m_lineEdit = new QLineEdit(this);

    m_clearBtn = new QPushButton("clear",this);
    m_clearBtn->setVisible(false);

    m_confirmBtn = new QPushButton("confirm", this);
    connect(m_confirmBtn, &QPushButton::clicked, this, [this]{
        accept();
    });

    connect(m_hsvBar, &ColorHueBar::sig_valueChanged, this, [this](int val){
        m_canvas->setHue(val);
    });
    connect(m_canvas, &ColorSVCanvas::sig_colorChanged, this, [this](const QColor &color){
        m_alphaSlider->setColor(color);
    });
    connect(m_alphaSlider, &ColorAlphaBar::sig_colorChanged, this, &ColorPickDialog::slot_colorDisplay);
    connect(m_lineEdit, &QLineEdit::textEdited, this, &ColorPickDialog::slot_colorEdit);

    // 布局
    auto handleLayout = new QHBoxLayout;
    handleLayout->addSpacing(m_canvas->margin());
    handleLayout->addWidget(m_lineEdit);
    handleLayout->addStretch();
    handleLayout->addWidget(m_clearBtn);
    handleLayout->addWidget(m_confirmBtn);

    auto alphaLayout = new QHBoxLayout;
    alphaLayout->setMargin(0);
    alphaLayout->addSpacing(m_canvas->margin());
    alphaLayout->addWidget(m_alphaSlider);

    auto mainLayout = new QGridLayout(this);
    mainLayout->addWidget(m_canvas, 0, 0);
    mainLayout->addWidget(m_hsvBar, 0, 1);
    mainLayout->addLayout(alphaLayout, 1, 0);
    mainLayout->addLayout(handleLayout, 2, 0, 1, 2);
}

ColorPickDialog::~ColorPickDialog()
{

}

void ColorPickDialog::setColor(QColor color)
{
    m_hsvBar->setValue(color.hsvHue());
    m_canvas->setSaturationValue(color.hsvSaturation(), color.value());
    m_alphaSlider->setValue(color.alpha());
}

QColor ColorPickDialog::colorFromStr(QString str)
{
    QColor color(str);
    if(!color.isValid()){
        QString tmpStr = str;
        QRegExp rx("[^\\d+^,^.]");
        if(str.contains(rx)){
            tmpStr.remove(rx);
        }
        if(!tmpStr.isEmpty()){
            QStringList strList = tmpStr.split(",");
            if(str.contains("rgba") && strList.count() == 4){
                color.setRgb(strList.at(0).toInt(), strList.at(1).toInt(), strList.at(2).toInt());
                if(strList.at(3).toDouble()>1){
                    color.setAlpha(strList.at(3).toInt());
                }else{
                    color.setAlphaF(strList.at(3).toDouble());
                }
            }
            else if(str.contains("rgb") && strList.count() == 3){
                color.setRgb(strList.at(0).toInt(), strList.at(1).toInt(), strList.at(2).toInt());
            }
            else if(str.contains("hsv") && strList.count() == 3){
                color.setHsv(strList.at(0).toInt(), strList.at(1).toInt(), strList.at(2).toInt());
            }
        }
    }

    return color;
}

void ColorPickDialog::slot_colorDisplay(const QColor& color)
{
    QRegExp reg("(\\.){0,1}0+$");// 去除末尾0
    m_lineEdit->setText(QString("rgba(%1, %2, %3, %4)")
                                .arg(color.red())
                                .arg(color.green())
                                .arg(color.blue())
                                .arg(QString::number(color.alphaF(), 'f', 2).replace(reg, "")));

    emit sig_colorChanged(color);
}

void ColorPickDialog::slot_colorEdit(const QString &text)
{
    QColor color = colorFromStr(text);
    if(color.isValid()){
        disconnect(m_alphaSlider, &ColorAlphaBar::sig_colorChanged, this, &ColorPickDialog::slot_colorDisplay);
        setColor(color);
        connect(m_alphaSlider, &ColorAlphaBar::sig_colorChanged, this, &ColorPickDialog::slot_colorDisplay);

        emit sig_colorChanged(color);
    }
}

//ColorWidget::ColorWidget(QWidget *parent)
//        : QLabel(parent)
//{
//    m_checker = new ColorChecker(this);
//
//    m_popup = new ColorPickDialog(this);
//    connect(m_popup, &ColorPickDialog::sig_colorChanged, this, &ColorWidget::slot_colorChanged);
//    connect(m_popup, &QDialog::finished, this, [this](int result){
//        if(result == QDialog::Accepted){
//            m_oriColor = m_curColor;
//        }
//        else{
//            setColor(m_oriColor);
//        }
//    });
//
//    m_button = new QPushButton("", this);
//    connect(m_button, &QPushButton::pressed, this, &ColorWidget::slot_showPopup);
//
//    setStyleSheet(QString("QLabel{border:1px solid %1; border-radius: 4px; background-color: %2;}")
//                          .arg(QColor(230, 230, 230).name())
//                          .arg(QColor(Qt::white).name()));
//    setColor(QColor(255,0,0,150));
//
//    auto mainLayout = new QHBoxLayout(this);
//    mainLayout->setMargin(0);
//    mainLayout->addWidget(m_button);
//}
//
//ColorWidget::~ColorWidget()
//{
//
//}
//
//void ColorWidget::resizeEvent(QResizeEvent *)
//{
//    m_checker->setGeometry(geometry());
//    m_button->setGeometry(geometry());
//}
//
//void ColorWidget::setColor(const QColor &color)
//{
//    m_curColor = color;
//    m_button->setStyleSheet(QString("QPushButton{border:1px solid %1; background-color:%2}")
//                                    .arg(QColor(152,152,152).name())
//                                    .arg(color.name(QColor::HexArgb)));
//}
//
//void ColorWidget::slot_showPopup()
//{
//    m_oriColor = m_curColor;
//    m_popup->setColor(m_oriColor);
//
//    QPoint tmpPos = mapToGlobal(m_button->geometry().center());
//    tmpPos += QPoint(-m_popup->width() / 2, m_button->height() / 2 + 5);
//    m_popup->move(tmpPos);
//
//    m_popup->open();
//}
//
//void ColorWidget::slot_colorChanged(const QColor &color)
//{
//    if (m_popup->isVisible()) {
//        setColor(color);
//    }
//}

