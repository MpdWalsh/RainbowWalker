//
// Created by Michael on 2020-08-15.
//

#include "Walker.h"

#include "cinder/Rand.h"

Walker::Walker()
: position(ci::vec2()), size(0), leftTopBound(ci::vec2()), rightBottomBound(ci::vec2()), colour(ci::Color::white())
{}

void Walker::setSize(float s) {
    size = s;
}

void Walker::setPosition(const ci::vec2 &p) {
    position = p;
}

void Walker::setBounds(const ci::vec2 &lt, const ci::vec2 &rb) {
    leftTopBound = lt;
    rightBottomBound = rb;
}

void Walker::setColour(const ci::ColorA &c) {
    colour = c;
}

float bounce(float boundary, float position) {
    return 2 * boundary - position;
}

void Walker::step() {
    float minWidth = leftTopBound.x;
    float maxWidth = rightBottomBound.x;
    float minHeight = leftTopBound.y;
    float maxHeight = rightBottomBound.y;

    ci::vec2 delta = ci::randVec2();

    float newX = position.x + delta.x;
    float newY = position.y + delta.y;

    position.x = newX;
    if (newX < minWidth) position.x = bounce(minWidth, newX);
    if (newX > maxWidth) position.x = bounce(maxWidth, newX);

    position.y = newY;
    if (newY < minHeight) position.y = bounce(minHeight, newY);
    if (newY > maxHeight) position.y = bounce(maxHeight, newY);
}

void Walker::draw() const {
    ci::gl::color(colour);
    ci::gl::drawSolidCircle(position, size);
}
