#ifndef SNOWFLAKE_H_
#define SNOWFLAKE_H_

#include "ofMain.h"
#include "Particle.h"

class Snowflake {
public:
    Snowflake() = default;
    Snowflake(float x, float y, float r);
    ~Snowflake();

    void update();
    void draw();
    bool is_complete();

private:
    float m_x, m_y, m_r;
    Particle cur;
    vector<Particle> particles;
	float rcnt = 0.f;
    bool m_complete;
};

#endif // SNOWFLAKE_H_
