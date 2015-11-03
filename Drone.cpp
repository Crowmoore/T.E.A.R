#include "Drone.h"

Drone::Drone() {}
Drone::~Drone() {}
Drone::Drone(sf::Vector2f spawn) {
	Loader loader;
	this->tex = loader.loadTexture("assets/pics/drone.png");
	this->setTexture(tex);

	this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
	this->setScale(sf::Vector2f(0.3, 0.3));
	this->setPosition(spawn);
	this->setRotation(0);
	this->damage = 5;
	this->score = 10;
	this->health = 30;
	this->velocity = sf::Vector2f(2.f, 2.f);
}

float Drone::calculateRotation(sf::RenderWindow &window, Player &player) {
	sf::Vector2f currentPosition = this->getPosition();
	sf::Vector2f playerPosition = player.getPosition();

	const float pi = 3.14159265;

	float dx = playerPosition.x - currentPosition.x;
	float dy = playerPosition.y - currentPosition.y;

	float degrees = (atan2(dy, dx)) * 180.0 / pi;
	float radians = (atan2(dy, dx));
	this->setRotation(degrees + 90);
	return radians;
}
void Drone::animate() {}

void Drone::shoot(sf::RenderWindow &window, Player &player, vector <Enemy *> &enemies, vector <Bullet *> &bullets) {

		int random = rand() % 50 + 1;
		if (random == 1) {
			Bullet* bullet = new Bullet(this->getPosition(), player.getPosition(), sf::Color::Yellow, "enemy");
			bullet->setVelocity(sf::Vector2f(8, 8));
			bullet->setScale(0.3, 0.3);
			bullet->setDamage(this->damage);
			bullet->calculateRotation(window);
			bullet->calculateDirection(window);
			bullets.push_back(bullet);
		}
	
}
