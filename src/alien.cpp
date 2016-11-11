#include "Alien.h"
#include "Point2D.h"
#include "Global_configs.h"
#include "Box2D.h"

Alien::Alien(Box2D const & box, Point2D const & direction, int const typeBeing): m_typeBeing(typeBeing)
{
  SetParameters(box, direction);
  Point2D point(box.Width() / 2, box.Width() / 2);
  m_gun = Gun(Box2D(point, point), direction, beingConfigs[m_typeBeing].typeGun);
  m_hp = beingConfigs[m_typeBeing].hp;
}

Alien::Alien(const Alien & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBeing = obj.TypeBeing();
  m_hp = beingConfigs[m_typeBeing].hp;
}

Alien Alien::operator = (const Alien & obj)
{
  SetParameters(obj.Box(), obj.Direction());
  m_typeBeing = obj.TypeBeing();
  m_hp = beingConfigs[m_typeBeing].hp;
  return *this;
}

int const & Alien::TypeBeing() const
{
  return m_typeBeing;
}

void Alien::Behavior()
{

}

void Alien::Shot()
{
  m_gun.Shot(Box().PointMin());
}
