#include "MyRadioButton.h"
#include <iostream>
#include <stdio.h>

#include <MyGLWidget.h>

using namespace std;
// constructor

MyRadioButton::MyRadioButton(QWidget *parent)
    : QRadioButton(parent) {
    // Inicialització d'atributs si cal
    esL = true;
    }
// implementació slots





void MyRadioButton::changeName(){
    esL = !esL;
    if (esL) setText("Focus Escena");
    else setText("Focus Càmara");

    /*
    if (n == 0) {setText("Càmara"); setStyleSheet("background-color: rgb(255,255,255);");}
    else if (n == 2) {setText("Arbre"); setStyleSheet("background-color: rgb(0,255,0);");}
    else {setText("Patricio"); setStyleSheet("background-color: rgb(255,150,0);");}*/
}
