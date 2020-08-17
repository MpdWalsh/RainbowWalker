#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Walker.h"

#define MAX_WALKERS 2048

#define ALPHA 0.05
#define SIZE 2

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define BORDER 10
#define LEFT_BOUND BORDER
#define TOP_BOUND BORDER
#define RIGHT_BOUND SCREEN_WIDTH - BORDER
#define BOTTOM_BOUND SCREEN_HEIGHT - BORDER

using namespace ci;
using namespace ci::app;

class RainbowWalkerApp : public App {
  public:
    static void prepareSettings(Settings*);
    void setup() override;
    void mouseDrag(MouseEvent e) override;
    void keyDown(KeyEvent e) override;
    void update() override;
    void draw() override;

  private:
    Walker*      walkers[MAX_WALKERS];
    unsigned int fill_level;

};

void RainbowWalkerApp::prepareSettings(Settings* s) {
    s->setTitle("Rainbow Walkers");
    s->setWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    s->setHighDensityDisplayEnabled();
}

void RainbowWalkerApp::setup() {
    gl::enableVerticalSync();
    gl::setMatricesWindow(getWindowSize());

    fill_level = 0;
}

bool mouseInBounds(MouseEvent &e) {
    int mouseX = e.getX();
    int mouseY = e.getY();

    return (mouseX >= LEFT_BOUND && mouseX <= RIGHT_BOUND && mouseY >= TOP_BOUND && mouseY <= BOTTOM_BOUND);
}

ColorA randomColour(float a) {
    float r = randFloat(0.0f, 1.0f);
    float g = randFloat(0.0f, 1.0f);
    float b = randFloat(0.0f, 1.0f);

    return ColorA(r, g, b, a);
}

void RainbowWalkerApp::mouseDrag(MouseEvent e) {
    if(!e.isLeft() || !mouseInBounds(e) || fill_level == MAX_WALKERS) return;

    vec2 leftTop (LEFT_BOUND, TOP_BOUND);
    vec2 rightBottom (RIGHT_BOUND, BOTTOM_BOUND);

    auto w = new Walker();
    w->setPosition(vec2(e.getX(), e.getY()));
    w->setSize(SIZE);
    w->setBounds(leftTop, rightBottom);
    w->setColour(randomColour(ALPHA));

    walkers[fill_level] = w;
    ++fill_level;
}

void RainbowWalkerApp::keyDown(KeyEvent e) {
    switch (e.getCode()) {
        case e.KEY_SPACE: fill_level = 0; break;
    }
}

void RainbowWalkerApp::update() {
    for (int i = 0; i < fill_level; ++i) walkers[i]->step();
}

void RainbowWalkerApp::draw() {
    if (fill_level == 0) gl::clear();
    for (int i = 0; i < fill_level; ++i) walkers[i]->draw();
}

CINDER_APP(RainbowWalkerApp, RendererGl, &RainbowWalkerApp::prepareSettings)
