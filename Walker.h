//
// Created by Michael on 2020-08-15.
//

#ifndef RAINBOW_WALKER_H
#define RAINBOW_WALKER_H

#include "cinder/gl/gl.h"

class Walker {
public:
    Walker();

    void setSize(float);
    void setPosition(const ci::vec2 &);
    void setBounds(const ci::vec2 &, const ci::vec2 &);
    void setColour(const ci::ColorA &);
    void step();
    void draw() const;

private:
    float      size;
    ci::vec2   position;
    ci::vec2   leftTopBound;
    ci::vec2   rightBottomBound;
    ci::ColorA colour;
};


#endif //RAINBOW_WALKER_H
