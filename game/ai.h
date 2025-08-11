#pragma once
enum AIDifficulty{ AI_Easy, AI_Normal, AI_Hard };
void ai_init(AIDifficulty d);
void ai_update(double dt);
