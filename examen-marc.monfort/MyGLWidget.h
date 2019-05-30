#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);
    // mouse{Press/Release/Move}Event - Són cridades quan es realitza l'event 
    // corresponent de ratolí
    virtual void mousePressEvent (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);
    virtual void mouseMoveEvent (QMouseEvent *event);

  private:
    void creaBuffersModel ();
    void creaBuffersPilota ();
    void creaBuffersCub ();
    void creaBuffersTerra ();
    void carregaShaders ();
    void iniEscena ();
    void iniCamera ();
    void projectTransform ();
    void viewTransform ();
    void modelTransformIdent ();
    void modelTransformModel ();
    void modelTransformPilota ();
    void calculaCapsaModel (Model &p, float &escala, glm::vec3 &CentreBase);

    void iniciPilota ();
    void dirInicialPilota ();
    void mouPilota (glm::vec3 dir);
    void rebotaParets ();
    void tractamentGol ();
    bool rebotaPorter ();
    void canviaDireccio ();
    
    void modelTransformIdent_1 ();
    void modelTransformIdent_2 ();
    void modelTransformIdent_3 ();

    // VAO i VBO names
    GLuint VAO_Patr, VAO_Pil, VAO_Cub, VAO_Terra;
    // Program
    QOpenGLShaderProgram *program;
    // Viewport
    GLint ample, alt;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // attribute locations
    GLuint vertexLoc, normalLoc, matambLoc, matdiffLoc, matspecLoc, matshinLoc;

    // model
    Model patr, pil;
    // paràmetres calculats a partir de la capsa contenidora del model
    glm::vec3 centreBaseModel, centreBasePil;
    float escalaModel, escalaPil;
    // radi de l'escena
    float radiEsc;
    glm::vec3 posPilota, posPorter;

    typedef  enum {NONE, ROTATE} InteractiveAction;
    InteractiveAction DoingInteractive;
    int xClick, yClick;
    float angleY, angleX;

    // per al moviment de la pilota
    QTimer timer;
    glm::vec3 dirPilota;;
    
    
    //NOU
    glm::vec3 minC, maxC;
    
    float FOV, zNear, zFar, ra, dist;
    float raw_act, FOV_act;
    
    glm::vec3 centreEsc;
    
    GLuint posLoc;
    glm::vec3 posFocus;
    GLuint esFLoc;
    bool esF;
    
    float pasito;
    
    int gols;
    bool esGol;
    
    
    bool novaC;

  public slots:
    void mourePilota ();
    void canviCamara();
    void cam1();
    void cam2();
    
signals:
    void sig_gol(int);
};

