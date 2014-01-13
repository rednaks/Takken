/**
 * This file is under MIT Licence
 * Copyright (C) 2014 Alexandre BM <s@rednaks.tn>
 *   
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *   
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *   
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef ABSTRACT_WIDGET_H
#define ABSTRACT_WIDGET_H


#include <QtGui>

class MainWindow;


/*
 * This is an abstract base class for all widgets.
 * If you are going to create a new widget you have to inherit from this one.
 * Please follow the instructions to see how you should properly implement the
 * virtual methods.
 */


class AbstractWidget: public QWidget {
	Q_OBJECT


	public:
		AbstractWidget(MainWindow* =0);
		virtual ~AbstractWidget();


	public slots:
		/* 
		 * This slot should be connected to any input (QSlider, QLineEdit, 
		 * QSpinBox, ...) to handle the |valueChanged| signal.
		 * When you will implement this method make sure you update the labels 
		 * of these inputs, then after processing the image, update it via : 
		 * |MainWindow::updateImage()|.
		 */
		virtual void updateVal(int) = 0;
		
		/*
		 * Slot connected to |mAboutPushButton| to handle the |clicked| signal.
		 * The prurpose of this slot is to display a description of the algorithm 
		 * used to process the image.
		 */
		virtual void aboutClicked() const;

	private:
		QString *mDoc;
		QPushButton *mAboutPushButton;
		MainWindow *parent;

};

#endif
