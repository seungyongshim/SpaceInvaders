#include "game_entity_with_weapon.hpp"

#include <memory>

class Alien : public GameEntityWithWeapon
{
public:
  Alien()
    : GameEntityWithWeapon("Alien")
  {}

  Alien(uint const & speed,
        QVector2D const & position,
        uint const & rate,
        uint const & health)
    : GameEntityWithWeapon(position, "Alien", rate, health),
      m_speed(speed)
  {}

  Alien(uint const & speed,
        QVector2D const & position,
        uint const & rate,
        uint const & health,
        std::shared_ptr<QImage> image,
        TSize const & size)
    : GameEntityWithWeapon(position, "Alien", rate, health, image, size),
      m_speed(speed),
      m_shotTime(rate)
  {}

  ~Alien() override;

  void Move() override;
  void Update() override;
  uint GetSpeed() const;
  void SetSpeed(uint const & rate);
  bool Shot();
  
private:
  uint m_speed = 0;
  uint m_shotTime = 0;
};

using TAlienPtr = std::shared_ptr<Alien>;

std::ostream & operator << (std::ostream & os,
                            Alien const & obj);
