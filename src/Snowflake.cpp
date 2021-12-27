#include "Snowflake.h"
#include "Particle.h"

Snowflake::Snowflake(float x, float y, float r):
    m_x(x), m_y(y), m_r(r), m_complete(false)
{
    cur = Particle({0, 0, 0}, 1);
}

Snowflake::~Snowflake() {}

void
Snowflake::update() {
    if (!m_complete) {
        while (!cur.finished() && !cur.intersects(particles)) {
            cur.update();
        }

        particles.push_back(cur);
        cur = Particle({m_r, ofRandom(-10.f, 10.f), 0}, 1);

        m_complete |= particles.size() >= m_r * 4;
    }

    rcnt += 1.f;
}

void
Snowflake::draw() {
    ofTranslate(m_x, m_y, 0);
    ofRotateYDeg(rcnt);

    for (auto i = 0ul; i < 6ul; ++i)
    {
        ofRotateZDeg(60.f);
        for (auto &p : particles)
        {
            p.draw();
        }

        ofPushMatrix();
        ofScale(1, -1);
        for (auto &p : particles)
        {
            p.draw();
        }
        ofPopMatrix();
    }

    ofRotateYDeg(-rcnt);
    ofTranslate(-m_x, -m_y);
}

bool
Snowflake::is_complete() {
    return m_complete;
}
