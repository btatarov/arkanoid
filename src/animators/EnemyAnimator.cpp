#include<animators/EnemyAnimator.h>
#include<SpriteUtils.h>

EnemyAnimator::EnemyAnimator(const std::vector<Enemy> &enemies) : enemies(enemies) {

}

void EnemyAnimator::loadSprites(SDL_Surface *spritesheet) {
  // Scale sprites to enemy physical dimensions.
  SpriteUtils::loadSpritesFromGrid(spritesheet, 8, 335, 34, 44, 10, 0, 5, 5, 
				   Enemy::enemyPhysicalWidth, Enemy::enemyPhysicalHeight, enemySprites);
}

void EnemyAnimator::incrementAll() {
  std::unordered_map<int, int> :: iterator it;
  for(it = frameCounter.begin(); it != frameCounter.end(); it++) {
    it -> second++;
    if(it -> second == framesPerSprite * enemySprites.size()) it -> second = 0;
  }
}

void EnemyAnimator::draw(SDL_Surface *target, int baseX, int baseY) {
  incrementAll();
  for(int i = 0; i < enemies.size(); i++) {
    const Enemy &enemy = enemies[i];
    SDL_Rect r;
    r.x = enemy.getX() + baseX;
    r.y = enemy.getY() + baseY;
    if(frameCounter.find(enemy.getId()) == frameCounter.end()) frameCounter[enemy.getId()] = 0;
    
    int framesSoFar = frameCounter[enemy.getId()];
    int whichSprite = framesSoFar / framesPerSprite;
    SDL_BlitSurface(enemySprites[whichSprite], nullptr, target, &r);
  }
}

void EnemyAnimator::reset() {
  frameCounter.clear();
}
