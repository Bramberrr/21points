#include "PlayerHouse.h"

Player::Player(const string &name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::IsHitting() const
{
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}
void Player::Win() const
{
    
    cout << m_Name << " You win!" << endl;
    cout << "You have "<<m_Money<<" dollars now."<<endl;
}
void Player::Lose() const
{

    cout << m_Name << " You Lose!" << endl;
    cout << "You have "<<m_Money<<" dollars now."<<endl;
}
void Player::Draw() const
{
    cout << m_Name << " You draw!" << endl;
    cout << "You have "<<m_Money<<" dollars now."<<endl;
}
