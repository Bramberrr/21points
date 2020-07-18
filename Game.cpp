#include "Game.h"
int n;

Game::Game()
{
    n = 0;
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{
}
int Game::Menu()
{
    char ch[5];
    while (1)
    {

        cout << "-------------------------\n";
        cout << "Welcome to xzw's 21 points!" << endl;
        cout << " "
             << "Menu" << endl;
        cout << "0:Continue" << endl;
        cout << "1:Single Game\n";
        cout << "2:Multiplayer Game\n";
        cout << "3:Help\n";
        cout << "4:Exit\n";
        cout << "-------------------------\n";
        cout << "Your choice:";
        while (cin >> ch)
        {
            if ('0' <= ch[0] && ch[0] <= '4')
                break;
            else
                cout << "Error! Enter again:";
        }
        switch (ch[0])
        {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return -1;
        }
    }
}

void Game::Save()
{
    ofstream outfile("history.txt", ios::out);
    if (!outfile)
    {
        cerr << "open error!" << endl;
        abort();
    }
    outfile << n << endl;
    for (int i = 0; i < n; i++)
    {
        outfile << m_Players[i].m_Name << " " << m_Players[i].m_Money << endl;
    }
    outfile.close();
}

void Game::Continue()
{
    ifstream infile("history.txt", ios::in);
    if (!infile)
    {
        cerr << "open error!" << endl;
        abort();
    }
    cout << "loading....." << endl;
    infile >> n;
    for (int i = 0; i < n; i++)
    {
        infile >> m_Players[i].m_Name >> m_Players[i].m_Money;
    }
    infile.close();
}

void Game::Help()
{
    cout << "21 piont is an ancient poker game. The rules of the game are: " << endl;
    cout << "each player tries to make his card score 21 but not more than that. " << endl;
    cout << "Poker cards are valued at their face value. A acts as a score of 1 " << endl;
    cout << "or 11 (a score chosen by the player himself). J. Q and K are both 10  " << endl;
    cout << "points. The dealer deals with one to seven players. At the beginning" << endl;
    cout << "of the game, all participants, including the banker, had two cards. " << endl;
    cout << "Players can see all their cards and total points, while the dealer has" << endl;
    cout << " a card that is temporarily hidden. Next, each player has the opportunity" << endl;
    cout << " to take another card in turn if he wants to. If a players total score " << endl;
    cout << "exceeds 21, the player loses. After all players have taken extra cards, " << endl;
    cout << "the dealer will show hidden cards. As long as the bankers total score " << endl;
    cout << "is less than 17, then he must take another card. If the banker detonates," << endl;
    cout << " then all players who have not detonated will win. The player who " << endl;
    cout << "detonated was tied. Otherwise, compare the total score of the remaining " << endl;
    cout << "players with the total score of the banker. If the total score of the " << endl;
    cout << "player is greater than the total score of the banker, the player wins. " << endl;
    cout << "If the total score of the two is the same, the player and the banker draw." << endl;
}

void Game::InitUser()
{

    n = 1;
    cout << "Please enter your name:";
    cin >> m_Players[0].m_Name;
    cout << "How many dollars do you have?";
    cin >> m_Players[0].m_Money;
    cout << "Game begin!" << endl;
}

void Game::InitUsers()
{
    cout << "Welcome to xzw's 21 points!" << endl;
    n = 0;
    while (n < 1 || n > 7)
    {
        cout << "How many people are going to play?(1-7):";
        cin >> n;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "No." << i + 1 << ", please enter your name:";
        cin >> m_Players[i].m_Name;
        cout << "How many dollars do you have?";
        cin >> m_Players[i].m_Money;
    }
    cout << "Game begin!" << endl;
}

void Game::Play()
{
    int i;

    for (i = 0; i < n; i++)
    {
        cout << m_Players[i].m_Name << " ,how many dollars do you want to bet?" << endl;
        int m;
        cin >> m;
        while (m <= 0)
        {
            cout << "Nonlegal! Enter again." << endl;
            cin >> m;
        }
        m_Players[i].m_Bet = m;
    }
    for (int c = 0; c < 2; c++)
    {
        for (i = 0; i < n; i++)
        {
            m_Deck.Deal(m_Players[i]);
        }
        m_Deck.Deal(m_House);
    }

    m_House.FlipFirstCard();

    for (i = 0; i < n; i++)
    {
        cout << m_Players[i] << endl;
    }
    cout << m_House << endl;

    for (i = 0; i < n; i++)
    {
        m_Deck.AdditionalCards(m_Players[i]);
    }

    m_House.FlipFirstCard();
    cout << endl
         << m_House;

    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted())
    {
        for (i = 0; i < n; i++)
        {
            if (!(m_Players[i].IsBusted()))
            {
                m_Players[i].m_Money += 1.5 * m_Players[i].m_Bet;
                m_Players[i].Win();
            }
            else
            {
                m_Players[i].m_Money -= m_Players[i].m_Bet;
                m_Players[i].Lose();
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (!(m_Players[i].IsBusted()))
            {
                if (m_Players[i].GetTotal() > m_House.GetTotal())
                {
                    m_Players[i].m_Money += 1.5 * m_Players[i].m_Bet;
                    m_Players[i].Win();
                }
                else if (m_Players[i].GetTotal() < m_House.GetTotal())
                {
                    m_Players[i].m_Money -= m_Players[i].m_Bet;
                    m_Players[i].Lose();
                }

                else
                {
                    m_Players[i].Draw();
                }
            }
            else
            {
                m_Players[i].m_Money -= m_Players[i].m_Bet;
                m_Players[i].Lose();
            }

            if (m_Players[i].m_Money < 0)
                cout << m_Players[i].m_Name << " , you have owed XZW(the house) a lot!" << endl;
        }
    }


    for (i = 0; i < n; i++)
    {
        m_Players[i].Clear();
    }
    m_House.Clear();
}
int Game::JudgePlay()
{
    char again;
    cout << "Once again?(Y/N)" << endl;
    cin >> again;
    if (again == 'y' || again == 'Y')
        return 1;
    else
        return 0;
}

ostream &operator<<(ostream &os, const Card &aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    if (aCard.m_IsFaceUp)
        os << SUITS[aCard.m_Suit] << RANKS[aCard.m_Rank];
    else
        os << "XX";
    return os;
}
ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";
    vector<Card *>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end(); ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.GetTotal() != 0)
            cout << "Total:" << aGenericPlayer.GetTotal() << endl;
    }
    else
    {
        os << "<nothing>";
    }
    return os;
}