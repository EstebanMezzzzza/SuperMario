#pragma once

#include "Boss.hpp"

class BossFinal : public Boss
{
public:

    BossFinal();

    ~BossFinal() override;

    void actualizar(float dt) override;
};
