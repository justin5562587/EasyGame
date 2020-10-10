//
// Created by justin on 2020/10/10.
//
#ifndef EASYGAME_PLAYER_H
#define EASYGAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player : public sf::Drawable {

public:

    Player(const Player &) = delete;

    Player &operator=(const Player &) = delete;

    Player();

private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the texture
        states.texture = &m_texture;

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_texture;

};


#endif //EASYGAME_PLAYER_H
