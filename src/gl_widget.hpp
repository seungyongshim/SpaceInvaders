#pragma once

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QTime>

#include <array>
#include <random>

#include "textured_rect.hpp"
#include "bullet.hpp"

class GameWindow;

double constexpr PI = 3.14159265;

QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)
QT_FORWARD_DECLARE_CLASS(QOpenGLShader)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT
public:
  GLWidget(GameWindow * mw, QColor const & background);
  ~GLWidget();

protected:
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void initializeGL() override;

  void Update(float elapsedSeconds);
  void Render();
  void RenderSpaceShip();
  void RenderBullet();
  void RenderObstacle();
  void RenderStar(float blend);
  void mousePressEvent(QMouseEvent * e) override;
  void mouseDoubleClickEvent(QMouseEvent * e) override;
  void mouseMoveEvent(QMouseEvent * e) override;
  void mouseReleaseEvent(QMouseEvent * e) override;
  void wheelEvent(QWheelEvent * e) override;
  void keyPressEvent(QKeyEvent * e) override;
  void keyReleaseEvent(QKeyEvent * e) override;

  ///
  /// Generate random number between min and max values.
  ///
  /// Look here for more info:
  /// http://www.cplusplus.com/reference/random/uniform_real_distribution/
  ///
  double Random(double min, double max);

private:
  int L2D(int px) const { return px * devicePixelRatio(); }

  GameWindow * m_mainWindow;

  unsigned int m_frames = 0;
  QTime m_time;
  QColor m_background;
  QSize m_screenSize;

  /// m_period is a value between 0.0 and 1.0 .
  /// It as a period.
  float m_period = 0.0f;

  std::vector<std::pair<float,float>> m_random = {
    {0.2f, 0.2f}, {0.5f, 0.5}, {0.7f, 0.7f}};

  QOpenGLTexture * m_textureAlien = nullptr;
  QOpenGLTexture * m_textureStar = nullptr;
  QOpenGLTexture * m_textureSpaceShip = nullptr;
  QOpenGLTexture * m_textureObstacle = nullptr;

  QImage * m_image = nullptr;

  std::list<Bullet*> m_bulletList;

  TexturedRect * m_texturedRect = nullptr;

  QVector2D m_position = QVector2D(200, 200);

  std::array<bool, 4> m_directions = {{ false, false, false, false }};

  std::default_random_engine m_generator;
};
