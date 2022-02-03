//Das ist die main von der uebung
#include<QtCore>
#include<QtGui>


class MainWindow :  public QWidget
{
  public:
  MainWindow();
};
// mit dem Befehl "new" wird der Speicher auf dem Heap belegt! 
MainWindow::MainWindow()
{
  setMinimumSize(1000, 600);

   //LineEdit_1, Spin, PushButton, slider, Progressbar, Spinbox
  QLineEdit *line_1 = new QLineEdit();
  line_1->setText("Zahlen von 0-999 können multipliziert werden!");
  line_1->setMaximumSize(300,35);


  //Hier werden Die SpinBoxen erstellt!
  QSpinBox *spin=new QSpinBox();
  spin->setRange(0,100);

  QSpinBox *spin_2 = new QSpinBox();
  spin_2->setRange(0,999);
  
  QSpinBox *spin_3 = new QSpinBox();
  spin_3->setRange(0,999);

  QSpinBox *spin_4 = new QSpinBox();
  spin_4->setRange(0,999999);

 //Hier werden die PushButton erstellt!
  QPushButton *pb_1 = new QPushButton();
  pb_1->setText("close");

  QPushButton *pb_2 = new QPushButton();
  pb_2->setText("Brechne");
 
 //Hier wird der Slider erstellt!
  QSlider *slider =new QSlider(Qt::Orientation::Horizontal);
  slider->setTickPosition(QSlider::TicksBothSides);
  slider->setTickInterval(10);
  slider->setSingleStep(1);
  slider->setRange(0,100);
  
  //Hier wird der ProgressBar erstellt!
  QProgressBar *Bar= new QProgressBar();
  Bar->setRange(0,100);
  
  //Hier wird der die "font" für die spinbox erstellt sodass die größer 
  // und ansprechender aussieht.
  QFont font = spin->font();
  font.setPointSize(15);
  spin->setFont(font);

  //Layout definition
  //###################################################################################
	QHBoxLayout *layout1 = new QHBoxLayout();
	layout1->addStretch();
  layout1->addWidget(slider);
  layout1->addStretch();

  QHBoxLayout *layout2 = new QHBoxLayout();
  layout2->addStretch();
  layout2->addWidget(Bar);
  layout2->addStretch();
  
  QHBoxLayout *layout3 = new QHBoxLayout();
  layout3->addStretch();
  layout3->addWidget(spin);
  layout3->addStretch();

  QHBoxLayout *layout4 = new QHBoxLayout();
  layout4->addStretch();
  layout4->addWidget(pb_1);
  layout4->addStretch();

  //die lineEdite
  QHBoxLayout *layout5 = new QHBoxLayout();
	layout5->addStretch();
  layout5->addWidget(line_1);
  layout5->addSpacing(50);
  layout5->addWidget(pb_2);
  layout5->addSpacing(50);
  layout5->addWidget(spin_4);
  layout5->addStretch();

  QHBoxLayout *layout6 = new QHBoxLayout();
  layout6->addStretch();
  layout6->addWidget(spin_2);
  layout6->addWidget(spin_3);
  layout6->addStretch();

//Hier fängt die MainBox an! 
  QVBoxLayout *MainBox = new QVBoxLayout(this);
  MainBox->addStretch();
  MainBox->addLayout(layout1);
  MainBox->addSpacing(100);
  MainBox->addLayout(layout2);
  MainBox->addSpacing(100);
  MainBox->addLayout(layout3);
  MainBox->addSpacing(100);
  MainBox->addLayout(layout5);
  MainBox->addSpacing(100);
  MainBox->addLayout(layout6);
  MainBox->addSpacing(50);
  MainBox->addLayout(layout4);

//hier folgen die Connect Befehle
//###################################################################################
//PushButton schließt das 
  QObject::connect(pb_1, &QPushButton::clicked, this 
    ,&QWidget::close);
//Slider,Bar, spin
  QObject::connect(slider, cs_mp_cast<int>(&QSlider::valueChanged), Bar 
    ,&QProgressBar::setValue);

  QObject::connect(Bar, cs_mp_cast<int>(&QProgressBar::valueChanged), spin
    ,&QSpinBox::setValue);

  QObject::connect(spin, cs_mp_cast<int>(&QSpinBox::valueChanged), slider 
    ,&QSlider::setValue);
//Hier folgt die verknüpfung zwischen dem "berechne " 
  QObject::connect(pb_2,&QPushButton::clicked, spin_4, [spin_2,spin_3,spin_4] () {
    spin_4->setValue((spin_2->value())*(spin_3->value()));
  });
}


int main(int argc, char *argv[]){

	QApplication app(argc, argv);


	MainWindow *window = new MainWindow();
	window->show();
	
	return app.exec();
}
