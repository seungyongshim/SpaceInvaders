#pragma once

#include <list>
#include "alien.hpp"
#include "space_ship.hpp"
#include "obstacle.hpp"
#include "star.hpp"
#include "explosion.hpp"

class Space
{
public:
  Space() = default;

  virtual ~Space();

  std::list<TAlienPtr> & GetAliens();
  std::list<TObstaclePtr> & GetObstacles();
  std::list<TStarPtr> const & GetStars() const;
  std::list<TBulletPtr> & GetAlienBullets();
  std::list<TBulletPtr> & GetSpaceShipBullets();
  TSpaceShipPtr const & GetSpaceShip() const;
  std::list<TExplosionPtr> & GetExplosions();

  void AddAlien(TAlienPtr alien);
  void AddObstacle(TObstaclePtr obstacle);
  void AddStar(TStarPtr star);
  void AddAlienBullet(TBulletPtr bullet);
  void AddSpaceShipBullet(TBulletPtr bullet);
  void SetSpaceShip(TSpaceShipPtr spaceShip);
  void AddExplosion(TExplosionPtr explosion);
  
private:
  std::list<TAlienPtr> m_alienList;
  TSpaceShipPtr m_space_ship = nullptr;
  std::list<TObstaclePtr> m_obstacleList;
  std::list<TStarPtr> m_starList;
  std::list<TBulletPtr> m_spaceShipBulletList;
  std::list<TBulletPtr> m_alienBulletList;
  std::list<TExplosionPtr> m_explosionList;
};

std::ostream & operator << (std::ostream & os,
                            Space const & obj);
