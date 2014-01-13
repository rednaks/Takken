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

#include "mainWindow.h"
#include "abstractWidget.h"

AbstractWidget::AbstractWidget(MainWindow *aParent){

	this->parent = aParent;
	mAboutPushButton = new QPushButton("About");

	/* TODO 
	 * Adding a function to load the description into |mDoc|
	 * right now, |mDoc| is set in the child class' constructor.
	 */

	/* Connection |mAboutPushButton| to |aboutClicked| */
	connect(mAboutPushButton, SIGNAL(clicked()), this, SLOT(aboutClicked()));

}

AbstractWidget::~AbstractWidget(){
	delete mAboutPushButton;
}

void AbstractWidget::aboutClicked() const {

	// Set mDoc as actual text to the splash screen
	this->parent->setSplashText(*mDoc);
	
	// If the Splash is visible, we hide it, if not we show it.
  if(this->parent->splashIsVisible())
    this->parent->hideSplash();
  else
    this->parent->showSplash();

}
