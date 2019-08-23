#pragma once

#include "Game2D.h"

namespace jm
{
	/*
	TODO:
	- add left arm and left leg
	- make a Person class and use it to draw many people.
	- make an Ironman and allow for him to shoot repulsor beam with his right hand
	*/
	class MyBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		~MyBullet()
		{
		}
		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::red, 0.02f, 0.1f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt;
		}
	};
	class SuperBullet : public virtual MyBullet
	{
	public:
		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::black, 0.02f, 0.1f, 8);
			endTransformation();
		}
	};

	class MySuperBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		~MySuperBullet()
		{
		}
		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledStar(Colors::yellow, 0.1f, 0.05f);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt;
		}
	};

	class WalkingPerson : public virtual Game2D
	{
		float time = 0.0f;
	public:
		vec2 center;
		vec2 velocity = vec2(0.0f, 0.0f);

		WalkingPerson()
		{
			center = vec2(0.0f, -0.55f);
		}
		WalkingPerson(const vec2 &start)
		{
			this->center = start;
		}
		void draw()
		{
			beginTransformation();
			{
				translate(center);
				translate(0.0f, -0.25f);
			}
			endTransformation();

			beginTransformation();
			{
				//face
				translate(center);
				drawFilledCircle(Colors::black, 0.03f);

				//body
				translate(-0.00f, -0.09f);
				drawFilledBox(Colors::black, 0.02f, -0.1f);

				//arm1
				translate(-0.00f, +0.04f);
				rotate(sin(time*5.0f) * 30.0f);					// animation!
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::black, 0.01f, -0.09f);

				//arm2
				translate(-0.00f, +0.04f);
				rotate(sin(time*-5.0f) * 60.0f);
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::black, 0.01f, -0.09f);
			}
			endTransformation();

			beginTransformation();
			{
				translate(center);
				translate(-0.00f, -0.18f);

				//leg2
				translate(-0.00f, +0.04f);
				rotate(sin(time*5.0f) * 20.0f);					// animation!
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::black, 0.01f, -0.08f);

				//leg1
				translate(-0.00f, +0.04f);
				rotate(sin(time*-5.0f) * 40.0f);
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::black, 0.01f, -0.08f);
			}
			endTransformation();
			time += this->getTimeStep();
		}
		void update() override
		{
		}
		friend class Main;
		friend class SuperEnemy;
	};


	class SuperEnemy : public virtual WalkingPerson
	{
	public:
		int enegy = 100;
		int para = 1;
		SuperEnemy() :WalkingPerson()
		{
			center = vec2(0.0f, -0.55f);
		}
		SuperEnemy(const vec2 &start)
		{
			this->center = start;
		}
		void draw()
		{
			beginTransformation();
			{
				translate(center);
				translate(0.0f, -0.25f);
				drawEnergybar(Colors::red, Colors::black, 0.15f, 0.02f, enegy, para);
			}
			endTransformation();

			beginTransformation();
			{
				//face
				translate(center);
				drawFilledCircle(Colors::red, 0.03f);

				//body
				translate(-0.00f, -0.09f);
				drawFilledBox(Colors::red, 0.02f, -0.1f);

				//arm1
				translate(-0.00f, +0.04f);
				rotate(sin(time*5.0f) * 30.0f);					// animation!
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::red, 0.01f, -0.09f);

				//arm2
				translate(-0.00f, +0.04f);
				rotate(sin(time*-5.0f) * 60.0f);
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::red, 0.01f, -0.09f);
			}
			endTransformation();

			beginTransformation();
			{
				translate(center);
				translate(-0.00f, -0.18f);

				//leg2
				translate(-0.00f, +0.04f);
				rotate(sin(time*5.0f) * 20.0f);					// animation!
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::red, 0.01f, -0.08f);

				//leg1
				translate(-0.00f, +0.04f);
				rotate(sin(time*-5.0f) * 40.0f);
				translate(-0.00f, -0.04f);
				drawFilledBox(Colors::red, 0.01f, -0.08f);
			}
			endTransformation();
			time += this->getTimeStep();
		}
		void update() override
		{
		}
	};


	class Main :public virtual WalkingPerson
	{
	public:
		Main() :WalkingPerson()
		{
		}
		int enegy = 1000;
		int para = 0;
		void draw()
		{
			if (center.y == -0.55f)
			{
				beginTransformation();
				{
					//enerybar
					translate(center);
					translate(0.0f, -0.25f);
					drawEnergybar(Colors::red, Colors::black, 0.15f, 0.02f, enegy,para);

					translate(0.0f, +0.35f);
					drawWiredCircle(Colors::gold, 0.02f);
					drawWiredCircle(Colors::black, 0.015f);
				}
				endTransformation();

				beginTransformation();
				{
					//face
					translate(center);
					drawFilledCircle(Colors::black, 0.03f);

					//body
					translate(-0.00f, -0.09f);
					drawFilledBox(Colors::gray, 0.02f, -0.1f);

					//arm1
					translate(-0.00f, +0.04f);
					rotate(sin(time*5.0f) * 30.0f);					// animation!
					translate(-0.00f, -0.04f);
					drawFilledBox(Colors::gold, 0.01f, -0.09f);

					//arm2
					translate(-0.00f, +0.04f);
					rotate(sin(time*-5.0f) * 60.0f);
					translate(-0.00f, -0.04f);
					drawFilledBox(Colors::blue, 0.01f, -0.09f);
				}
				endTransformation();

				beginTransformation();
				{
					translate(center);
					translate(-0.00f, -0.18f);

					//leg2
					translate(-0.00f, +0.04f);
					rotate(sin(time*5.0f) * 20.0f);					// animation!
					translate(-0.00f, -0.04f);
					drawFilledBox(Colors::blue, 0.01f, -0.08f);

					//leg1
					translate(-0.00f, +0.04f);
					rotate(sin(time*-5.0f) * 40.0f);
					translate(-0.00f, -0.04f);
					drawFilledBox(Colors::blue, 0.01f, -0.08f);
				}
				endTransformation();
				time += this->getTimeStep();
			}
			////////ÂÞ±×¸®±â
			else if (center.y <= -0.65f)
			{
				beginTransformation();
				{
					//enerybar
					translate(center);
					translate(0.0f, -0.15f);
					drawEnergybar(Colors::red, Colors::black, 0.15f, 0.02f, enegy,para);

					translate(0.0f, +0.25f);
					drawWiredCircle(Colors::gold, 0.02f);
					drawWiredCircle(Colors::black, 0.015f);
				}
				endTransformation();

				beginTransformation();
				{
					//face
					translate(center);
					drawFilledCircle(Colors::black, 0.03f);

					//body
					translate(+0.1f, -0.00f);
					drawFilledBox(Colors::gray, 0.1f, -0.02f);

					//arm1
					translate(-0.04f, -0.05f);
					drawFilledBox(Colors::gold, 0.01f, -0.1f);

					//arm2

					translate(+0.02f, -0.00f);
					drawFilledBox(Colors::blue, 0.01f, -0.1f);

					//leg2
					translate(+0.065f, +0.00f);
					drawFilledBox(Colors::blue, 0.01f, -0.09f);

					//leg1
					translate(-0.015f, -0.00f);
					drawFilledBox(Colors::blue, 0.01f, -0.09f);

					//leg rest
					translate(+0.035f, -0.04f);
					drawFilledBox(Colors::blue, 0.09f, -0.01f);
				}
			}
			else if (center.y == -0.649f)
			{
				beginTransformation();
				{
					//enerybar
					translate(center);
					translate(0.0f, -0.15f);
					drawEnergybar(Colors::red, Colors::black, 0.15f, 0.02f, enegy,para);

					translate(0.0f, +0.25f);
					drawWiredCircle(Colors::gold, 0.02f);
					drawWiredCircle(Colors::black, 0.015f);
				}
				endTransformation();

				beginTransformation();
				{
					//face
					translate(center);
					drawFilledCircle(Colors::black, 0.03f);

					//body
					translate(-0.1f, -0.00f);
					drawFilledBox(Colors::gray, 0.1f, -0.02f);

					//arm1
					translate(+0.04f, -0.05f);
					drawFilledBox(Colors::gold, 0.01f, -0.1f);

					//arm2

					translate(-0.02f, -0.00f);
					drawFilledBox(Colors::blue, 0.01f, -0.1f);

					//leg2
					translate(-0.065f, +0.00f);
					drawFilledBox(Colors::blue, 0.01f, -0.09f);

					//leg1
					translate(+0.015f, -0.00f);
					drawFilledBox(Colors::blue, 0.01f, -0.09f);

					//leg rest
					translate(-0.035f, -0.04f);
					drawFilledBox(Colors::blue, 0.09f, -0.01f);
				}
			}
		}
	};
}